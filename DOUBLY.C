#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void insert_first();
void insert_last();
void insert_pos();
void delete_first();
void delete_last();
void delete_pos();
void display();
void taildisplay();

struct node
{
	int data;
	struct node *prev, *next;
} *head, *tail;

int n = 0; // size of linked list

void main()
{

	int ch;
	clrscr();

	do
	{
		printf("Select\n1.Insert at first\n2.Insert at last\n3.insert at position\n4.Delete at first\n5.Delete at last\n6.Delete at position\n7.Display\n8.Reverse Display\n9.Exit\n");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			insert_first();
			continue;

		case 2:
			insert_last();
			continue;

		case 3:
			insert_pos();
			continue;

		case 4:
			delete_first();
			continue;

		case 5:
			delete_last();
			continue;

		case 6:
			delete_pos();
			continue;

		case 7:
			display();
			continue;

		case 8:
			taildisplay();
			continue;

		default:
			exit(0);
		}

	} while (ch != 0);
}

void insert_first()
{

	struct node *newnode;
	int data;

	printf("Enter node value\n");
	scanf("%d", &data);

	if (head == NULL)
	{

		n++;
		head = malloc(sizeof(struct node));
		head->data = data;
		head->prev = NULL;
		head->next = NULL;
		tail = head;
		printf("Node Inserted\n");
	}
	else
	{

		n++;
		newnode = malloc(sizeof(struct node));
		newnode->data = data;
		newnode->prev = head->prev;
		newnode->next = head;
		head->prev = newnode;
		head = newnode;
		printf("Node Inserted\n");
	}
}

void insert_last()
{

	struct node *curr, *previous, *newnode;
	int data;

	printf("Enter node value\n");
	scanf("%d", &data);

	if (head == NULL)
	{
		insert_first();
		return;
	}
	else
	{

		n++;
		curr = head;

		while (curr != NULL)
		{
			previous = curr;
			curr = curr->next;
		}

		newnode = malloc(sizeof(struct node));
		newnode->data = data;
		newnode->prev = previous;
		newnode->next = NULL;
		previous->next = newnode;
		tail = newnode;
		printf("Node Inserted\n");
	}
}

void insert_pos()
{
	struct node *curr, *newnode, *nex;
	int data, pos, i;

	printf("Enter positon to be inserted\n");
	scanf("%d", &pos);

	if (pos < 1 || pos > n)
	{
		printf("Invalid Position\n");
	}
	else
	{

		if (pos == 1)
		{
			insert_first();
		}
		else if (pos == n)
		{
			insert_last();
		}
		else
		{
			n++;

			printf("Enter node value\n");
			scanf("%d", &data);

			newnode = malloc(sizeof(struct node));
			newnode->data = data;

			curr = head;
			pos--;

			for (i = 0; i < pos - 1; ++i)
			{

				curr = curr->next;
			}

			newnode->prev = curr;
			newnode->next = curr->next;
			curr->next = newnode;
			curr->next->next->prev = newnode;
			printf("Node Inserted\n");
		}
	}
}

void delete_first()
{

	struct node *temp;

	if (head == NULL)
		printf("List Empty\n");

	else if (head->next == NULL)
	{

		printf("Node deleted is %d\n", head->data);
		head = NULL;
		free(head);
		n--;
	}
	else
	{

		printf("Node deleted is %d\n", head->data);
		temp = head;
		head = head->next;
		head->prev = NULL;
		free(temp);
		n--;
	}
}

void delete_last()
{

	struct node *temp;

	if (head == NULL)
		printf("List Empty\n");

	else if (head->next == NULL)
	{

		printf("Node deleted is %d\n", head->data);
		head = NULL;
		free(head);
		n--;
	}
	else
	{

		printf("Node deleted is %d\n", tail->data);
		temp = tail;
		tail = tail->prev;
		tail->next = NULL;
		free(temp);
		n--;
	}
}

void delete_pos()
{

	struct node *temp, *curr, *prev;
	int pos, i;

	if (head == NULL)
	{
		printf("List Empty\n");
		return;
	}

	printf("Enter the positon to be deleted\n");
	scanf("%d", &pos);

	if (pos < 1 || pos > n)
	{
		printf("Invalid Positon\n");
		return;
	}
	else if (pos == 1)
	{
		delete_first();
	}

	else if (pos == n)
	{
		delete_last();
	}
	else
	{

		curr = head;

		for (i = 0; i < pos - 1; ++i)
		{

			prev = curr;
			curr = curr->next;
		}

		printf("%d \n", curr->data);

		temp = curr;
		prev->next = curr->next;
		curr->next->prev = prev;
		free(temp);
		n--;
	}
}

void display()
{

	struct node *curr;

	printf("The list is\n");
	if (n == 0)
	{
		printf("Empty\n");
		return;
	}
	curr = head;
	while (curr != NULL)
	{

		printf("[%d<--%d-->%d] ", curr->prev->data, curr->data, curr->next->data);
		curr = curr->next;
	}
	printf("\n");
}

void taildisplay()
{

	struct node *curr;

	printf("The list is\n");

	if (n == 0)
	{
		printf("Empty\n");
		return;
	}
	curr = tail;
	while (curr != NULL)
	{

		printf("[%d<--%d-->%d] ", curr->next->data, curr->data, curr->prev->data);
		curr = curr->prev;
	}
	printf("\n");
}