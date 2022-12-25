#include <stdlib.h>

typedef int node_payload_t;

struct node {
  struct node* left;
  struct node* right;
  node_payload_t payload;
};

struct node* node_create(node_payload_t payload);
void node_visit(struct node* node, void (*visitor)(node_payload_t));
void node_free(struct node* node);
