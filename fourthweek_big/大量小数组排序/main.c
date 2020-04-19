#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include "Sort.h"

void adddata(int a[10000])
{
  srand((int)time(0));
  for (int i = 0; i < 10000; i++)
  {
    a[i] = rand() % 500000 + 1;
  }
}
int main()
{
  int a[10000];
  long start_time = 0, end_time = 0, spend_time = 0;

  for (int i = 0; i < 100; i++)
  {
    adddata(a);
    start_time = clock();
    BubbleSort(a, 10000);
    end_time = clock();
    spend_time += (end_time - start_time);
  }
  printf("\nBubbleSort'time:%ldms", spend_time);
  spend_time = 0;

  for (int i = 0; i < 100; i++)
  {
    adddata(a);
    start_time = clock();
    SelectionSort(a, 10000);
    end_time = clock();
    spend_time += (end_time - start_time);
  }
  printf("\nSelectionSort'time:%ldms", spend_time);
  spend_time = 0;

  for (int i = 0; i < 100; i++)
  {
    adddata(a);
    start_time = clock();
    InsectionSort(a, 10000);
    end_time = clock();
    spend_time += (end_time - start_time);
  }
  printf("\nInsectionSort'time:%ldms", spend_time);
  spend_time = 0;

  int *tmp2 = (int *)malloc(10000 * sizeof(int));
  for (int i = 0; i < 100; i++)
  {
    adddata(a);
    start_time = clock();
    MergeSort(a, 0, 9999, tmp2);
    end_time = clock();
    spend_time += (end_time - start_time);
  }
  printf("\nMergeSort'time:%ldms", spend_time);
  spend_time = 0;
  free(tmp2);

  for (int i = 0; i < 100; i++)
  {
    adddata(a);
    start_time = clock();
    QuickSort(a, 0, 9999);
    end_time = clock();
    spend_time += (end_time - start_time);
  }
  printf("\nQuickSort'time:%ldms", spend_time);
  spend_time = 0;

  for (int i = 0; i < 100; i++)
  {
    adddata(a);
    start_time = clock();
    CountSort(a, 10000);
    end_time = clock();
    spend_time += (end_time - start_time);
  }
  printf("\nCountSort'time:%ldms", spend_time);
  spend_time = 0;

  for (int i = 0; i < 100; i++)
  {
    adddata(a);
    start_time = clock();
    RadixSort(a, 10000);
    end_time = clock();
    spend_time += (end_time - start_time);
  }
  printf("\nRadixSort'time:%ldms", spend_time);
  spend_time = 0;

  return 0;
}
