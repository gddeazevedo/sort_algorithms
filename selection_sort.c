#include <stdio.h>


void selection_sort(int* array, int length);
void swap(int* array, int index1, int index2);

void main() {
    int vetor[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    int length = 10;
    selection_sort(vetor, length);

    for (int i = 0; i < length; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\n");
}


void swap(int* array, int index1, int index2) {
    int tmp = array[index1];
    array[index1] = array[index2];
    array[index2] = tmp;
}

void selection_sort(int* array, int length) {
    for (int i = 0; i < length; i++) {
        int smallest_element_index = i;

        for (int j = i + 1; j < length; j++) {
            if (array[j] < array[smallest_element_index]) {
                smallest_element_index = j;
            }
        }
   
        swap(array, i, smallest_element_index);
    }
}
