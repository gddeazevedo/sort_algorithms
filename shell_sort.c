#include <stdio.h>


void shell_sort(int* array, int length);

void main() {
    int vetor[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    int length = 10;
    shell_sort(vetor, length);

    for (int i = 0; i < length; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\n");
}


void shell_sort(int* array, int length) {
    int jump = length / 2;

    while (jump > 0) {
        for (int i = jump; i < length; i++) {
            int j = i;
            int current = array[i];

            while (j >= jump && array[j - jump] > current) {
                array[j] = array[j - jump];
                j -= jump;
            }

            array[j] = current;
        }

        jump /= 2;
    }
}