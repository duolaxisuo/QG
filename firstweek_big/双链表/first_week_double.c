#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>
#include"head_double.h"


 /*********************************************************************/
int main()
{
    char select[1000];
    LinkedList head = (LinkedList)malloc(sizeof(LNode));/*Ϊͷ������洢�ռ�*/
    head->next = NULL;
    head->data = 99999;
    InitList(head);
    printf("�Ѿ���ʼ����һ����10����������������ͷ��㣩\n");
    printf("1����ӡ�����ֵ\n2����ѯ���������Ƿ��ж�Ӧ��ֵ\n");
    printf("3����ѯ�������Ƿ�Ϊѭ������\n4����ѯ�Ƿ�ת����ɹ�\n");
    printf("5�������½��\n6��ɾ����㲢��ȡ�ý���ֵ\n");
    printf("7������10�����or���ٺ����³�ʼ��\n8��Ѱ���м����ֵ\n9����������\n0������\nѡ�������");
    scanf("%s",&select);
    while(select[0]!='0'){
       if(select[0]<'0'||select[0]>'9'||select[1]!='\0'){
        printf("\n����������ȷ����:");
        scanf("%s",&select);
    }
    else{
        switch(temp(select[0]))
         {
              case 0: ;break;
              case 1: TraverseList(head,visit);break;
              case 2: search(head);break;
              case 3: IsLoop(head);break;
              case 4: Reverse(&head);break;
              case 5: printf("\n�˹�����ʱ��֪����ô���ֳ���");break;
              case 6: printf("\n�˹�����ʱҲ��֪����ô���ֳ���") ;break;
              case 7: InitList(head) ;break;
              case 8: mid(&head);break;
              case 9: DestroyList(head);break;
         }
         printf("\nѡ�����:");
         getchar();
         scanf("%s",&select);
        }
    }
    return 0;
}
