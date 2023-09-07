#include <stdio.h>
#include <stdlib.h>

void create ();
void display();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();


int main()
{
        int choice;
        while(1){

                printf("\n                MENU                             \n");
                printf("\n 1.Create\n");
                printf("\n 2.Display \n");
                printf("\n 3.Insert at the beginning \n");
                printf("\n 4.Insert at the end  \n");
                printf("\n 5.Insert at specified position       \n");
                printf("\n 6.Delete from beginning      \n");
                printf("\n 7.Delete from the end        \n");
                printf("\n 8.Delete from specified position     \n");
                printf("\n 9.Exit       \n");
                printf("\n--------------------------------------\n");
                printf("Enter your choice:\t");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                                        create();
                                        break;
                        case 2:
                                        display();
                                        break;
                        case 3:
                                        insert_begin();
                                        break;
                        case 4:
                                        insert_end();
                                        break;
                        case 5:
                                        insert_pos();
                                        break;
                        case 6:
                                        delete_begin();
                                        break;
                        case 7:
                                        delete_end();
                                        break;
                        case 8:
                                        delete_pos();
                                        break;

                        case 9:
                                        exit(0);
                                        break;

                        default:
                                        printf("\n Wrong Choice:\n");
                                        break;
                }
        }

        return 0;
}


struct node {

int info;
struct node *next ;

};

struct node *start = NULL;

void create ()
{
    struct node *temp , *ptr ;
    temp = (struct node *) malloc(sizeof(struct node)) ;
    printf("enter the value of your node: ");
    scanf("%d",&temp->info);
    if(temp==NULL)
    {
        printf("there is enough memory");
        return;
    }
    if(start==NULL)
    {
        start=temp;
        temp->next=NULL;
    }

    else
    {
        ptr=start;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
        temp->next=NULL;
    }

}


void display()
{
        struct node *ptr;
        if(start==NULL)
        {
                printf("\nList is empty:\n");
                return;
        }
        else
        {
                ptr=start;
                printf("\nThe List elements are:\n");
                while(ptr!=NULL)
                {
                        printf("%d\t",ptr->info );
                        ptr=ptr->next ;
                }
        }
}

void insert_begin()
{
    struct node *temp , *ptr ;
    temp = (struct node *) malloc(sizeof(struct node)) ;
    printf("enter the value of your node to be inserted at begin: ");
    scanf("%d",&temp->info);
    if(start==NULL)
    {
        start=temp;
        temp->next=NULL;
    }
    else
    {
        temp->next=start;
        start=temp;
    }
}


void insert_end()
{
    struct node *temp , *ptr ;
    temp = (struct node *) malloc(sizeof(struct node)) ;
    printf("enter the value of your node to be inserted at end: ");
    scanf("%d",&temp->info);
    ptr=start;
     while(ptr->next!=NULL)
     {
       ptr=ptr->next;
     }
    ptr->next=temp;
    temp->next=NULL;

}

void insert_pos()
{
    struct node *temp , *ptr ;
    int n,i;
    temp = (struct node *) malloc(sizeof(struct node)) ;

    if(temp==NULL)
    {
            printf("\nOut of Memory Space:\n");
            return;
    }
    printf("enter the value of your node to be inserted at postion: ");
    scanf("%d",&temp->info);
    printf("enter the postion: ");
    scanf("%d",&n);

    temp->next=NULL;

        if(n==0)
        {
                temp->next=start;
                start=temp;
        }
        else
        {
                ptr=start;
                for(i=0;i<n-1;i++)
                {
                    ptr=ptr->next;
                        if(ptr==NULL)
                        {
                                printf("\nPosition not found:[Handle with care]\n");
                                return;
                        }
                }
                temp->next=ptr->next;
                ptr->next=temp;
        }
}


void delete_begin()
{
struct node *ptr ;

    if(start->next==NULL)
    {
        printf("the linked list is empty");
    }
    else
    {
    ptr=start;
    start=start->next;
    free(ptr);
    }

}


void delete_end()
{
struct node *ptr ,*temp ;

    if(start==NULL)
    {
        printf("the linked list is empty");
        return;
    }
    ptr=start;
    while(ptr->next!=NULL)
    {
        temp=ptr;
        ptr=ptr->next;
    }
    temp->next=NULL;
    free(ptr);
}

void delete_pos()
{
    struct node *ptr ,*temp ;
    int i,n;
    printf("enter the postion: ");
    scanf("%d",&n);
   if (start==NULL)
   {
        printf("the linked list is empty");
        return;
   }

   ptr=start;

   for(i=0;i<n;i++)
   {
     temp=ptr;
     ptr=ptr->next;
   }
   temp->next=ptr->next;
   free(ptr);
}
