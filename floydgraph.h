#ifndef FLOYDGRAPH_H
#define FLOYDGRAPH_H

#include <QWidget>

namespace Ui {
class FLoydGraph;
}

class FLoydGraph : public QWidget
{
    Q_OBJECT

public:
    explicit FLoydGraph(QWidget *parent = 0);
    ~FLoydGraph();

private:
    Ui::FLoydGraph *ui;
};

#endif // FLOYDGRAPH_H
