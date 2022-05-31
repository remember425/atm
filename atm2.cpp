#include<stdio.h>
#include<stdlib.h> 
#include<string.h>

struct Account
{
	char username[100];
	char password[100];
	
	struct Account * next;	
};
typedef struct Account Account;

Account * head=NULL;//ָ��ͷ����ָ��
Account * tail=NULL;//ָ��β����ָ�� 
Account * curAccount=NULL;//��ǰ��¼�˻���ָ�� 

int findAccount(Account a)
{
	Account *curP=head;
	while(curP!=NULL)
	{
		if((strcmp(curP->username,a.username)==0)
		&&(strcmp(curP->password,a.password)==0))
		{
			curAccount=curP;
			return 1;
		}
		curP=curP->next;
	}
	return 0;
}

void updatePassword()
{
	printf("����������룺\n");
	char oldPassword[100];
	scanf("%s",oldPassword);
	if(strcmp(oldPassword,curAccount->password)==0)
	{
		printf("�����������룺\n");
		scanf("%s",curAccount->password);
		printf("�޸�����ɹ���\n");
	}
	else
	{
		printf("������󣬲����޸ģ�\n");
	}
}

void homePage()
{
	printf("Press...\n");
	printf("��...\n");
	updatePassword();
}

void signIn()
{
	for(int i=0;i<3;i++)
	{
		Account a;
		printf("�������˺ţ�\n");
		scanf("%s",a.username);
		
		printf("���������룺\n");
		scanf("%s",a.password);
		
		if(findAccount(a))
		{
			printf("��¼�ɹ���\n");	
			homePage();
			break;
		}
		else
		{
			printf("��¼ʧ��!\n");
		}
	}
}

int loadData()
{
	FILE*fp=fopen("C:/atm.txt","r");
	if(fp==NULL)
	{
		return 0;
	}
	else
	{
		while(!feof(fp))
		{
				//�������
				Account *newNode=(Account *)malloc(sizeof(Account));
				
				//����ʼ��
				newNode->next=NULL;
				fscanf(fp,"%s %s\n",newNode->username,newNode->password); 
				
				//��ӵ�����
				if(head==NULL)
				{
					head=newNode;
					tail=newNode;
				} 
				else
				{
					tail->next=newNode;
					tail=newNode;
				}
		}	
		return 1;
	}
}

void printLinkedList()
{
	Account* curP=head;
	while(curP!=NULL)
	{
		printf("%s\t%s\n",curP->username,curP->password);
		curP=curP->next;
	}	
}

int main()
{
	int status=loadData(); 
	if(status==1)
	{
		printf("���سɹ���\n");
		printLinkedList();
	}
	else
	{
		printf("����ʧ��!\n");
	}
	signIn();
	
	return 0;
}
