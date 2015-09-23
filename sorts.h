#ifndef SORTS_H
#define SORTS_H


class Sorts
{
public:
    int *array;
    void mergeSort(int *array, int size, int menor, int mayor);
    void merge(int *array,int size, int menor, int mitad, int mayor);


    Sorts();
};

#endif // SORTS_H
