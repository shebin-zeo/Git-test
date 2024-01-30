#include <stdio.h>
#include <conio.h>

void enqueue();
void dequeue();
void display();

int queue[10];
int front=-1;
int rear=-1;
int item;
int n;

void main(){
	int ch;
	clrscr();

	printf("Enter the size of the queue\n");
	scanf("%d",&n);
	do{

	printf("SELECT\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
	scanf("%d",&ch);


	switch(ch){
		case 1: enqueue();
			continue;
		case 2: dequeue();
			continue;
		case 3: display();
			continue;
		default:exit(0);

	}

	}while(ch!=0);

}

void enqueue(){

	if(front==(rear+1)%n){
		printf("Queue Overflow\n");
	}
	else if(front==-1 && rear==-1){

		printf("Enter value\n");
		scanf("%d",&item);
		front=0;
		rear=0;
		queue[rear]=item;
		printf("Value inserted\n");

	}
	else{
	    printf("Enter value\n");
		scanf("%d",&item);
		rear=(rear+1)%n;
		queue[rear]=item;
		printf("Value inserted\n");

	}
}

void dequeue(){

if(front==-1 && rear==-1){
	printf("Queue Underflow\n");
}
else if(front==rear){
	printf("%d deleted\n",queue[front]);
	queue[front]=NULL;
	front=-1;
	rear=-1;

}
else{
	printf("%d deleted\n",queue[front]);
	queue[front]=NULL;
	front=(front+1)%n;

}
}

void display(){
	int i;
	printf("The Circular Queue is \n");

	for (i=0;i<n;++i){

		if(queue[i]==NULL)
			printf("- ");
		else{
			printf("%d ",queue[i]);
		}
	}
	printf("\n");
}