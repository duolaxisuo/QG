#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 1000
#include"SqStack.h"

int main()
{
   SqStack s ;
   char n[1000];
   printf("1����ʼ��ջ\n2����ջ\n3����ջ\n4�����ջ");
   printf("\n5������ջ\n6����ȡջ�ĳ���\n7���õ�ջ��Ԫ��\n8���ж�ջ�Ƿ�Ϊ��");
   printf("\n0������");
   printf("\n��ѡ�������");
   scanf("%s",&n);
   while(n[0]!='0'){
    if(n[0]<'0'||n[0]>'8'||n[1]!='\0'){
        printf("\n����������ȷ����:");
        scanf("%s",&n);
        }
   else{
        switch(temp(n[0])){
            case 1: init(&s);break;
            case 2: push(&s);break;
            case 3: pop(&s);break;
            case 4: clear(&s);break;
            case 5: destroy(&s);break;
            case 6: Length(&s);break;
            case 7: getTop(&s);break;
            case 8: isEmpty(&s);break;
            case 0: ;break;
            }
            printf("\n\nѡ�����:");
            getchar();
            scanf("%s",&n);
        }
   }
    return 0;
}
