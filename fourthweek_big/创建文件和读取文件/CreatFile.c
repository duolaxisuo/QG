#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


  int main()
  {
    FILE *fp; //�ļ�ָ��
    int i, d, k;
    printf("�ô������ļ���Ϊdata.txt\n");
        printf("����Ҫ�������������:");
    scanf("%d", &k);

    printf("\n����Ҫ�������:");
    /*�ļ��Ĵ�*/
    fp = fopen("data.txt", "w"); //fopen���ļ�������ļ������ǵ�ǰ�����ڵġ���w����д�����ʽ�򿪣���r���Զ�����ʽ��
    if (fp == NULL)              //�ж�����ļ�ָ��Ϊ��
    {
      printf("File cannot open! ");
      exit(0); //����0����ʽ�˳����������ļ���ͷ��#include <stdlib.h>,stdlib ͷ�ļ���standard library��׼��ͷ�ļ�
    }

    //д�붫��
    for (i = 0; i < k; i++)
    {
      scanf("%d", &d);        //�û�����
      fprintf(fp, "%d\t", d); //д��ָ��fp��д��Ķ������Ǹղŵ��û������d,ע�������fp��dû������
    }

    //�ر��ļ�
    fclose(fp);
    printf("�����ɹ�");
    return 0;
  }
