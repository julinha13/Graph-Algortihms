#include "../hpp/funcoesAuxiliares.hpp"


//funçao que verifica se um grafo possui ciclo
/*visita os vértices com um dfs marcando-os como visitados, e se caso o vértice tenha sido visitado mais de uma vez pelo mesmo pai,
o grafo possui ciclo.*/
int FuncoesAuxiliares::temCicloGrafo(Grafo gr){ 
    int i = 0;	
    std::vector<int> visitado; 
	std::vector<int> pilhaAuxiliar;
    std::list<int> verticesAux;
    for(i=0;i<gr.numV;i++) {
        visitado.push_back(0);
		pilhaAuxiliar.push_back(0); 
        verticesAux.push_back(i);
	}   
    while(verticesAux.empty()==0)    {        
        if(BuscaGrafo::dfsCicloAux(gr, verticesAux.front(), visitado, pilhaAuxiliar, &verticesAux)){
            return 1;
        }
    }
	return 0;
}

//função que trasnpoem o grafo, copiando a lista de adjacência ao contrário.
Grafo FuncoesAuxiliares::transposto(Grafo gr){
    int i = 0;
    Grafo transposto(gr.numV, gr.numA, gr.numC);    
    for(i=0;i<gr.numV;i++){          
        std::list<int>::iterator k;  
        for(k=gr.listaArestas[i].begin();k!=gr.listaArestas[i].end();k++){  
            transposto.listaArestas[*k].push_back(i);                       
        }  
    }  
    return transposto; 
}

//função que realiza a ordenação topológia do grafo. Utiliza o dfs para auxliar a visita.
std::vector<int> FuncoesAuxiliares::ordenaGrafo(Grafo gr){
    int i = 0;

    std::vector<int> visitado;
    std::vector<int> ordem;
    visitado.assign(gr.numV, 0);

    for(i=0;i<gr.numV;i++){
        if(visitado[i]==0){
            BuscaGrafo::dfsOrdenaAux(gr, i, visitado, ordem);
        }
    }
    
    reverse(ordem.begin(), ordem.end());
    return ordem;
}