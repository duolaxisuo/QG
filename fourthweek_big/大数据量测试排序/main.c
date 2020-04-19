#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include "Sort.h"
/*****************************************************/

void addadta(int a[], int length)
{
  srand((int)time(0));
  for (int i = 0; i < length; i++)
  {
    a[i] = rand() % 500000 + 1;
  }
}
int main()
{
  long start_time = 0, end_time = 0;
  int cesi1[10000], cesi2[50000], cesi3[200000];
  printf("In the case of data 10000:");
  addadta(cesi1, 10000);
  start_time = clock();
  BubbleSort(cesi1, 10000); //冒泡排序
  end_time = clock();
  printf("\nBubbleSort'time:%ldms", (long)(end_time - start_time));

  addadta(cesi1, 10000);
  start_time = clock();
  SelectionSort(cesi1, 10000); //选择排序
  end_time = clock();
  printf("\nSelectionSort'time:%ldms", (long)(end_time - start_time));

  addadta(cesi1, 10000);
  start_time = clock();
  InsectionSort(cesi1, 10000); //插入排序
  end_time = clock();
  printf("\nInsectionSor'time:%ldms", (long)(end_time - start_time));

  int *tmp7 = (int *)malloc(10000 * sizeof(int));
  addadta(cesi1, 10000);
  start_time = clock();
  MergeSort(cesi1, 0, 9999, tmp7);
  end_time = clock();
  free(tmp7);
  printf("\nMergeSort'time:%ldms", (long)(end_time - start_time));

  addadta(cesi1, 10000);
  start_time = clock();
  QuickSort(cesi1, 0, 9999); //快速排序
  end_time = clock();
  printf("\nQuickSort'time:%ldms", (long)(end_time - start_time));

  addadta(cesi1, 10000);
  start_time = clock();
  CountSort(cesi1, 10000); //计数排序
  end_time = clock();
  printf("\nCountSort'time:%ldms", (long)(end_time - start_time));

  addadta(cesi1, 10000);
  start_time = clock();
  RadixSort(cesi1, 10000); //基数排序
  end_time = clock();
  printf("\nRadixSort'time:%ldms", (long)(end_time - start_time));

  free(cesi1);

  printf("\n*******************************************************\n");
  printf("In the case of data 50000:");
  addadta(cesi2, 50000);
  start_time = clock();
  BubbleSort(cesi2, 50000); //冒泡排序
  end_time = clock();
  printf("\nBubbleSort'time:%ldms", (long)(end_time - start_time));

  addadta(cesi2, 50000);
  start_time = clock();
  SelectionSort(cesi2, 50000); //选择排序
  end_time = clock();
  printf("\nSelectionSort'time:%ldms", (long)(end_time - start_time));

  addadta(cesi2, 50000);
  start_time = clock();
  InsectionSort(cesi2, 50000); //插入排序
  end_time = clock();
  printf("\nInsectionSor'time:%ldms", (long)(end_time - start_time));

  int *temp5 = (int *)malloc(50000 * sizeof(int));
  addadta(cesi2, 50000);
  start_time = clock();
  MergeSort(cesi2, 0, 49999, temp5);
  end_time = clock();
  free(temp5);
  printf("\nMergeSort'time:%ldms", (long)(end_time - start_time));

  addadta(cesi2, 50000);
  start_time = clock();
  QuickSort(cesi2, 0, 49999); //快速排序
  end_time = clock();
  printf("\nQuickSort'time:%ldms", (long)(end_time - start_time));

  addadta(cesi2, 50000);
  start_time = clock();
  CountSort(cesi2, 50000); //计数排序
  end_time = clock();
  printf("\nCountSort'time:%ldms", (long)(end_time - start_time));

  addadta(cesi2, 50000);
  start_time = clock();
  RadixSort(cesi2, 50000); //基数排序
  end_time = clock();
  printf("\nRadixSort'time:%ldms", (long)(end_time - start_time));

  free(cesi2);
  printf("\n*******************************************************\n");
  printf("In the case of data 200000:");
  addadta(cesi3, 200000);
  start_time = clock();
  BubbleSort(cesi3, 200000); //冒泡排序
  end_time = clock();
  printf("\nBubbleSort'time:%ldms", (long)(end_time - start_time));

  addadta(cesi3, 200000);
  start_time = clock();
  SelectionSort(cesi3, 200000); //选择排序
  end_time = clock();
  printf("\nSelectionSort'time:%ldms", (long)(end_time - start_time));

  addadta(cesi3, 200000);
  start_time = clock();
  InsectionSort(cesi3, 200000); //插入排序
  end_time = clock();
  printf("\nInsectionSor'time:%ldms", (long)(end_time - start_time));

  int *tmp2 = (int *)malloc(200000 * sizeof(int));
  addadta(cesi3, 200000);
  start_time = clock();
  MergeSort(cesi3, 0, 199999, tmp2);
  end_time = clock();
  free(tmp2);
  printf("\nMergeSort'time:%ldms", (long)(end_time - start_time));

  addadta(cesi3, 200000);
  start_time = clock();
  QuickSort(cesi3, 0, 199999); //快速排序
  end_time = clock();
  printf("\nQuickSort'time:%ldms", (long)(end_time - start_time));

  addadta(cesi3, 200000);
  start_time = clock();
  CountSort(cesi3, 200000); //计数排序
  end_time = clock();
  printf("\nCountSort'time:%ldms", (long)(end_time - start_time));
  /*printarray(cesi3,200000);*/

  addadta(cesi3, 200000);
  start_time = clock();
  RadixSort(cesi3, 200000); //基数排序
  end_time = clock();
  printf("\nRadixSort'time:%ldms", (long)(end_time - start_time));

  free(cesi3);

  return 0;
}
