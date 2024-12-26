#include <stdio.h>
#include <conio.h>
#define SIZE 3
void insert();
void delete();
void display();
int front = -1;
int rear = -1;
int queue[SIZE];
void main() {
int choice;
while(1){
printf("\nEnter your choice\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
scanf("%d", &choice);
switch (choice) {
case 1:
insert();
break;
case 2:
delete();
break;
case 3:
display();
break;
case 4:
exit(0);
break;
default:
printf("Invalid choice");
break;
}
}
}
void insert() {
if (rear == SIZE - 1)
printf("Queue overflow");
else {
int ele;
printf("Enter the element to be inserted");
scanf("%d", &ele);
rear++;
queue[rear] = ele;
if (front == -1)
front = 0;
}
}
void delete() {
if (front == -1 || front > rear)
printf("Underflow, cannot delete element");
else {
int del;
del = queue[front];
printf("Element deleted = %d", del);
front++;
}
}
void display() {
if (front == -1 || front > rear)
printf("No elements in queue");
else {
for (int i = front; i <= rear; i++)
printf("%d ", queue[i]);
}
}
