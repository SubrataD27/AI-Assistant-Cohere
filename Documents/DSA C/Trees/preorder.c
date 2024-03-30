#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* left;
  struct Node* right;
};

// Helper function to create a new node
struct Node* newNode(int data) {
  struct Node* node = (struct Node*)malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

// Recursive function to perform preorder traversal
void preorderTraversalRecursive(struct Node* root) {
  if (root != NULL) {
    printf("%d ", root->data);  // Visit root first in preorder
    preorderTraversalRecursive(root->left);
    preorderTraversalRecursive(root->right);
  }
}

int main() {
  struct Node* root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);

  printf("Preorder traversal (recursive): ");
  preorderTraversalRecursive(root);

  return 0;
}