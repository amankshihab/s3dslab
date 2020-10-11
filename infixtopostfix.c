#include <stdio.h>
#include<string.h>
#include<ctype.h>
char stack[100], a[100], b[100], ch, item;
float estack[100];
int i = 0, j = 0, TOP = -1, TOPE = -1, TOPB = -1;

void push(char ch){
   	if(TOP >= 99)
    	printf("stack overflow");
    	else{
        	TOP = TOP + 1;
        	stack[TOP] = ch;
    	}
}

char pop(){
	if(TOP < 0)
    	printf("stack underflow");
    	else{
        	ch = stack[TOP];
        	TOP = TOP-1;
    	}
    	return ch;
}

void output(char ch){
	if(i > 99)
    	printf("overflow");
    	else{
        	b[i] = ch;
        	++i;
    	}
}

int ISP(char ch){
	switch(ch){
        	
        	case '^': return 3;
                 	  break;
        	case '*': return 2;
                 	  break;
        	case '/': return 2;
                 	   break;
         	case '+': return 1;
                          break;
        	case '-': return 1;
                 	   break;
         	case '(': return 0;
                 	   break;
         	default: printf("\nInvalid ISP!");
    }
}

int ICP(char ch){
    	switch(ch){
        	
        	case '^': return 3;
                 	  break;
        	case '*': return 2;
                 	   break;
        	case '/': return 2;
                 	   break;
         	case '+': return 1;
                 	   break;
        	case '-': return 1;
                 	   break;
        	case '(': return 4;
                 	   break;
        	default: printf("\nInvalid ICP");
    }
}

char read_symbol(){
	char ch;
    	if(j > 99)
    	printf("overflow");
   	else{
        	ch = a[j];
        	++j;
    	}
    	return ch;
}

float estack_pop(){
	float num;
	if(TOPE < 0){
		printf("\nStack Underflow!");
	}
	else{
		num = estack[TOPE];
		--TOPE;
	}
	return num;
}
void estack_push(float n){
	if(TOPE > 100){
		printf("Stack Overflow!");
	}
	else{
		++TOPE;
		estack[TOPE] = n;
	}
}
char b_read_symbol(){
	if(TOPB > 100){
		printf("\n Stack Overflow!");
	}
	else{
		++TOPB;
		ch = b[TOPB];
		//++TOPB;
		return ch;
	}
}

float op(float r,float s,char o)
{
    int pow = 1;
    switch(o)
    {
        case '^': for(int i = 1; i <= s; i++ ){
        		pow = pow * r;
        	  }
        	  return pow;
                 break;
        case '*':return r*s;
                 break;
        case '/':return r/s;
                 break;
        case '+':return r+s;
                 break;
        case '-':return r-s;
                 break;
        default:printf("Invalid character!");
    }
}

float eval(){
	int len, n;
	float num_item, x = 0, y = 0, t = 0, value = 0;
	len = strlen(b);
	b[len] = '#';
	item = b_read_symbol();
	n = 1;
	while(item != '#'){
		if(isalpha(item)){
			printf("Enter the value for %d : ", n);
			scanf("%f", &num_item);
			++n;
			estack_push(num_item);
		}
		else{
			y = estack_pop();
			x= estack_pop();
			t = op(x, y, item);
			estack_push(t);
		}
		item = b_read_symbol();
	}
	value = estack_pop();
	return value;
}
void main(){
    	
    	char item,x;
    	int length;
    	float evalue = 0;
    	printf("\nEnter the infix expression:");
    	scanf("%s", a);
    	length = strlen(a);
    	a[length] = ')';
    	push('(');
    	while(TOP > -1){
        	item = read_symbol();
        	x = pop();
        	if(isalpha(item)){
            		push(x);
            		output(item);
        	}									   	
        	else if(item == ')'){
            		while(x != '('){
                		output(x);
                		x = pop();
            		}
        	}
        	else if(ISP(x) >= ICP(item)){
            		while(ISP(x) >= ICP(item)){
                		output(x);
                		x = pop();
            		}
            		push(x);
            		push(item);
        	}
        	else if(ISP(x) < ICP(item)){
            		push(x);
            		push(item);
        	}
        	else
        	printf("Invalid Expression!");
    	}
    	printf("Postfix expression:\n %s\n",b);
    	evalue = eval();
    	printf("Value of the stack : %f\n", evalue);
}
