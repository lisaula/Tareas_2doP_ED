#ifndef KRUSKALGRAPH_H
#define KRUSKALGRAPH_H
#include "kruskal.h"
#include <QWidget>

namespace Ui {
class KruskalGraph;
}

class KruskalGraph : public QWidget
{
    Q_OBJECT

public:
    void setGrafo(Grafo *g);
    explicit KruskalGraph(QWidget *parent = 0);
    ~KruskalGraph();

private:
    void insertar();
    Grafo * grafo;
    Kruskal * k;
    Ui::KruskalGraph *ui;
};

#endif // KRUSKALGRAPH_H
