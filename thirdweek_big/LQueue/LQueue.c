#include<stdio.h>
#include<stdlib.h>
#include"LQueue.h"
int main()
{
    LQueue head;
    (&head)->length = 0;
    (&head)->sign =0;
   char n[1000];

   printf("1����ʼ������\n2�����\n3������\n4����ն���");
   printf("\n5�����ٶ���\n6����ȡ���еĳ����ҵõ���ͷԪ��\n7���������в���ӡ\n8���ж϶����Ƿ�Ϊ��");
   printf("\n9����������\n0������");
   printf("\n��ѡ�������");
   scanf("%s",&n);
   while(n[0]!='0'){
        if(n[0]<'0'||n[0]>'9'||n[1]!='\0'){
        printf("\n����������ȷ����:");
        scanf("%s",&n);}
   else{
        switch(temp(n[0])){
            case 1: init(&head);break;
            case 2: En(&head);break;
            case 3: De(&head);break;
            case 4: clear(&head);break;
            case 5: destroy(&head);break;
            case 6: Length(&head);break;
            case 7: traverse(&head);break;
            case 8: isEmpty(&head);break;
            case 9: system("cls");break;
            case 0: ;break;
            }
            if(temp(n[0])==9){
                printf("1����ʼ������\n2�����\n3������\n4����ն���");
                printf("\n5�����ٶ���\n6����ȡ���еĳ����ҵõ���ͷԪ��\n7���������в���ӡ\n8���ж϶����Ƿ�Ϊ��");
                printf("\n9����������\n0������");
                printf("\n��ѡ�������");
            }
             printf("\n\nѡ�����:");
             getchar();
             scanf("%s",&n);
        }
   }
    return 0;
}
