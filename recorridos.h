#ifndef RECORRIDOS_H
#define RECORRIDOS_H
#include"grafo.h"
#include"dijksttable.h"
#include"floyd.h"
#include"floydgraph.h"
#include <QWidget>
#include <QString>
#include <QGraphicsScene>
#include <QGraphicsSimpleTextItem>
namespace Ui {
class Recorridos;
}

class Recorridos : public QWidget
{
    Q_OBJECT

public:
    explicit Recorridos(QWidget *parent = 0);
    ~Recorridos();

private slots:
    void on_Dijkstra_clicked();

    void on_Floyd_clicked();

private:
    void insert();
    QString printGrafo();
    Grafo *grafo;
    DijkstTable *dt;
    Ui::Recorridos *ui;
};

#endif // RECORRIDOS_H
