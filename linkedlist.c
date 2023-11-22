/* 1 and 2
#include <stdio.h>
#include <stdlib.h>
struct Node{
int data;
struct Node* next;
};
void insert_beginning(struct Node* head,int value)
{
struct Node* l=head;
struct Node* x=(struct Node*)malloc(sizeof(struct Node));
x->data=value;
x->next=head;
l=x;
while(x)
{
printf("%d",x->data);
x=x->next;
}
free(x);
printf("\n");
}
void insert_end(struct Node* head,int value)
{
struct Node* p=head;
while(p->next)
p=p->next;
p->next=(struct Node*)malloc(sizeof(struct Node));
p->next->data=value;
p->next->next=NULL;
struct Node* x=head;
while(x)
{
printf("%d",x->data);
x=x->next;
}
free(p->next);
p->next=NULL;
printf("\n");
}
void insert_between(struct Node* head,int k,int value)
{
struct Node* x=head;
int c=0;
struct Node* j=NULL;
while(x)
{
c++;
if(c==k-1)
{
j=x->next;
x->next=(struct Node*)malloc(sizeof(struct Node));
x->next->data=value;
x->next->next=j;
break;
}
x=x->next;
}
struct Node* l=head;
while(l)
{
printf("%d",l->data);
l=l->next;
}
printf("\n");
struct Node* p=x->next;
free(p);
x->next=j;
}
void delete_beginning(struct Node* head)
{
struct Node* x=head;
head=head->next;
free(x);
struct Node* l=head;
while(l)
{
printf("%d",l->data);
l=l->next;
}
printf("\n");
}
int delete_end(struct Node* head)
{
struct Node* l=head;
while(l->next->next)
{
printf("%d",l->data);
l=l->next;
}
printf("%d",l->data);
int ans=l->next->data;
printf("\n");
l->next=NULL;
return ans;
}
void delete_between(struct Node* head,int k)
{
int c=0;
struct Node* x=head;
while(x)
{
c++;
if(c==k)
{
struct Node* p=x->next;
x->data=x->next->data;
x->next=p->next;
free(p);
break;
}
x=x->next;
}
struct Node* l=head;
while(l)
{
printf("%d",l->data);
l=l->next;
}
printf("\n");
return;
}
int main()
{
int n,k,value;
scanf("%d",&n);
printf("value=");
scanf("%d",&value);
printf(",");
printf("k=");
scanf("%d",&k);
int c;
scanf("%d",&c);
struct Node* p=NULL;
struct Node* head=(struct Node*)malloc(sizeof(struct Node));
head->data=c;
p=head;
for(int i=1;i<n;i++)
{
int c;
scanf("%d",&c);
p->next=(struct Node*)malloc(sizeof(struct Node));
p->next->data=c;
p=p->next;
}
p->next=NULL;
insert_beginning(head,value);
insert_end(head,value);
insert_between(head,k,value);
int val=head->data;
struct Node* newHead=head->next;
delete_beginning(head);
struct Node* l=newHead;
struct Node* x=(struct Node*)malloc(sizeof(struct Node));
x->data=val;
x->next=newHead;
l=x;
int lastnodeval=delete_end(x);
struct Node* b=x;
while(b->next)
b=b->next;
b->next=(struct Node*)malloc(sizeof(struct Node));
b->next->data=lastnodeval;
b->next->next=NULL;
delete_between(x,k);
return 0;
}*/
/* 3
#include <stdio.h>
#include <stdlib.h>
struct Node{
int data;
struct Node *next;
};
int main()
{
int n,value;
scanf("%d",&n);
struct Node* head=(struct Node*)malloc(sizeof(struct Node));
scanf("%d",&value);
head->data=value;
struct Node* l=head;
for(int i=1;i<n;i++)
{
int value;
scanf("%d",&value);
l->next=(struct Node*)malloc(sizeof(struct Node));
l->next->data=value;
l=l->next;
}
l->next=NULL;
struct Node* sorted=(struct Node*)malloc(sizeof(struct Node));
struct Node* k=head;
sorted->next=NULL;
for(int i=0;i<n;i++)
{
struct Node* z=sorted->next;
struct Node* d=sorted;
while(z && z->data<=k->data)
{
d=z;
z=z->next;
}
struct Node* h=z;
d->next=(struct Node*)malloc(sizeof(struct Node));
d->next->data=k->data;
d->next->next=h;
k=k->next;
}
struct Node* u=sorted->next;
while(u)
{
printf("%d",u->data);
u=u->next;
}
return 0;
}*/
/* 4
#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
int main()
{
int n,value;
scanf("%d",&n);
struct Node* head=(struct Node*)malloc(sizeof(struct Node));
scanf("%d",&value);
head->data=value;
struct Node* p=head;
for(int i=1;i<n;i++)
{
int value;
scanf("%d",&value);
p->next=(struct Node*)malloc(sizeof(struct Node));
p->next->data=value;
p=p->next;
}
p->next=NULL;
struct Node* b=(struct Node*)malloc(sizeof(struct Node));
struct Node* a=b;
b->next=head;
struct Node* d=head;
struct Node* c=head->next;
while(c)
{
d->next=a;
a=d;
d=c;
c=c->next;
}
d->next=a;
a=d;
head->next=NULL;
while(a)
{
printf("%d",a->data);
a=a->next;
}
return 0;
}*/
/* 5
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define min(X, Y) (((X) < (Y)) ? (X) : (Y))
#define max(X, Y) (((X) > (Y)) ? (X) : (Y))
struct Node{
int data;
struct Node *next
};
int main()
{
int n,value;
scanf("%d",&n);
struct Node* head=(struct Node*)malloc(sizeof(struct Node));
scanf("%d",&value);
head->data=value;
struct Node* l=head;
for(int i=1;i<n;i++)
{
int value;
scanf("%d",&value);
l->next=(struct Node*)malloc(sizeof(struct Node));
l->next->data=value;
l=l->next;
}
l->next=NULL;
int maximum=0,minimum=INT_MAX;
struct Node* f=head;
while(f)
{
maximum=max(f->data,maximum);
minimum=min(f->data,minimum);
f=f->next;
}
printf("Maximum:%d, Minimum:%d, Maximum-Minimum:%d",maximum,minimum,maximum-minimum);
return 0;
}*/
/* 6
#include <stdio.h>
#include <stdlib.h>
struct Node{
int data;
struct Node* prev;
struct Node* next;
};
int main()
{
int n,sum=0;
scanf("%d",&n);
int value;
struct Node* head=(struct Node*)malloc(sizeof(struct Node));
scanf("%d",&value);
head->data=value;
if(value%2==0)
sum=sum+value;
struct Node* p=head;
for(int i=1;i<n;i++)
{
int value;
scanf("%d",&value);
if(value%2==0)
sum=sum+value;
p->next=(struct Node*)malloc(sizeof(struct Node));
p->next->prev=p;
p->next->data=value;
p=p->next;
}
p->next=head;
head->prev=p;
return sum;
}*/
/* 7 and 8
#include <stdio.h>
#include <stdlib.h>
#define min(X,Y) ((X<Y)?X:Y)
struct Node{
int data;
struct Node* prev;
struct Node* next;
};
int main()
{
int n,minimum;
scanf("%d",&n);
int value;
struct Node* head=(struct Node*)malloc(sizeof(struct Node));
scanf("%d",&value);
head->data=value;
minimum=min(minimum,value);
struct Node* p=head;
for(int i=1;i<n;i++)
{
int value;
scanf("%d",&value);
minimum=min(minimum,value);
p->next=(struct Node*)malloc(sizeof(struct Node));
p->next->prev=p;
p->next->data=value;
p=p->next;
}
p->next=NULL;
head->prev=NULL;
struct Node* k=head;
while(k)
{
printf("%d and ",k->data);
if(k->prev)
printf("%d 's previous is %d",k->data,k->prev->data);
printf("\n");
k=k->next;
}
printf("minimum value is: %d",minimum);
return 0;
}*/
/* 9
#include <stdio.h>
#include <stdlib.h>
#define min(X,Y) ((X<Y)?X:Y)
struct Node{
int data;
struct Node* prev;
struct Node* next;
};
int main()
{
int n,minimum;
scanf("%d",&n);
int value;
struct Node* head=(struct Node*)malloc(sizeof(struct Node));
scanf("%d",&value);
head->data=value;
minimum=min(minimum,value);
struct Node* p=head;
for(int i=1;i<n;i++)
{
int value;
scanf("%d",&value);
minimum=min(minimum,value);
p->next=(struct Node*)malloc(sizeof(struct Node));
p->next->prev=p;
p->next->data=value;
p=p->next;
}
p->next=NULL;
head->prev=NULL;
struct Node* k=head;
struct Node* t=NULL;
while(k)
{
t=k;
if(k->data==minimum)
{
struct Node* j=k->next;
t->next=j;
j->prev=t;
free(k);
k=j;
}
else {
printf("%d",k->data);
k=k->next;
}
}
return 0;
}*/
/* 10
#include <stdio.h>
#include <stdlib.h>
struct Node{
int data;
struct Node* prev;
struct Node* next;
};
int main()
{
int n,minimum;
scanf("%d",&n);
int value;
struct Node* head=(struct Node*)malloc(sizeof(struct Node));
scanf("%d",&value);
head->data=value;
struct Node* p=head;
for(int i=1;i<n;i++)
{
int value;
scanf("%d",&value);
p->next=(struct Node*)malloc(sizeof(struct Node));
p->next->prev=p;
p->next->data=value;
p=p->next;
}
p->next=NULL;
head->prev=NULL;
struct Node* k=head;
struct Node* t=NULL;
while(k->next)
k=k->next;
struct Node* j=k;
while(j)
{
struct Node* b=j->next;
j->next=j->prev;
j->prev=b;
j=j->next;
}
while(k)
{
printf("%d",k->data);
k=k->next;
}
return 0;
}*/
/* 11
#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
int main()
{
int n,value,k;
scanf("%d",&n);
scanf("%d",&k);
struct Node* head=(struct Node*)malloc(sizeof(struct Node));
scanf("%d",&value);
head->data=value;
struct Node* p=head;
for(int i=1;i<n;i++)
{
int value;
scanf("%d",&value);
p->next=(struct Node*)malloc(sizeof(struct Node));
p->next->data=value;
p=p->next;
}
p->next=NULL;
struct Node* s=head;
int c=0;
while(s)
{
if(c%k==0)
printf("%d ",s->data);
c++;
s=s->next;
}
return 0;
}*/
/* 12
#include <stdio.h>
#include <stdlib.h>
struct Node{
int data;
struct Node* prev;
struct Node* next;
};
int main()
{
int n,k;
scanf("%d",&n);
scanf("%d",&k);
int value;
struct Node* head=(struct Node*)malloc(sizeof(struct Node));
scanf("%d",&value);
head->data=value;
struct Node* p=head;
for(int i=1;i<n;i++)
{
int value;
scanf("%d",&value);
p->next=(struct Node*)malloc(sizeof(struct Node));
p->next->prev=p;
p->next->data=value;
p=p->next;
}
p->next=head;
head->prev=p;
struct Node* h=head;
int arr[n],c=0;
for(int i=0;i<n;i++)
arr[i]=0;
while(h)
{
if(c%k==0 && arr[c%n]==0)
{
printf("%d ",h->data);
arr[c%n]=1;
}
c++;
h=h->next;
}
return 0;
}*/
/* 13
#include <stdio.h>
#include <stdlib.h>
struct Node{
int data;
struct Node *next;
};
int main()
{
int n,value;
scanf("%d",&n);
struct Node* head=(struct Node*)malloc(sizeof(struct Node));
scanf("%d",&value);
head->data=value;
struct Node* l=head;
for(int i=1;i<n;i++)
{
int value;
scanf("%d",&value);
l->next=(struct Node*)malloc(sizeof(struct Node));
l->next->data=value;
l=l->next;
}
l->next=NULL;
struct Node *ptr1,*ptr2,*dup;
ptr1=head;
while(ptr1!=NULL && ptr1->next!=NULL){
ptr2=ptr1;
while(ptr2->next!=NULL)
{
if(ptr1->data==ptr2->next->data)
{
dup=ptr2->next;
ptr2->next=ptr2->next->next;
free(dup);
}
else
ptr2=ptr2->next;
}
ptr1=ptr1->next;
}
struct Node* h=head;
while(h)
{
printf("%d ",h->data);
h=h->next;
}
return 0;
}*/
/* 14
#include <stdio.h>
#include <stdlib.h>
struct Node{
int data;
struct Node *next;
};
int main()
{
int n,value,k;
scanf("%d",&n);
scanf("%d",&k);
struct Node* head=(struct Node*)malloc(sizeof(struct Node));
scanf("%d",&value);
head->data=value;
struct Node* l=head;
for(int i=1;i<n;i++)
{
int value;
scanf("%d",&value);
l->next=(struct Node*)malloc(sizeof(struct Node));
l->next->data=value;
l=l->next;
}
l->next=NULL;
  if(!head || !head->next)
  {
    printf("%d",head->data);
    return 0;
  }
    struct Node* dummy=(struct Node*)malloc(sizeof(struct Node));
    dummy->next=head;
    struct Node* x=head;
    struct Node* p=dummy;
    while(n>=k){
    struct Node* a=p->next;
    struct Node* b=a->next;
    for(int i=1;i<k;i++){
    a->next=b->next;
    b->next=p->next;
    p->next=b;
    b=a->next;
    }
    p=a;
    n-=k;
    }
    if(n>0)
    {
    struct Node* a=p->next;
    struct Node* b=a->next;
    for(int i=1;i<n;i++){
    a->next=b->next;
    b->next=p->next;
    p->next=b;
    b=a->next;
    }
    p=a;
    }
    struct Node* c=dummy->next;
    while(c)
    {
    printf("%d ",c->data);
    c=c->next;
    }
    return 0;
    }*/
/* 15
#include <stdio.h>
#include <stdlib.h>
struct Node{
int data;
struct Node *next;
};
int main()
{
int n,value;
scanf("%d",&n);
struct Node* head=(struct Node*)malloc(sizeof(struct Node));
scanf("%d",&value);
head->data=value;
struct Node* l=head;
for(int i=1;i<n;i++)
{
int value;
scanf("%d",&value);
l->next=(struct Node*)malloc(sizeof(struct Node));
l->next->data=value;
l=l->next;
}
l->next=NULL;
struct Node* d=(struct Node*)malloc(sizeof(struct Node));
struct Node* h=d;
struct Node* p=head;
if(!p ||!p->next)
{
printf("%d",p->data);
return;
}
while(p && p->next)
{
h->next=p;
if(p->next->data>p->data)
{
h->next=p->next;
free(p);
p=h->next;
continue;
}
printf("%d ",p->data);
p=p->next;
}
printf("%d ",p->data);
return 0;
}*/
/* 16
#include <stdio.h>
#include <stdlib.h>
struct Node{
int data;
struct Node *next;
};
int main()
{
int n,value;
scanf("%d",&n);
struct Node* head=(struct Node*)malloc(sizeof(struct Node));
scanf("%d",&value);
head->data=value;
struct Node* l=head;
for(int i=1;i<n;i++)
{
int value;
scanf("%d",&value);
l->next=(struct Node*)malloc(sizeof(struct Node));
l->next->data=value;
l=l->next;
}
l->next=NULL;
struct Node* k=head;
if(!k || !k->next)
{
printf("%d",k->data);
return;
}
while(k->next)
{
printf("%d ",k->data);
struct Node* j=k->next;
k->next=k->next->next;
k=k->next;
free(j);
}
return 0;
}*/
/* 17
#include <stdio.h>
#include <stdlib.h>
struct Node{
int data;
struct Node *next;
};
int main()
{
int n,value;
scanf("%d",&n);
struct Node* head=(struct Node*)malloc(sizeof(struct Node));
scanf("%d",&value);
head->data=value;
struct Node* l=head;
for(int i=1;i<n;i++)
{
int value;
scanf("%d",&value);
l->next=(struct Node*)malloc(sizeof(struct Node));
l->next->data=value;
l=l->next;
}
l->next=NULL;
struct Node* current = head;
struct Node* prev = NULL;
while (current != NULL && current->next != NULL) {
struct Node* firstNode = current;
struct Node* secondNode = current->next;
firstNode->next = secondNode->next;
secondNode->next = firstNode;
if (prev == NULL) {
head = secondNode;
}
else {
prev->next = secondNode;
}
prev = firstNode;
current = firstNode->next;
}
struct Node* x=head;
while(x)
{
printf("%d ",x->data);
x=x->next;
}
return 0;
}*/
/* 18
#include <stdio.h>
#include <stdlib.h>
struct Node{
int data;
struct Node *next;
};
int main()
{
int n,value;
scanf("%d",&n);
struct Node* head=(struct Node*)malloc(sizeof(struct Node));
scanf("%d",&value);
head->data=value;
struct Node* l=head;
for(int i=1;i<n;i++)
{
int value;
scanf("%d",&value);
l->next=(struct Node*)malloc(sizeof(struct Node));
l->next->data=value;
l=l->next;
}
l->next=NULL;
int middle;
if(n%2==0)
middle=n/2;
else
middle=n/2;
struct Node* x=head;
int c=0;
while(x)
{
if(c==middle)
printf("%d",x->data);
c++;
x=x->next;
}
return 0;
}*/
/* 19
#include <stdio.h>
#include <stdlib.h>
struct Node{
char data;
struct Node *next;
};
int main()
{
int n;
char value;
scanf("%d",&n);
struct Node* head=(struct Node*)malloc(sizeof(struct Node));
scanf(" %c",&value);
head->data=value;
struct Node* l=head;
for(int i=1;i<n;i++)
{
char value;
scanf(" %c",&value);
l->next=(struct Node*)malloc(sizeof(struct Node));
l->next->data=value;
l=l->next;
}
l->next=NULL;
struct Node* x=head;
char str[n+1];
int k=0;
while(x)
{
str[k++]=x->data;
x=x->next;
}
int i=0,j=n-1;
while(i<j)
{
if(str[i]==str[j])
{
i++;
j--;
}
else
{
printf("not palindrome");
return 0;
}
}
printf("palindrome");
return 0;
}*/
/* 20
#include <stdio.h>
#include <stdlib.h>
struct Node{
int data;
struct Node *next;
};
int main()
{
int n;
int value;
scanf("%d",&n);
struct Node* head=(struct Node*)malloc(sizeof(struct Node));
scanf("%d",&value);
head->data=value;
struct Node* l=head;
for(int i=1;i<n;i++)
{
int value;
scanf("%d",&value);
l->next=(struct Node*)malloc(sizeof(struct Node));
l->next->data=value;
l=l->next;
}
l->next=NULL;
int freq[1000]={0};
struct Node* x=head;
while(x)
{
freq[x->data]++;
x=x->next;
}
struct Node* p=head;
while(p)
{
if(freq[p->data]>0)
{
printf("freq(%d) = %d\n",p->data,freq[p->data]);
freq[p->data]=0;
}
p=p->next;
}
return 0;
}*/
/* 21
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
int data;
struct Node* prev;
struct Node* next;
};

void freeList(struct Node* head) {
if (head == NULL) return;
struct Node* current = head;
do {
struct Node* temp = current;
current = current->next;
free(temp);
    } while (current != head);
}

int main() {
int n, n1;
scanf("%d", &n);
if(n <= 0) {
printf("Invalid input for 'n'\n");
return 1; // Return an error code
}

int value;
struct Node* head = (struct Node*)malloc(sizeof(struct Node));
scanf("%d", &value);
head->data = value;
struct Node* p = head;

for(int i = 1; i < n; i++) {
int value;
scanf("%d", &value);
p->next = (struct Node*)malloc(sizeof(struct Node));
p->next->prev = p;
p->next->data = value;
p = p->next;
}
p->next = head;
head->prev = p;
scanf("%d", &n1);
if(n1 <= 0) {
printf("Invalid input for 'n1'\n");
freeList(head);
return 1; // Return an error code
}
int value1;
struct Node* head1 = (struct Node*)malloc(sizeof(struct Node));
scanf("%d", &value1);
head1->data = value1;
struct Node* p1 = head1;

for(int i = 1; i < n1; i++) {
int value;
scanf("%d", &value);
p1->next = (struct Node*)malloc(sizeof(struct Node));
p1->next->prev = p1;
p1->next->data = value;
p1 = p1->next;
}

p1->next = head1;
head1->prev = p1;
int maximum1 = INT_MIN, maximum2 = INT_MIN;
struct Node* maxNode1 = NULL;
struct Node* maxNode2 = NULL;
struct Node* x = head;
do {
if(x->data > maximum1) {
maximum1 = x->data;
maxNode1 = x;
}
x = x->next;
} while (x != head);
struct Node* y = head1;
do {
if(y->data > maximum2) {
maximum2 = y->data;
maxNode2 = y;
}
y = y->next;
} while (y != head1);
maxNode2->prev->next = maxNode1->next;
maxNode1->next->prev = maxNode2->prev;
maxNode1->next = maxNode2;
maxNode2->prev = maxNode1;
x = head;
do {
printf("%d ", x->data);
x = x->next;
} while (x != head);
freeList(head);
free(head1);
return 0;
}*/
/* 22
#include <stdio.h>
#include <stdlib.h>
struct Node{
int data;
struct Node *next;
};
int main()
{
int n,value;
scanf("%d",&n);
if(n<1)
return 0;
struct Node* head=(struct Node*)malloc(sizeof(struct Node));
scanf("%d",&value);
head->data=value;
struct Node* l=head;
for(int i=1;i<n;i++)
{
int value;
scanf("%d",&value);
l->next=(struct Node*)malloc(sizeof(struct Node));
l->next->data=value;
l=l->next;
}
l->next=NULL;
int n1,value1;
scanf("%d",&n1);
if(n1<1)
return 0;
if(n1>n)
return 0;
struct Node* head1=(struct Node*)malloc(sizeof(struct Node));
scanf("%d",&value1);
head1->data=value1;
struct Node* y=head1;
for(int i=1;i<n1;i++)
{
int value;
scanf("%d",&value);
y->next=(struct Node*)malloc(sizeof(struct Node));
y->next->data=value;
y=y->next;
}
y->next=NULL;
struct Node* x=head;
y=head1;
int count=0;
while(x)
{
if(!y)
{
x=x->next;
continue;
}
if(y && (count%2==0))
{
struct Node* j=x->next;
x->next=y;
x=j;
count++;
continue;
}
if(y && (count%2==1))
{
struct Node* k=y->next;
y->next=x;
y=k;
count++;
continue;
}
}
x=head;
while(x)
{
printf("%d",x->data);
x=x->next;
}
return 0;
}*/
/* 23
#include <stdio.h>
#include <stdlib.h>
struct Node{
int data;
struct Node *next;
};
int main()
{
int n,value,k;
scanf("%d",&n);
if(n<1)
return 0;
scanf("%d",&k);
struct Node* head=(struct Node*)malloc(sizeof(struct Node));
scanf("%d",&value);
head->data=value;
struct Node* l=head;
for(int i=1;i<n;i++)
{
int value;
scanf("%d",&value);
l->next=(struct Node*)malloc(sizeof(struct Node));
l->next->data=value;
l=l->next;
}
l->next=NULL;
struct Node* p=head;
struct Node* x1=NULL;
int count=1;
while(p)
{
if(count==k)
x1=p;
if(count==n-k+1)
{
int temp=p->data;
p->data=x1->data;
x1->data=temp;
break;
}
count++;
p=p->next;
}
p=head;
while(p)
{
printf("%d ",p->data);
p=p->next;
}
return 0;
}*/
/* 24
#include <stdio.h>
#include <stdlib.h>
struct Node{
int data;
struct Node *next;
};
void add_list(struct Node* head)
{
struct Node* k=head->next;
struct Node* head1=(struct Node*)malloc(sizeof(struct Node));
head1->data=head->data;
struct Node* y=head1;
while(k)
{
struct Node* h=(struct Node*)malloc(sizeof(struct Node));
h->data=k->data;
y->next=h;
y=y->next;
k=k->next;
}
y->next=NULL;
k=head;
while(k->next)
k=k->next;
k->next=head1;
}
int main()
{
int n,value;
scanf("%d",&n);
if(n<1)
return 0;
struct Node* head=(struct Node*)malloc(sizeof(struct Node));
scanf("%d",&value);
head->data=value;
struct Node* l=head;
for(int i=1;i<n;i++)
{
int value;
scanf("%d",&value);
l->next=(struct Node*)malloc(sizeof(struct Node));
l->next->data=value;
l=l->next;
}
l->next=NULL;
add_list(head);
struct Node* j=head;
while(j)
{
printf("%d ",j->data);
j=j->next;
}
return 0;
}*/
/* 25
#include <stdio.h>
#include <stdlib.h>
struct Node{
int data;
int power;
struct Node *next;
};
int main()
{
int n,value,power1;
scanf("%d",&n);
if(n<1)
return 0;
struct Node* head=(struct Node*)malloc(sizeof(struct Node));
scanf("%d",&value);
scanf("%d",&power1);
head->data=value;
head->power=power1;
struct Node* l=head;
for(int i=1;i<n;i++)
{
int value,power1;
scanf("%d",&value);
scanf("%d",&power1);
l->next=(struct Node*)malloc(sizeof(struct Node));
l->next->data=value;
l->next->power=power1;
l=l->next;
}
l->next=NULL;
int n1,value1,power2;
scanf("%d",&n1);
if(n1<1)
return 0;
struct Node* head1=(struct Node*)malloc(sizeof(struct Node));
scanf("%d",&value1);
scanf("%d",&power2);
head1->data=value1;
head1->power=power2;
struct Node* x=head1;
for(int i=1;i<n1;i++)
{
int value,power2;
scanf("%d",&value);
scanf("%d",&power2);
x->next=(struct Node*)malloc(sizeof(struct Node));
x->next->data=value;
x->next->power=power2;
x=x->next;
}
x->next=NULL;
l=head;
x=head1;
struct Node* dummy=(struct Node*)malloc(sizeof(struct Node));
struct Node* d=dummy;
while(l || x)
{
if(l && x && (l->power==x->power))
{
d->next=(struct Node*)malloc(sizeof(struct Node));
d->next->data=l->data+x->data;
d->next->power=l->power;
l=l->next;
x=x->next;
}
else if((l && x && l->power>x->power) || (!x))
{
d->next=(struct Node*)malloc(sizeof(struct Node));
d->next->data=l->data;
d->next->power=l->power;
l=l->next;
}
else
{
d->next=(struct Node*)malloc(sizeof(struct Node));
d->next->data=x->data;
d->next->power=x->power;
x=x->next;
}
d=d->next;
}
d->next=NULL;
struct Node* v=dummy->next;
while(v)
{
printf("coefficient: %d, power: %d\n", v->data, v->power);
v=v->next;
}
return 0;
}*/
/* 27
#include <stdio.h>
#include <stdlib.h>

struct Node {
int data;
int nextIndex;
};
#define MAX_NODES 100

struct Node linkedList[MAX_NODES];
int freeList = 0;

void initializeLinkedList() {
for (int i = 0; i < MAX_NODES - 1; i++) {
linkedList[i].nextIndex = i + 1;
}
linkedList[MAX_NODES - 1].nextIndex = -1;
}

int malloc_arr(int data) {
if(freeList == -1) {
printf("Error: Linked list is full.\n");
return -1;
}
int newIndex = freeList;
freeList = linkedList[freeList].nextIndex;
linkedList[newIndex].data = data;
linkedList[newIndex].nextIndex = -1;
return newIndex;
}

void free_arr(int index) {
if(index < 0 || index >= MAX_NODES) {
printf("Error: Invalid index.\n");
return;
}
linkedList[index-1].nextIndex = linkedList[index].nextIndex ;
freeList = index;
}

void printLinkedList() {
    int currentIndex = 0;
    while (currentIndex != -1) {
        if (linkedList[currentIndex].data != 0) {
            printf("%d ", linkedList[currentIndex].data);
        }
        currentIndex = linkedList[currentIndex].nextIndex;
    }
    printf("\n");
}

int main() {
initializeLinkedList();

int node1 = malloc_arr(10);
int node2 = malloc_arr(20);
int node3 = malloc_arr(30);

linkedList[node1].nextIndex = node2;
linkedList[node2].nextIndex = node3;

printf("Linked List: ");
printLinkedList();

free_arr(node2);

printf("Linked List after freeing node2: ");
printLinkedList();
return 0;
}*/
