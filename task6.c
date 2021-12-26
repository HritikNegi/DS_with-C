
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node *next;
}node;

void insert(struct node**head)
{
     int val;
     printf("enter a val:");
     scanf("%d",&val);
     printf("\n");
     node *ptr=(struct node *)malloc(sizeof(struct node));
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
int length( node* head ){
	int len = 0;
	while( head != NULL ){
		head = head-> next ;
		len ++ ;
	}
	return len ;
}

void del( node* head ){
	node* tmp = head-> next ;
	head-> next = tmp-> next ;
	free( tmp ) ;
}

void delete( node **head ){
	if( *head == NULL ){
		printf( "\nLL is Empty" ) ;
	}
	int len = length( *head ) ;
	len &= 1 ;
	node *trv = *head ;
	while( ( len == 0 && trv != NULL ) || ( len == 1 && trv-> next != NULL ) ){
		del( trv ) ;
		trv = trv-> next ;
	}
}
void display( node* head ){
	printf( "Elements in LL: " ) ;

	while( head != NULL ){
		printf( "%d ", head-> data ) ;
		head = head-> next ;
	}
	printf( "\n" ) ;
}


int main()
{
    node *head=NULL;
    int q;
    while(1){
        printf("1.insert\n2.display\n3.delete\n4.exit\n");
         printf("enter your choice: ");
         scanf("%d",&q);
        switch(q){
            case 1: insert(&head);
                    break;
            case 2: display(head);
                    break;
            case 3: delete(&head);
                    break;
            
            case 4: printf("exiting..!!!");
                    exit(0);
                    break;
            default:printf("invalid input\n");
        }
       
    }
} 
