#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <map>

#include "../hpp/leitura.hpp"

Grafo leArquivo(std::string arquivotxt){
	std::ifstream arquivoGrafo;

	arquivoGrafo.open(arquivotxt);
	int i = 0;
	int numV = 0, numA = 0, numC = 0;
	int idade = 0, orig = 0, dest = 0;
	int vertice = 0;
	char comando;
	std::vector<char> comandos;
	std::vector<int> verticesComandos;

	arquivoGrafo >> numV >> numA >> numC;

	Grafo gr(numV, numA, numC);

	for(i=0;i<numV;i++){
		arquivoGrafo >> idade;
		gr.idades[i] = idade;
	}

	for(i=0;i<numA;i++){
		arquivoGrafo >> orig >> dest;
		gr.insereA(orig, dest);
	}

	for(i=0;i<numC;i++){

		arquivoGrafo >> comando;

		if(comando=='C'){
			comandos.push_back(comando);
			arquivoGrafo >> vertice;
			verticesComandos.push_back(vertice);
		} else if(comando=='S'){
			comandos.push_back(comando);
			arquivoGrafo >> vertice;
			verticesComandos.push_back(vertice);
			arquivoGrafo >> vertice;
			verticesComandos.push_back(vertice);
		} else if(comando=='M'){
			comandos.push_back(comando);
		}
	}

	gr.verticesComandos = verticesComandos;
	gr.comandos = comandos;
	arquivoGrafo.close();
	
	return gr;
}