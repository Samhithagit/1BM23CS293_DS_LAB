/* Write a program to simulate the working of stack using an array with the following:
a) Push
b) Pop
c) Display
The program should print appropriate messages for stack overflow, stack underflow*/

#include <stdio.h>
#include <conio.h>
#define SIZE 10
void push(int);
void pop();
void display();
int stack[SIZE], top = -1;
void main() {
int value, choice;
clrscr();
while (1) {
printf("\n MENU");
printf("\n 1. Push\n 2. Pop\n 3. Display\n 4. End");
printf("\n Enter your choice :");
scanf("%d", &choice);
switch (choice) {
case 1: printf("Enter value to be inserted");
scanf("%d", &value);
push(value);
break;
case 2: pop();
break;
case 3: display();
break;
case 4: exit(0);
default:
}}}
void push(int value) {
if (top == SIZE - 1) printf("Stack is full");
else {
top++;
stack[top] = value;
printf("Insertion successful");
}}
void pop() {
if (top == -1) printf("Stack is empty");
else {
printf("Deleted: %d", stack[top]);
top--;
}}
void display() {
if (top == -1) printf("Stack is empty");
else {
printf("Stack elements:\n");
for (int i = top; i >= 0; i--)
printf("%d\n", stack[i]);
}
}
