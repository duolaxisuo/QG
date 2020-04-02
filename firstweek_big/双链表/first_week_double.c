#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>


typedef int ElemType;

typedef struct node{ /*��װ����,���������������LNode��*ListNodePtr*/
    ElemType data;
    struct node* pre;
    struct node* next;
}LNode,*LinkedList;

typedef enum Status {
	error,
	success
}Status;

Status InitList(LinkedList L){  /**/
    Status status = success;
    ElemType n = 10, i;
    LinkedList temp = NULL;
    srand(time(0));
   /* *L = (LinkedList)malloc(sizeof(LNode));/*Ϊͷ������洢�ռ�
    (*L)->next = NULL;*/
    for(i=0;i<n;i++){
        temp = (LinkedList)malloc(sizeof(LNode));
        if(!temp){  /* �޷�Ϊtemp�����ڴ�ռ�    */
            status = error;
            break;
        }
        temp->data = rand()%100+1;/* �����*/
        temp->pre = L;
        temp->next = L->next;   /*ͷ�巨*/
        L->next = temp;
    }

    return status;
}

void DestroyList(LinkedList L){  /**/
    LinkedList p = L,q = p->next;
    while(q){
        p->next = q->next; /* p�ĵ�ַһֱ��L,ֻ����������q*/
        free(q);
        q = p->next;
    }
    free(L);
    printf("\n�Ѿ�����");
}

Status InsertList(LNode *p, LNode *q){ /* insert q after node p*/
     Status status;
     if(p){
        p->next = q->pre;
        q->next = p->next;
        q->pre = p;
        p->next = q;
        status = success;
      }
     else
        status = error;
     return status;
}

void TraverseList(LinkedList L, void (*visit)(LinkedList L)){
        if(L == NULL||L->next == NULL)
            printf("������û����");
        else
            visit(L);

}

Status SearchList(LinkedList L, ElemType e){
       LinkedList p = L,q = p->next;
       Status status = error;
       while(q){
        if(q->data==e){
            status = success;
            break;
        }
        else{
            p = q;
            q = p->next;
        }
       }
        return status;
}

Status DeleteList(LNode *p, ElemType *e){
      Status status;
      if(p->next){
        status = error;
      }
      else{
        *e = p->next->data;
        p->next->pre = p->pre;
        p->pre->next = p->next;
      }
      return status;
}

Status ReverseList(LinkedList *L){
        Status status;
        LinkedList p = *L,q = p->next,f = p->next->next;
        if(p==NULL||f==NULL){
             status = error;
        }
        else if(f->next == NULL){
             status = success;
             (*L)->next = NULL;
             q->next = *L ;
             f->next = q;
             *L = f;
        }
        else{
            p = NULL;
            q->next = p;
            while(f!=NULL){
                p = q;
                q = f;
                f = f->next;
                q->next = p;
                }
                (*L) ->next = q;
                (*L) ->data = 99999;
        status = success;
        }
        return status;
}

Status IsLoopList(LinkedList L){
        Status status = error;
        LinkedList fast , slow = L->next;
        if(L == NULL)
            status = error ;
        else if(slow == NULL)
            status = error;
        else{
            fast = slow->next;
            while(slow != NULL && fast != NULL ){
                if( slow == fast){
                    status = success;
                    break;
                }
                slow = slow->next; /*��һ��*/
                fast = fast->next; /*����һ��*/
                if(fast != NULL){  /*�ж��ߵ���һ���Ƿ�Ϊ��*/
                    fast = fast->next;
                }
            }
        }
        return status ;
 }


 LNode* FindMidNode(LinkedList *L){
        LinkedList last, mid;
        last = mid = (*L);
        while( last->next != NULL){
        if (last->next->next != NULL){
            last = last->next->next;
            mid = mid ->next;
        }
        else{
            last = last->next;
        }
   }
   return mid;
 }
 /*********************************************************************/
 void visit(LinkedList L){
        LinkedList p = L;
        while(p){
            if(p->data == 99999)
            p = p->next;
            printf("%d  ",p->data);
            p = p->next;
        }

        printf("\n");
}

void search(LinkedList L){
        int a,b;
        printf("����Ҫ��ѯ����");
        scanf("%d",&a);
        b=SearchList(L,a);
        if(b==0)
            printf("NO\n");
        else
           printf("YES\n");
}

void IsLoop(LinkedList L){
        int a;
        a=IsLoopList(L);
        if(a==0)
            printf("NO\n");
        else
           printf("YES\n");
}

void mid(LinkedList *L){
        LNode*a;
        a = FindMidNode(L);
        printf("\n%d",a->data);
}

void Reverse(LinkedList L){
        int a;
        a = ReverseList(L);
        if(a==0)
            printf("NO\n");
        else
           printf("YES\n");
}

int temp(char a){
        int b;
        b=(int)a;
        return b-48;
}
 /*********************************************************************/
int main()
{
    char select[1000];
    LinkedList head = (LinkedList)malloc(sizeof(LNode));/*Ϊͷ������洢�ռ�*/
    head->pre = NULL;
    head->next = NULL;
    head->data = 99999;
    InitList(head);
    printf("�Ѿ���ʼ����һ����10����������������ͷ��㣩\n");
    printf("1����ӡ�����ֵ\n2����ѯ���������Ƿ��ж�Ӧ��ֵ\n");
    printf("3����ѯ�������Ƿ�Ϊѭ������\n4����ѯ�Ƿ�ת����ɹ�\n");
    printf("5�������½��\n6��ɾ����㲢��ȡ�ý���ֵ\n");
    printf("7������10�����\n8��Ѱ���м����ֵ\n0������\nѡ�������");
    scanf("%s",&select);
    while(select[0]!='0'){
       if(select[0]<'0'||select[0]>'8'||select[1]!='\0'){
        printf("\n����������ȷ����:");
        scanf("%s",&select);
    }
    else{
        switch(temp(select[0]))
         {
              case 0: ;break;
              case 1: TraverseList(head,visit);break;
              case 2: search(head);break;
              case 3: IsLoop(head);break;
              case 4: Reverse(&head);break;
              case 5: printf("\n�˹�����ʱ��֪����ô���ֳ���");break;
              case 6: printf("\n�˹�����ʱҲ��֪����ô���ֳ���") ;break;
              case 7: InitList(head) ;break;
              case 8: mid(&head);break;
         }
         printf("\nѡ�����:");
         getchar();
         scanf("%s",&select);
        }
    }
    return 0;
}
