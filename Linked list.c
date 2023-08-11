#include<stdio.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node *next;
};
struct node *createnode();
struct node *createlist(struct node *);
struct node *display(struct node *);
struct node *insert_begin(struct node *);
struct node *insert_end(struct node *);
struct node *insert_atposition(struct node *);
struct node *insert_beforenode(struct node *);
struct node *insert_afternode(struct node *);
struct node *delete_begin(struct node *);
struct node *delete_end(struct node *);
struct node *delete_specificpos(struct node *);
struct node *delete_specificvalue(struct node *);
struct node *delete_afternode(struct node *);
struct node *sort(struct node *);
struct node *reverse(struct node *);
struct node *concatenate(struct node *,struct node *);
void main()
 {
 int ch,ch1,ch2,ch3,ch4;
 struct node *head=NULL;
 struct node *head1,*head2;
  while(1)
    { 
      printf("\nChoose any operation\n");    
      printf("\n1. Create linked list\n");
      printf("\n2. Insert\n");
      printf("\n3. Delete\n");
      printf("\n4. Display\n");
      printf("\n5. Sort linked list\n");
      printf("\n6. Reverse linked list\n");
      printf("\n7. Merge two linked list\n");
      printf("\n8. Exit\n");
      printf("\nEnter your choice\n");
      scanf("%d",&ch);
  
      switch(ch)
       {
       case 1:
            head=createlist(head);
            printf("\n Linkedlist is created\n");
            break;
       case 2:
        do
        {
       	    printf("\nChoose any operation\n");
            printf("\n1. Insert at the begininig\n");
            printf("\n2. Insert at specific position\n");
            printf("\n3. Insert at the end\n");
            printf("Enter your choice\n");
            scanf("%d",&ch);
            switch(ch)
            {
                case 1:
                       head=insert_begin(head);
		               printf("\n node is inserted at the begining\n");
                       display(head);
                              break;
                case 2:
                   do
                   {
                	   printf("\n choose any operation\n");
                       printf("\n1. Insert at given position\n");
                       printf("\n2. Insert after a given node\n");
                       printf("\n3. Insert before a given node\n");
                       printf("\nEnter your choice\n");
                       scanf("%d",&ch2);
                       switch(ch)
                       {
                           case 1:
                           	      head=insert_atposition(head);
        	                      printf("\n node is inserted\n");
                                  display(head);
                           	      break;
                           case 2:
                                  head=insert_afternode(head);
                                  printf("\n node is inserted\n");
                                  display(head);
                                  break;
                           case 3:
                                   head=insert_beforenode(head);
                                   display(head);
		                           printf("\n node is inserted\n");
                                  break;
                           default:
                                  printf("\n wrong choice\n");
                                  break;
                       
                           
                       }
                    }while(ch!=3);

                    break;
                case 3:
                	   head=insert_end(head);
		               printf("\n node is inserted at the end\n");
                       display(head);
                       break;
                default:
                printf("\n wrong choice\n");
                break;
           }
        }while(ch!=3);
        break;
        case 3:
        do
        {
        printf("\n Choose any operation\n");
        printf("\n1. Delete from Begining\n");
        printf("\n2. Delete from End\n");
        printf("\n3. Delete from any position\n");
        printf("\n Enter your choice\n");
        scanf("%d",&ch);
        switch(ch3)
        {
            case 1:
                   head=delete_begin(head);
                   printf("\n node is deleted from begining\n");
                   display(head);
                   break;
            case 2:
                   head=delete_end(head);
                   printf("\n node is deleted from end\n");
                   display(head);
                   break;
            case 3:
                do
                {
                   printf("\n choose any operation\n");
                   printf("\n1. Delete after a node\n");
                   printf("\n2. Delete node in a specific position\n");
                   printf("\n3. Delete node with specific value\n");
                   printf("\n Enter your choice\n");
                   scanf("%d",&ch);
                   switch(ch4)
                   {
                    case 1:
                          head=delete_afternode(head);
                          printf("\n node is deleted\n");
                          display(head);
                          break;
                    case 2:
                          head=delete_specificpos(head);
                          printf("\n node is deleted\n");
                          display(head);
                          break;
                    case 3:
                          head=delete_specificvalue(head);
                          printf("\n node is deleted\n");
                          display(head);
                          break;
                    default:
                           printf("\n wrong choice\n");
                           break;
                   }
                }while(ch!=4);
                break;
            default:
                     printf("\n wrong choice\n");
                     break;


        }
        }while(ch!=3);
        break;


        case 4:
        	printf("\n Linkedlist elements:\n");
			head=display(head);
			break;
        case 5:
             head=sort(head);
             printf("\n sorted list is\n");
             display(head);
             break;
        case 6:
             head=reverse(head);
             printf("\n list is reversed\n");
             break;
        case 7:
             head1=createlist(head);
             printf("\n list1 is :\n");
             display(head1);
             head2=createlist(head);
             printf("\n list2 is :\n");
             display(head2);
             head1=concatenate(head1,head2);
             printf("\n concatenated list is :\n");
             display(head1);
             break;
       case 8:
            exit(0);
            break;
       default:
            printf("\nInvalid choice\n");
            break;
        }
    

    }
}
   struct node *createnode()
    {
    	struct node *p;
    	p=(struct node *)malloc(sizeof(struct node));
    	p->next=NULL;
    	
	}
	struct node *createlist(struct node *head)
	{
		char ch1;
		head=NULL;
		do
		{
			head=insert_begin(head);
			printf("\nDo you want to continue(y/n)::\t");
			scanf("\n%c",&ch1);
		}while(ch1=='y'|| ch1=='Y');
		return head;
	}
        
 
    struct node *display(struct node *head)
    {
         struct node *ptr,*p;
         if(p==NULL)
         {
            printf("list is empty\n");
         }
          ptr=head;
        while(ptr!=NULL)
        {
            printf("%d -> ", ptr->data);
            ptr=ptr->next;
        }
        printf("NULL\n");
        return head;
    }
 
 
    struct node *insert_begin(struct node *head)
    {
    	
        struct node *p;
        int m;
        p=createnode();
        if(p==NULL)
         {
        	printf("list is empty\n");
		 }
        printf("\n Enter the value : ");
        scanf("%d", &m);
        p->data=m;
        if(head==NULL)
         {
        	head=p;
		 }
		else
		 {
             p->next=head;
             head=p;
         }
        return head;
    }
 
    struct node *insert_end(struct node *head)
    {
    	
        struct node *ptr,*p;
        int m;
        p=createnode();
        if(p==NULL)
        {
        	printf("list is empty\n");
		}
        printf("\n Enter the value : ");
        scanf("%d", &m);
        p->data=m;
        ptr=head;
        while(ptr->next!=NULL)
        {	
            ptr=ptr->next;
        }
            ptr->next=p;
        
        return head;
    }
    
    struct node *insert_atposition(struct node *head)
    {
    	int pos,m;
    	struct node *p,*ptr;
    	p=createnode();
    	if(head==NULL)
    	{
    		printf("list is empty\n");
		}
		printf("\n Enter the value :");
		scanf("%d",&m);
		p->data=m;
		printf("\n Enter the position where the node has to be inserted: ");
		scanf("%d",&pos);
		ptr=head;
		for(int i=0;i<pos-1;i++)
		{
			ptr=ptr->next;
			
		}
		p->next=ptr->next;
		ptr->next=p;
		return head;
    
	}
 
    struct node *insert_beforenode(struct node *head)
    {
    	
        struct node *p,*ptr,*preptr;
        int m, value;
        if(p==NULL)
        {
            printf("\n list is empty\n");
        }
        printf("\n Enter the value : ");
        scanf("%d", &m);
        printf("\n Enter the value before which the data has to be inserted : ");
        scanf("%d", &value);
        p=createnode();
        p->data=m;
        ptr=head;
        while(ptr->data!=value)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=p;
        p->next=ptr;
        return head;
    }
 
    struct node *insert_afternode(struct node *head)
    {
    	
        struct node *p,*ptr,*preptr;
        int m,value;
        if(p==NULL)
        {
            printf("\n list is empty\n");
        }
        printf("\n Enter the value : ");
        scanf("%d", &m);
        printf("\n Enter the value after which the data has to be inserted : ");
        scanf("%d", &value);
        p=createnode();
        p->data=m;
        ptr=head;
        preptr=ptr;
        while(preptr->data!=value)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=p;
        p->next=ptr;
        return head;
    }

    struct node *delete_begin(struct node *head)
        {
            
            struct node *ptr;
            if(head==NULL)
            {
                printf("list is empty\n");
            }
            ptr=head;
            head=head->next;
            free(ptr);
            return head;
        }
 
        struct node *delete_end(struct node *head)
        {
            struct node *ptr,*preptr;
            if(head==NULL)
            {
                printf("list is empty\n");
            }
            ptr=head;
            while(ptr->next!=NULL)
            {
                preptr=ptr;
                ptr=ptr->next;
            }
            preptr->next=NULL;
            free(ptr);
            return head;
        }
 
        struct node *delete_specificvalue(struct node *head)
        {
        
        struct node *ptr,*preptr;
        int value;
        if(head==NULL)
        {
            printf("list is empty\n");
        }
        printf("\n Enter the value of the node which has to be deleted : ");
        scanf("%d", &value);
        ptr=head;
        if(ptr->data==value)
        {
            head=delete_begin(head);
            return head;
        }
        else
        {
            while(ptr->data!=value)
            {
                preptr=ptr;
                ptr=ptr->next;
            }
            preptr->next=ptr->next;
            free(ptr);
            return head;
        }
        }
 
        struct node *delete_afternode(struct node *head)
        {
            
            struct node *ptr,*preptr;
            int value;
            if(head==NULL)
            {
                printf("\n list is empty\n");
            }
            printf("\n Enter the value after which the node has to deleted : ");
            scanf("%d", &value);
            ptr=head;
            preptr=ptr;
            while(preptr->data!=value)
            {
                preptr=ptr;
                ptr=ptr->next;
            }
            preptr->next=ptr->next;
            free(ptr);
            return head;
        }

        struct node *delete_specificpos(struct node *head)
        {
            int pos,i;
            struct node *ptr1,*ptr2;
            ptr1=head;
            printf("\n Enter the position\n");
            scanf("%d",&pos);
            if(head==NULL)
            {
                printf("\n list is empty \n");
            }
            if(pos==1)
            {
                head=ptr1->next;
                free(ptr1);
            }
            for(i=0;i<pos-2;i++)
            {
                ptr1=ptr1->next;
            }
            ptr2=ptr1->next;
            ptr1->next=ptr2->next;
            free(ptr2);
            return head;
        }
 
 
        struct node *reverse(struct node *head)
        {
            struct node *preptr=NULL;
            struct node *ptr,*curr;
            curr=head;
            ptr=head;
            while(curr!=NULL)
            {
                ptr=ptr->next;
                curr->next=preptr;
                preptr=curr;
                curr=ptr;
            }
            head=preptr;
            return head;
       }
       
       struct node *concatenate(struct node *head1,struct node *head2)
       {
            struct node *ptr;
            if(head1==NULL)
            {
                printf("list is empty\n");
                return head2;
            }
            if(head2==NULL)
            {
                printf("list is empty\n");
                return head1;
            }
            ptr=head1;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=head2;
            return head1;
       }

       struct node *sort(struct node *head)
        {
            struct node *ptr1, *ptr2;
            int temp;
            ptr1=head;
            while(ptr1->next!=NULL)
            {
                ptr2= ptr1->next;
                while(ptr2!=NULL)
                {
                    if(ptr1->data>ptr2->data)
                    {
                        temp=ptr1->data;
                        ptr1->data=ptr2->data;
                        ptr2->data=temp;
                    }
                    ptr2=ptr2->next;
                }
                ptr1=ptr1->next;
            }
            return head;
        }


            
        
        
                    
        
 










