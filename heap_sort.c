#include <stdio.h>

#define ROOT 0

void heap_sort(int* array, int length);
void heap_up(int* array, int length);
void heap_down(int* array, int init_index, int last_index);
int get_parent(int child);
int get_left_child(int parent);
int get_right_child(int parent);
void swap(int* array, int index1, int index2);


void main() {
    int vetor[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    int length = 10;
    
    heap_sort(vetor, length);

    for (int i = 0; i < length; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\n");
}


void heap_sort(int* array, int length) {
    // heap size is the quantity of elements in the unordered set
    int heap_size = length - 1;
    
    heap_up(array, length);

    for (int i = length - 1; i > 0; i--) {
        swap(array, ROOT, i);
        heap_size--;
        heap_down(array, ROOT, heap_size);
    }
}

void heap_up(int* array, int length) {
    for (int i = 1; i < length; i++) {
        int child = i;
        int parent = get_parent(child);

        while (parent >= ROOT && array[child] > array[parent]) {
            swap(array, child, parent);
            child = parent;
            parent = get_parent(child);
        }
    }
}

void heap_down(int* array, int init_index, int last_index) {
    int parent = init_index;

    while (get_left_child(parent) <= last_index) {
        int left = get_left_child(parent);
        int right = get_right_child(parent);
        int child = left;

        if (right <= last_index && array[right] > array[left]) {
            child = right;
        }

        if (array[child] > array[parent]) {
            swap(array, child, parent);
            parent = child;
        } else {
            break;
        }
    }
}

int get_parent(int child) {
    return (child - 1) / 2;
}

int get_left_child(int parent) {
    return 2 * parent + 1;
}

int get_right_child(int parent) {
    return 2 * parent + 2;
}

void swap(int* array, int index1, int index2) {
    int tmp = array[index1];
    array[index1] = array[index2];
    array[index2] = tmp;
}