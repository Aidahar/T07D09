// Copyright 2022 <Trudieis>
#include <stdio.h>
#include <stdlib.h>
#define NMAX 10

int input(int *a);
void sort(int *data);
void swap(int *a, int *b);
void printArray(int *data);

int main(void) {
    int n;
    int *data;
    if (scanf("%d", &n) != 1) {
        printf("n/a");
    } else { 
        data = (int*)calloc(n, sizeof(int));
        if (NULL == data) {
            printf("n/a");
        } else {
            if (input(data) == 0) {
                sort(data);
                printArray(data);
            } else {
                printf("n/a");
            }
        }
        free(data);
    }
    return 0;
}

int input(int *a) {
    int i = 0;
    for (int *p = a; p - a < NMAX; p++) {
        if (scanf("%d", p) != 1) {
            i++;
            break;
        }
    }
    if (getchar() != '\n') {
        i++;
    }
    return i;
}

void sort(int *data) {
    int isSorted = 0;
    for (int j = 0; j < NMAX; ++j) {
        isSorted = 1;
        for (int i = 1; i < NMAX - j; ++i) {
            if (data[i] < data[i - 1]) {
                isSorted = 0;
                swap(&data[i], &data[i - 1]);
            }
        }
        if (isSorted) {
            return;
        }
    }
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void printArray(int *a) {
  for (int i = 0; i < NMAX; i++) {
    (i == NMAX - 1) ? printf("%d\n", a[i]) : printf("%d ", a[i]);
  }
}
