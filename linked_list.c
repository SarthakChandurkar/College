#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<MMsystem.h>

char songs[5][20]={"butter","shapeofyou","senorita"};

struct node
{
    char song[19];
    struct node *link;
};

int num=3;

void generate(struct node **);
void display(struct node *);
void search(struct node *,char []);
void add_new(struct node **,char []);

int main()
{
    char new[19];
    struct node *start;
    struct node *recent;
    char choice;
    char toSearch[19];
    generate(&start);
    do
    {
        printf("a. Add new Song\nb. Delete Song\nc. Display Entered Playlist\nd. Total Songs\ne. Search song\nf. Play Song\ng. Sorted Playlist\nh. Recently Played Song\nEnter: ");
        scanf(" %c",&choice);
        switch(choice)
        {
            case 'a':
                printf("Enter the song name: ");
                scanf("%s",new);
                add_new(&start,new);
            break;

            case 'b':
            break;

            case 'c':
                display(start);
            break;

            case 'd':
                printf("Total Songs: %d\n",num);
            break;

            case 'e':
                printf("Enter the song name to search: ");
                scanf("%s",toSearch);
                search(start,toSearch);
            break;

            case 'f':
            break;

            case 'g':
            break;

            case 'h':
                display(recent);
            break;

            case 'i':
            break;
            
            default:
                printf("Invalid Option\n");
            break;
        }
    }while(choice!='i');
    
    return 0;
}
void generate(struct node **head)
{
    int i;
    struct node *temp;
    for(i=0;i<num;i++)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        strcpy(temp->song,songs[i]);
        if(*head==NULL)
        {
            *head=temp;
            (*head)->link=NULL;
        }
        else
        {
            temp->link=*head;
            *head=temp;
        }
    }
}
void display(struct node *head)
{
    int i=0;
    for(i=0;i<num;i++)
    {
        printf("%d. %s\n",i+1,head->song);
        head=head->link;
    }
    printf("\n");
}

void search(struct node *head,char s[])
{
    int i;
    for(i=0;i<num;i++)
    {
        if(strcmp(head->song,s)==0)
        {
            printf("Found at location %d\n",i+1);
            break;
        }
        else
        {
            head=head->link;
        }
    }
}
void add_new(struct node **head,char new[])
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    strcpy(temp->song,new);
    if(*head==NULL)
    {
        *head=temp;
        (*head)->link=NULL;
    }
    else
    {
        temp->link=*head;
        *head=temp;
    }
    num++;
}
