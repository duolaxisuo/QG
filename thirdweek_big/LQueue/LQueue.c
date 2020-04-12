#include<stdio.h>
#include<stdlib.h>
#include"LQueue.h"
int main()
{
    LQueue head;
    (&head)->length = 0;
    (&head)->sign =0;
   char n[1000];

   printf("1、初始化队列\n2、入队\n3、出队\n4、清空队列");
   printf("\n5、销毁队列\n6、获取队列的长度且得到队头元素\n7、遍历队列并打印\n8、判断队列是否为空");
   printf("\n9、清屏操作\n0、结束");
   printf("\n请选择操作：");
   scanf("%s",&n);
   while(n[0]!='0'){
        if(n[0]<'0'||n[0]>'9'||n[1]!='\0'){
        printf("\n重新输入正确的数:");
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
                printf("1、初始化队列\n2、入队\n3、出队\n4、清空队列");
                printf("\n5、销毁队列\n6、获取队列的长度且得到队头元素\n7、遍历队列并打印\n8、判断队列是否为空");
                printf("\n9、清屏操作\n0、结束");
                printf("\n请选择操作：");
            }
             printf("\n\n选择操作:");
             getchar();
             scanf("%s",&n);
        }
   }
    return 0;
}
