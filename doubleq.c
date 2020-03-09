#include<stdio.h>
int size;
struct queue
{
int x[20];
int f,r;
};
void initialize(struct queue *q)
{
	q->f=q->r=-1;
}
int empty(struct queue *q)
{
	if(q->r==-1 && q->f==-1)
	return 1;
	return 0;
}
int full(struct queue *q)
{
	if(q->f==(q->r+1)%size)
	return 1;
	return 0;
}
void insert_rear(struct queue *q,int ele)
{
if(full(q))
printf("Overflow\n");
	else if(empty(q))
	{
	q->f=q->r=0;
	q->x[q->r]=ele;
	}
		else
		{
		q->r=(q->r+1)%size;
		q->x[q->r]=ele;
		}
}
void insert_front(struct queue*q,int ele)
{
if(full(q))
printf("Overflow\n");
	else if(empty(q))
	{
	q->f=q->r=0;
	q->x[q->f]=ele;
	}
		else
		{
		q->f=(q->f-1+size)%size;
		q->x[q->f]=ele;
		}
}
void remove_front(struct queue *q)
{
if(empty(q))
printf("Queue is empty\n");
	else if(q->f==q->r)
	{
	printf("Removed element is %d ",q->x[q->f]);
	q->f=q->r=-1;
	}
		else
		{
		printf("Removed element is %d ",q->x[q->f]);
		q->f=(q->f+1)%size;
		}
}
void remove_rear(struct queue *q)
{
if(empty(q))
printf("Queue is empty\n");
	else if(q->f==q->r)
	{
	printf("Removed element is %d",q->x[q->r]);
	q->f=q->r=-1;
	}
		else
		{
		printf("Removed element is %d",q->x[q->r]);
		q->r=(q->r-1+size)%size;
		}
}

void display(struct queue *q)
{
int i;
if(empty(q))
printf("Queue is empty\n");
	else
	{
	for(i=q->f;i!=q->r;i=(i+1)%size)
	{
	printf("%d\t",q->x[i]);
	}
	printf("%d\t\n",q->x[q->r]);
	}
}

void main()
{
struct queue d;
struct queue *q=&d;
int ch,ele;
initialize(&d);
printf("Enter size of queue\n");
scanf("%d",&size);
printf("Menu:\n1.Insert rear\n2.Insert front\n3.Remove rear\n4.Remove front\n5.Display\n6.Exit\n");
do
{
printf("Enter choice\n");
scanf("%d",&ch);
	switch(ch)
	{
	case 1:printf("Enter the element to be inserted\n");
	scanf("%d",&ele);
	insert_rear(&d,ele);
	break;
	case 2:printf("Enter the element to be inserted\n");
	scanf("%d",&ele);
	insert_front(&d,ele);
	break;
	case 3:remove_rear(&d);
	break;
	case 4:remove_front(&d);
	break;
	case 5:display(&d);
	break;
	case 6:printf("Exit\n");
	break;

	}
}while(ch!=6);
}