#ifndef PRIMGRAPH_H
#define PRIMGRAPH_H
#include"prim.h"
#include <QWidget>
#include<QString>
namespace Ui {
class PrimGraph;
}

class PrimGraph : public QWidget
{
    Q_OBJECT

public:
    void setGrafo(Grafo *g);
    explicit PrimGraph(QWidget *parent = 0);
    ~PrimGraph();

private slots:
    void on_origen_clicked();

private:
    int cont;
    void insertar();
    Nodo* actual;
    Grafo * grafo;
    Prim *prim;
    Ui::PrimGraph *ui;
    enum Columna{
        VERTICE, VISITADO,COSTO, CAMINO
    };
};

#endif // PRIMGRAPH_H
