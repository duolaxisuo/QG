#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>
#include"head_double.h"


 /*********************************************************************/
int main()
{
    char select[1000];
    LinkedList head = (LinkedList)malloc(sizeof(LNode));/*为头结点分配存储空间*/
    head->next = NULL;
    head->data = 99999;
    InitList(head);
    printf("已经初始好了一个有10个结点的链表（不包括头结点）\n");
    printf("1、打印链表的值\n2、查询该链表中是否有对应的值\n");
    printf("3、查询该链表是否为循环链表\n4、查询是否翻转链表成功\n");
    printf("5、插入新结点\n6、删除结点并获取该结点的值\n");
    printf("7、增加10个结点or销毁后重新初始化\n8、寻找中间结点的值\n9、销毁链表\n0、结束\n选择操作：");
    scanf("%s",&select);
    while(select[0]!='0'){
       if(select[0]<'0'||select[0]>'9'||select[1]!='\0'){
        printf("\n重新输入正确的数:");
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
              case 5: printf("\n此功能暂时不知道怎么表现出来");break;
              case 6: printf("\n此功能暂时也不知道怎么表现出来") ;break;
              case 7: InitList(head) ;break;
              case 8: mid(&head);break;
              case 9: DestroyList(head);break;
         }
         printf("\n选择操作:");
         getchar();
         scanf("%s",&select);
        }
    }
    return 0;
}
