#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 1000
#include"SqStack.h"

int main()
{
   SqStack s ;
   char n[1000];
   printf("1、初始化栈\n2、入栈\n3、出栈\n4、清空栈");
   printf("\n5、销毁栈\n6、获取栈的长度\n7、得到栈顶元素\n8、判断栈是否为空");
   printf("\n0、结束");
   printf("\n请选择操作：");
   scanf("%s",&n);
   while(n[0]!='0'){
    if(n[0]<'0'||n[0]>'8'||n[1]!='\0'){
        printf("\n重新输入正确的数:");
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
            printf("\n\n选择操作:");
            getchar();
            scanf("%s",&n);
        }
   }
    return 0;
}
