#include<stdio.h>
#include<stdlib.h>
int ch;
struct node *create_ll();
struct node *insert_begin(struct node * head);
struct node *insert_end(struct node * head);
struct node *insert_pos(struct node *head);
struct node *delete_end(struct node *head);
struct node *delete_begin(struct node *head);
struct node *traverse(struct node *head);
struct node *delete_position(struct node *head,int p);
	struct node
	{
 	int data;
	 struct node * next;
	};
		
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


                 		  struct node * create_ll()
		 {
   	 	 struct node *newnode;
		 int data;
	 	 printf("\nEnter the data ");
	  	 scanf("%d",&data);
	 	 newnode=(struct node *)malloc(sizeof(struct node));
	  	 newnode->data=data;
		 newnode->next=NULL;
		 return newnode;
		}
  		
											
		struct node * insert_begin(struct node * head)
		{
		 struct node *newnode,*tmp;
		if(head==NULL)
		{
		  head=create_ll();
		}
			else
			{
			 newnode=create_ll();
			newnode->next=head;
			head=newnode;
			}
		return head; 
		}


		struct node * insert_end(struct node * head)
		{
  		struct node *newnode,*tmp;
 		if(head==NULL)
  		{
    		head=create_ll();
  		 }
  			else
			 {
   			tmp=head;	
			while(tmp->next!=NULL)
   			{
     			tmp=tmp->next;
			}
			newnode=create_ll();
    			tmp->next=newnode;
   			
			}
 		 return head;
			 
		}

		struct node * insert_pos(struct node *head)
		{
		  struct node *newnode,*tmp;
                                         int length;
		  length=count(head);
		  int p,i=0;
		  printf("Enter the position to insert the element");
		  scanf("%d",&p);
		  if(head==NULL)
		{
		  head=create_ll();
		}
			else if(p==1)
			{
		   	head=create_ll();
			 }
				else if(p>length)
				{
				 printf("Invalid position");
				printf("No of nodes are %d",length);
				}
					else
					{
					tmp=head;
					while(i<p-2)
					{
					tmp=tmp->next;
					i++;
					}
					newnode=create_ll();
					newnode->next=tmp->next;
					tmp->next=newnode;
					}
					return head;
		}
					
		struct node * delete_end(struct node *head)
		{
 		 struct node *tmp,*tmp1;
			if(head==NULL)
			{
			printf("\nEmpty");
			}

 				else 
   		 		{
      				tmp=head;
      				while(tmp->next!=NULL)
      		 		{
          				tmp1=tmp;
          				tmp=tmp->next;
       				}
      				tmp1->next=NULL;
				printf("Deleted element is %d",tmp->data);
      				free(tmp);
       		 		return head;
    				}
    
		  }

	 struct node *delete_begin(struct node *head)
	{
  	struct node *tmp;
 		 if(head!=NULL)
 		 {
   		 tmp=head;
   		 head=tmp->next;
    		tmp->next=NULL;
		printf("Deleted element is %d",tmp->data);
   		 free(tmp);
		return head;
  		}
			 else
 			{
  			printf("Empty");
  			 return NULL;
  			}
	}

	struct node *traverse(struct node *head)
	 {
    	struct node *tmp;
   	 tmp=head;
   		while(tmp!=NULL)
  	 	{
    	 	printf("\t%d",tmp->data);
     		tmp=tmp->next;
   		}
   		return head;
	}

	struct node *delete_position(struct node *head,int p)
	{  int len;
	len=count(head); 
	struct node *tmp,*tmp1;
	int i=0;
	tmp=head;
		if(head==NULL)
		{
		printf("\nEmpty");
		return NULL;
		}
			else if(p==1)
			{
			head=tmp->next;
			printf("Deleted element is %d",tmp->data);
			free(tmp);
			return head;
			}
				else if(p>len)
				{
				printf("\nInvalid location");
				printf("\nNumber of nodes present are %d",len);
				}
					else
					{
					while(i<p-2)
					{

					tmp=tmp->next;
					i++;
					}
					tmp1=tmp->next;
            

					tmp->next=tmp1->next;
					tmp1->next=NULL;
					printf("Deleted element is %d",tmp1->data);
					free(tmp1);



					}
					return head;
		}

void main()
{
 struct node *head=NULL;
int p;

 printf("MENU:\n1.Insert Begin\n2.Insert end\n3.Insert at specific position\n4.Delete end\n5.Delete begin\n6.Delete at specific postion\n7.Display\n8.Exit\n");
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
      case 4:head=delete_end(head);
             break;
      case 5:head=delete_begin(head);
             break;
      case 6:printf("Enter position");
	scanf("%d",&p);
	head=delete_position(head,p);
	break;
      case 7:traverse(head);
             break;
  default:printf("Invalid");
    }
   }
   while(ch!=8);
}


