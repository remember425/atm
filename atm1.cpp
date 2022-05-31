#include<stdio.h>
#include<stdlib.h>

struct Account
{
	char name[100];
	char username[100];
	char password[100];	
	
	struct Account * next; 
};
typedef struct Account Account;

Account a[500]; 

Account *head=NULL;
Account *tail=NULL;

void addNode(Account *node)
{
	node->next=NULL;
	if(head==NULL)
	{
		head=node;
		tail=node;
	}
	else
	{
		tail->next=node;
		tail=node;
	}
}

void loadData()
{
	FILE* fp=fopen("C:/atm.txt","r");
	if(fp!=NULL)
	{
		while(!feof(fp))
		{
			//����һ���ڴ�ռ䣬�����ַ��ֵ��ָ��newNodeP 
			Account *newNodeP=(Account *)malloc(sizeof(Account));
			fscanf(fp,"%s %s %s\n",newNodeP->name,newNodeP->username,newNodeP->password);
			addNode(newNodeP);
		}
		fclose(fp);
		printf("��ʼ���ɹ���\n");
	}
}

void printLinkedList()
{
	Account * curP=head;
	while(curP!=NULL)
	{
		printf("%s\t%s\t%s\n",curP->name,curP->username,curP->password);
		curP=curP->next;
	}
}

void saveData()
{
	FILE* fp=fopen("C:/atm.txt","w");
	if(fp!=NULL)
	{
		Account * curP=head;
		while(curP!=NULL)
		{
			fprintf(fp,"%s %s %s\n",curP->name,curP->username,curP->password);
			curP=curP->next;
		}
		fclose(fp);
	}
}

void signUp()
{
	Account * newNodeP=(Account *)malloc(sizeof(Account));
	printf("���������֣�\n");
	scanf("%s",newNodeP->name);
	
	printf("�������˺ţ�\n");
	scanf("%s",newNodeP->username);
	
	printf("���������룺\n");
	scanf("%s",newNodeP->password);
	
	addNode(newNodeP);
	
	printf("�����ɹ���\n");
}

int main()
{
	loadData();
	
	signUp();
	
	printLinkedList();
	
	saveData();
	return 0;
}
