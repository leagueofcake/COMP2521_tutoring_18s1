// q3 - various sorting algorithms
void selectionSort (int a[], int lo, int hi) {
    int i, j, min;
    for (i = lo; i < hi; i++) {
        min = i;
        for (j = i+1; j <= hi; j++) {
            if (less(a[j],a[min])) min = j;
        }
        swap(a,i,min);
    }
}


void bubbleSort(int a[], int lo, int hi) {
    int i, j, nswaps;
    for (i = lo; i < hi; i++) {
        nswaps = 0;
        for (j = hi; j > i; j--) {
            if (less(a[j], a[j-1])) {
                swap(a,j,j-1);
                nswaps++;
            }
        }
        if (nswaps == 0) break;
    }
}


void quickSort(int a[], int lo, int hi) {
    int i; // index of pivot
    if (lo >= hi) return;
    i = partition(a, lo, hi);
    quickSort(a, lo, i-1);
    quickSort(a, i+1, hi);
}
