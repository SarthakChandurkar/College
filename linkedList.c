#include<stdio.h>
#include<stdlib.h>

struct node
{
    int number;
    struct node *next;
};

void generate(struct node **);
void display(struct node *);
int count(struct node *);
void insert(struct node *,int,int);
void delete(struct node *,int);


int main()
{
    char choice;
    int value,position;
    struct node *start=NULL;
    struct node *ptr;
    generate(&start);

    do
    {
        printf("Linked-List\n");
        ptr=start;
        display(ptr);
        printf("Perform the:\n");
        printf("a.Displaying linked list\nb.Counting nodes in linked list\nc.Insertion in linked list\nd.Deletion in linked list\ne.Exit\nEnter: ");
        scanf(" %c",choice);
        switch(choice)
        {
            case 'a':
                ptr=start;
                display(ptr);
            break;

            case 'b':
                ptr=start;
                printf("No of nodes: %d",count(ptr));
            break;

            case 'c':
                ptr=start;
                printf("Enter the position to Enter: ");
                scanf("%d",&position);
                printf("Enter the number to insert: ");
                scanf("%d",&value);
                insert(ptr,value,position);
            break;

            case 'd':
                ptr=start;
                printf("Enter the position delete: ");
                scanf("%d",&position);
                delete(ptr,position);
            break;

            case 'e':
            break;

            default:
            break;
        }
    }while(choice!='e');
    return 0;
}

void generate(struct node **head)
{
    int i,num=3;
    struct node *temp;
    for(i=0;i<num;i++)
    {
        temp=(struct node *)malloc(sizeof(struct node));
        temp->number=i;
        if(*head==NULL)
        {
            *head=temp;
            (*head)->next=NULL;
        }
        else
        {
            temp->next=*head;
            *head=temp;
        }
    }
}

void display(struct node *head)
{
    while(head->next!=NULL)
    {
        printf("%d\n",head->number);
        head=head->next;
    }
}

int count(struct node *head)
{
    int t=0;
    while(head->next!=NULL)
    {
        t++;
    }
    return t;
}

void insert(struct node *head,int value,int position)
{
    int i=1;
    while(head->next!=NULL)
    {
        if(position-1==i)
        {
            struct node *temp=(struct node *)malloc(sizeof(struct node));
            temp->number=value;
            temp->next=head->next;
            head->next=temp;
            break;
        }
        else
        {
            head=head->next;
        }
        i++;
    }
}

void delete(struct node *head,int position)
{
    int i=1;
    while(head->next!=NULL)
    {
        if(position-1==i)
        {
            head->next=head->next->next;
            break;
        }
        else
        {
            head=head->next;
        }
        i++;
    }
}