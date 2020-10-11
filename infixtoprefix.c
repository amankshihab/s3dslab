#include<stdio.h>
#include<string.h>
#include<ctype.h>

char inexp[100], stack[100], outexp[100];
int top = -1,i = 0,j = 0;
float stack1[100];

char *strrev(char *str)
{
	int j = 0;
    	int i = strlen(str)-1;
    	char ch;
    	while(i > j)
    	{
        	ch = str[i];
        	str[i] = str[j];
        	str[j] = ch;
        	i--;
        	j++;
      	}
      	return str;
}
void push(char inp)
{
	if(top >= 99)
   	{
     		printf("!STACK OVERFLOW!\n");
  	}
  	else
  	{
    		top++;
    		stack[top] = inp;
  	}
}
void pushev(float item)
{
  	if(top >= 99)
  	{
    		printf("!STACK OVERFLOW!\n");
  	}
  	else
  	{
    		top += 1;
    		stack1[top] = item;
  	}
}
char pop()
{
	char ch;
  	if(top < 0)
  	{
    		printf("!STACK UNDERFLOW!\n");
  	}
  	else
  	{
    		ch = stack[top];
    		top--;
  	}
  	return ch;
}
float popev()
{
  	float item;
  	if(top < 0)
  	printf("!STACK OVERFLOW!");
  	else
  	{
    		item = stack1[top];
    		top -= 1;
    		return(item);
  	}
}
char read_symbol()
{
 	char ch = inexp[i];
  	i++;
  	return(ch);
}
void output(char item)
{
  	outexp[j] = item;
  	j++;
}
int isp(char ch)
{
  	switch(ch)
  	{
      		case '^':return 4;
               	break;
      		case '*':return 2;
               	break;
      		case '/':return 2;
               	break;
      		case '+':return 1;
               	break;
      		case '-':return 1;
               	break;
      		case ')':return 0;
               	break;
      		default:printf("Invalid ISP\n");
  	}
}
int icp(char ch)
{
  	switch(ch)
  	{
      		case '^':return 3;
               	break;
      		case '*':return 2;
               	break;
      		case '/':return 2;
               	break;
      		case '+':return 1;
               	break;
      		case '-':return 1;
               	break;
      		case ')':return 4;
               	break;
      		default:printf("Invalid ICP\n");
  }
}
char readsymbol()
{
  	char ch;
  	ch = outexp[j];
  	j++;
  	return(ch);
}
void main()
{
  	float mul = 1;
  	printf("Enter Infix Expression: ");
  	scanf("%s", inexp);
  	char x, item;
  	int len;
  	float value;
  	strrev(inexp);
  	len=strlen(inexp);
  	inexp[len] = '(';
  	push(')');
  	while(top > -1)
  	{
   	 	item = read_symbol();
    		x = pop();
    		if(isalpha(item))
    		{
      			push(x);
      			output(item);
    		}
    		else if (item == '(')
    		{
      			while(x != ')')
      			{
        			output(x);
        			x=pop();
      			}
    		}
    		else if(isp(x) > icp(item))
   	 	{
      			while(isp(x) > icp(item))
      			{
        			output(x);
        			x = pop();
      			}
      			push(x);
      			push(item);
    		}
    		else if(isp(x) <= icp(item))
    		{
      			push(x);
      			push(item);
    		}
    		else
      		printf("INVALID EXPRESSION\n");
  	}
  	printf("Prefix %s\n", strrev(outexp));
  	for(i = 0; outexp[i] != '\0'; i++)
  	{
    		if(isalpha(outexp[i]))
    		{
     			 printf("Enter the value of %c: ", outexp[i]);
      			scanf(" %c", &outexp[i]);
    		}
  	}
  	strrev(outexp);
  	float X,y,t;
  	char op;
  	outexp[i] = '#';
  	j = 0;
  	item = readsymbol();
  	while(item != '#')
  	{
    		if(isdigit(item))
      		pushev(item - '0');
    		else
    		{
      			op = item;
      			X = popev();
      			y = popev();
      			switch(item)
      			{
        			case '^':for(i = 1; i <= y; i++){
        					mul *= i;
        					t = mul;
        					}
                 			break;
        			case '*':t = X * y;
                 			break;
        			case '/':t = X / y;
                 			break;
        			case '+':t = X + y;
                 			break;
        			case '-':t =X - y;
                 			break;
      			}
      			pushev(t);
    		}	
    		item = readsymbol();
  	}
  	value = popev();
  	printf("The value of expression is %f\n",value+1);
}

