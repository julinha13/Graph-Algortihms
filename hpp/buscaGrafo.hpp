#include "leitura.hpp"

class BuscaGrafo {
    public:
        static int dfsCicloAux(Grafo gr, int verticeInicial, std::vector<int>& visitado, std::vector<int>& pilhaAuxiliar, std::list<int>* vertices);

        static void dfsOrdenaAux(Grafo gr, int posicao, std::vector<int>& visitado, std::vector<int>& ordem);

        static void bfsAuxCommander(Grafo gr, Grafo grafoT, std::list<int>& fila, std::vector<int>& idades, int vertice, std::vector<int>& visitado);
};