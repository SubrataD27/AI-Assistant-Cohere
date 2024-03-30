#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// Function to perform inorder traversal without recursion
void inorderTraversalIterative(struct Node* root) {
  struct Node* current = root;
  struct Node* stack[100]; // Adjust stack size based on tree height
  int top = -1;

  while (current != NULL || top != -1) {
    // Traverse left subtree
    while (current != NULL) {
      stack[++top] = current;
      current = current->left;
    }

    // Pop from stack and print data
    if (top != -1) {
      current = stack[top--];
      printf("%d ", current->data);
      current = current->right;
    }
  }
}

int main() {
  struct Node* root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);

  printf("\nInorder traversal (iterative): ");
  inorderTraversalIterative(root);

  return 0;
}