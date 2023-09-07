#include <stdio.h>
#include <stdlib.h>

void push();
void pop();
void display();

int main()
{
        int choice;
        while(1){

                printf("\n                MENU                             \n");
                printf("\n 1.push\n");
                printf("\n 2.pop \n");
                printf("\n 3.display \n");
                printf("\n 4.Exit       \n");
                printf("\n--------------------------------------\n");
                printf("Enter your choice:\t");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                                        push();
                                        break;
                        case 2:
                                        pop();
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


void push()
{
    struct node *temp , *ptr ;
    temp = (struct node *) malloc(sizeof(struct node)) ;
    if (temp == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("enter the value to push: ");
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

void pop()
{
struct node *ptr ,*temp ;

    if(start==NULL)
    {
        printf("the stack is empty");
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

void display()
{
        struct node *ptr ,*temp;
        if(start==NULL)
        {
                printf("\nstack is empty:\n");
                return;
        }
        else
        {
                ptr=start;
                printf("\nlast element in the stack is: \n");
                while(ptr!=NULL)
                {
                        temp=ptr;
                        ptr=ptr->next ;
                }
                printf("%d\t",temp->info );
        }
}
