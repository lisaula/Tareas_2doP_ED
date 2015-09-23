#include "kruskal.h"

bool Kruskal::checkSiblings(Nodo *n, int tree, Arista *v)
{
    Arista *a;
    Nodo* temp;
    bool t1=false, t2=false;
    if(v->origen->tree!=0 || v->apuntoA->tree !=0){
        for(int x=0;x<trees.size();x++){
            if(v->origen->tree==trees[x]){
                t1=true;
                break;
            }
        }
        for(int x=0;x<trees.size();x++){
            if(v->apuntoA->tree==trees[x]){
                t2=true;
                break;
            }
        }
        if(t1 && t2)return true;
    }

    //for(int i =0; i<n->arcos.size();i++){

    //a=n->arcos[i];
//        temp=a->origen;
//        if(temp==n){
//            temp=a->apuntoA;
      //  }

//        bool ver=false;
//        for(int i =0;i<aristas.size();i++){
//            if(a==aristas[i]){
//                ver=true;
//                break;
//            }
//        }
//        if(a==v || ver)continue;
//        if(temp->tree!=0){
//            if(temp->tree==n->tree){
//                cout<<"tree "<<tree<<endl;
//                cout<<"return true entre "<<n->valor<<" con "<<n->tree<<" "<<temp->valor<<" con "<<temp->tree<<endl;
//                return true;
//            }
//        }
//    }
    return false;
}

bool Kruskal::checkTrees(Nodo *n, Arista *a)
{
    for(int i =0;i<trees.size();i++){
        if(checkSiblings(n,trees[i],a))
            return true;
    }
    return false;
}

bool Kruskal::checkAristas(Nodo *n)
{
    Arista* a;
    for(int i =0;i<n->arcos.size();i++){
        a=n->arcos[i];
        if(a->intree)
            return true;
    }
    return false;
}

void Kruskal::newTree()
{
    cont++;
    trees.push_back(cont);
}

bool Kruskal::isNewTree(int tree)
{
    for(int i=0;i<trees.size();i++){
        if(trees[i]==tree){
            return true;
        }
    }
    return false;
}

multimap<int, Arista *> Kruskal::sortAristas(vector<Arista *> arcos)
{
    multimap<int, Arista*>map;
    Arista* v=NULL;
    for(int i =0; i<arcos.size();i++){
        v= arcos[i];
        map.insert(pair<int,Arista*>(v->valor,v));
    }
    return map;
}

void Kruskal::analisis()
{
    multimap<int, Arista*>::iterator ari =sortAristas(grafo->arcos).begin();
    Arista*v;
    for(int i =0; i<grafo->arcos.size();i++){
        v=ari->second;

        cola->push(v);
        ari++;
    }
    Arista *a=NULL;
    Nodo* o=NULL, *d=NULL;
    //string t = cola->imprimir().toStdString();
    cout<<cola->imprimir().toStdString()<<endl;

    while(cola->size()>0){
        cout<<"entro while"<<endl;
        a=cola->pop()->valor;
        cout<<"evaluando a "<<a->origen->valor<<" peso "<<a->valor<<" apunto "<<a->apuntoA->valor<<endl;
        cout<<endl;
        o=a->origen;
        d=a->apuntoA;
        QString t =cola->imprimir();
        cout<<t.toStdString()<<endl;
        cout<<"tree "<<cont<<endl;
        if(o->tree==0 || d->tree==0){
            cout<<"Entro 1er if"<<endl;
            if(o->tree==0 && d->tree==0){
                cout<<"Entro 1.1"<<endl;
                if(trees.size()>0){
                    if(!checkAristas(o) && !checkAristas(d)){
                        newTree();
                        o->setTree(cont);
                        d->setTree(cont);
                        a->setIntree(true);
                        aristas.push_back(a);
                        cout<<"Entro 1"<<endl;
                        cout<<"tree "<<cont<<endl;
                        continue;
                    }else{
                        if(!checkTrees(o,a) && !checkTrees(d,a)){
                            o->setTree(cont);
                            d->setTree(cont);
                            a->setIntree(true);
                            aristas.push_back(a);
                            cout<<"Entro 2"<<endl;
                            cout<<"tree "<<cont<<endl;
                            continue;
                        }
                    }
                }else{
                    newTree();
                    o->setTree(cont);
                    d->setTree(cont);
                    a->setIntree(true);
                    aristas.push_back(a);
                    cout<<"Entro 3"<<endl;
                    cout<<"tree "<<cont<<endl;
                    continue;
                }
            }

            cout<<"trees size "<<trees.size()<<endl;
            cout<<"Que pedo porq no quisiste "<<endl;
            if(trees.size()!=0){
                cout<<"no quiso 1"<<endl;
                if(!checkTrees(o,a) && !checkTrees(d,a)){
                    o->setTree(cont);
                    d->setTree(cont);
                    a->setIntree(true);
                    aristas.push_back(a);
                    cout<<"Entro 4"<<endl;
                    cout<<"tree "<<cont<<endl;
                    continue;
                }
            }else{
                newTree();
                o->setTree(cont);
                d->setTree(cont);
                a->setIntree(true);
                aristas.push_back(a);
                cout<<"Entro 5"<<endl;
                cout<<"tree "<<cont<<endl;
                continue;
            }
            cout<<"Salio"<<endl;
        }else{
            continue;
        }

    }
    Arista* m=NULL;
    cout<<"Size aristas "<<aristas.size()<<endl;
    for(int i =0;i<aristas.size();i++){
        m= aristas[i];
        cout<<m->origen->valor<<" peso "<<m->valor<<" apunto A "<<m->apuntoA->valor<<endl;
    }
}

Kruskal::Kruskal(Grafo *g)
{
    grafo = g;
    cola = new Cola();
    cont=0;
}

