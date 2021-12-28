
#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
void insert(struct node**top)
{
    int val;
    printf("enter a val:");
    scanf("%d",&val);
    printf("\n");
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
     ptr->data=val;
    if(*top==NULL){
        ptr->next=NULL;
        *top=ptr;
    }
    else{
        ptr->next=*top;
        *top=ptr;
    }
}

void display(struct node *top)
{
    if(top==NULL){
        printf("Empty!!\n");
    }
    else{
        printf("list is: ");
        while(top!=NULL){
            printf("%d ",top->data);
            top=top->next;
        }
         printf("\n");
    }
}

void delete(struct node **top)
{
    if(*top==NULL){
        printf("list is empty\n");
    }
    else{
        struct node *temp;
        temp=*top;
        *top=temp->next;
        free(temp);
    }
}

int main()
{
    struct node*top=NULL;
    int q;
    while(1){
        printf("1.insert\n2.display\n3.delete4.exit\n");
         printf("enter your choice: ");
         scanf("%d",&q);
        switch(q){
            case 1: insert(&top);
                    break;
            case 2: display(top);
                    break;
            case 3: delete(&top);
                    break;
            case 4: printf("exiting..!!!\n");
                    exit(0);
                    break;
            default:printf("invalid input\n");
        }
       
    }
}
