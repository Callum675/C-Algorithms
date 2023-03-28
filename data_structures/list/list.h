#ifndef LIST_H
#define LIST_H

struct Node
{
  int data;
  struct Node *next;
};

void insert(struct Node **head_ref, int new_data);
void delete(struct Node **head_ref, int key);
void display(struct Node *head);

#endif
