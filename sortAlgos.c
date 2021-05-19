#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define NUM 50000

void menu();
void insertion_sort(int list[], int n);
void selection(int a[], int n);
void generateArray(int a[], int n);
void measureInsertion(int a[], int n);
void measureSelection(int a[], int n);
void swap(int *xp, int *yp);
void bubbleSort(int a[], int n);
void measureBubble(int a[], int n);
void heapsort(int list[], int n);
void adjust(int list[], int root, int n);
void measureHeap(int a[], int n);
int main()
{
    int choice = 0;
    int *arr = (int *)malloc(NUM * sizeof(int));
    while (1)
    {
        menu();
        printf("Your choice is: ");
        scanf(" %d", &choice);
        if (choice == 1)
        {
            generateArray(arr, NUM);
        }
        else if (choice == 2)
        {
            measureInsertion(arr, NUM);
        }
        else if (choice == 3)
        {
            measureSelection(arr, NUM);
        }
        else if (choice == 4)
        {
            measureBubble(arr, NUM);
        }
        else if(choice ==5){
            measureHeap(arr, NUM);
        }
        else{
            break;
        }
    }

    free(arr);
    return 0;
}

void menu()
{
    printf("Sorting Algorithms Comparison\n");
    printf("1. Create dataset (Generate integers)\n");
    printf("2. Insertion Sort\n");
    printf("3. Selection Sort\n");
    printf("4. Bubble Sort\n");
    printf("5. Heap Sort\n");
}

void generateArray(int a[], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        a[i] = rand();
    }
}
void insertion_sort(int list[], int n)
{
    int i, j;
    int next;
    for (i = 1; i < n; i++)
    {
        next = list[i];
        for (j = i - 1; j >= 0 && next < list[j]; j--)
            list[j + 1] = list[j];
        list[j + 1] = next;
    }
}

void selection(int a[], int n)
{
    int i, j, min, tmp;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j <= n - 1; j++)
            if (a[j] < a[min])
                min = j;
        tmp = a[i];
        a[i] = a[min];
        a[min] = tmp;
    }
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

void measureBubble(int a[], int n)
{
    time_t t1, t2;
    clock_t tstart, tfinish;
    time(&t1);
    tstart = clock();
    bubbleSort(a, n);
    tfinish = clock();
    time(&t2);
    int durationinseconds = (int)t2 - (int)t1;
    float tcomp;
    tcomp = (float)(tfinish - tstart) / CLOCKS_PER_SEC;
    printf("Time to sort with bubble sort is: %d seconds and %f clocks per sec\n", durationinseconds, tcomp);
}

void measureSelection(int a[], int n)
{
    time_t t1, t2;
    clock_t tstart, tfinish;
    time(&t1);
    tstart = clock();
    selection(a, n);
    tfinish = clock();
    time(&t2);
    int durationinseconds = (int)t2 - (int)t1;
    float tcomp;
    tcomp = (float)(tfinish - tstart) / CLOCKS_PER_SEC;
    printf("Time to sort with selection sort is: %d seconds and %f clocks per sec\n", durationinseconds, tcomp);
}

void measureInsertion(int a[], int n)
{
    time_t t1, t2;
    clock_t tstart, tfinish;
    time(&t1);
    tstart = clock();
    insertion_sort(a, n);
    tfinish = clock();
    time(&t2);
    int durationinseconds = (int)t2 - (int)t1;
    float tcomp;
    tcomp = (float)(tfinish - tstart) / CLOCKS_PER_SEC;
    printf("Time to sort with insertion sort is: %d seconds and %f clocks per sec\n", durationinseconds, tcomp);
}

void adjust(int list[], int root, int n)
{
    int child, rootkey;
    int temp;
    temp = list[root];
    rootkey = list[root];
    child = 2 * root;
    while (child <= n)
    {
        if ((child < n) &&
            (list[child] < list[child + 1]))
            child++;
        if (rootkey > list[child])
            break;
        else
        {
            swap(&list[child / 2], &list[child]);
            child *= 2;
        }
    }
}

void heapsort(int list[], int n)
{
    //ascending order (max heap)
    int i, j;
    int temp;
    for (i = n / 2; i > 0; i--)
        adjust(list, i, n);
    for (i = n - 1; i > 0; i--)
    {
        swap(&list[1], &list[i + 1]);
        swap(&list[i+1],&temp);
        adjust(list, 1, i);
    }
}

void measureHeap(int a[], int n)
{
    time_t t1, t2;
    clock_t tstart, tfinish;
    time(&t1);
    tstart = clock();
    heapsort(a,n);
    tfinish = clock();
    time(&t2);
    int durationinseconds = (int)t2 - (int)t1;
    float tcomp;
    tcomp = (float)(tfinish - tstart) / CLOCKS_PER_SEC;
    printf("Time to sort with heap sort is: %d seconds and %f clocks per sec\n", durationinseconds, tcomp);
}
