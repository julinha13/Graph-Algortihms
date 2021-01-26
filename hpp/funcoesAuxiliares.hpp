#include "buscaGrafo.hpp"
#include <stack>
#include <vector>
#include <algorithm>

class FuncoesAuxiliares{
    public:
        static int temCicloGrafo(Grafo gr);
        static Grafo transposto(Grafo gr);
        static std::vector<int> ordenaGrafo(Grafo gr);
};