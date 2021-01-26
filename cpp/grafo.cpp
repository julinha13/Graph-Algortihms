#include "../hpp/grafo.hpp"

Grafo::Grafo(int numV, int numA, int numC){
	this->numV = numV;
	this->numA = numA;
	this->numC = numC;
    this->listaArestas = new std::list<int>[numV];
}

Grafo::~Grafo() {}

void Grafo::insereA(int orig, int dest){
	orig -= 1;
	dest -= 1;	
	this->listaArestas[orig].push_back(dest); //push a edge in beetwen two given vertex
}