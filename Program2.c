#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100
char stack[SIZE];
int top = -1;

void push(char c) {
if (top < SIZE - 1) {
stack[++top] = c;
} else {
printf("Stack overflow\n");
exit(1);
}
}

char pop() {
if (top >= 0) {
return stack[top--];
} else {
printf("Stack underflow\n");
exit(1);
}
}

char peek() {
if (top >= 0)
return stack[top];
return '\0';
}

int precedence(char op) {
switch (op) {
case '+':
case '-': return 1;
case '*':
case '/': return 2;
case '^': return 3;
default: return 0;
}
}

void infixToPostfix(const char *infix, char *postfix) {
int j = 0;
int i = 0;
while (infix[i] != '\0') {
char c = infix[i];
if (isalnum(c)) {
postfix[j++] = c;
} else if (c == '(') {
push(c);
} else if (c == ')') {
while (top != -1 && peek() != '(') {
postfix[j++] = pop();
}
pop();
} else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
while (top != -1 && precedence(peek()) >= precedence(c)) {
postfix[j++] = pop();
}
push(c);
}
i++;
}
while (top != -1) {
postfix[j++] = pop();
}
postfix[j] = '\0';
}

int main() {
char infix[SIZE], postfix[SIZE];
printf("Enter a valid parenthesized infix expression: ");
scanf("%s", infix);
infixToPostfix(infix, postfix);
printf("Postfix expression: %s\n", postfix);
return 0;
}

