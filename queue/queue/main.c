#include <stdio.h>
#include <stdlib.h>


void insert_end();
void delete_begin();
void display();

int main()
{
        int choice;
        while(1){

                printf("\n                MENU                             \n");
                printf("\n 1.Insert at the end  \n");
                printf("\n 2.Delete from beginning      \n");
                printf("\n 3.Display \n");
                printf("\n 4.Exit       \n");
                printf("\n--------------------------------------\n");
                printf("Enter your choice:\t");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                                        insert_end();
                                        break;
                        case 2:
                                        delete_begin();
                                        break;
                        case 3:
                                        display();
                                        break;
                        case 4:
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

void insert_end()
{
    struct node *temp , *ptr ;
    temp = (struct node *) malloc(sizeof(struct node)) ;
    printf("enter the value of your node to be inserted at end: ");
    scanf("%d",&temp->info);
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
