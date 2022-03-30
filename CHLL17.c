#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;	
};
void generate(struct node**);
void display(struct node *head);

int main()
{
	struct node *start,*temp;
	generate(&start);
	display(start);
	return 0;
}
void generate(struct node **head)
{
	int n,i;

	printf("Enter the no of nodes in circular header linked list: ");
	scanf("%d",&n);
	int num;
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("Enter the no: ");
	scanf("%d",&num);
	temp->info=num;
	*head=temp;
	struct node *realstart=*head;
	for(i=0;i<n-1;i++)
	{
		temp=(struct node *)malloc(sizeof(struct node));
		printf("Enter the no: ");
		scanf("%d",&num);
		temp->info=num;
		temp->next=*head;
		*head=temp;			
	}
	realstart->next=*head;	
}
void display(struct node *head)
{
    printf("Linked-List\n");
    int i=1;
    
    while(head!=NULL)
    {
        printf("Node %d\nAddress: %u Info: %d Next: %u\n",i,head,head->info,head->next);
        i++;
        head=head->next;
    }
}
