#ifndef LQUEUE_H_INCLUDED
#define LQUEUE_H_INCLUDED

typedef int element;

typedef struct node
{
    element data;                   //������ָ��
    struct node *next;            //ָ��ǰ������һ���
} QueueNode,*QueueNodePtr;

typedef struct Lqueue
{
    int sign;
    QueueNode *front;                   //��ͷ
    QueueNode *rear;                    //��β
    element length;               //���г���
} LQueue;

typedef enum
{
    error=0,
    success=1
} Status;
char type;
char datatype[30];

/**************************************************************/
Status InitLQueue(LQueue *Q)  //��ʼ������
{
    QueueNodePtr ptr = (QueueNodePtr)malloc(sizeof(QueueNode));
    if(ptr){         /*�ڶ���ͷ���֮ǰ�ٸ�һ��ͷ���*/
        Q->front = Q->rear = ptr;
        ptr->next = NULL;
    }
    Q->sign = 1;
    return success;
}

void DestoryLQueue(LQueue *Q)  //���ٶ���
{
    Q->sign = 0;
    free(Q);
}

Status IsEmptyLQueue(const LQueue *Q) //����Ƿ�Ϊ�ն���
{
    if(Q->front->next == NULL)
        return success;
    return error;
}

Status GetHeadLQueue(LQueue* Q, element* e)  //�õ���ͷԪ��
{
    if(IsEmptyLQueue(Q))
        return error;

    *e = Q->front->next->data;
    return success;
}

int LengthLQueue(LQueue *Q)   //�õ����г���
{
    return Q->length;
}

Status EnLQueue(LQueue* Q, element e) //���
{
    QueueNode* p=(QueueNode*)malloc(sizeof(QueueNode));/*�����½��*/
    if(!p){
        return error;
    }
    Q->length++;
    p->data = e;
    p->next = NULL;
    Q->rear->next = p;  /*p���ӵ����ĺ���*/
    Q->rear = p;        /*��βָ��ָ���µ�β���*/
    return success;
}

Status DeLQueue(LQueue *Q,element* e)  //����
{
    QueueNode* p;
    if(IsEmptyLQueue(Q))
        return error;
    p = Q->front->next; /*ָ���ͷ���*/
    *e = p->data;         /*�������������*/
    Q->front->next = p->next; /*����ͷ���Ӷ���ɾȥ*/
    if(Q->front->next == p){     /*ԭ����ֻ��һ�����������ɾȥ����б�գ���ͷ����nextҲӦ��NULL*/
        Q->rear = Q->front;
        Q->front->next = NULL;
    }
     Q->length--;
    free(p);              /*�ͷű�ɾ���Ķ�ͷ���*/
    return success;
}

void ClearLQueue(LQueue *Q) //��ն���
{
    Q->length = 0;
    Q->rear->next=Q->front->next=NULL;
}

Status TraverseLQueue(const LQueue *Q) //��������ӡ
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
        printf("\n��ʼ���ɹ�");
    }
    else
        printf("\n��ʼ��ʧ��");
}

void En(LQueue* q)
{
    char in[1000],c;
    int data, b,car=0,i=10;
     if(q->sign==1){
      printf("\nһ��ʮ����ѡ��1��һ����һ����ѡ��2\n");
     A:   scanf("%c",&c);
           if(c == '1'||c == '2'){
           switch(c){
           case'2': printf("\n���������֣�");
                    scanf("%s",in);
            while(checkinput(in,&car) == error){
                printf("����������ȷ����:");
                scanf("%s",in);}
                data =car ;
                b = EnLQueue(q, data);
                if(b == 1)
               printf("\n��ӳɹ�");
                else
               printf("\n���ʧ��");
           break;
           case'1':printf("\n���������֣�");
           while(i){
               scanf("%s",in);
            while(checkinput(in,&car) == error){
                printf("����������ȷ����:");
                scanf("%s",in);}
                data =car ;
                b = EnLQueue(q, data);
               i--;
              };
              printf("\n��ӳɹ�");
              break;
           }
           }
           else{
             printf("Ҫ��ȷ����!");
            goto A;
           }

    }
    else
        printf("\n���ȳ�ʼ������");
}

void De(LQueue* q)
{
    int a;
    if(q->sign == 1){
        if(DeLQueue(q,&a)){
        printf("\n���ӳɹ�������Ԫ��Ϊ:%d",a);
    }
    else
        printf("\n����ʧ��");
    }
    else
        printf("\n���ȳ�ʼ������");

}

void clear(LQueue* q)
{
    if(q->sign == 1){
        ClearLQueue(q);
        printf("\n��ճɹ�");
    }
    else
        printf("\n���ȳ�ʼ������");
}

void destroy(LQueue* q)
{
    if(q->sign == 1){
        DestoryLQueue(q);
        printf("���ٳɹ�");
    }
    else
        printf("\n���ȳ�ʼ������");
}

void Length(LQueue* q)
{
    int a,e;
    if(q->sign == 1){
        a = LengthLQueue(q);
        printf("\n���г���Ϊ��%d",a);
        if(a == 0)
            printf("\n�޶�ͷԪ��");
        else{
            GetHeadLQueue(q,&e);
            printf("\n��ͷԪ��Ϊ��%d",e);
        }

    }
    else
        printf("\n���ȳ�ʼ������");
}
void traverse(LQueue* q)
{
    if(q->sign == 1){
        if(TraverseLQueue(q)==0)
            printf("\n�޷���ӡ�ͱ���");
    }
    else
        printf("���ʼ������");
}

void isEmpty(LQueue* q)
{
    if(q->sign==1){
     if(IsEmptyLQueue(q))
        printf("\n�ǿն���");
     else
        printf("\n���ǿն���");
    }
     else
        printf("\n���ȳ�ʼ������");
}

/************************************************************/

#endif // LQUEUE_H_INCLUDED
