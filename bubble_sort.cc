#include "bubble_sort.h"

void bubble_sort(int *array, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            if (array[i] > array[j]) {
                int temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }
}
