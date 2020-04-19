#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <limits.h>
#include <string.h>
#include <assert.h>
#include "Sort.h"

#define ST 64

char* s_gets(char *st, int size)
{
  char* re;
  int i = 0;

  re = fgets(st, size, stdin); //stdin:标准输入,FILE类型;返回一个相同的st
  if (re)
  {
    while (st[i] != '\n' && st[i] != '\0') //如果没有到输入字符串结束
      i++;                                 //递增
    if (st[i] == '\n')                     //如果字符串最后一个字符是'\n'
      st[i] = '\0';                        //把它变成'\0'
    else                                   //否则缓冲区内还有一部分超出读取范围的字符没有被读取
      while (getchar() != '\n')            //把这些字符读取完（清空缓冲区）
        continue;
  }
  return re;
}

int main()
{
  FILE *sor, *dest; //sor源文件  dest目标文件
  int i, n;         //n表示元素个数
  char fname[ST];   //临时存储字符串

  printf("Please enter the number of elements first:");
  while (scanf("%d", &n) != 1 || n <= 0)
  {
    printf("Input error, please input again!\n");
    while (getchar()!= '\n')
    {
      continue;
    }
  }
  while (getchar() != '\n')
    continue;
  int *ptr = (int *)malloc(n * sizeof(int));
  if (ptr == NULL)
  { //stderr:标准错误输出；stdout:标准输出
    fprintf(stderr, "FAIL TO ASK FOR MEMORY SPACE\n");
    exit(EXIT_FAILURE); //关闭所有文件，终止正在执行的进程
  }

  printf("Please enter the original file name:");
  if (s_gets(fname, ST) == NULL) //
  {
    fprintf(stderr, "Fail to get a string\n");
    exit(EXIT_FAILURE);
  }

  sor = fopen(fname, "r"); //打开包含数据的源文件
  if (sor == NULL)
  {
    fprintf(stderr, "Fail to open the source file\n");
    exit(EXIT_FAILURE);
  }

  for (i = 0; i < n; i++) //获取数据到动态数组
    if (fscanf(sor, "%d", &ptr[i]) != 1)
    {
      fprintf(stderr, "Fail to get the data\n");
      exit(EXIT_FAILURE);
    }

  /*排序函数*/
  printf("Sorted data:");
  QuickSort(ptr, 0, n-1);
  printarray(ptr, n);

  if (fclose(sor) != 0)
  { //关闭源文件
    fprintf(stderr, "Fail to close the source file\n");
    exit(EXIT_FAILURE);
  }
  if (fclose(dest) != 0)
  { //关闭目标文件
    fprintf(stderr, "Fail to close the destination file\n");
    exit(EXIT_FAILURE);
  }
  free(ptr); //释放内存

  printf("Completed successfully! \n press any key to continue\b\b");

  getch();

  return 0;
}


