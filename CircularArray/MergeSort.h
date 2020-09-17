//
// Created by AIO on 17/09/2020.
//

#ifndef CIRCULARARRAY_MERGESORT_H
#define CIRCULARARRAY_MERGESORT_H

void merge(int *&arr, int l, int m, int r) {
    int i, j, k, nl, nr;
    nl = m - l + 1;
    nr = r - m;
    int larr[nl], rarr[nr];
    for (i = 0; i < nl; i++)
        larr[i] = arr[l + i];
    for (j = 0; j < nr; j++)
        rarr[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < nl && j < nr) {
        if (larr[i] <= rarr[j]) {
            arr[k] = larr[i];
            i++;
        }
        else {
            arr[k] = rarr[j];
            j++;
        }
        k++;
    }
    while (i < nl) {
        arr[k] = larr[i];
        i++;
        k++;
    }
    while (j < nr){
        arr[k] = rarr[j];
        j++;
        k++;
    }
}
void mergeSort(int *&arr, int l, int r){
    int m;
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

#endif //CIRCULARARRAY_MERGESORT_H
