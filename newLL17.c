#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<MMsystem.h>

char songs[5][30]={"song1","song2","song3"};

struct node
{
    char song[30];
    struct node *next;
};

void generate(struct node **);
void display(struct node *);
int count(struct node *);
void add_new(struct node **,char []);
void delete_first(struct node **);
void delete_(struct node *,int num);
void search(struct node *head,char toSearch[]);
void play(struct node *,struct node *head,int position);
void sort(struct node **head,struct node *temp);


int main()
{
	char choice,new[30],toSearch[30];
	int position;
	struct node *start=NULL;
	struct node *recent=NULL;
	struct node *ptr;
	generate(&start);
	ptr=start;
	display(ptr);
	ptr=start;
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
            	ptr=start;
            	display(ptr);
            	printf("Enter:");
            	scanf("%d",&position);
            	if(position==1)
            	{
            		delete_first(&start);
				}
				else if(1<position<=count(ptr))
				{
					ptr=start;
					delete_(ptr,position);
				}
				else
				{
					printf("Wrong method\n");
				}
            break;

            case 'c':
            	ptr=start;
               display(start);
            break;

            case 'd':
            	ptr=start;
                printf("Total Songs: %d\n",count(ptr));
            break;

            case 'e':
                printf("Enter the song name to search: ");
                scanf("%s",toSearch);
                search(start,toSearch);
            break;

            case 'f':
            	ptr=start;
            	display(ptr);
            	printf("Enter: ");
            	scanf("%d",position);
            	ptr=start;
            	play(recent,ptr,position);
            break;

            case 'g':
            	ptr=start;
            	sort(&start,ptr);
            break;

            case 'h':
            	ptr=recent;
                display(ptr);
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
	int i=0,num=3;
	struct node *temp;
	for(i=0;i<num;i++)
	{
		temp=(struct node *)malloc(sizeof(struct node));
		strcpy(temp->song,songs[i]);
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
	int i=1;
	printf("PlayList\n");
	while(head!=NULL)
	{
		printf("%d.%s\n",i,head->song);
		i++;
		head=head->next;
	}
}
int count(struct node *head)
{
	int counter=0;
	while(head!=NULL)
	{
		counter++;
		head=head->next;
	}
	return counter;
}
void add_new(struct node **head,char newSong[])
{
	struct node *new;
	new=(struct node *)malloc(sizeof(struct node));
	strcpy(new->song,newSong);
	if(*head==NULL)
	{
		*head=new;
		(*head)->next=NULL;
	}
	else
	{
		new->next=*head;
		*head=new;
	}
}
void delete_first(struct node **head)
{
	struct node *temp;
	temp=(*head)->next;
	*head=temp;
}
void delete_(struct node *head,int position)
{
	int i=1;
	while(head!=NULL)
	{
		if(position-1==i)
		{
			head->next=head->next->next;
			break;
		}
		else
		{
			head=head->next;
			i++;
		}
	}
}
void search(struct node *head,char toSearch[])
{
	int i=1;
	while(head!=NULL)
	{
		if(strcmp(head->song,toSearch)==0)
		{
			printf("Song Exist at position %d\n",i);
			break;
		}
		else
		{
			head=head->next;
			i++;
		}
	}
}
void play(struct node *recent,struct node *head,int position)
{
	int i=1;
	while(head!=NULL)
	{
		if(position==i)
		{
			add_new(&recent,head->song);
			PlaySound(TEXT(strcat(head->song,".wav")),NULL,SND_ASYNC);
			Sleep(15000);
			break;
		}
		else
		{
			head=head->next;
			i++;
		}
	}
}
void sort(struct node **head,struct node *temp)
{
	char replacer[30];
	struct node *ptr;
	ptr=temp;
	int c=count(ptr),i;
	for(i=0;i<c-1;i++)
	{
		while(temp!=NULL)
		{
			if(strcmp(temp->song,temp->next->song)==1)
			{
				strcpy(replacer,temp->song);
				strcpy(temp->song,temp->next->song);
				strcpy(temp->next->song,replacer);
				temp=temp->next;
			}
			else
			{
				temp=temp->next;
			}
		}
		temp=*head;
	}
}


