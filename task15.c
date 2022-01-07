//liked list insert,delete,sorting... and display

#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
void insert(struct node**head)
{
     int val;
     printf("enter a val:");
     scanf("%d",&val);
     printf("\n");
     struct node *ptr=(struct node *)malloc(sizeof(struct node));
      ptr->data=val;
      if(*head==NULL){
          ptr->data=val;
          ptr->next=NULL;
          *head=ptr;
      }
      else{
          struct node *temp=*head;
          while(temp->next!=NULL){
              temp=temp->next;
          }
          temp->next=ptr;
          ptr->next=NULL;
         }
}
void deletea(struct node **head)
{
    struct node *temp1,*temp2; 
    temp1=temp2=*head;
    if(*head == NULL)  
    {  
        printf("\nlist is empty");  
    }  
    else if(temp2->next==NULL)  
    {  
        temp2 = NULL;  
        free(temp2);
    }  
          
    else  
    {
        while(temp1->next != NULL)  
        {  
            temp2 = temp1;  
            temp1 = temp1 ->next;  
        }  
        printf("%d is deleted\n\n",temp1->data);
        temp2->next = NULL;  
        free(temp1);
    }
}

void display(struct node *head)
{
    if(head==NULL){
        printf("Empty!!\n");
    }
    else{
        printf("list is: ");
        while(head!=NULL){
            printf("%d ",head->data);
            head=head->next;
        }
         printf("\n");
    }
}

void sorting(struct node **head)
{
    int a;
    struct node *temp1,*temp2;
    temp1=temp2= *head;
    while(temp1!=NULL){
        temp2=temp1->next;
        while(temp2!=NULL){
            if(temp1->data > temp2->data){
                a=temp1->data;
                temp1->data=temp2->data;
                temp2->data=a;
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
  printf("\nlinked list is sort\n");
         display(*head);
}

int main()
{
    struct node*head=NULL;
    int q;
    while(1){
        printf("1.insert\n2.display\n3.delete\n4.sorting\n5.exit\n");
         printf("enter your choice: ");
         scanf("%d",&q);
        switch(q){
            case 1: insert(&head);
                    break;
            case 2: display(head);
                    break;
            case 3: deletea(&head);
                    break;
            case 4: sorting(&head);
                    break;
            case 5: printf("exiting..!!!\n");
                    exit(0);
                    break;
            default:printf("invalid input\n");
        }
    }
}
