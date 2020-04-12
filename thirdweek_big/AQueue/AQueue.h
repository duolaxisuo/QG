#ifndef AQUEUE_H_INCLUDED
#define AQUEUE_H_INCLUDED
#define MAXQUEUE 10
typedef int element;

typedef struct Aqueue
{
    element data[MAXQUEUE];      //������
    int front;
    int rear;
    int length;        //���г���
    int sign;
} AQueue,*AQueuePtr;

typedef enum
{
    error=0,
    success=1
} Status;

/*********************************************/
Status InitAQueue(AQueue *Q)//��ʼ��ѭ������
{
    Q->sign = 1;

    Q->front=Q->rear = 0;//ͷ��βָ��ͬһ�ռ䣬�ÿ�
    return success;
}

Status DestoryAQueue(AQueue *Q)//����ѭ������
{
    Q->length = 0;
    Q->sign = 0;
    free(Q);
    return success;
}

Status IsFullAQueue(const AQueue *Q) //�ж��Ƿ�Ϊ������
{
    if(Q->length == MAXQUEUE)
       return success;
    return error;
}

Status IsEmptyAQueue(const AQueue *Q)//�ж��Ƿ�Ϊ�ն���
{
    if(Q->length == 0)
        return success;
    return error;
}

Status GetHeadAQueue(AQueue *Q, element *e)//�õ���ͷԪ��
{
    int p;
    p = Q->front;
    if(Q->length == 0)
        return error;
    *e = Q->data[p];
    return success;
}

int LengthAQueue(AQueue *Q)//�ӵĳ���
{
    return Q->length;
}

Status EnAQueue(AQueue *Q, element e)//���
{
    if(Q->length == MAXQUEUE)
        return error;
    Q->length++;
    Q->data[(Q->rear)] = e;
    Q->rear = (Q->rear+1)%MAXQUEUE;
    return success;
}

Status DeAQueue(AQueue *Q, element* e)//���Ӳ��õ���ͷԪ��
{
    if(Q->length){
        *e = Q->data[Q->front];
         Q->front = (Q->front+1)%MAXQUEUE;
        Q->length --;
        return success;
    }
    return error;
}

void ClearAQueue(AQueue *Q)//���ѭ������
{
    Q->length = 0;
    Q->front = Q->rear = 0;
}

Status TraverseAQueue(const AQueue *Q)//��������ӡѭ������
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

void init(AQueue* q)
{
    if(InitAQueue(q)){
        printf("\n��ʼ���ɹ�");
    }
    else
        printf("\n��ʼ��ʧ��");
}

void En(AQueue* q)
{
    char in[1000],c;
    int data, b,car=0,i=5;
     if(q->sign==1){
     printf("\nһ�������ѡ��1��һ��һ����ѡ��2\n");
     A:    scanf("%c",&c);
           if(c == '1'||c == '2'){
           switch(c){
           case'2': printf("\n���������֣�");
                    scanf("%s",in);
            while(checkinput(in,&car) == error){
                printf("����������ȷ����:");
                scanf("%s",in);}
                data =car ;
                b = EnAQueue(q, data);
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
                b = EnAQueue(q, data);
               i--;
              };
              printf("\n��ӳɹ�");
              break;
           }
           }
           else{
             printf("Ҫ��ȷ����!\n");
            goto A;
           }

    }
    else
        printf("\n���ȳ�ʼ������");
}

void De(AQueue* q)
{
    int a;
    if(q->sign == 1){
        if(DeAQueue(q,&a)){
        printf("\n���ӳɹ�������Ԫ��Ϊ:%d",a);
    }
    else
        printf("\n����ʧ��");
    }
    else
        printf("\n���ȳ�ʼ������");

}

void clear(AQueue* q)
{
    if(q->sign == 1){
        ClearAQueue(q);
        printf("\n��ճɹ�");
    }
    else
        printf("\n���ȳ�ʼ������");
}

void destroy(AQueue* q)
{
    if(q->sign == 1){
        DestoryAQueue(q);
        printf("���ٳɹ�");
    }
    else
        printf("\n���ȳ�ʼ������");
}

void Length(AQueue* q)
{
    int a,e;
    if(q->sign == 1){
        a = LengthAQueue(q);
        printf("\n���г���Ϊ��%d",a);
        if(a == 0)
            printf("\n�޶�ͷԪ��");
        else{
            GetHeadAQueue(q,&e);
            printf("\n��ͷԪ��Ϊ��%d",e);
        }

    }
    else
        printf("\n���ȳ�ʼ������");
}

void traverse(AQueue* q)
{
    if(q->sign == 1){
        if(TraverseAQueue(q)==0)
            printf("\n�޷���ӡ�ͱ���");
    }
    else
        printf("���ʼ������");
}

void isEmpty(AQueue* q)
{
    if(q->sign==1){
     if(IsEmptyAQueue(q))
        printf("\n�ǿն���");
     else
        printf("\n���ǿն���");
    }
     else
        printf("\n���ȳ�ʼ������");
}
/*************************************************************/
#endif // AQUEUE_H_INCLUDED
