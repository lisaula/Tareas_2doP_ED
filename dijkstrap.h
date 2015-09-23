#ifndef DIJKSTRAP_H
#define DIJKSTRAP_H
#include "grafo.h"
#include "arista.h"
#include <QWidget>
#include <QString>
namespace Ui {
class Dijkstrap;
}

class Dijkstrap : public QWidget
{
    Q_OBJECT

public:
    vector<Nodo*>vertices;
    bool *visitado;
    int *distancia;
    QString *path;
    multimap<int,Nodo*>adyacentes;
    explicit Dijkstrap(QWidget *parent = 0);
    ~Dijkstrap();

private slots:
    void on_Analizar_clicked();

    void on_CrearNodo_clicked();

    void on_CrearArista_clicked();

    void on_pushButton_clicked();

    void on_probar_clicked();

private:
    void setTabla(int nodos, Nodo *origen);
    void Analisis(Nodo *origen);
    void setcambio(Nodo* actual, Nodo* ady, int peso);\
    bool checkVisited();
    int getMyPos(Nodo *n);
    multimap<int, Nodo *> setAdyacentes(Nodo *o, vector<Arista*> aristas);
    int cont;
    Grafo *grafo = new Grafo();
    Ui::Dijkstrap *ui;
};

#endif // DIJKSTRAP_H
