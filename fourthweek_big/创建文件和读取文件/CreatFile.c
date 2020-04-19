#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


  int main()
  {
    FILE *fp; //文件指针
    int i, d, k;
    printf("该创建的文件名为data.txt\n");
        printf("输入要保存的数的数量:");
    scanf("%d", &k);

    printf("\n输入要保存的数:");
    /*文件的打开*/
    fp = fopen("data.txt", "w"); //fopen打开文件，这个文件可以是当前不存在的。“w”以写入的形式打开，“r”以读的形式打开
    if (fp == NULL)              //判断如果文件指针为空
    {
      printf("File cannot open! ");
      exit(0); //在以0的形式退出，必须在文件开头有#include <stdlib.h>,stdlib 头文件即standard library标准库头文件
    }

    //写入东西
    for (i = 0; i < k; i++)
    {
      scanf("%d", &d);        //用户出入
      fprintf(fp, "%d\t", d); //写入指针fp，写入的东西就是刚才的用户输入的d,注意这里的fp和d没有引号
    }

    //关闭文件
    fclose(fp);
    printf("创建成功");
    return 0;
  }
