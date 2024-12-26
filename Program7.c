#include <stdio.h>
#include <stdlib.h>
struct node {
int data;
struct node *next;
struct node *prev;
};
struct node *head = NULL, *tail = NULL;
void create() {
struct node *newnode;
int ch = 1;
while (ch==1) {
newnode = (struct node *)malloc(sizeof(struct node));
printf("Enter the data: ");
scanf("%d", &newnode->data);
newnode->next = NULL;
newnode->prev = NULL;
if (head == NULL) {
head = tail = newnode;
} else {
tail->next = newnode;
newnode->prev = tail;
tail = newnode;
}
printf("Enter 1 to continue: ");
scanf("%d", &ch);
}
}
void insertBeg(int x) {
struct node *newnode;
newnode = (struct node *)malloc(sizeof(struct node));
newnode->data = x;
newnode->prev = NULL;
if (head == NULL) {
head = tail = newnode;
newnode->next = NULL;
} else {
newnode->next = head;
head->prev = newnode;
head = newnode;
}
}
void insertEnd(int x) {
struct node *newnode;
newnode = (struct node *)malloc(sizeof(struct node));
newnode->data = x;
newnode->next = NULL;
if (head == NULL) {
head = tail = newnode;
newnode->prev = NULL;
} else {
newnode->prev = tail;
tail->next = newnode;
tail = newnode;
}
}
void insertPos(int x) {
struct node *newnode, *temp;
int pos;
printf("Enter the position: ");
scanf("%d", &pos);
if (pos == 1) {
insertBeg(x);
} else {
newnode = (struct node *)malloc(sizeof(struct node));
newnode->data = x;
newnode->next = NULL;
newnode->prev = NULL;
temp = head;
for (int i = 1; i < pos - 1; i++) {
temp = temp->next;
if (temp == NULL) {
printf("There are less than %d nodes", pos);
return;
}
}
newnode->prev = temp;
newnode->next = temp->next;
if (temp->next != NULL) temp->next->prev = newnode;
temp->next = newnode;
if (newnode->next == NULL) tail = newnode;
}
}
void display() {
struct node *temp;
if (head == NULL) {
printf("List is empty\n");
} else {
temp = head;
while (temp != NULL) {
printf("%d ", temp->data);
temp = temp->next;
}
printf("\n");
}
}
int main() {
int ch, x;
while (1) {
printf("\n1. Create DLL\n2. Insert at Beginning\n3. Insert at End\n4. Insert at Position\n5. Display\n6. Exit\n");
printf("Enter your choice: ");
scanf("%d", &ch);
switch (ch) {
case 1: create();
break;
case 2: printf("Enter the data to insert at beginning: ");
scanf("%d", &x);
insertBeg(x);
break;
case 3: printf("Enter the data to insert at end: ");
scanf("%d", &x);
insertEnd(x);
break;
case 4: printf("Enter the data to insert: ");
scanf("%d", &x);
insertPos(x);
break;
case 5: display();
break;
case 6: exit(0);
default: printf("Invalid choice\n");
}
}
return 0;
}

