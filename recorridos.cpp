#include "recorridos.h"
#include "ui_recorridos.h"

Recorridos::Recorridos(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Recorridos)
{
    ui->setupUi(this);
    setWindowTitle("Recorridos");
    grafo = new Grafo();
    grafo->agregarNodo(0);
    grafo->agregarNodo(1);
    grafo->agregarNodo(2);
    grafo->agregarNodo(3);
    grafo->agregarNodo(4);
    grafo->agregarNodo(5);
    grafo->agregarNodo(6);
    grafo->agregarNodo(7);

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
    insert();
}

Recorridos::~Recorridos()
{
    delete ui;
}

void Recorridos::on_Dijkstra_clicked()
{
    dt = new DijkstTable();
    dt->show();
    dt->setGrafo(grafo);
}

void Recorridos::insert()
{

    QGraphicsScene *scene = new QGraphicsScene();
    scene->setParent(ui->graphicsView);
    QGraphicsSimpleTextItem *text = new QGraphicsSimpleTextItem();
    QString t = printGrafo();
    text->setText(t);
    scene->addItem(text);
    ui->graphicsView->setScene(scene);
}

QString Recorridos::printGrafo()
{
    cout<<"Empieza funcion"<<endl;
    Nodo * temp = grafo->actual;
    QString texto="";
        while(temp){
            texto +=QString("Actual: %1\n").arg(temp->valor);
            texto+=temp->imprimirArcos();
            texto+="\n";
            temp = temp->Ady;
        }
        return texto;
}

void Recorridos::on_Floyd_clicked()
{
    FLoydGraph *f= new FLoydGraph();
    f->show();
    f->setGrafo(grafo);
}

void Recorridos::on_Kruskal_clicked()
{
    KruskalGraph *k = new KruskalGraph();
    k->setGrafo(grafo);
    k->show();

}

void Recorridos::on_Prim_clicked()
{
    PrimGraph * p= new PrimGraph();
    p->setGrafo(grafo);
    p->show();
}
