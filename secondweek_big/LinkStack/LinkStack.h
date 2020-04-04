#ifndef LINKSTACK_H_INCLUDED
#define LINKSTACK_H_INCLUDED

typedef enum Status //定义枚举类型
{
    ERROR = 0,
	SUCCESS = 1
} Status;

typedef int ElemType;

typedef  struct StackNode /*定义结点或者称为链栈存储元素的数据结构*/
{
	ElemType data;
	struct StackNode* next; /*向下一个结点*/
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack  /*链栈类型定义*/
{
	LinkStackPtr top;       /*指向栈顶(有着数据域和指针域的类型节点)的指针*/
	int	count;              /*计数器*/
	int sign;
}LinkStack;

/************************************************************/
Status initLStack(LinkStack *s) /*初始化栈*/
{
    if(!s)
        return ERROR;
    s->top = NULL;  //初始化指向空
    s->count = 0;  //初始化长度 为0
    s->sign = 1;
    return SUCCESS;
}

Status isEmptyLStack(LinkStack *s) /*判断栈是否为空*/
{
    if(s->top == NULL)
        return SUCCESS;
    else
        return ERROR;
}

Status pushLStack(LinkStack *s,ElemType data) /*入栈*/
{
    LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode)); //申请生成一个新节点
    if(p == NULL)
        return ERROR;
    else{
        p->data = data;
        p->next =s->top;
        s->top = p;
        s->count++;
        return SUCCESS;
    }
}

Status popLStack(LinkStack *s,ElemType *data)/*出栈*/
{
    LinkStackPtr p;//临时节点，用来存储即将被free的节点
    if(isEmptyLStack(s))
        return ERROR;
    else{
        p = s->top;
        *data = s->top->data;
        s->count--;
        s->top = s->top->next;
        free(p);  //让该地址和内存说拜拜
        return SUCCESS;
    }
}
Status LStackLength(LinkStack *s,int *length)/*栈的长度*/
{
    *length = s->count;
    return SUCCESS;
}

Status getTopLStack(LinkStack *s,ElemType *e)/*得到栈顶元素*/
{
    if(isEmptyLStack(s))
        return ERROR;
    else{
        *e = s->top->data;
        return SUCCESS;
    }
}
Status clearLStack(LinkStack *s) /*清空栈*/
{
    s->top = NULL;
    s->count = 0;
    return SUCCESS;
}
Status destroyLStack(LinkStack *s)
{
    s->sign = 0;
    free(s);
    return SUCCESS;
}

/************************************************************/
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

void init(LinkStack* s)
{

    int a;
    a = initLStack(s);
    if(a==1)
        printf("\n初始化完成");
    else
        printf("\n初始化失败");

}

void push(LinkStack* s)
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
    b = pushLStack(s, data);
        if(b == 1)
         printf("\n入栈成功");
        else
         printf("\n入栈失败");
    }
    else
        printf("\n请先初始化栈");

}

void pop(LinkStack* s)
{
     ElemType a=0, c;
     ElemType* b = &a;
      if(s->sign==1){
       c = popLStack(s,b);
     if(c == 1){
        printf("\n出栈成功\n该出栈数据为:%d",a);
     }
    else
        printf("\n出栈失败");
    }
    else
        printf("\n请先初始化栈");

}

void clear(LinkStack* s)
{
    if(s->sign == 1){
         int a=0;
    a = clearLStack(s);
    if(a == 1)
        printf("\n清空成功");
    else
        printf("\n清空失败");
    }
    else
         printf("\n请先初始化栈");

}

void destroy(LinkStack* s)
{
    if(s->sign == 1){
        int a = destroyLStack(s);
    if(a == 1)
        printf("\n销毁成功");
    else
        printf("\n销毁失败");
    }
    else
        printf("\n请先初始化栈");
}

void Length(LinkStack* s)
{
    int a;
    ElemType b = 0;
    ElemType*c = &b;
    if(s->sign == 1){
        a = LStackLength(s,c);
    printf("\n栈的长度为：%d",b);
    }
    else
        printf("\n请先初始化栈");
}

void getTop(LinkStack* s)
{
    int c;
    ElemType a;
    ElemType* b=&a;
     if(s->sign == 1){
         c = getTopLStack(s, b);
    if(c == 1)
        printf("\n栈顶元素为:%d", a);
    else
        printf("\n无栈顶元素");
    }
    else
        printf("\n请先初始化栈");

}

void isEmpty(LinkStack* s)
{
    if(s->sign == 1){
        if(isEmptyLStack(s))
        printf("\n是空栈");
    else
        printf("\n不是空栈");
    }
    else
        printf("\n请先初始化栈");
}
/************************************************************/

#endif // LINKSTACK_H_INCLUDED
