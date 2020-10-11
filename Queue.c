#include<stdio.h>
#include<stdlib.h>  

int front = -1, rear = -1, q[100], n = 0, item = 0, sz = 0;

void display(){
	
	printf("\nThe queue now is:\n");
	
	for(int i = front; i <= rear; i++){
		printf("%d  ", q[i]);
	}
}

void enq(){
	
	if(rear == (n - 1)){
	
		printf("\nQueue is full!");
	}
	else{
		if(front == -1 && rear == -1){
			front = 0; rear = 0;
		}
		else{
			++rear;
		}
		printf("\nEnter the element to be inserted:");
		scanf("%d", &item);
		q[rear] = item;
		display();
	}
}

void dq(){
	
	if(front == -1 && rear == -1)
	printf("\nQueue is empty!");
	else{
		item = q[front];
		
		if(front == rear){
			front = -1; rear = -1;
			printf("\nQueue is empty!");
		}
		else{
		++front;
		//--n;
		}
		
		display();	
	}
}

void main(){
	int c = 0, ch = 1;
	
	printf("\n\nEnter the size of the queue:");
	scanf("%d", &n);
	
	do{
		
		printf("\n\nQueue Operations:\n");
		printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter your choice:");
		scanf("%d", &c);
		
		switch(c){
		
			case 1: enq();
				  break;
			case 2: dq();
				  break;
			case 3: display();
				  break;
			case 4: exit(0);
				  break;
			default: printf("!!Wrong Option!!\n");
		}
	}while(c != 4);
}
