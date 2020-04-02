#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>


typedef int ElemType;

typedef struct node{ /*封装起来,定义抽象数据类型LNode和*ListNodePtr*/
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
   /* *L = (LinkedList)malloc(sizeof(LNode));/*为头结点分配存储空间
    (*L)->next = NULL;*/
    for(i=0;i<n;i++){
        temp = (LinkedList)malloc(sizeof(LNode));
        if(!temp){  /* 无法为temp分配内存空间    */
            status = error;
            break;
        }
        temp->data = rand()%100+1;/* 随机数*/
        temp->pre = L;
        temp->next = L->next;   /*头插法*/
        L->next = temp;
    }

    return status;
}

void DestroyList(LinkedList L){  /**/
    LinkedList p = L,q = p->next;
    while(q){
        p->next = q->next; /* p的地址一直是L,只是用来更新q*/
        free(q);
        q = p->next;
    }
    free(L);
    printf("\n已经销毁");
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
            printf("此链表没有数");
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
                slow = slow->next; /*走一步*/
                fast = fast->next; /*先走一步*/
                if(fast != NULL){  /*判断走的那一步是否为空*/
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
        printf("输入要查询的数");
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
    LinkedList head = (LinkedList)malloc(sizeof(LNode));/*为头结点分配存储空间*/
    head->pre = NULL;
    head->next = NULL;
    head->data = 99999;
    InitList(head);
    printf("已经初始好了一个有10个结点的链表（不包括头结点）\n");
    printf("1、打印链表的值\n2、查询该链表中是否有对应的值\n");
    printf("3、查询该链表是否为循环链表\n4、查询是否翻转链表成功\n");
    printf("5、插入新结点\n6、删除结点并获取该结点的值\n");
    printf("7、增加10个结点\n8、寻找中间结点的值\n0、结束\n选择操作：");
    scanf("%s",&select);
    while(select[0]!='0'){
       if(select[0]<'0'||select[0]>'8'||select[1]!='\0'){
        printf("\n重新输入正确的数:");
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
              case 5: printf("\n此功能暂时不知道怎么表现出来");break;
              case 6: printf("\n此功能暂时也不知道怎么表现出来") ;break;
              case 7: InitList(head) ;break;
              case 8: mid(&head);break;
         }
         printf("\n选择操作:");
         getchar();
         scanf("%s",&select);
        }
    }
    return 0;
}
