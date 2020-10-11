#include<stdio.h>
#include<stdlib.h>

int n, dq[100], front = -1, rear = -1, temp = 0, item = 0;

void disp(){
	if(front == -1 && rear == -1)
		printf("\nDequeue is empty!\n");
	else if(front > rear){
		
		printf("\nThe dequeue now is:\n");
		
		for(int i = front; i < n; i++)
			printf(" %d ", dq[i]);
        for(int j = 0; j <=rear; j++)
			printf(" %d ", dq[j]);
	}
	else{
		
		printf("\nThe circular now is:\n");
		
		for(int i = front; i <= rear; i++)
			printf(" %d ", dq[i]);
	}
	printf("\n");
}
void eject(){

    if(front == -1 && rear == -1)
    printf("\n!!Dequeue is empty!!\n");
    else{

        if(front == rear){

            item = dq[rear];
            front = -1; rear = -1;
        }
        else{

            item = dq[rear];
            if(rear == 0)
            rear = n - 1;
            else
            rear = rear - 1;
        }
        disp();
    }
}

void inject(){

    if(front == ((rear + 1) % n))
    printf("\n!!Dequeue is full!!\n");
    else{

        printf("\nEnter the element to inject : ");
        scanf("%d", &item);
        
        if(front == -1 && rear == -1){

            front = 0; rear = 0;
            dq[rear] = item;
        }
        else{

            rear = ((rear + 1) % n);
            dq[rear] = item;
        }
        disp();
    }
}

void popdq(){

    if(front == -1 && rear == -1)
    printf("\n!!Dequeue is empty!!\n");
    else{

        if(front == rear){

            front = -1; rear = -1;
        }
        else
        front = ((front + 1) % n);

        disp();
    }
}

void pushdq(){
    
    //printf("\nEnter the element to push : ");
    //scanf("%d", &item);
    
    if(front == -1 && rear == -1){
        printf("\nEnter the element to push : ");
        scanf("%d", &item);
        
        front = 0; rear = 0;
        dq[front] = item;
        disp();
    }
    else{

        if(front == 0){
            temp = n - 1;
            disp();
        }
        else{
            
            temp = front - 1;
        }
        if(temp == rear)
        printf("\n!!Dequeue is full!!\n");
        else{
            
            printf("\nEnter the element to push : ");
            scanf("%d", &item);
            front = temp;
            dq[front] = item;
            disp();
        }
        
    }
}

void main(){
    int c;
    
    printf("\nEnter the size of the double ended queue : ");
    scanf("%d", &n);

    do{
        printf("\nOperations on Double Ended Queue:\n1.Inject\n2.Pop\n3.Eject\n4.Display\n5.Exit\nEnter your choice : ");
        scanf("%d", &c);

        switch(c){
            
            case 1 : inject();
                    break;
            case 2 : popdq();
                    break;
            case 3 : eject();
                    break;
            case 4 : disp();
                    break;
            case 5 : exit(0);
                    break;
            default : "\n!!WRONG OPTION!!\n"; 
        }
    }while(c != 5);
}
