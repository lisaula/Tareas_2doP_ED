#include "sorts.h"

void Sorts::mergeSort(int *array, int size, int menor, int mayor)
{
    if(menor <mayor){
        int mitad = (menor+mayor)/2;
        mergeSort(array,size,menor, mitad);
        mergeSort(array,size,mitad+1,mayor);
        merge(array,size,menor,mitad,mayor);
    }
}

void Sorts::merge(int *array, int size, int menor, int mitad, int mayor)
{
    int temp[size];
    for(int x = menor; x<mayor;x++){
        temp[x]=array[x];
    }
    int i=menor;
    int j=mitad+1;
    int k=mayor;

    while(i<=mitad && j<=mayor){
        if(temp[i]<=temp[j]){
            array[k]=temp[i];
            ++i;
        }else{
            array[k]=temp[j];
            j++;
        }
        k++;
    }
    while(i<=mitad){
        array[k]=temp[i];
        ++k;
        ++i;
    }
}

Sorts::Sorts()
{

}

