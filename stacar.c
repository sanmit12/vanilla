#include<stdio.h>
int top=-1,ch,x,stack[100],y,n;
void push(int);
int pop();
int stacktop();
void display();
int size();
int isfull();
int empty();
void main()
{
printf ("Enter the size of the array");
scanf ("%d",&n);
printf("operations:\n1.push\n2.pop\n3stacktop\n4.display\n5.exit");
do
	{
		printf("Enter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:printf("Enter the elements");
		scanf("%d",&x);
		push(x);
		break;
		case 2:y=pop();
		printf("\n%d",y);
		break;
		case 3:stacktop();
		printf("%d",y);
		break;
		case 4:display();
		break;
		case 5:printf("exit");
		break;
		case 6:y=isfull();
		printf("%d",y);
		break;
		case 7:y=isempty();
		printf("%d",y);
		break;
		case 8:y=size();
		printf("%d",y);
		break;
		default:printf("invalid");
		}
	}
while(ch!=5);
}
void push(int x)
{
if(top==n-1)
printf("\n stack overflow");
else
{
top++;
stack[top]=x;
}	
}
int pop()
{
int y;
if (top==-1)
{
printf("\n stack underflow");
}
else
{
y=stack[top];
top--;
return y;
}
}
int stacktop()
{
if(top==-1)
printf ("empty");
else 
return(stack[top]);
}
void display()
{
int i;
for(i=top;i>=0;i--)
{
printf("%d\t",stack[i]);
printf("\n");
}
}
int size()
{
return(top);
}
int isfull()
{
if(top==4)
return 1;
else
return 0;
}
int isempty()
{
if(top==1)
return 1;
else
return 0;
}
