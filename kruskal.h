#ifndef KRUSKAL_H
#define KRUSKAL_H
#include"grafo.h"
#include<QString>
#include <vector>
#include<map>
#include"cola.h"
class Kruskal
{
public:
    Cola *cola;
    int cont;
    vector<int>trees;
    vector<Arista*>aristas;
    bool checkSiblings(Nodo *n, int tree, Arista *v);
    bool checkTrees(Nodo* n,Arista *a);
    bool checkAristas(Nodo* n);
    void newTree();
    bool isNewTree(int tree);
    Grafo * grafo;
    multimap<int, Arista *> sortAristas(vector<Arista*>arcos);
    void analisis();
    Kruskal(Grafo * g);
};

#endif // KRUSKAL_H
