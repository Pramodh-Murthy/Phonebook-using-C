#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct phonebook
{
	char fname[30];
	char lname[30];
	char fatname[30];
	int pnum;
	char eid[30];
	char address[30];
	struct phonebook *link;
}node;
node *header=NULL;
node *get_node()
{
	return((node *)malloc(sizeof(node)));
}
void insert()
{
char fname[30];
	char lname[30];
	char fatname[30];
	int pnum;
	char eid[30];
	char address[30];
	node *p;
	printf("Enter FIRST NAME\n LAST NAME\n FATHER NAME\n PHONE NUMBER\n EMAIL-ID/ADDRESS: ");
	scanf("%s %s %s %d %s %s",&fname,&lname,&fatname,&pnum,&eid,&address);
	p=get_node();
	strcpy(p->fname,fname);
	strcpy(p->lname,lname);
	strcpy(p->fatname,fatname);
	p->pnum=pnum;
	strcpy(p->eid,eid);
	strcpy(p->address,address);
	p->link=NULL;
	if(header==NULL)
		header=p;
	else
	{
		p->link=header;
		header=p;
	}
}
	void del()
{
	node *temp;
	if(header==NULL)
	{
		printf("Empty List\n");
		return;
	}
	else
	{
		temp=header;
		header=header->link;
	printf("The following record is deleted : %s %s %s %d %s %s\n",temp->fname,temp->lname,temp->fatname,temp->pnum,temp->eid,temp->address);
	free(temp);
	}
}
void display()
{
	node *temp;
	printf("FIRST_NAME   LAST_NAME      FATHER_NAME      PHONE_NUMBER   EMAIL-ID      ADDRESS\n");
	for(temp=header;temp!=NULL;temp=temp->link)
	printf("%-10s %-10s %-10s %d %-20s %-30s\n",temp->fname,temp->lname,temp->fatname,temp->pnum,temp->eid,temp->address);
	}
	
void search()
{
int pnum;
	node *temp;	
	printf("Enter the Number to be searched : ");
	scanf("%d",&pnum);
	for(temp=header;temp!=NULL;temp=temp->link)	
	{
		if(pnum==temp->pnum)
		{
			printf("FIRST_NAME   LAST_NAME      FATHER_NAME PHONE_NUMBER   EMAIL-ID      ADDRESS\n");
				printf("%-10s %-10s %-10s %d %-20s %-30s\n",temp->fname,temp->lname,temp->fatname,temp->pnum,temp->eid,temp->address);
			return;
		}
	}
		printf("Phonebook Record Not Found !!!\n");
}
void menu()
{
	int choice;
	printf("\nChoose :\n1 - Add contact\n2 - Remove contact\n3 - Search contact\n4 - Display\nPress any other key to EXIT !\n");
	scanf("%d",&choice);
		switch(choice)
		{
		case 1 : insert();break;
		case 2 : del();break;
		case 3 : search();break;
		case 4 : display();break;
		default : exit(0);break;
		}
}

int main()
{
	for(;;) 
	{
		menu();
	}
	return 0;
}


