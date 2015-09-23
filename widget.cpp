#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("Estructura de Datos");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_Tarea1_clicked()
{
    Dijkstrap *d = new Dijkstrap();
    d->setVisible(true);
}

void Widget::on_pushButton_clicked()
{
    sg = new SortsGraph();
    sg->setVisible(true);
}
