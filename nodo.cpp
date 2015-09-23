#include "nodo.h"

void Nodo::addArco(Arista* v)
{
    arcos.push_back(v);
}

void Nodo::setTree(int v)
{
    tree=v;
}

void Nodo::printArcos()
{
    for(int i=0;i<arcos.size();i++){
        Arista *a = arcos[i];
        if(a->apuntoA==this){
            cout<<" Peso: "<<a->valor<<" Apunto a: "<<a->origen->valor<<endl;
        }else{
            cout<<" Peso: "<<a->valor<<" Apunto a: "<<a->apuntoA->valor<<endl;
        }

    }
}

Nodo::Nodo(int valor)
{
    this->valor=valor;
    this->Ady=NULL;
    this->aristas= new ListaAristas();
    tree=0;
}

Nodo::Nodo(){
    valor=0;
    Ady=NULL;
    aristas=NULL;
    tree=0;
}

