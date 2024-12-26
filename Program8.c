#include<stdio.h>
#include<stdlib.h>
struct BST {
int data;
struct BST *left;
struct BST *right;
};
struct BST *create() {
struct BST *temp;
temp = (struct BST *)malloc(sizeof(struct BST));
printf("Enter data: ");
scanf("%d", &temp->data);
temp->left = temp->right = NULL;
return temp;
}
void insert(struct BST *root, struct BST *temp) {
if (temp->data < root->data) {
if (root->left == NULL)
root->left = temp;
else
insert(root->left, temp);
} else if (temp->data > root->data) {
if (root->right == NULL)
root->right = temp;
else
insert(root->right, temp);
}
}
void preorder(struct BST *root) {
if (root != NULL) {
printf("%d ", root->data);
preorder(root->left);
preorder(root->right);
}
}
void inorder(struct BST *root) {
if (root != NULL) {
inorder(root->left);
printf("%d ", root->data);
inorder(root->right);
}
}
void postorder(struct BST *root) {
if (root != NULL) {
postorder(root->left);
postorder(root->right);
printf("%d ", root->data);
}
}
int main() {
char ch;
struct BST *root = NULL, *temp;
do {
temp = create();
if (root == NULL)
root = temp;
else
insert(root, temp);
printf("Do you want to enter more(y/n)? ");
getchar();
scanf("%c", &ch);
} while (ch == 'y' || ch == 'Y');
printf("Preorder Traversal: ");
preorder(root);
printf("\nInorder Traversal: ");
inorder(root);
printf("\nPostorder Traversal: ");
postorder(root);
return 0;
}
