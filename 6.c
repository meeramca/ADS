#include <stdio.h>
#include <stdlib.h>
struct node {
  int key;
  struct node *left, *right;
};
struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}
void inorder(struct node *root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d -> ", root->key);
    inorder(root->right);
  }
}
struct node *insert(struct node *node, int key) {
  if (node == NULL) return newNode(key);
  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);
  return node;
}
struct node *minValueNode(struct node *node) {
  struct node *current = node;

  while (current && current->left != NULL)
  current = current->left;
  return current;
}
struct node *deleteNode(struct node *root, int key) {
  if (root == NULL) return root;
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);
  else {
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }
    struct node *temp = minValueNode(root->right);
    root->key = temp->key;
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}
void main() {
  struct node *root = NULL;
  int choice, n;
        while(1){
                printf(" 1. Operation for Insertion");
                printf("\n 2.Operation for Deletion");
                printf("\n 3.Operation for Traversal");
                printf("\n 4.Exit");
                printf("\nEnter your choice:\n");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1: printf("Enter the element to be Inserted:");
                                scanf("%d",&n);
                                root = insert(root, n);
                                break;
                        case 2: printf("Enter the element to be Deleted:");
                                scanf("%d",&n);
                                root = deleteNode(root, n);
                                break;
                        case 3: printf("Inorder traversal: \n");
                                inorder(root);
                                break;
                         case 4:
                                        exit(0);
                                        break;
                        default:
                                        printf("n Wrong Choice:n");
                                        break;
                }
        }
}

