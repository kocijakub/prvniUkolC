#include <stdio.h>

void bubbleSort(int *list, int size) {
    bool sorted = false;

    while (!sorted) {
        sorted = true;
        for (int i = 1; i < size; i++) {
            int *num1 = &list[i - 1];
            int *num2 = &list[i];

            if (*num1 > *num2) {
                int temp = *num1;
                *num1 = *num2;
                *num2 = temp;

                sorted = false;
            }
        }
    }
}

void selectionSort(int *list, int size) {
    for (int index = 0; index < size - 1; index++) { // Iterate until the second-to-last element
        int minIndex = index; // Assume the current index has the smallest value
        for (int i = index + 1; i < size; i++) { // Look for the smallest value in the unsorted portion
            if (list[i] < list[minIndex]) {
                minIndex = i; // Update minIndex if a smaller value is found
            }
        }
        if (index != minIndex) { // Swap only if a new minimum was found
            int temp = list[index];
            list[index] = list[minIndex];
            list[minIndex] = temp;
        }
    }
}


int main() {
    int list[] = {5, 3, 8, 6, 2};
    int size = sizeof(list) / sizeof(list[0]);
    //bubbleSort(list, size);
    selectionSort(list, size);
    printf("sorted list: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    return 0;
}
