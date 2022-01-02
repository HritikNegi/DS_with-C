
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}node;
void insert(node **last,int value)
{
    node *temp=(node*)malloc(sizeof(node));
    temp->data=value;
    if(temp==NULL)
        temp->next=NULL;
    if(*last==NULL)
    {
        *last=temp;
        (*last)->next=temp;
    }
    else{
        temp->next=(*last)->next;
        (*last)->next=temp;
        *last=(*last)->next;
    }
    printf("Entered %d Sucessfully\n",value);
}

void display(node *last)
{
    node *head=last->next;
    while(head!=last)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    printf("%d \n",head->data);

}

int main()
{
    node *last;
    int counter=0,choice,value;

    last=NULL;
    while(counter==0)
    {
        printf("1.INSERT \n2.DISPLAY \n3.EXIT\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter a value : ");
                scanf("%d",&value);
                insert(&last,value);
                break;

            case 2:
                display(last);
                break;

            case 3:
                printf("EXITED\n");
                counter++;
                break;

            default:
                printf("WRONG CHOICE\n");
                break;
        }
    }
    return 0;
}

