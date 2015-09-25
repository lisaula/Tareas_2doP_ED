#include "floydgraph.h"
#include "ui_floydgraph.h"

FLoydGraph::FLoydGraph(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FLoydGraph)
{
    ui->setupUi(this);
}

FLoydGraph::~FLoydGraph()
{
    delete ui;
}
