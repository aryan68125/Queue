// this program implements queue using structure array

#include<stdio.h>
#include<stdlib.h>

//now we will create a structure array
struct queue
{
	int size;
	int rear; //this is a pointer used in queue
    int *q ; //array pointer where the elements of the data will be stored

};

void createQueue(struct queue *qt)
{
	//struct queue *qt is the call by reference of the actual structure of the queue and it will allow us to make changes to the queue's data
	printf("Enter the size of the queue\n");
	scanf("%d", &qt->size);
	qt->rear = -1;
	qt->q=(int*)malloc(qt->size*sizeof(int));

}

//this function is used to enter the values in the queue
//struct queue *qt is the call by reference of the actual queue structure
//int X is the value that will initialized in the main function that we want to enter in the queue
void enqueue(struct queue *qt, int X)
{

   if(qt->rear==qt->size-1)
   {
   	printf("Queue is full\n");
   }
   else
   {
   	qt->rear++;
   	qt->q[qt->rear]=X;
   }

}

//this function will delete the elements from the queue
void dequeue(struct queue *qt)
{
	int x=qt->q[0];
	if(qt->rear==-1)
	{
		printf("Queue is empty\n");
	}
	else
	{
		for(int i=0;i<qt->size;i++)  //shift the elements after deleting the zeroth element from the array
		{
          qt->q[i]=qt->q[i+1];
		}
		qt->rear--;
		printf("%d is deleted from the queue\n", x);
	}
}


/*
the struct queue qt is the call by value it is used when we are just reading data from the structure array

*/
void displayqueue(struct queue qt)
{
  int i; //loop variable
  for(i=0;i<qt.rear;i++)
  {
  	printf("%d\n", qt.q[i]);
  }
}

int main()
{

    struct queue qt; //initializing queue in the main function
    int choiceQueue;
    int QueueCounter=0;
    int X; //value to be pushed inside the queue
    do
    {

         printf("-----------------QUEUE USING ARRAY-------------------\n");
         printf("press 1 to create a queue\n");
         printf("press 2 to display the queue elements\n");
         printf("press 3 to enqueue\n");
         printf("press 4  to dequeue\n");
         printf("press 5 to exit\n");
         scanf("%d", &choiceQueue);
         printf("\n");
         switch(choiceQueue)
         {

           case 1:
           createQueue(&qt);  //note $qt is used when we are editing the queue structure by calling the function
           printf("\n");
           break;

           case 2:
           displayqueue(qt);
           break;

           case 3:
           printf("Enter the elements in the queue\n");
           scanf("%d",&X);
           enqueue(&qt,X);
           printf("\n");
           break;

           case 4:
           dequeue(&qt);
           break;

           case 5:
           printf("Name: Aditya Kumar\n");
           printf("Roll number:1901230100001\n");
           printf("Course B.tech 2nd year\n");
           printf("College: SITM\n");
           QueueCounter=5000;
           break;

           default:
           printf("wrong chopice try again!!!\n");
           break;
         }


    }while(QueueCounter<4000);

	return 0;
}