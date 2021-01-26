/*
* Trabalho prático 01 
* Disciplina: ALGORITMOS 01
* Nome: Júlia Amorim de Araujo
*
*/

#include "../hpp/comandos.hpp"

int main(int argc, char* argv[]){
	int i = 0;
	int verticesComandos = 0;
	Grafo grafo = leArquivo(argv[1]);
	
	for(i=0;i<grafo.numC;i++){
		if(grafo.comandos[i]=='C'){
			commander(grafo, grafo.verticesComandos[verticesComandos]);
			verticesComandos++;
		} else if(grafo.comandos[i]=='S') {
			swap(grafo, grafo.verticesComandos[verticesComandos], grafo.verticesComandos[verticesComandos+1]);
			verticesComandos = verticesComandos + 2;
		} else if(grafo.comandos[i]=='M'){
			meeting(grafo);
		}
	}
	return 1;		
}