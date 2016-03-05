#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 500000

#define SIZE_MIN   5000
#define SIZE_STEP  5000
#define SIZE_MAX  500000

#define CICLES 10

#define xorswap(a, b) ((a)^=(b),(b)^=(a),(a)^=(b))

int nswap = 0;
int ncompare = 0;

int * vector_create(size_t size) {
    int *vector = NULL;
    int i = 0;

    if ((vector = malloc(sizeof(int) * size)) != NULL) {
        for(i = 0; i < size; i++)
            vector[i] = rand() % MAX;
    }

    return vector;
}

void vector_destroy(int ** vector) {
    if (vector != NULL) {
        free(*vector);
        *vector = NULL;
    }
}

struct timespec time_get(void) {
    struct timespec ts;

    clock_gettime(CLOCK_REALTIME, &ts);

    return ts;
}

double time_diff(struct timespec start, struct timespec end) {
    double diff = 0;

    diff += end.tv_sec - start.tv_sec - 1;
    diff += (1000000000 - (double)start.tv_nsec + (double)end.tv_nsec) / 1000000000;

    return diff;
}

void sort_bubble(int * vector, size_t size) {
    int flag = 1, i = 0;

    nswap = 0;
    ncompare = 0;

    while (flag) {
        flag = 0;

        for (i = 0; i < size - 1; i++) {
            ncompare++;
            if (vector[i] > vector[i + 1]) {
                nswap++;
                xorswap(vector[i], vector[i + 1]);
                flag = 1;
            }
        }
    }
}

void sort_insertion(int * vector, size_t size) {
    int i = 0;

    nswap = 0;
    ncompare = 0;

    for (i = 1; i < size; i++) {
        ncompare++;
        while (i != 0 && vector[i] < vector[i - 1]) {
            nswap++;
            xorswap(vector[i], vector[i - 1]);
            i--;
        }
    }
}

void sort_selection(int * vector, size_t size) {
    int i = 0, j = 0, min = 0;

    nswap = 0;
    ncompare = 0;

    for (i = 0; i < size - 1; i++) {
        min = i;

        for (j = i + 1; j < size; j++) {
            ncompare++;
            if (vector[j] < vector[min]) {
                min = j;
            }
        }

        if (i != min) {
            nswap++;
            xorswap(vector[i], vector[min]);
        }
    }
}

void quick_sort(int * vector, int left, int right) {
    int i, j, x, y;
     
    i = left;
    j = right;
    x = vector[(left + right) / 2];
     
    while(i <= j) {
        while(vector[i] < x && i < right) {
            i++;
        }
        while(vector[j] > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = vector[i];
            vector[i] = vector[j];
            vector[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > left) {
        quick_sort(vector, left, j);
    }
    if(i < right) {
        quick_sort(vector, i, right);
    }
}

int main(void) {
    int * vector, size, cycle, cycles;
    struct timespec start, end;
    double sum;

    srand(time(NULL));

    for (size = SIZE_MIN; size <= SIZE_MAX; size += SIZE_STEP) {
        
        // BUBBLE SORT
        printf("\nBUBBLE SORT - %d cycles with %d elements\n", CICLES, size);

        for (cycle = 0, cycles = 0, sum = 0.0; cycle < CICLES; cycle++) {
            printf("%do cycle sorting of a vector with %d elements with the booble sort algorithm : ", cycle, size);

            if ((vector = vector_create(size)) != NULL) {

                start = time_get();
                sort_bubble(vector, size);
                end = time_get();
                vector_destroy(&vector);

                cycles++;
                sum += time_diff(start, end);

                printf("%lf seconds (num. swaps = %d, num. compares = %d)\n", time_diff(start, end), nswap, ncompare);
            } else {
                printf(" error allocating %d bytes of memory\n", (int) (size * sizeof(int)));
            }
        }

        printf("The sorting of a vector with %d elements took in average %lf seconds to sort with a booble sort algorithm\n", size, sum / cycles);

        /*
        // INSERTION SORT
        printf("\nINSERTION SORT - %d cycles with %d elements\n", CICLES, size);

        for (cycle = 0, cycles = 0, sum = 0.0; cycle < CICLES; cycle++) {
            printf("%do cycle sorting of a vector with %d elements with the insertion sort algorithm : ", cycle, size);

            if ((vector = vector_create(size)) != NULL) {

                start = time_get();
                sort_insertion(vector, size);
                end = time_get();
                vector_destroy(&vector);

                cycles++;
                sum += time_diff(start, end);

                printf("%lf seconds (num. swaps = %d, num. compares = %d)\n", time_diff(start, end), nswap, ncompare);
            } else {
                printf(" error allocating %d bytes of memory\n", (int) (size * sizeof(int)));
            }
        }

        printf("The sorting of a vector with %d elements took in average %lf seconds to sort with a insertion sort algorithm\n", size, sum / cycles);
        */

        // QUICK SORT
        printf("\nQUICK SORT - %d cycles with %d elements\n", CICLES, size);

        for (cycle = 0, cycles = 0, sum = 0.0; cycle < CICLES; cycle++){
            printf("%do cycle sorting of a vector with %d elements with the insertion sort algorithm : ", cycle, size);

            if ((vector = vector_create(size)) != NULL){

                start = time_get();
                quick_sort(vector,size,size);
                end = time_get();
                vector_destroy(&vector);

                cycles++;
                sum += time_diff(start, end);

            printf("%lf seconds (num. swaps = %d, num. compares = %d)\n", time_diff(start, end), nswap, ncompare);
            }
            else{
                printf(" error allocating %d bytes of memory\n", (int) (size * sizeof(int)));
            }
        }
        printf("The sorting of a vector with %d elements took in average %lf seconds to sort with a insertion sort algorithm\n", size, sum / cycles);
        
        // SELECTION SORT
        printf("\nSELECTION SORT - %d cycles with %d elements\n", CICLES, size);

        for (cycle = 0, cycles = 0, sum = 0.0; cycle < CICLES; cycle++) {
            printf("%do cycle sorting of a vector with %d elements with the selection sort algorithm : ", cycle, size);

            if ((vector = vector_create(size)) != NULL) {

                start = time_get();
                sort_selection(vector, size);
                end = time_get();
                vector_destroy(&vector);

                cycles++;
                sum += time_diff(start, end);

                printf("%lf seconds (num. swaps = %d, num. compares = %d)\n", time_diff(start, end), nswap, ncompare);
            } else {
                printf(" error allocating %d bytes of memory\n", (int) (size * sizeof(int)));
            }
        }

        printf("The sorting of a vector with %d elements took in average %lf seconds to sort with a selection sort algorithm\n", size, sum / cycles);
    }

    return 0;
}     