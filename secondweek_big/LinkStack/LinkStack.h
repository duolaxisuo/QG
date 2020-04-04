#ifndef LINKSTACK_H_INCLUDED
#define LINKSTACK_H_INCLUDED

typedef enum Status //����ö������
{
    ERROR = 0,
	SUCCESS = 1
} Status;

typedef int ElemType;

typedef  struct StackNode /*��������߳�Ϊ��ջ�洢Ԫ�ص����ݽṹ*/
{
	ElemType data;
	struct StackNode* next; /*����һ�����*/
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack  /*��ջ���Ͷ���*/
{
	LinkStackPtr top;       /*ָ��ջ��(�����������ָ��������ͽڵ�)��ָ��*/
	int	count;              /*������*/
	int sign;
}LinkStack;

/************************************************************/
Status initLStack(LinkStack *s) /*��ʼ��ջ*/
{
    if(!s)
        return ERROR;
    s->top = NULL;  //��ʼ��ָ���
    s->count = 0;  //��ʼ������ Ϊ0
    s->sign = 1;
    return SUCCESS;
}

Status isEmptyLStack(LinkStack *s) /*�ж�ջ�Ƿ�Ϊ��*/
{
    if(s->top == NULL)
        return SUCCESS;
    else
        return ERROR;
}

Status pushLStack(LinkStack *s,ElemType data) /*��ջ*/
{
    LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode)); //��������һ���½ڵ�
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

Status popLStack(LinkStack *s,ElemType *data)/*��ջ*/
{
    LinkStackPtr p;//��ʱ�ڵ㣬�����洢������free�Ľڵ�
    if(isEmptyLStack(s))
        return ERROR;
    else{
        p = s->top;
        *data = s->top->data;
        s->count--;
        s->top = s->top->next;
        free(p);  //�øõ�ַ���ڴ�˵�ݰ�
        return SUCCESS;
    }
}
Status LStackLength(LinkStack *s,int *length)/*ջ�ĳ���*/
{
    *length = s->count;
    return SUCCESS;
}

Status getTopLStack(LinkStack *s,ElemType *e)/*�õ�ջ��Ԫ��*/
{
    if(isEmptyLStack(s))
        return ERROR;
    else{
        *e = s->top->data;
        return SUCCESS;
    }
}
Status clearLStack(LinkStack *s) /*���ջ*/
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

void init(LinkStack* s)
{

    int a;
    a = initLStack(s);
    if(a==1)
        printf("\n��ʼ�����");
    else
        printf("\n��ʼ��ʧ��");

}

void push(LinkStack* s)
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
    b = pushLStack(s, data);
        if(b == 1)
         printf("\n��ջ�ɹ�");
        else
         printf("\n��ջʧ��");
    }
    else
        printf("\n���ȳ�ʼ��ջ");

}

void pop(LinkStack* s)
{
     ElemType a=0, c;
     ElemType* b = &a;
      if(s->sign==1){
       c = popLStack(s,b);
     if(c == 1){
        printf("\n��ջ�ɹ�\n�ó�ջ����Ϊ:%d",a);
     }
    else
        printf("\n��ջʧ��");
    }
    else
        printf("\n���ȳ�ʼ��ջ");

}

void clear(LinkStack* s)
{
    if(s->sign == 1){
         int a=0;
    a = clearLStack(s);
    if(a == 1)
        printf("\n��ճɹ�");
    else
        printf("\n���ʧ��");
    }
    else
         printf("\n���ȳ�ʼ��ջ");

}

void destroy(LinkStack* s)
{
    if(s->sign == 1){
        int a = destroyLStack(s);
    if(a == 1)
        printf("\n���ٳɹ�");
    else
        printf("\n����ʧ��");
    }
    else
        printf("\n���ȳ�ʼ��ջ");
}

void Length(LinkStack* s)
{
    int a;
    ElemType b = 0;
    ElemType*c = &b;
    if(s->sign == 1){
        a = LStackLength(s,c);
    printf("\nջ�ĳ���Ϊ��%d",b);
    }
    else
        printf("\n���ȳ�ʼ��ջ");
}

void getTop(LinkStack* s)
{
    int c;
    ElemType a;
    ElemType* b=&a;
     if(s->sign == 1){
         c = getTopLStack(s, b);
    if(c == 1)
        printf("\nջ��Ԫ��Ϊ:%d", a);
    else
        printf("\n��ջ��Ԫ��");
    }
    else
        printf("\n���ȳ�ʼ��ջ");

}

void isEmpty(LinkStack* s)
{
    if(s->sign == 1){
        if(isEmptyLStack(s))
        printf("\n�ǿ�ջ");
    else
        printf("\n���ǿ�ջ");
    }
    else
        printf("\n���ȳ�ʼ��ջ");
}
/************************************************************/

#endif // LINKSTACK_H_INCLUDED
