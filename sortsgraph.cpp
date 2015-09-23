#include "sortsgraph.h"
#include "ui_sortsgraph.h"

SortsGraph::SortsGraph(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SortsGraph)
{
    ui->setupUi(this);
    cont =0;
    s=0;
    setWindowTitle("Sorts");
}

SortsGraph::~SortsGraph()
{
    delete ui;
}

void SortsGraph::on_Merge_clicked()
{
    sort->mergeSort(array,s,0,s-1);
    print();
}

void SortsGraph::on_Introduce_clicked()
{
    int v= ui->values->value();
    if(cont<s){
        array[cont]=v;
        print();
        cont++;
    }else{
        QMessageBox::warning(this,"Error","Index out of bound (Exception)");
    }

}


void SortsGraph::on_init_clicked()
{
    s = ui->size->value();
    array = new int[s];
    for(int i =0;i<s;i++){
        array[i]=0;
    }
    cout<<"arreglo inicializado"<<endl;
}

void SortsGraph::print()
{
    for(int i =0;i<s;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}
