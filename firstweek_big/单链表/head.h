#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

typedef int ElemType;

typedef struct node{ /*��װ����,���������������LNode��*ListNodePtr*/
    ElemType data;
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
    printf("\n�Ѿ�����");
}

Status InsertList(LNode *p, LNode *q){ /* insert q after node p*/
     Status status;
     if(p){
        q->next = p->next;
        p->next = q;
        status = success;
      }
     else
        status = error;
    return status;
}

Status DeleteList(LNode *p, ElemType *e){
      Status status;
      if(p->next){
        status = error;
      }
      else{
        *e = p->next->data;
        p->next = p->next->next;
      }
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

 LNode* ReverseEvenList(LinkedList L){
     LinkedList p = L->next, q = p->next, j = L;
     if(p == NULL || q == NULL){
        printf("�����㽻��������");
        return L;
     }
     else{
          while(p != NULL && q != NULL){
            q = p->next;
            p->next = q->next ;
            q->next = p;
            j->next = q;

            j = p;
            p = p->next;
          }
        }
        printf("�����ɹ�");

     return L;
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
/**********************************************************************/
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
void Reverse(LinkedList L){
        int a;
        a=ReverseList(L);
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
int temp(char a){
        int b;
        b=(int)a;
        return b-48;
}
/**********************************************************************/
#endif // HEAD_H_INCLUDED
