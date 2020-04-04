#ifndef SQSTACK_H_INCLUDED
#define SQSTACK_H_INCLUDED

typedef enum Status
{
	ERROR = 0,
	SUCCESS = 1
} Status;

typedef int ElemType;

typedef struct SqStack
{
	ElemType elem[MAXSIZE];  //定义一个数组
	int top;
	int size;
	int sign;
} SqStack;
/*******************************************************/

Status* initStack(SqStack* s)/* 初始化栈 */
{
    s->top = -1;
    s->size = 0;
    s->sign = 1;
    return SUCCESS;
}

Status pushStack(SqStack* s, ElemType data, ElemType sizes) /* 入栈*/
{
    if(s->top == sizes - 1 )
        return ERROR;
    else{
        s->top++;
        s->elem[s->top] = data;
        s->size++;
        return SUCCESS;
    }
}


Status popStack(SqStack* s,ElemType* data) /*出栈*/
{
    if(s->top == -1 )
        return ERROR;
    else{
        *data = s->elem[s->top];
        s->top--;
        s->size--;
        return SUCCESS;
    }
}

Status clearStack(SqStack *s) /*清空栈*/
{
    s->size = 0;
    s->top = -1;
    return SUCCESS;
}

Status destroyStack(SqStack* s)    /*销毁栈*/
{
    s->sign=0;
    free(s);
    return SUCCESS;
}

Status stackLength(SqStack* s,int* length) /* 获取栈的长度*/
{
    *length = s->size;
    return SUCCESS;
}

Status isEmptyStack(SqStack* s)  /* 判断栈是否为空*/
{
    if(s->top == -1)
        return SUCCESS;
    else
        return ERROR;
}

Status getTopStack(SqStack* s, ElemType *e) /* 得到栈顶元素*/
{
    if(s->top == -1 )
        return ERROR;
    else{
        *e = s->elem[s->top];
        return SUCCESS;
    }
}
/*******************************************************/
int temp(char a){  /*防止菜单选择时选择其他非法输入*/
        int b;
        b=(int)a;
        return b-48;
}

Status checkinput(char* a, int *car) /*检测用户输入是否符合规格*/
{
    int i=0, flag=1, mark=1, num=0;
    while( a[i] != '\0' ){
        if(i==0&&(a[i] =='-'||a[i] == '+')){
            i++;
            continue;
        }
        if(a[i]<'0'||a[i]>'9'){
            return ERROR;
        }
    i++;
    }
    for(int j = 0;a[j] !='\0';j++){
        if(a[j] =='-'){
             mark = -1;
             continue;
        }
        num = num*10 + (a[j]-48);
    }
    *car = num *mark;
    return SUCCESS;
}

void init(SqStack* s)
{

    int a;
    a = initStack(s);
    if(a==1)
        printf("\n初始化完成");
    else
        printf("\n初始化失败");

}

void push(SqStack* s)
{
    /*printf("%d",s->top);*/
   /* printf("%d",sizes);*/
    ElemType data;
    char in[1000];
    int a, b, car=0;
    if(s->sign==1){
            printf("\n请输入数字：");
            scanf("%s",in);
            while(checkinput(in,&car) == ERROR){
                printf("重新输入正确的数:");
                scanf("%s",in);
              }
              data =car ;
    b = pushStack(s, data, MAXSIZE);
        if(b == 1)
         printf("\n入栈成功");
        else
         printf("\n入栈失败");
    }
    else
        printf("\n请先初始化栈");

}

void pop(SqStack* s)
{
     ElemType a=0, c;
     ElemType* b = &a;
      if(s->sign==1){
       c = popStack(s,b);
     if(c == 1){
        printf("\n出栈成功\n该出栈数据为:%d",a);
     }
    else
        printf("\n出栈失败");
    }
    else
        printf("\n请先初始化栈");

}

void clear(SqStack* s)
{
    if(s->sign == 1){
         int a=0;
    a = clearStack(s);
    if(a == 1)
        printf("\n清空成功");
    else
        printf("\n清空失败");
    }
    else
         printf("\n请先初始化栈");

}

void destroy(SqStack* s)
{
    if(s->sign == 1){
        int a = destroyStack(s);
    if(a == 1)
        printf("\n销毁成功");
    else
        printf("\n销毁失败");
    }
    else
        printf("\n请先初始化栈");
}

void Length(SqStack* s)
{
    int a;
    ElemType b = 0;
    ElemType*c = &b;
    if(s->sign == 1){
        a = stackLength(s,c);
    printf("\n栈的长度为：%d",b);
    }
    else
        printf("\n请先初始化栈");
}

void getTop(SqStack* s)
{
    int c;
    ElemType a;
    ElemType* b=&a;
     if(s->sign == 1){
         c = getTopStack(s, b);
    if(c == 1)
        printf("\n栈顶元素为:%d", a);
    else
        printf("\n无栈顶元素");
    }
    else
        printf("\n请先初始化栈");

}

void isEmpty(SqStack* s)
{
    if(s->sign == 1){
        if(isEmptyStack(s))
        printf("\n是空栈");
    else
        printf("\n不是空栈");
    }
    else
        printf("\n请先初始化栈");
}
/*******************************************************/

#endif // SQSTACK_H_INCLUDED
