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
if (head == NULL) {
head = newNode;
} else {
struct Node* temp = head;
while (temp->next != NULL) {
temp = temp->next;
}
temp->next = newNode;
}
}

void deleteFirst() {
if (head == NULL) {
printf("The list is empty.\n");
return;
}
struct Node* temp = head;
head = head->next;
printf("First element deleted.\n");
}

void deleteSpecified(int x) {
if (head == NULL) {
printf("The list is empty.\n");
return;
}
struct Node* temp = head;
struct Node* prev = NULL;
if (temp != NULL && temp->data == x) {
head = temp->next;
free(temp);
printf("Element %d deleted.\n", x);
return;
}
while (temp != NULL && temp->data != x) {
prev = temp;
temp = temp->next;
}
if (temp == NULL) {
printf("Element %d not found.\n", x);
return;
}
prev->next = temp->next;
printf("Element %d deleted.\n", x);
}

void deleteLast() {
if (head == NULL) {
printf("The list is empty.\n");
return;
}
if (head->next == NULL) {
free(head);
head = NULL;
printf("Last element deleted.\n");
return;
}
struct Node* temp = head;
struct Node* prev = NULL;
while (temp->next != NULL) {
prev = temp;
temp = temp->next;
}
prev->next = NULL;
printf("Last element deleted.\n");
}

void display() {
if (head == NULL) {
printf("The list is empty.\n");
return;
}
struct Node* temp = head;
printf("Linked List: ");
while (temp != NULL) {
printf("%d -> ", temp->data);
temp = temp->next;
}
printf("NULL\n");
}

int main() {
int ch, a, m;
while (1) {
printf("\nMenu:\n");
printf("1. Create \n2. Delete First Element\n3.Delete Specified Element\n4. Delete Last Element\n5. Display List\n6. Exit\n");
printf("Enter your choice: ");
scanf("%d", &ch);
switch (ch) {
case 1:
printf("Enter the data to insert: ");
scanf("%d", &m);
create(m);
break;
case 2:
deleteFirst();
break;
case 3:
printf("Enter the element to delete: ");
scanf("%d", &a);
deleteSpecified(a);
break;
case 4:
deleteLast();
break;
case 5:
display();
break;
case 6:
exit(0);
default:
printf("Invalid choice\n");
}
}
return 0;
}

