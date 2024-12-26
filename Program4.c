#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node* next;
};
struct Node* head = NULL;
void create(int data) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->next = NULL;
head = newNode;
}
void insertfirst(int data) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->next = head;
head = newNode;
}
void insertlast(int data) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->next = NULL;
if (head == NULL) {
head = newNode;
return;
}
struct Node* current = head;
while (current->next != NULL) {
current = current->next;
}
current->next = newNode;
}
void display() {
struct Node* current = head;
if (current == NULL) {
printf("List is empty.\n");
return;
}
printf("Linked List: ");
while (current != NULL) {
printf("%d -> ", current->data);
current = current->next;
}
printf("NULL\n");
}
void main() {
int b,m,n,p;
printf(“1.Create\n2.Insert at beginning\n3.Insert at end\n4.Display\n5.Exit”);
printf(“Enter your choice”);
scanf(“%d”,&b);
switch(b){
case 1:printf(“Enter head node value: “);
scanf(“%d”,m);
create(m);
break;
case 1:printf(“Enter head node value: “);
scanf(“%d”,m);
create(m);
break;
case 1:printf(“Enter head node value: “);
scanf(“%d”,m);
create(m);
break;
case 4:display();
break;
case 5:exit(1);
break;
default:printf(“Invalid choice”);
break;
}
