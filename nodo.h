#ifndef NODO_H
#define NODO_H

#include <iostream>
#include<vector>
#include "listaaristas.h"
using namespace std;
class Arista;
class ListaAristas;
class Nodo
{
public:
    int valor;
    int tree;
    bool visitado=false;
    vector<Arista*>arcos;
    void addArco(Arista*);
    void setTree(int v);
    Nodo *Ady;
    void printArcos();
    ListaAristas* aristas;
    Nodo(int valor);
    Nodo();
};

#endif // NODO_H
