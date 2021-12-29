#include <stdlib.h>
#include <stdio.h>

typedef struct node *list_head;

typedef struct node
{
	int data;
	list_head next;
}item;




int main()
{
	list_head head;
	list_head p1;
	list_head newNode;
	int i = 10;
	head = (list_head)malloc(sizeof(item));
	if(!p1)
		exit(1);
	p1 = head;
	p1->data = i;
	p1->next = NULL;
	

	/*       head/p1 ->  |__| --->\ground          */

	while(i > 0)
	{
		newNode = (list_head)malloc(sizeof(item));
		if(!p1)
			exit(1);
		newNode->next = NULL;
		p1->next = newNode;
		p1 = newNode;
		i -= 1;
		p1->data = i;
	}
	p1 = head;
	while(p1 != NULL)
	{
		printf("the value is: %d\n", p1->data);
		p1 = p1->next;
	}	























}






