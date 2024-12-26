#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int q[MAX];
int front = -1;
int rear = -1;
void insert(int value) {
if ((rear + 1) % MAX == front) {
printf("Queue is full\n");
return;
}
if (front == -1 && rear == -1)
front = 0;
rear = (rear + 1) % MAX;
q[rear] = value;
printf("Inserted = %d\n", value);
}
void delete() {
if (front == -1 && rear == -1) {
printf("Queue is empty\n");
return;
}
int value = q[front];
printf("Deleted = %d\n", value);
if (front == rear)
front = rear = -1;
else
front = (front + 1) % MAX;
}
void display() {
if (front == -1 && rear == -1) {
printf("Queue is empty\n");
return;
}
printf("Queue elements: ");
for (int i = front; i != rear; i = (i + 1) % MAX)
printf("%d ", q[i]);
printf("%d\n", q[rear]);
}
int main() {
int ch, value;
while (1) {
printf("1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your choice: ");
scanf("%d", &ch);
switch (ch) {
case 1: printf("Enter value to be inserted: ");
scanf("%d", &value);
insert(value);
break;
case 2: delete();
break;
case 3: display();
break;
case 4: exit(0);
default: printf("Invalid choice\n");
}
}
return 0;
}

