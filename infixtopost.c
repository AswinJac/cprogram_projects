#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
void postfixer(char infix[],char postfix[]);
char stack[20],top=-1;
bool isOperator(char ch);
int preced(char ch);
int evaluate(char postfix[]);
void main() {
    int ch;
    char infix[20], postfix[20];
    printf("Enter a string");
    scanf("%s", infix);
    while (true) {
        printf("Menu Driven\n1:Convert to Infix\n2:Evaluate postfix\n3:Exit\nEnter choice\n");
        scanf("%d", &ch);
        if (ch == 1) {
            postfixer(infix, postfix);
            printf("Postfix Expression%s\n",postfix);
        }
        else if(ch==2)
        {
            printf("After Valuation:%d\n",evaluate(postfix));
        }
    }
}
void postfixer(char infix[], char postfix[]) {
    int res = 0;
    char ch;

    for (int i = 0; i < strlen(infix); i++) {
        ch = infix[i];

        if (isalpha(ch)) {
            postfix[res++] = ch;
        }
        else if(isdigit(ch))
        {
            postfix[res++] = ch;
        }
        else if (isOperator(ch)) {
            while (top >= 0 && preced(stack[top]) >= preced(ch)) {
                postfix[res++] = stack[top--];
            }
            stack[++top] = ch;
        } else if (ch == '(') {
            stack[++top] = ch;
        } else if (ch == ')') {
            while (top >= 0 && stack[top] != '(') {
                postfix[res++] = stack[top--];
            }
            top--;
        }
    }

    while (top >= 0) {
        postfix[res++] = stack[top--];
    }

    postfix[res] = '\0';
}

bool isOperator(char ch) {
    return (ch == '*' || ch == '/' || ch == '+' || ch == '-' || ch == '^');
}

int preced(char ch) {
    if (ch == '^')
        return 3;
    if (ch == '/' || ch == '*')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;

    return 0;
}
int evaluate(char postfix[])
{
    int stak[20];
    top=-1;
    for(int i=0;i< strlen(postfix);i++)
    {
        char ch=postfix[i];
        if(isdigit(ch))
        {
            stak[++top]=ch-'0';
        }
        else if(isalpha(ch))
        {int val;
            printf("Enter value for %c",ch);
            scanf("%d",&val);
            stak[++top]=val;
        }
        else if(isOperator(ch))
        {
            int v1=stak[top--];
            int v2=stak[top--];
            if(ch=='+')
                stak[++top]=v2+v1;
            else if(ch=='-')
                stak[++top]=v2-v1;
            else if(ch=='/')
                stak[++top]=v2/v1;
            else if(ch=='*')
                stak[++top]=v2*v1;
            else if(ch=='^')
                stak[++top]=pow(v2,v1);
        }
    }
    return stak[top];
}