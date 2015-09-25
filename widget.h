#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"sortsgraph.h"
#include"recorridos.h"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_Tarea1_clicked();

    void on_pushButton_clicked();

private:
    SortsGraph *sg;
    Ui::Widget *ui;
};

#endif // WIDGET_H
