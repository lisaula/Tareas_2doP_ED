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
    cout<<"Size "<<s<<endl;
    int arr[s];
    for(int i =0;i<s;i++){
        arr[i]=array[i];
    }

    int arr_size = sizeof(arr)/sizeof(arr[0]);

    printf("MERGESORT \n");
    printArray(arr, arr_size);

    sort->mergeSort(arr, 0, arr_size - 1);

    printf("--------------------\n");
    printArray(arr, arr_size);
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

void SortsGraph::on_quick_clicked()
{
    int arr[s];
    for(int i =0;i<s;i++){
        arr[i]=array[i];
    }
    cout<<"Metodo quickSort"<<endl;
    printArray(arr,s);
    cout<<"Lista ya ordenada"<<endl;
    sort->quicksort(arr,0,s-1);
    printArray(arr,s);
    cout << endl;
}

void SortsGraph::on_Heap_clicked()
{
    int arr[s];
    for(int i =0;i<s;i++){
        arr[i]=array[i];
    }
    const size_t sz = sizeof(arr)/sizeof(arr[0]);
    cout<<"HEAPSORT"<<endl;
    printArray(arr, sz);
    cout << "----------------------------------" << endl;
    sort->heapsort(arr, sz);
    printArray(arr, sz);
    cout << endl;
}

void SortsGraph::on_Bin_clicked()
{
    int arr[s];
    for(int i =0;i<s;i++){
        arr[i]=array[i];
    }
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"BINSORT"<<endl;
    printArray(arr,s);
    sort->binsort(arr,n);
    cout << "----------------------------------" << endl;
    printArray(arr,s);
}
