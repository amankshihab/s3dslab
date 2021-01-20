#include <stdio.h>
#include <stdlib.h>

struct vertex{
	
	int data;
	struct vertex *link;
};

struct vertex *gptr = NULL;
int n = 0;

int visit[20], count = 0;

struct node{
	
	struct vertex *data;
	struct node *link;
};

struct node *TOP = NULL;
struct node *FRONT = NULL, *REAR = NULL;


void push(struct vertex *vert){
	
	struct node *p = malloc(sizeof(struct node));
	p->data = vert;
	p->link = TOP;
	TOP = p;
}

struct vertex *pop(){
	
	if(TOP == NULL){
		return NULL;
	}
	else{
		struct node *temp = TOP;
		struct vertex *vert;
		vert = temp->data;
		TOP = TOP->link;
		free(temp);
		return vert;
	}
}

void enqueue(struct vertex *vert){
	
	struct node *p = malloc(sizeof(struct node));
	p->data = vert;
	p->link = NULL;
	if(FRONT == NULL && REAR == NULL){
		FRONT = p;
	}
	else{
		
		REAR->link = p;
	}
	REAR = p;
}

struct vertex *dequeue(){
	
	if(FRONT == NULL && REAR == NULL){
		return NULL;
	}
	else{
		
		struct node *temp = FRONT;
		struct vertex *vert = temp->data;
		
		if(FRONT == REAR){
			FRONT = NULL;
			REAR = NULL;
		}
		else{
			FRONT = FRONT->link;
		}
		free(temp);
		
		return vert;
	}
}

void init(){
	
	int i;
	
	for(i = 0; i < 20; i++){
		visit[i] = 0;
	}
	
	count = 0;
}

int visited(struct vertex *u){
	
	int i;
	
	for(i = 0; i < count; i++){
		if(visit[i] == u->data){
			return 1; 
		}
	}
	
	visit[count] = u->data;
	count++;
	
	return 0;
}

struct vertex *get_gptr(struct vertex *u){
	int i = 0;
	
	for(i = 0; i < n; i++){
		
		if(gptr[i].data == u -> data){
			return &gptr[i];
		}
	}
}

//dfs traversal of graph
void dfs(){
	
	if(gptr == NULL){
		printf("Empty Graph!");
	}
	else{
		init();
		
		struct vertex *u, *ptr;
		
		printf("\nDFS Traversal: ");
		
		push(&gptr[0]);
		
		while(TOP != NULL){
			u = pop();
			
			if(visited(u) == 0){
				
				printf("%d  ", u->data);
				
				ptr = get_gptr(u);
				ptr = ptr->link;
				
				while(ptr != NULL){
					push(ptr);
					ptr = ptr->link;
				}
			}
		}
	}
}

//bfs traversal of graph
void bfs(){
	
	if(gptr == NULL){
		printf("Empty Graph!");
	}
	else{
		init();
		
		struct vertex *u, *ptr;
		
		printf("\nBFS Traversal: ");
		enqueue(&gptr[0]);
		
		while(FRONT != NULL && REAR != NULL){
			u = dequeue();
			
			if(visited(u) == 0){
				
				printf("%d  ", u->data);
				
				ptr = get_gptr(u);
				ptr = ptr->link;
				
				while(ptr != NULL){
					enqueue(ptr);
					ptr = ptr->link;
				}
			}
		}
	}
}

//Creates the graph
void create(){
	
	printf("\nEnter number of vertices: ");
	scanf("%d", &n);
	
	gptr = malloc(sizeof(struct vertex) * n);
	
	struct vertex *edge, *ptr;
	
	int i, j, e;
	
	//printf("Enter vertices %d:\n", n);
	
	for(i = 0; i < n; i++){
		printf("\nEnter vertex %d: ", i);
		scanf("%d", &gptr[i].data);
		gptr[i].link = NULL;
	}
	
	printf("\nEntered vertices are: ");
	
	for(i = 0; i < n; i++){
		printf("%d  ", gptr[i].data);
	}
	
	printf("\n");
	
	for(i = 0; i < n; i++){
		
		printf("\nNo. of Edges for Vertex '%d': ", gptr[i].data);
		scanf("%d", &e);
		ptr = &gptr[i];

		for(j = 0; j < e; j++){
			struct vertex *vert = malloc(sizeof(struct vertex));
			ptr->link = vert;
			vert->link = NULL;
			printf("Enter Edge %d: ", j + 1);
			scanf("%d", &vert->data);
			ptr = ptr->link;
		}
	}
	printf("\n");
}

//main
int main(){
	
	printf("\nEnter your graph:\n");
	
	create();
	
	dfs();
	
	bfs();
	
	printf("\n");

	return 0;
}
