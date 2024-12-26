//Stack Implementation:

#include <stdio.h>
#include <stdlib.h>
struct node {
int data;
struct node *next;
};
struct node *top = NULL;
void push(int x) {
struct node *newnode = (struct node *) malloc(sizeof(struct node));
newnode->data = x;
newnode->next = top;
top = newnode;
}
void peek() {
if (top == NULL)
printf("No element to display");
else
printf("The top element is %d", top->data); 
}
void display() {
struct node *temp;
temp = top;
if (top == NULL)
printf("Underflow condition");
else {
while (temp != NULL) {
printf("%d", temp->data);
temp = temp->next;
}
}
}
void pop() {
struct node *temp;
temp = top;
if (top == NULL)
printf("Underflow");
else {
printf("The deleted element is %d", top->data);
top = top->next;
}
}
void main()
{
int a,ch;
while(1)
{
printf(“\n1.Push\n2.Peek\n3.Pop\n4.Display\n5.Exit\n”);
printf(“Enter your choice”);
scanf(“%d”,&ch);
switch(ch)
{
case 1:printf(“Enter element:”);
scanf(“%d”,&a);
push(a);
break;
case 2:peek();
break;
case 3:pop();
break;
case 4:display();
break;
case 5:exit(1);
break;
default:printf(“Invalid choice”);
break;
}
}

//Queue Implementation:

#include <stdio.h>
#include <stdlib.h>
struct node {
int data;
struct node *next;
};
struct node *front = NULL, *rear = NULL;
void enqueue(int x) {
struct node *newnode = (struct node *)malloc(sizeof(struct node));
newnode->data = x;
newnode->next = NULL;
if (front == NULL && rear == NULL) {
front = rear = newnode;
} else {
rear->next = newnode;
rear = newnode;
}
}
void dequeue() {
struct node *temp;
if (front == NULL)
printf("Underflow");
else {
temp = front;
printf("The deleted element is %d", front->data);
front = front->next;
if (front == NULL)
rear = NULL;
}
}
void display() {
struct node *temp;
temp = front;
if (front == NULL)
printf("Queue is empty");
else {
while (temp != NULL) {
printf("%d ", temp->data);
temp = temp->next;
}
}
}
int main() {
int ch, x;
while (1) {
printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
printf("Enter your choice: ");
scanf("%d", &ch);
switch (ch) {
case 1: printf("Enter the data to enqueue: ");
scanf("%d", &x);
enqueue(x);
break;
case 2: dequeue();
break;
case 3: display();
break;
case 4: exit(0);
default: printf("Invalid choice");
}
}
return 0;
}

