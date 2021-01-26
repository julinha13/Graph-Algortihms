#include "../hpp/buscaGrafo.hpp"

// Call function to topological ordering (using DFS)
void BuscaGrafo::dfsOrdenaAux(Grafo gr, int posicao, std::vector<int>& visitado, std::vector<int>& ordem){
    visitado[posicao] = 1;
    for(auto i:gr.listaArestas[posicao]){
        if(visitado[i]==0){
            BuscaGrafo::dfsOrdenaAux(gr, i, visitado, ordem);
        }
    }

    ordem.push_back(posicao);
}

// Function that uses a modify DFS to check if there is a cycle 
int BuscaGrafo::dfsCicloAux(Grafo gr, int inicio, std::vector<int>& visitado, std::vector<int>& pilhaAuxiliar, std::list<int> *verticesAux) {     
    visitado[inicio] = 1;
	pilhaAuxiliar[inicio] = 1;	
    verticesAux->remove(inicio);
    std::list<int>::iterator k;

    for(k=gr.listaArestas[inicio].begin();k!=gr.listaArestas[inicio].end();k++){
		if(visitado[*k]==0&&BuscaGrafo::dfsCicloAux(gr, *k, visitado, pilhaAuxiliar, verticesAux)){
            return 1;
        } else if(pilhaAuxiliar[*k]){
			return 1;
        }
	}   
	pilhaAuxiliar[inicio] = 0;
	return 0;
}

// BFS Function BFS of transpose of a graph
void BuscaGrafo::bfsAuxCommander(Grafo gr, Grafo grT, std::list<int>& fila, std::vector<int>& idades, int vertice, std::vector<int>& visitado){
    std::list<int>::iterator k;
    while(fila.empty()==0){

        vertice = fila.front();
        fila.remove(vertice);

        for(k=grT.listaArestas[vertice].begin();k!=grT.listaArestas[vertice].end();k++){
            if(visitado[*k]==0){
                visitado[*k] = 1;                              
                idades.push_back(gr.idades[*k]);
                fila.push_back(*k);
            }
        }         
    }
}
