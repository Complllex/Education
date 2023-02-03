#include "tree.h"
#include <stddef.h>

struct node* node_create(int payload) {
  struct node* node = malloc(sizeof(struct node));
  node->left = NULL;
  node->right = NULL;
  node->payload = payload;
  return node;
}

void node_visit(struct node* node, void (*visitor)(payload_t)) {
  if (node->left == NULL && node->right == NULL) {
    visitor(node->payload);
  }
  if (node->left != NULL) {
    // visitor(node->payload);
    node_visit(node->left, visitor);
  }
  if (node->right != NULL) {
    // visitor(node->payload);
    node_visit(node->right, visitor);
  }
}

void node_free(struct node* node) {
  if (node->left != NULL) {
    node_free(node->left);
  }
  if (node->right != NULL) {
    node_free(node->right);
  }
  free(node);
}
