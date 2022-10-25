#include <stdio.h>


void merge_sort(int* array, int left, int right);
void merge(int* array, int left1, int right1, int left2, int right2);

void main() {
    int vetor[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    int length = 10;
    merge_sort(vetor, 0, length - 1);

    for (int i = 0; i < length; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\n");
}


void merge_sort(int* array, int left, int right) {
    if (left < right) {
        int middle = (left + right) / 2;
        merge_sort(array, left, middle);
        merge_sort(array, middle + 1, right);
        merge(array, left, middle, middle + 1, right);
    }
}

void merge(int* array, int left1, int right1, int left2, int right2) {
    int aux_array[right2 - left1 + 1];
    int i = left1;
    int j = left2;
    int k = 0;

    while (i <= right1 && j <= right2) {
        if (array[i] < array[j]) {
            aux_array[k] = array[i];
            i++;
        } else {
            aux_array[k] = array[j];
            j++;
        }
        k++;
    }

    while (i <= right1) {
        aux_array[k] = array[i];
        i++;
        k++;
    }

    while (j <= right2) {
        aux_array[k] = array[j];
        j++;
        k++;
    }

    for (i = left1, j = 0; i <= right2; i++, j++) {
        array[i] = aux_array[j];
    }
}