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

// Function to perform preorder traversal without recursion
void preorderTraversalIterative(struct Node* root) {
  struct Node* stack[100]; // Adjust stack size based on tree height
  int top = -1;

  if (root != NULL) {
    stack[++top] = root;

    while (top != -1) {
      // Pop from stack and print data
      struct Node* current = stack[top--];
      printf("%d ", current->data);

      // Push right child first (processed later)
      if (current->right != NULL) {
        stack[++top] = current->right;
      }

      // Push left child (processed before right)
      if (current->left != NULL) {
        stack[++top] = current->left;
      }
    }
  }
}

int main() {
  struct Node* root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);

  printf("\nPreorder traversal (iterative): ");
}