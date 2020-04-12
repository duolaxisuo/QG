#ifndef AQUEUE_H_INCLUDED
#define AQUEUE_H_INCLUDED
#define MAXQUEUE 10
typedef int element;

typedef struct Aqueue
{
    element data[MAXQUEUE];      //数据域
    int front;
    int rear;
    int length;        //队列长度
    int sign;
} AQueue,*AQueuePtr;

typedef enum
{
    error=0,
    success=1
} Status;

/*********************************************/
Status InitAQueue(AQueue *Q)//初始化循环队列
{
    Q->sign = 1;

    Q->front=Q->rear = 0;//头与尾指向同一空间，置空
    return success;
}

Status DestoryAQueue(AQueue *Q)//销毁循环队列
{
    Q->length = 0;
    Q->sign = 0;
    free(Q);
    return success;
}

Status IsFullAQueue(const AQueue *Q) //判断是否为满队列
{
    if(Q->length == MAXQUEUE)
       return success;
    return error;
}

Status IsEmptyAQueue(const AQueue *Q)//判断是否为空队列
{
    if(Q->length == 0)
        return success;
    return error;
}

Status GetHeadAQueue(AQueue *Q, element *e)//得到队头元素
{
    int p;
    p = Q->front;
    if(Q->length == 0)
        return error;
    *e = Q->data[p];
    return success;
}

int LengthAQueue(AQueue *Q)//队的长度
{
    return Q->length;
}

Status EnAQueue(AQueue *Q, element e)//入队
{
    if(Q->length == MAXQUEUE)
        return error;
    Q->length++;
    Q->data[(Q->rear)] = e;
    Q->rear = (Q->rear+1)%MAXQUEUE;
    return success;
}

Status DeAQueue(AQueue *Q, element* e)//出队并得到队头元素
{
    if(Q->length){
        *e = Q->data[Q->front];
         Q->front = (Q->front+1)%MAXQUEUE;
        Q->length --;
        return success;
    }
    return error;
}

void ClearAQueue(AQueue *Q)//清空循环队列
{
    Q->length = 0;
    Q->front = Q->rear = 0;
}

Status TraverseAQueue(const AQueue *Q)//遍历并打印循环队列
{
    int p = Q->front;
    if(Q->length==0)
        return error;

    while(p!=Q->rear){
        printf("%d ",Q->data[p]);
        p++;
        p = p%MAXQUEUE;
    }
    return success;
}

/*********************************************/
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
            return error;
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
    return success;
}

void init(AQueue* q)
{
    if(InitAQueue(q)){
        printf("\n初始化成功");
    }
    else
        printf("\n初始化失败");
}

void En(AQueue* q)
{
    char in[1000],c;
    int data, b,car=0,i=5;
     if(q->sign==1){
     printf("\n一次五个数选择1，一次一个数选择2\n");
     A:    scanf("%c",&c);
           if(c == '1'||c == '2'){
           switch(c){
           case'2': printf("\n请输入数字：");
                    scanf("%s",in);
            while(checkinput(in,&car) == error){
                printf("重新输入正确的数:");
                scanf("%s",in);}
                data =car ;
                b = EnAQueue(q, data);
                if(b == 1)
               printf("\n入队成功");
                else
               printf("\n入队失败");
           break;
           case'1':printf("\n请输入数字：");
           while(i){
               scanf("%s",in);
            while(checkinput(in,&car) == error){
                printf("重新输入正确的数:");
                scanf("%s",in);}
                data =car ;
                b = EnAQueue(q, data);
               i--;
              };
              printf("\n入队成功");
              break;
           }
           }
           else{
             printf("要正确输入!\n");
            goto A;
           }

    }
    else
        printf("\n请先初始化队列");
}

void De(AQueue* q)
{
    int a;
    if(q->sign == 1){
        if(DeAQueue(q,&a)){
        printf("\n出队成功，出队元素为:%d",a);
    }
    else
        printf("\n出队失败");
    }
    else
        printf("\n请先初始化队列");

}

void clear(AQueue* q)
{
    if(q->sign == 1){
        ClearAQueue(q);
        printf("\n清空成功");
    }
    else
        printf("\n请先初始化队列");
}

void destroy(AQueue* q)
{
    if(q->sign == 1){
        DestoryAQueue(q);
        printf("销毁成功");
    }
    else
        printf("\n请先初始化队列");
}

void Length(AQueue* q)
{
    int a,e;
    if(q->sign == 1){
        a = LengthAQueue(q);
        printf("\n队列长度为：%d",a);
        if(a == 0)
            printf("\n无队头元素");
        else{
            GetHeadAQueue(q,&e);
            printf("\n队头元素为：%d",e);
        }

    }
    else
        printf("\n请先初始化队列");
}

void traverse(AQueue* q)
{
    if(q->sign == 1){
        if(TraverseAQueue(q)==0)
            printf("\n无法打印和遍历");
    }
    else
        printf("请初始化队列");
}

void isEmpty(AQueue* q)
{
    if(q->sign==1){
     if(IsEmptyAQueue(q))
        printf("\n是空队列");
     else
        printf("\n不是空队列");
    }
     else
        printf("\n请先初始化队列");
}
/*************************************************************/
#endif // AQUEUE_H_INCLUDED
