#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node* next;
};
struct Node* head = NULL;

void create(int n) {
struct Node* newNode;
newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = n;
newNode->next = NULL;
head = newNode;
}

void insert(int data, int pos) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->next = NULL;
if (pos== 1) {
newNode->next = head;
head = newNode;
return;
}
struct Node* temp = head;
for (int i = 1; i < pos- 1 && temp != NULL; i++) {
temp = temp->next;
}
if (temp == NULL) {
printf("Node inserted at the end.\n");
}
newNode->next = temp->next;
temp->next = newNode;
}

void concatenate(struct Node* list2) {
if (head == NULL) {
head = list2;
return;
}
struct Node* temp = head;
while (temp->next != NULL) {
temp = temp->next;
}
temp->next = list2;
}

void display() {
if (head == NULL) {
printf("The list is empty.\n");
return;
}
struct Node* temp = head;
while (temp != NULL) {
printf("%d -> ", temp->data);
temp = temp->next;
}
printf("NULL\n");
}

void sortList() {
struct Node* current = head;
struct Node* index = NULL;
int temp;
if (head == NULL) {
printf("The list is empty.\n");
return;
}
while (current != NULL) {
index = current->next;
while (index != NULL) {
if (current->data > index->data) {
temp = current->data;
current->data = index->data;
index->data = temp;
}
index = index->next;
}
current = current->next;
}
printf("The list has been sorted.\n");
}

void reverseList() {
struct Node* prev = NULL;
struct Node* current = head;
struct Node* next = NULL;
while (current != NULL) {
next = current->next;
current->next = prev;
prev = current;
current = next;
}
head = prev;
printf("The list has been reversed.\n");
}

int main() {
int ch, data, pos, n;
do {
printf("1. Create linked list\n2. Insert an element\n3. Display the list\n4. Sort the list\n5. Reverse the list\n6. Concatenate another list\n7. Exit\n");
printf("Enter your choice: ");
scanf("%d", &ch);
switch (ch) {
case 1: printf("Enter head node value: ");
scanf("%d", &n);
create(n);
break;
case 2: printf("Enter the element to insert: ");
scanf("%d", &data);
printf("Enter the position to insert at: ");
scanf("%d", &pos);
insert(data, pos);
break;
case 3: display();
break;
case 4: sortList();
break;
case 5: reverseList();
break;
case 6: {
struct Node* list2 = NULL;
int m;
printf("Enter the number of elements for the second list: ");
scanf("%d", &m);
struct Node* temp;
for (int i = 0; i < m; i++) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
printf("Enter element %d: ", i + 1);
scanf("%d", &data);
newNode->data = data;
newNode->next = NULL;
if (list2 == NULL) {
list2 = newNode;
} else {
temp->next = newNode;
}
temp = newNode;
}
concatenate(list2);
printf("Lists concatenated successfully.\n");
break;
}
case 7:
printf("Exiting the program.\n");
break;
default:
printf("Invalid choice. Please try again.\n");
}
} while (ch != 7);
return 0;
}


