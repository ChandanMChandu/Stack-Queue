#include "stack.h"
#include<stdint.h>
#include<assert.h>
#include<stddef.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
int balancing_symbols(char c[10])
{

	Stack s = stack_new(5);
	Stack *stk = &s;

	Stack_Result res;
	
	for(int i=0;i<strlen(c);i++)
	{
		
		if(c[i] == '[' || c[i] == '(' || c[i] == '{')
		{
			stk = stack_push(stk,c[i],&res);
			continue;
		}
		else if(c[i] == ']' && stk->data[stk->top]=='[')
		{
			stk = stack_pop(stk,&res);
			continue;
		}
		else if(c[i] == ')' && stk->data[stk->top]=='(')
		{
			stk = stack_pop(stk,&res);
			continue;
		}
		else if(c[i] == '}' && stk->data[stk->top]=='{')
		{
			stk = stack_pop(stk,&res);
			continue;
		}
		else
		{
			assert(stk->top==2 || stk->top == -1);
			return 0;//if first symbol is },)or] then it will come out of function.
		}

	}
	stk = stack_peek(stk,&res);
	assert(stk->top == -1);

	return 0;
}

int postfix(char p[20])
{
	Stack s = stack_new(5);
	Stack *stk = &s;

	Stack_Result res;
	for(int i=0;i<strlen(p);i++)
    {
    	
    	if(isdigit(p[i]))
       
        {
            stk=stack_push(stk,p[i],&res);
            
        }
        else
        {
            
            int32_t a=0;
            int32_t b=0;
            char c=0;
            a = stk->data[stk->top];
            
            stk = stack_pop(stk,&res);
            

            b = stk->data[stk->top];
            stk = stack_pop(stk,&res);
            
            
            if(p[i]=='+')
            {
            
            
			c = b + a;            
            
            }
            else if(p[i]=='-')
            {
                
                c= (b-'0')- (a-'0');
            }
            else if(p[i]=='*')
            {
                
                c = b*a;
            }
            else if(p[i]=='/')
            {
                
                c = b/a;
            }
            

            stk = stack_push(stk,c,&res);


           
        }
    }


stk = stack_peek(stk,&res);
printf("final  %c",res.data);

}

int main()
{
	
    
	char p[20]="42+1+";
	postfix(p);
	return 0;
}
