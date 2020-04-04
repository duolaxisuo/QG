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
	ElemType elem[MAXSIZE];  //����һ������
	int top;
	int size;
	int sign;
} SqStack;
/*******************************************************/

Status* initStack(SqStack* s)/* ��ʼ��ջ */
{
    s->top = -1;
    s->size = 0;
    s->sign = 1;
    return SUCCESS;
}

Status pushStack(SqStack* s, ElemType data, ElemType sizes) /* ��ջ*/
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


Status popStack(SqStack* s,ElemType* data) /*��ջ*/
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

Status clearStack(SqStack *s) /*���ջ*/
{
    s->size = 0;
    s->top = -1;
    return SUCCESS;
}

Status destroyStack(SqStack* s)    /*����ջ*/
{
    s->sign=0;
    free(s);
    return SUCCESS;
}

Status stackLength(SqStack* s,int* length) /* ��ȡջ�ĳ���*/
{
    *length = s->size;
    return SUCCESS;
}

Status isEmptyStack(SqStack* s)  /* �ж�ջ�Ƿ�Ϊ��*/
{
    if(s->top == -1)
        return SUCCESS;
    else
        return ERROR;
}

Status getTopStack(SqStack* s, ElemType *e) /* �õ�ջ��Ԫ��*/
{
    if(s->top == -1 )
        return ERROR;
    else{
        *e = s->elem[s->top];
        return SUCCESS;
    }
}
/*******************************************************/
int temp(char a){  /*��ֹ�˵�ѡ��ʱѡ�������Ƿ�����*/
        int b;
        b=(int)a;
        return b-48;
}

Status checkinput(char* a, int *car) /*����û������Ƿ���Ϲ��*/
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
        printf("\n��ʼ�����");
    else
        printf("\n��ʼ��ʧ��");

}

void push(SqStack* s)
{
    /*printf("%d",s->top);*/
   /* printf("%d",sizes);*/
    ElemType data;
    char in[1000];
    int a, b, car=0;
    if(s->sign==1){
            printf("\n���������֣�");
            scanf("%s",in);
            while(checkinput(in,&car) == ERROR){
                printf("����������ȷ����:");
                scanf("%s",in);
              }
              data =car ;
    b = pushStack(s, data, MAXSIZE);
        if(b == 1)
         printf("\n��ջ�ɹ�");
        else
         printf("\n��ջʧ��");
    }
    else
        printf("\n���ȳ�ʼ��ջ");

}

void pop(SqStack* s)
{
     ElemType a=0, c;
     ElemType* b = &a;
      if(s->sign==1){
       c = popStack(s,b);
     if(c == 1){
        printf("\n��ջ�ɹ�\n�ó�ջ����Ϊ:%d",a);
     }
    else
        printf("\n��ջʧ��");
    }
    else
        printf("\n���ȳ�ʼ��ջ");

}

void clear(SqStack* s)
{
    if(s->sign == 1){
         int a=0;
    a = clearStack(s);
    if(a == 1)
        printf("\n��ճɹ�");
    else
        printf("\n���ʧ��");
    }
    else
         printf("\n���ȳ�ʼ��ջ");

}

void destroy(SqStack* s)
{
    if(s->sign == 1){
        int a = destroyStack(s);
    if(a == 1)
        printf("\n���ٳɹ�");
    else
        printf("\n����ʧ��");
    }
    else
        printf("\n���ȳ�ʼ��ջ");
}

void Length(SqStack* s)
{
    int a;
    ElemType b = 0;
    ElemType*c = &b;
    if(s->sign == 1){
        a = stackLength(s,c);
    printf("\nջ�ĳ���Ϊ��%d",b);
    }
    else
        printf("\n���ȳ�ʼ��ջ");
}

void getTop(SqStack* s)
{
    int c;
    ElemType a;
    ElemType* b=&a;
     if(s->sign == 1){
         c = getTopStack(s, b);
    if(c == 1)
        printf("\nջ��Ԫ��Ϊ:%d", a);
    else
        printf("\n��ջ��Ԫ��");
    }
    else
        printf("\n���ȳ�ʼ��ջ");

}

void isEmpty(SqStack* s)
{
    if(s->sign == 1){
        if(isEmptyStack(s))
        printf("\n�ǿ�ջ");
    else
        printf("\n���ǿ�ջ");
    }
    else
        printf("\n���ȳ�ʼ��ջ");
}
/*******************************************************/

#endif // SQSTACK_H_INCLUDED
