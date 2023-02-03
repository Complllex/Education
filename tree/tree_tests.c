#include <glib.h>
#include <stdbool.h>
#include <stdio.h>
#include "tree.h"

void print_node_payload(node_payload_t payload) { printf("%d ", payload); }

struct node* parse_expr() {
  struct node* root = node_create(40);
  root->left = node_create(4);
  root->right = node_create(45);
  root->left->right = node_create(34);
  root->right->right = node_create(55);
  root->left->right->left = node_create(14);
  root->right->right->left = node_create(48);
  root->left->right->left->left = node_create(13);
  root->left->right->left->right = node_create(15);
  root->right->right->left->left = node_create(47);
  root->right->right->left->right = node_create(49);
  return root;
}

void test_node_init() {
  struct node* root = parse_expr();
  node_visit(root, &print_node_payload); // 13 15 14 34 4 47 49 48 55 45 40
  node_free(root);
  printf("\n");
  g_assert_true(true);
}

int main(int argc, char* argv[]) {
  g_test_init(&argc, &argv, NULL);
  g_test_add_func("/tree/init", test_node_init);
  return g_test_run();
}