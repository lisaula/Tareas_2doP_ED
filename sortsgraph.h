#ifndef SORTSGRAPH_H
#define SORTSGRAPH_H

#include <QWidget>
#include <QMessageBox>
#include "sorts.h"
#include<iostream>
using namespace std;
namespace Ui {
class SortsGraph;
}

class SortsGraph : public QWidget
{
    Q_OBJECT

public:
    explicit SortsGraph(QWidget *parent = 0);
    ~SortsGraph();

private slots:
    void on_Merge_clicked();

    void on_Introduce_clicked();

    void on_init_clicked();

private:
    Sorts *sort = new Sorts();
    void print();
    int *array, cont, s;
    Ui::SortsGraph *ui;
};

#endif // SORTSGRAPH_H
