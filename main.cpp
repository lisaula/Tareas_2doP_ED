#include "widget.h"
#include <QApplication>
#include "grafo.h"
#include "iostream"
#include "dijks.h"
#include "floyd.h"
#include"prim.h"
#include"kruskal.h"
using namespace std;

void printGrafos(Nodo* actual){
    while(actual){
        cout<<"Actual: "<<actual->valor<<endl;
        actual->printArcos();
        cout<<endl;
        actual = actual->Ady;
    }
}
//void printArcos(vector<Arista*> v){
//    for(int i =0;i<v.size();i++){
//        Arista * temp= v[i];
//        cout<<"Vengo de: "<<temp->origen->valor<<" Peso: "<<temp->valor<<" Apunto a: "<<temp->apuntoA->valor<<endl;
//    }
//}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    Grafo * grafo = new Grafo();
    grafo->agregarNodo(5);
    grafo->agregarNodo(4);
    grafo->agregarNodo(3);
    grafo->agregarNodo(2);
    grafo->agregarNodo(1);
    grafo->agregarNodo(6);
    grafo->agregarNodo(7);
    grafo->agregarNodo(0);
//    grafo->agregarNodo(1);
//    grafo->agregarNodo(2);
//    grafo->agregarNodo(3);
//    grafo->agregarNodo(4);
//    grafo->agregarNodo(5);

//    grafo->agregarArista(1,5,4);
//    grafo->agregarArista(1,2,3);
//    grafo->agregarArista(2,3,2);
//    grafo->agregarArista(3,4,1);
//    grafo->agregarArista(4,1,8);
    //printGrafos(grafo->actual);
//      grafo->addArco(1,5,4);
//      grafo->addArco(1,2,3);
//      grafo->addArco(2,3,2);
//      grafo->addArco(3,4,1);
//      grafo->addArco(4,1,8);
    grafo->addArco(0,1,7);
    grafo->addArco(0,2,5);
    grafo->addArco(0,3,7);
    grafo->addArco(1,2,9);
    grafo->addArco(1,3,8);
    grafo->addArco(1,5,6);
    grafo->addArco(3,7,7);
    grafo->addArco(4,6,5);
    grafo->addArco(5,6,9);
    grafo->addArco(5,7,2);
    grafo->addArco(6,7,7);
    //grafo->addAcout<<"AQUI Actual"<<endl;rco(5,6,7);
    //    grafo->agregarArista(2,3,2);
    //    grafo->agregarArista(3,4,1);
    //    grafo->agregarArista(4,1,8);
    printGrafos(grafo->actual);
    //      grafo->addArco(1,5,4);
    //      grafo->addArco(1,2,3);
    //      grafo->addArco(2,3,2);
    //      grafo->addArco(3,4,1);
    //      grafo->addArco(4,1,8);
//        grafo->addArco(0,1,9);
//        grafo->addArco(0,4,7);
//    grafo->addArco(5,6,3);
    //grafo->addArco(5,3,2);
    //printGrafos(grafo->actual);
    //printArcos(grafo->arcos);
    //cout<<grafo->actual->arcos[0]->apuntoA->valor<<endl;


   //Dijks *dis= new Dijks(grafo);
   Nodo* origen = grafo->buscarNodo(0);
   //dis->Analisis(origen);

    Floyd * floyd = new Floyd(grafo);
    floyd->analisis(origen);
    floyd->camino(1,4);
    floyd->printTabla();
    cout<<endl;
    floyd->printP();
//    Prim * prim = new Prim(grafo);
//    prim->analisis(origen);

//      Kruskal *krus=new Kruskal(grafo);
//      krus->analisis();
//      Nodo* n = krus->grafo->buscarNodo(7);
//      cout<<n->tree<<endl;
//      cout<<krus->grafo->nodos<<endl;
      cout<<endl;
//      cout<<krus->cola->size()<<endl;
//      QString t =krus->cola->imprimir();
//      cout<<t.toStdString()<<endl;
      cout<<"que onda"<<endl;
      cout<<endl;

//    Nodo* nodo = grafo->buscarNodo(5);
//    cout<<"valor buscado"<<nodo->valor<<endl;

//    cout<<"Grafo 1: "<<grafo->actual->valor<<"apunta a"<<grafo->actual->aristas->apuntoA->valor<<endl;
//    cout<<"Grafo 1: "<<grafo->actual->valor<<endl;


    return a.exec();
}

