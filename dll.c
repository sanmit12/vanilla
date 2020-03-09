


#include<stdio.h>
#include<stdlib.h>
struct node *create_ll();
void traverse(struct node *head);
struct node *insert_end(struct node *head); 
struct node *insert_pos(struct node *head);
struct node *delete_begin(struct node *head);
int count(struct node *head);
struct node *delete_end(struct node *head);
void traverse_back(struct node *head);
struct node *delete_pos(struct node *head);

struct node
{
int data;
struct node *prev;
struct node *next;
};
	struct node *create_ll()
	{
	int data;
	struct node *newnode;
	printf("Enter data\n");
	scanf("%d",&data);
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->prev=NULL;
	newnode->next=NULL;
	return newnode;
	}

	struct node *insert_begin(struct node *head)
	{
	struct node *newnode;
	if(head==NULL)
	{
	head=create_ll();
	}
		else
		{
		newnode=create_ll();
		newnode->next=head;
		head->prev=newnode;
		newnode->prev=NULL;
		head=newnode;
		}
	return head;
	}

	struct node *insert_end(struct node *head)
	{
	struct node *newnode,*tmp;
	if(head==	NULL)
	{
	head=create_ll();
	}
		else
		{
		tmp=head;
		newnode=create_ll();
			while(tmp->next!=NULL)
			{
			tmp=tmp->next;
			}
			tmp->next=newnode;
			newnode->prev=tmp;
		}
		return head;
	}
	struct node *insert_pos(struct node *head)
	{
	int p,i=1,n;
	struct node *newnode,*tmp;
	printf("Enter specific position to enter element\n");
	scanf("%d",&p);
	n=count(head);
	if(p>n)
	printf("Number of nodes are %d. Please enter valid position\n",n);
		else
		{
		tmp=head;
		while(i<p-1)
		{
		tmp=tmp->next;
		i++;
		}
		newnode=create_ll();
		newnode->next=tmp->next;	
		tmp->next=newnode;
		newnode->prev=tmp;
		newnode->next->prev=newnode;
		return head;
		}
	}

	struct node *delete_begin(struct node *head)
	{
	struct node *tmp,*tmp1;
	tmp=head;
	tmp1=tmp->next;
	head=tmp1;
	tmp1->prev=NULL;
	tmp->next=NULL;
	free(tmp);
	return head;
	}
	
	struct node *delete_end(struct node *head)
	{
	struct node *tmp,*tmp1;
	tmp=head;
		while(tmp->next->next!=NULL)
		{
		tmp=tmp->next;
		}
		tmp1=tmp->next;
		tmp->next=NULL;
		tmp1->prev=NULL;
		free(tmp1);
		return head;
	}

	struct node *delete_pos(struct node *head)
	{
	int n,p,i=1;
	struct node *tmp=head,*tmp1;
	printf("Enter specific position\n");
	scanf("%d",&p);
	if(p>n)
	printf("Number of nodes present are %d .Please enter valid positon",n);
		else
		{
		while(i<p-1)
		{
		tmp=tmp->next;
		i++;
		}
		tmp1=tmp->next;
		tmp->next=tmp1->next;
		tmp1->next->prev=tmp1->prev;
		free(tmp1);
		return head;
		}
	}
		
		
	void traverse_front(struct node *head)
	 {
	printf("Linked traversed from front\n");
    	struct node *tmp;
   	 tmp=head;
   		while(tmp!=NULL)
  	 	{
    	 	printf("\t%d",tmp->data);
     		tmp=tmp->next;
   		}
		printf("\n");
	}
		
	void traverse_back(struct node *head)
	{
	struct node *tmp=head;
	while(tmp->next!=NULL)
	{
	tmp=tmp->next;
	}
	while(tmp!=NULL)
	{
	printf("%d\t",tmp->data);
	tmp=tmp->prev;
	}
	}

		int count(struct node *head)
		{
		    int count=0;
		    struct node *current=head;
		    while(current!=NULL)
		    {
		       count++;
		        current=current->next;
		    }
		  return count;
		 }


void main()
{
int ch;
struct node *head=NULL;
printf("Menu\n1.Insert begin\n2.Insert end\n3.Insert at specific position\n4.Delete begin\n5.Delete End\n6.Delete at specific position\n7.Traverse forward\n8.Traverse Backward\n");
	do
	{
	printf("Enter your choice\n");
	scanf("%d",&ch);
		switch(ch)
		{
		case 1:head=insert_begin(head);
		break;
		case 2:head=insert_end(head);
		break;
		case 3:head=insert_pos(head);
		break;
		case 4:head=delete_begin(head);
		break;
		case 5:head=delete_end(head);
		break;
		case 6:head=delete_pos(head);
		break;
		case 7:traverse_front(head);
		break;
		case 8:traverse_back(head);
		break;
		}
	}while(ch!=9);
}
