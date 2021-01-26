#include "../hpp/comandos.hpp"

//Function that prints the youngest commander from right or left
void commander(Grafo gr, int vertice){
	int i = 0;
	int menorIdade = 0;

	vertice -= 1;

	std::vector<int> visitado;
    std::list<int> fila;
    std::vector<int> idades;
	
	Grafo grafoT = FuncoesAuxiliares::transposto(gr);

	for(i=0;i<grafoT.numV;i++){
        visitado.push_back(0);     
	}

    visitado[vertice] = 1;
    fila.push_back(vertice);

	BuscaGrafo::bfsAuxCommander(gr, grafoT, fila, idades, vertice, visitado);
	sort(idades.begin(), idades.end());
	
	if(idades.empty()==1){
		std::cout << "C *" << std::endl;
	}
	else {
		menorIdade = idades.front(); 
		std::cout << "C " << menorIdade << std::endl;
	}
}

// Check if there is a edge in between two vertex, if yes, the edge direction is swaped since that change doesn't create any cycle
void swap(Grafo gr, int vertice1, int vertice2){
	vertice1 -= 1;
	vertice2 -= 1;

	int temAresta = find(gr.listaArestas[vertice1].begin(), gr.listaArestas[vertice1].end(), vertice2) != gr.listaArestas[vertice1].end();	
	
	if(temAresta==0){
		std::cout << "S N" << std::endl;
		return;
	} else{
		gr.listaArestas[vertice1].remove(vertice2);
		gr.listaArestas[vertice2].push_back(vertice1);
	}
	
	if(FuncoesAuxiliares::temCicloGrafo(gr)==1){
		gr.listaArestas[vertice2].remove(vertice1);
		gr.listaArestas[vertice1].push_back(vertice2);
		std::cout << "S N" << std::endl;
		return;
	}
	else{
		std::cout << "S T" << std::endl;
		return;
	}
}

// Function that print the topological ordering 
void meeting(Grafo gr){

	unsigned int i = 0;

	std::vector<int> ordem = FuncoesAuxiliares::ordenaGrafo(gr);
	std::cout << "M ";

	for(i=0;i<ordem.size();i++){
		std::cout << ordem[i]+1 << " ";
	}
	std::cout << std::endl;
}