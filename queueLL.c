/*
this program implements queue using linked list
*/
#include <stdio.h>
#include<stdlib.h>

//creating a stucture for a linked list
struct QueueLL // here struct QueueLL =  struct node
{
	int infoQueue;    // int infoQueue will hold the integer value inside the linked list
	struct QueueLL *nextQueue; // struct QueueLL *nextQueue; = struct node *next;
};
struct QueueLL *startQueue=NULL; //struct QueueLL *startQueue = struct node *start;

/*
this function is used to enter elements inside the queue
*/
void enqueueLL()
{
	struct QueueLL *temp,*ptr; //temp is the new node in the liked list and ptr is the pointer which will be used for traversal of the likned list
	temp = (struct QueueLL*)malloc(sizeof(struct QueueLL)); //allocating memory for the new node of the linked list
    if(temp == NULL)
    {
    	printf("\nQueue is full\n");
    }
    printf("Enter the elements in the queue\n");
    scanf("%d",&temp->infoQueue);
    temp->nextQueue=NULL;
    if(startQueue==NULL)
    {
    	startQueue=temp;
    }
    else
    {
    	ptr = startQueue;
    	while(ptr->nextQueue!=NULL)
    	{
    		ptr=ptr->nextQueue;
    	}
    	ptr->nextQueue=temp;
    }
}

//this function will delete the element from the beginning of the linked list
//this is cruesial so that we can follow the First in First out policy of the Queue data structure
void dequeueLL()
{
	   struct QueueLL *ptr;
        if(startQueue==NULL)
        {
                printf("\nQueue is Empty!!!!.....\n");
                return;
        }
        else
        {
                ptr=startQueue;
                startQueue=startQueue->nextQueue ;
                printf("\ndeleting elements from the Queue!!!!!!.....%d\n",ptr->infoQueue);
                free(ptr);
        }
}

void displayQueue()
{
	struct QueueLL *ptr;
        if(startQueue==NULL)
        {
                printf("\nQueue is Empty\n");
                return;
        }
        else
        {
                ptr=startQueue;
                printf("\nElements in the stack is :-\n");
                while(ptr!=NULL)
                {
                        printf("%d\n",ptr->infoQueue );
                        ptr=ptr->nextQueue ;
                }
        }
}

int main()
{

	int choiceQueue;
        while(1){
               
                printf("\n                QUEUE USING LINKED LIST MENU                             \n");
                printf("\n 1.enQueue (insert element in the queue)   \n");
                printf("\n 2.Display elements in queue    \n");
                printf("\n 3.deQueue (delete elements from the queue)   \n");
                printf("\n 4.Exit       \n");
                printf("\n--------------------------------------\n");
                printf("\nEnter your choice:\n");
                scanf("%d",&choiceQueue);
                switch(choiceQueue)
                {
                        case 1:
                                        enqueueLL();
                                        break;
                        case 2:
                                        displayQueue();
                                        break; 
                        case 3:
                                        dequeueLL();
                                        break;    
                        
                        case 4:
                                        printf("This piece of program was written by\n");
                                        printf("Name : Aditya Kumar\n");
                                        printf("Roll number : 1901230100001\n");
                                        printf("College code: 123\n");
                                        printf("College Name : SITM\n");
                                        printf("Course: B.Tech\n");
                                        printf("Branch : Computer science\n");
                                        printf("Year : 2nd Year\n");
                                        printf("Thank you for using my program ....Bye\n");
                                        exit(0);
                                        break;
                             
                        default:
                                        printf("\n Wrong Choice:\n");
                                        break;
                }
        }
	return 0;
}