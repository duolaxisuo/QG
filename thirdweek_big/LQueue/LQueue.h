#ifndef LQUEUE_H_INCLUDED
#define LQUEUE_H_INCLUDED

typedef int element;

typedef struct node
{
    element data;                   //数据域指针
    struct node *next;            //指向当前结点的下一结点
} QueueNode,*QueueNodePtr;

typedef struct Lqueue
{
    int sign;
    QueueNode *front;                   //队头
    QueueNode *rear;                    //队尾
    element length;               //队列长度
} LQueue;

typedef enum
{
    error=0,
    success=1
} Status;
char type;
char datatype[30];

/**************************************************************/
Status InitLQueue(LQueue *Q)  //初始化队列
{
    QueueNodePtr ptr = (QueueNodePtr)malloc(sizeof(QueueNode));
    if(ptr){         /*在队列头结点之前再搞一个头结点*/
        Q->front = Q->rear = ptr;
        ptr->next = NULL;
    }
    Q->sign = 1;
    return success;
}

void DestoryLQueue(LQueue *Q)  //销毁队列
{
    Q->sign = 0;
    free(Q);
}

Status IsEmptyLQueue(const LQueue *Q) //检查是否为空队列
{
    if(Q->front->next == NULL)
        return success;
    return error;
}

Status GetHeadLQueue(LQueue* Q, element* e)  //得到队头元素
{
    if(IsEmptyLQueue(Q))
        return error;

    *e = Q->front->next->data;
    return success;
}

int LengthLQueue(LQueue *Q)   //得到队列长度
{
    return Q->length;
}

Status EnLQueue(LQueue* Q, element e) //入队
{
    QueueNode* p=(QueueNode*)malloc(sizeof(QueueNode));/*申请新结点*/
    if(!p){
        return error;
    }
    Q->length++;
    p->data = e;
    p->next = NULL;
    Q->rear->next = p;  /*p结点接到链的后面*/
    Q->rear = p;        /*队尾指针指向新的尾结点*/
    return success;
}

Status DeLQueue(LQueue *Q,element* e)  //出队
{
    QueueNode* p;
    if(IsEmptyLQueue(Q))
        return error;
    p = Q->front->next; /*指向队头结点*/
    *e = p->data;         /*保存里面的数据*/
    Q->front->next = p->next; /*将队头结点从队列删去*/
    if(Q->front->next == p){     /*原队列只有一个结点的情况，删去后队列变空，队头结点的next也应该NULL*/
        Q->rear = Q->front;
        Q->front->next = NULL;
    }
     Q->length--;
    free(p);              /*释放被删除的队头结点*/
    return success;
}

void ClearLQueue(LQueue *Q) //清空队列
{
    Q->length = 0;
    Q->rear->next=Q->front->next=NULL;
}

Status TraverseLQueue(const LQueue *Q) //遍历并打印
{
    QueueNode *p;
    p = Q->front->next;
    if(p == NULL)
        return error;
    printf("\n");
    while(p != NULL){
        printf("%d  ",p->data);
        p = p->next;
    }
    return success;
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

void init(LQueue* q)
{
    if(InitLQueue(q)){
        printf("\n初始化成功");
    }
    else
        printf("\n初始化失败");
}

void En(LQueue* q)
{
    char in[1000],c;
    int data, b,car=0,i=10;
     if(q->sign==1){
      printf("\n一次十个数选择1，一键次一个数选择2\n");
     A:   scanf("%c",&c);
           if(c == '1'||c == '2'){
           switch(c){
           case'2': printf("\n请输入数字：");
                    scanf("%s",in);
            while(checkinput(in,&car) == error){
                printf("重新输入正确的数:");
                scanf("%s",in);}
                data =car ;
                b = EnLQueue(q, data);
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
                b = EnLQueue(q, data);
               i--;
              };
              printf("\n入队成功");
              break;
           }
           }
           else{
             printf("要正确输入!");
            goto A;
           }

    }
    else
        printf("\n请先初始化队列");
}

void De(LQueue* q)
{
    int a;
    if(q->sign == 1){
        if(DeLQueue(q,&a)){
        printf("\n出队成功，出队元素为:%d",a);
    }
    else
        printf("\n出队失败");
    }
    else
        printf("\n请先初始化队列");

}

void clear(LQueue* q)
{
    if(q->sign == 1){
        ClearLQueue(q);
        printf("\n清空成功");
    }
    else
        printf("\n请先初始化队列");
}

void destroy(LQueue* q)
{
    if(q->sign == 1){
        DestoryLQueue(q);
        printf("销毁成功");
    }
    else
        printf("\n请先初始化队列");
}

void Length(LQueue* q)
{
    int a,e;
    if(q->sign == 1){
        a = LengthLQueue(q);
        printf("\n队列长度为：%d",a);
        if(a == 0)
            printf("\n无队头元素");
        else{
            GetHeadLQueue(q,&e);
            printf("\n队头元素为：%d",e);
        }

    }
    else
        printf("\n请先初始化队列");
}
void traverse(LQueue* q)
{
    if(q->sign == 1){
        if(TraverseLQueue(q)==0)
            printf("\n无法打印和遍历");
    }
    else
        printf("请初始化队列");
}

void isEmpty(LQueue* q)
{
    if(q->sign==1){
     if(IsEmptyLQueue(q))
        printf("\n是空队列");
     else
        printf("\n不是空队列");
    }
     else
        printf("\n请先初始化队列");
}

/************************************************************/

#endif // LQUEUE_H_INCLUDED
