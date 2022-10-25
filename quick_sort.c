#include <stdio.h>


void qsort(int *array, int left, int right);
int partition(int* array, int left, int right);
void swap(int* array, int index1, int index2);

void main() {
    int vetor[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    int length = 10;
    qsort(vetor, 0, length - 1);

    for (int i = 0; i < length; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\n");
}


void qsort(int *array, int left, int right) {
    if (left < right) {
        int pivot_index = partition(array, left, right);
        qsort(array, left, pivot_index);
        qsort(array, pivot_index + 1, right);
    }
}

int partition(int* array, int left, int right) {
    int pivot = array[(left + right) / 2];

    while (1) {
        while (array[left] < pivot) left++;
        while (array[right] > pivot) right--;

        if (left < right) {
            swap(array, left, right);
            left++;
            right--;
        } else {
            return right;
        }
    }
}

void swap(int* array, int index1, int index2) {
    int tmp = array[index1];
    array[index1] = array[index2];
    array[index2] = tmp;
}