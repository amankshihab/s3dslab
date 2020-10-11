#include<stdio.h>
#include<stdlib.h>	//Header files

int n, cq[100], front = -1, rear = -1, item;	//Circular queue elements

void disp(){	//function to display the circular array
	if(front == -1 && rear == -1)
		printf("\nCircular Queue is empty!\n");
	else if(front > rear){
		
		printf("\nThe circular queue now is:\n");
		
		for(int i = front; i < n; i++)
			printf(" %d ", cq[i]);
		for(int j = 0; j <=rear; j++)
			printf(" %d ", cq[j]);
	}
	else{
		
		printf("\nThe circular queue now is:\n");
		
		for(int i = front; i <= rear; i++)
			printf(" %d ", cq[i]);
	}
	printf("\n");
}

void enq(){	//function to enqueue
	
	if(front == ((rear+1) % n)){
		printf("\nCircular queue is full!\n");
	}
	else{
		if(front == -1 && rear == -1){
			printf("\nEnter the element:");
			scanf("%d", &item);
			front = 0; rear = 0; cq[rear] = item;
			disp();
		}
		else{
			printf("\nEnter the element:");
			scanf("%d", &item);
			rear = ((rear + 1) % n);
			cq[rear] = item;
			disp();
		}
	}
}

void dq(){	//function to dequeue
	
	if(front == -1 && rear == -1)
		printf("\nNothing to dequeue! Circular queue is empty!\n");
	else{
		item = cq[front];
		if(front == rear){
			front = -1; rear = -1; printf("\nCircular queue has been emptied!\n");
		}
		else{
			front = ((front + 1) % n); disp();
		}
	}	
}

void main(){	//main function 
	
	int ch, ans = 1;
	printf("\nEnter the size of the circular array:");
	scanf("%d", &n);
	
	do{	
		printf("\nChose array options:\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter your choice:");
		scanf("%d", &ch);	
		switch(ch){
			case 1: enq();	//calling enq()
				break;
			case 2: dq();	//calling dq()
				break;
			case 3: disp();	//calling disp()
				break;
			case 4: exit(0);
				break;
			default: printf("\nWrong Option!\n");
		}
	}while(ch != 4);
}
