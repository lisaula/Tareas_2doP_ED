#include "dijkstrap.h"
#include "ui_dijkstrap.h"
#include<QMessageBox>

Dijkstrap::Dijkstrap(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Dijkstrap)
{
    ui->setupUi(this);
    setWindowTitle("Dijkstrap");
    cont=0;
}

Dijkstrap::~Dijkstrap()
{
    delete ui;
}

void Dijkstrap::on_Analizar_clicked()
{
    int origen = ui->origen_2->value();
    Nodo* inicio = grafo->buscarNodo(origen);
    int iteraciones=0;
    QString recorrido="";
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
}


void Dijkstrap::on_CrearNodo_clicked()
{
    if(cont==0){
    int num = ui->Nodo->value();
    grafo->agregarNodo(num);
    }else{
        QMessageBox::warning(this,"Atencion","No se veran estos nodos reflejados en la tabla ya que la tabla no puede ser creada dos veces");
    }
}

void Dijkstrap::on_CrearArista_clicked()
{
    int origen = ui->origen->value();
    int destino = ui->destino->value();
    int peso = ui->peso->value();
    grafo->addArco(origen,destino,peso);

}

void Dijkstrap::on_pushButton_clicked()
{
    cont+=1;
    cout<<cont<<endl;
    int nodos = grafo->nodos;

    QStringList titulos;
    titulos << "Iteraciones"<< "Recorrido"<<"Visitado";
    QString t = "";
    Nodo* temp = grafo->actual;
    for(int i =0;i<nodos;i++){
        t = QString("%1").arg(temp->valor);
        titulos << t;
        temp=temp->Ady;
    }
    if(cont==1){
        ui->tableWidget->setColumnCount(3+nodos);
        ui->tableWidget->setHorizontalHeaderLabels(titulos);
    }else{
        QMessageBox::warning(this,"ERROR","No puedes crear la tabla dos veces");
    }
}

void Dijkstrap::setTabla(int nodos, Nodo* origen)
{
    vertices[nodos];
    distancia[nodos];
    path[nodos];
    visitado[nodos];

    for(int i=0; i<nodos;i++){
        Nodo*temp = grafo->actual;
        vertices[i]=temp;
        distancia[i]=INT_MAX;
        path[i]="-1";
        visitado[i]=false;
        temp=temp->Ady;
    }
}

void Dijkstrap::Analisis(Nodo *origen)
{
    setTabla(grafo->nodos,origen);
    this->adyacentes=setAdyacentes(origen,origen->arcos);
    int pos = getMyPos(origen);
    distancia[pos]=0;
    cout<<distancia[pos]<<endl;
}

bool Dijkstrap::checkVisited()
{
    bool visited=false;
    for(int i=0;i<sizeof(visitado);i++){
        if(!visitado[i]){
            return true;
        }
    }
    return false;
}

int Dijkstrap::getMyPos(Nodo* n)
{
    for(int i =0;i<vertices.size();i++){
        if(vertices[i]==n)
            return i;
    }
    return -1;
}

multimap<int,Nodo*> Dijkstrap::setAdyacentes(Nodo* o,vector<Arista *> aristas)
{
    vector<Arista*> ordenado;
    multimap<int, Nodo*>temp2;
    Nodo* n;\
    Arista* v;
    for(int i =0;i<aristas.size();i++){
        v=aristas[i];
        n=v->origen;
        if(n==o){
            n=v->apuntoA;
        }
        temp2.insert(pair<int,Nodo*>(v->valor,n));
    }
    return temp2;
//    multimap<int,Arista*>temp;
//    for(int i =0;i<aristas.size();i++){
//        temp.insert(pair<int,Arista*>(aristas[i]->valor,aristas[i]));
//    }
//    multimap<int,Arista*>::iterator m = temp.end();
//    for(int i=0;i<aristas.size();i++){
//        ordenado.push_back(m->second);
//        m--;
//    }
    //return ordenado;
}

void Dijkstrap::on_probar_clicked()
{

}
