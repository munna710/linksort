#include<stdio.h>
#include<conio.h>
#include<alloc.h>
typedef struct listnode*listpointer;
struct listnode
{
	int data;
	listpointer next;
};
listpointer fnode=NULL,node;
void create();
void list();
void sort();
void main()
{
	int choice;
	do
	{
		clrscr();
		printf("\n\linkedlist operation:");
		printf("\n\t\t1.create");
		printf("\n\t\t2.list");
		printf("\n\t\t3.sort");
		printf("\n\t\t4.exit");
		printf("\nenter your choice(1-4): ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:create();
				break;
			case 2:list();
				break;
			case 3:	sort();break;
			default:continue;
		}
		getch();
	}
	while(choice!=4);
}
void create()
{
	int i,n;
	if(fnode!=NULL)
	{
		printf("\nlist is already created");
		return;
	}
	printf("\nenter the number of elements: ");
	scanf("%d",&n);
	if(n<1)
	return;
	printf("\nenter %d elements to the list:\n",n);
	fnode=(listpointer) malloc (sizeof(*fnode));
	scanf("%d",&fnode->data);
	node=fnode;
	for(i=0;i<n-1;i++)
	{
		node->next=(listpointer)malloc(sizeof(*node));
		node=node->next;
		scanf("%d",&node->data);
	}
	node->next=NULL;
	printf("\n list created with %d elements",n);
}
void list()
{
	if(fnode==NULL)
	{
		printf("\nlist is empty.....");
		return;
	}
	printf("\n elements in the list");
	for(node=fnode;node!=NULL;node=node->next)
	printf("\t%d",node->data);
}
void sort()
{
	int temp;
	listpointer node1,node2;
	if(fnode==NULL)
	{
		printf("\nlist is empty.....");
		return;
	}
	for(node1=fnode;node1->next!=NULL;node1=node1->next)
	{
		node=node1;
		for(node2=node1->next;node2!=NULL;node2=node2->next)
			if(node2->data<node->data)node=node2;
		if(node==node1)continue;
		temp=node1->data;
		node1->data=node->data;
		node->data=temp;
	}
	printf("\nlist is sorted...");
}
