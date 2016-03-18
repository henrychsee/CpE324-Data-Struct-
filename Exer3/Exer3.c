
/*
	Name: Matidios, Henry
	Date: 13/12/15 20:32
	Description: Phonebook
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct phonebook
{
	char lastname[50];
	char firstname[50];
	char middlename[50];
	char tel_num[50];
	struct phonebook *next;
};
struct phonebook *head;
struct phonebook *tail;
//Functions
void askDetails();
void userMenu();
void displayContacts();
void searchContacts();
void updateContacts();
void update();
void removeContacts();
void removeAllContacts();
void removebyFirstName();
void addContacts(char lastname[],char firstname[],char middlename[],char tel_num[]);

void askDetails()
{
	char lastname[50];
	char firstname[50];
	char middlename[50];
	char tel_num[50];

	system("cls");
	
	printf("Your last name: ");
	fflush(stdin);
	fgets(lastname,sizeof(lastname),stdin);

	printf("Your first name: ");
	fflush(stdin);
	fgets(firstname,sizeof(firstname),stdin);

	printf("Your middle name: ");
	fflush(stdin);
	fgets(middlename,sizeof(middlename),stdin);

	printf("Your contact number: ");
	fflush(stdin);
	fgets(tel_num,sizeof(tel_num),stdin);

	addContacts(lastname,firstname,middlename,tel_num);
}
void userMenu()
{
	char choice;
	
	system("cls");
	printf("[1]-DISPLAY CONTACTS\n[2]-ADD CONTACTS\n[3]-SEARCH CONTACT\n[4]-UPDATE CONTACTS\n[5]-DELETE CONTACTS");
	printf("\nPress Esc to exit...\n");
	choice=getch();
	

	switch(choice)
	{
		case '1':
			displayContacts();
			getch();
			userMenu();
			break;
		case '2':
			askDetails();
			displayContacts();
			getch();
			userMenu();
			break;
		case '3':
			searchContacts();
			getch();
			userMenu();
			break;
		case '4':
			updateContacts();
			getch();
			userMenu();
			break;
		case '5':
			removeContacts();
			getch();
			userMenu();
			break;
		default:
			getch();
			break;
	}
}
void updateContacts()
{
	struct phonebook *current;
	char lastname[50];
	char firstname[50];
	
	
	if(head==NULL)
	{
		printf("Contact List is Empty!");
	}
	else
	{
		system("cls");
		printf("\n\nSEARCH");
		printf("\nLast name: ");
		fflush(stdin);
		fgets(lastname,sizeof(lastname),stdin);
	
		printf("First name: ");
		fflush(stdin);
		fgets(firstname,sizeof(firstname),stdin);
	
	
		current=head;
		while(1)
		{
			if(!strcmp(current->lastname,lastname)&&(!strcmp(current->firstname,firstname)))
			{
				update(current);
				break;
			}
			if(current->next==NULL)
			{
				break;
			}
			else if(current->next!=NULL)
			{
				current=current->next;
			}
		}
	}
}
void update(struct phonebook *current)
{
	char lastname[50];
	char firstname[50];
	char middlename[50];
	char tel_num[50];

		system("cls");
		printf("\n\nUPDATE");
		printf("\nYour last name: ");
		fflush(stdin);
		fgets(lastname,sizeof(lastname),stdin);
	
		printf("Your first name: ");
		fflush(stdin);
		fgets(firstname,sizeof(firstname),stdin);
	
		printf("Your middle name: ");
		fflush(stdin);
		fgets(middlename,sizeof(middlename),stdin);
	
		printf("Your contact number: ");
		fflush(stdin);
		fgets(tel_num,sizeof(tel_num),stdin);
	
		strcpy(current->lastname,lastname);
		strcpy(current->firstname,firstname);
		strcpy(current->middlename,middlename);
		strcpy(current->tel_num,tel_num);
		
		printf("SUCCESSFULLY UPDATED!");
}

void removeContacts()
{
	char choice;
	
	if(head==NULL)
	{
		printf("Contact List is Empty!");
	}
	else
	{
		system("cls");
		printf("[1]-REMOVE BY FIRST NAME\n[2]-REMOVE ALL CONTACT\n");
		choice=getche();
		
		switch(choice)
		{
			case '1':
				removebyFirstName();
				break;
			case '2':
				removeAllContacts();
				break;
		}
	}
}
void removebyFirstName()
{
	struct phonebook *current;
	struct phonebook *before;
	struct phonebook *after;
	struct phonebook *temp;
	
	char firstname[50];
	
	printf("\nEnter first name: ");
	fflush(stdin);
	fgets(firstname,sizeof(firstname),stdin);
	
	current=head;
	before=head;
	while(1)
	{
		if(!strcmp(current->firstname,firstname))
		{
			if(current==head)
			{
				temp=head;
				head=head->next;
				free(temp);
			}
			else if(current==tail)
			{
				before=head;
				while(before->next!=tail)
				{
					before=before->next;
				}
				if(before->next!=NULL)
				{
					free(before->next->next);
					before->next=NULL;
					tail=before;
				}
				else
				{
					free(before->next);
					tail=head;
					tail->next=NULL;
				}	
			}
			else
			{
				before=head;
				while(before->next!=current)
				{
					before=before->next;
				}
				temp=before->next;
				after=before->next->next;
				free(temp);
				before->next=after;
				
			}
		}

		if(current->next==NULL)
		{
			break;
		}
		else if(current->next!=NULL)
		{
			before=current;
			current=current->next;
		}
	}
}
void removeAllContacts()
{
	struct phonebook *current;
	struct phonebook *before;
	
	current=head;
	before=head;
	
	while(1)
	{
		current=current->next;
		free(before);
		head=current;
		before=current;
		
		if(current->next==NULL)
		{
			free(current);
			head=NULL;
			break;
		}
	}
}
void searchContacts()
{
	struct phonebook *current;
	char lastname[50];
	char firstname[50];
	char middlename[50];
	char tel_num[50];

	if(head==NULL)
	{
		printf("Contact List is Empty");
	}
	else
	{
		printf("\nFirst name: ");
		fflush(stdin);
		fgets(firstname,sizeof(firstname),stdin);
	
	
		current=head;
		while(1)
		{
			if(!strcmp(current->firstname,firstname))
			{
				printf("\nLASTNAME: %sFIRSTNAME: %sMIDDLENAME: %sTELEPHONE NUMBER: %s\n\n",current->lastname,current->firstname,current->middlename,current->tel_num);
			}
			
			if(current->next==NULL)
			{
				break;
			}
			else if(current->next!=NULL)
			{
				current=current->next;
			}
		}
	}
}
void displayContacts()
{
	struct phonebook *current;

	current=head;
	if(head==NULL)
	{
		printf("Contact List is Empty!");
	}
	else
	{
		while(1)
		{
			printf("\nLASTNAME: %sFIRSTNAME: %sMIDDLENAME: %sTELEPHONE NUMBER: %s\n\n",current->lastname,current->firstname,current->middlename,current->tel_num);
			if(current->next!=NULL)
			{
				current=current->next;
			}
			else
			{
				break;
			}	
		}
	}
}
void addContacts(char lastname[],char firstname[],char middlename[],char tel_num[])
{
	struct phonebook *newNode;
	struct phonebook *current;

	newNode=(struct phonebook*)malloc(sizeof(struct phonebook));

	if(newNode)
	{
		strcpy(newNode->lastname,lastname);
		strcpy(newNode->firstname,firstname);
		strcpy(newNode->middlename,middlename);
		strcpy(newNode->tel_num,tel_num);
		newNode->next=NULL;
		

		if(head==NULL)
		{
			head=newNode;
		}
		else if(head!=NULL)
		{	
			current=head;
			while(current->next!=NULL)			//traverse the linked list and point the current pointer to the last node of the list
			{
				current=current->next;
			}
			current->next=newNode;				//connect the newNode to the linked list
			tail=newNode;
		}
	}
}
void main()
{
	head=NULL;
	userMenu();
}
