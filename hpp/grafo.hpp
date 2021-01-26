#include <iostream>
#include <string>
#include <list>
#include <map>
#include <vector>

class Grafo { 
    public: 
        Grafo(int numV, int numA, int numC);
        ~Grafo();
        int numV, numA, numC;
        std::list<int>* listaArestas;
        std::map<int, int> idades;
        std::vector<char> comandos;
        std::vector<int> verticesComandos;
	    void insereA(int orig, int dest);
};
