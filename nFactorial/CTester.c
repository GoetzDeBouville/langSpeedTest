#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void arrayBuild(int *arr, int num) {
    for(int i = 0; i < num; ++i) {
        arr[i] = rand() % 1000;
    }
}

void rearangeArr(int *arr, int start, int length) {
    for (int i = start; i < length; ++i) {
        int temp = arr[start];
        arr[start] = arr[i];
        arr[i] = temp;

        rearangeArr(arr, start + 1, length);

        temp = arr[start];
        arr[start] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int array[11];
    arrayBuild(array, 11);

    clock_t start, end;
    start = clock();

    rearangeArr(array, 0, 11);

    end = clock();
    double time_taken = ((double) end - start) / CLOCKS_PER_SEC;

    printf("%.5f sec\n", time_taken);

    return 0;
}
