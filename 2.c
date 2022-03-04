#include<stdio.h>
#include<conio.h>
#define SIZE 5
void enQueue(int);
void deQueue();
void display();

int cQueue[SIZE], front = -1, rear = -1;
void main()
{
   int choice, value;
   //clrscr();
   while(1){
      printf("Circular Queue ***\n");
      printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
      printf("Enter your choice: ");
      scanf("%d",&choice);
      switch(choice){
	 case 1: printf("Enter the value to be insert:  \n");
		 scanf("%d",&value);
		 enQueue(value);
		 break;
	 case 2: deQueue();
		 break;
	 case 3: display();
		 break;
	 case 4: exit(0);
	 default: printf("Please select the correct choice!!!\n");
      }
   }
}
void enQueue(int value)
{
   if((front == 0 && rear == SIZE - 1) || (front == rear+1))
      printf("Circular Queue is Full! Insertion not possible!!!\n");
   else{
      if(rear == SIZE-1 && front != 0)
	 rear = -1;
      cQueue[++rear] = value;
      printf("Insertion Success!!!\n");
      if(front == -1)
	 front = 0;
   }
}
void deQueue()
{
   if(front == -1 && rear == -1)
      printf("Circular Queue is Empty! Deletion is not possible!!!\n");
   else{
      printf("Deleted element : %d\n",cQueue[front++]);
      if(front == SIZE)
	 front = 0;
      if(front-1 == rear)
	 front = rear = -1;
   }
}
void display()
{
   if(front == -1)
      printf("Circular Queue is Empty!!!\n");
   else{
      int i = front;
      printf("Circular Queue Elements are : \n");
      if(front <= rear){
	 while(i <= rear)
	    printf("%d\t",cQueue[i++]);
      }
      else{
	 while(i <= SIZE - 1)
	    printf("%d\t", cQueue[i++]);
	 i = 0;
	 while(i <= rear)
	    printf("%d\t",cQueue[i++]);
      }
   }
}

