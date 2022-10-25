#include <stdio.h>


void insertion_sort(int* array, int lenght);

void main() {
    int vetor[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    int length = 10;
    insertion_sort(vetor, length);

    for (int i = 0; i < length; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\n");
}


void insertion_sort(int* array, int length) {
    for (int i = 1; i < length; i++) {
        int j = i;
        int current = array[i];

        while (j > 0 && array[j - 1] > current) {
            array[j] = array[j - 1];
            j -= 1;
        }

        array[j] = current;
    }
}