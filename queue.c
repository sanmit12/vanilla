#include<stdio.h>
#include<stdlib.h>
#define max 5
struct queue
{
int a[max];
int front,rear;
};
void enqueue(struct queue *p,int x)
{
if(p->rear==max-1)
printf("overflow");
else if(p->front==-1&& p->rear==-1)
{
p->front++;
p->rear++;
p->a[p->rear]=x;
}
else
{
p->a[++p->rear]=x;
}
}
int dequeue(struct queue *p)
{
int x;
if(p->front==-1&&p->rear==-1)
{
printf("underflow");
return -1;
}
else if (p->front==p->rear)
{


x=p->a[p->front];
p->front==-1;
p->rear==-1;
return x;
}

else
{
x=p->a[p->front];
p->front++;
return x;
}
}
void display(struct queue*p)
{
int i;
if(p->front==-1&&p->rear==-1)
printf("underflow \n");
else
{
for( i =p->front;i<=p->rear;i++)
{
printf("%d\n",p->a[i]);
}
}
}
int main()
{
struct queue s;
s.front=-1;
s.rear=-1;
int x;
int choice;
while(1)
{
printf("Enter 1:enqueue\t 2.dequeue\t 3.dsilpay\t 4. exit\n");
scanf("%d",&choice);
switch(choice)
{

int n;
case 1: printf("Enter value to be entered in list \n");
scanf("%d",&n);
enqueue(&s,n);
break;
case 2: printf("value are denqueue\n");
x=dequeue(&s);
printf("denqueue element is %d \n",x);
break;
case 3: display(&s);
break;
case 4: exit(0);
break;
default: printf("Invalid choice \n");
break;
}
}
}
