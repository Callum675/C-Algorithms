#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void insert(struct Node **head_ref, int new_data)
{
  // Allocate memory for new node
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

  // Set data for new node
  new_node->data = new_data;

  // Set next of new node to head
  new_node->next = (*head_ref);

  // Set head to new node
  (*head_ref) = new_node;
}

void delete(struct Node **head_ref, int key)
{
  // Store head node
  struct Node *temp = *head_ref, *prev;

  // If head node itself holds the key to be deleted
  if (temp != NULL && temp->data == key)
  {
    *head_ref = temp->next; // Change head
    free(temp);             // Free old head
    return;
  }

  // Search for the key to be deleted
  while (temp != NULL && temp->data != key)
  {
    prev = temp;
    temp = temp->next;
  }

  // If key was not present in linked list
  if (temp == NULL)
  {
    return;
  }

  // Unlink the node from linked list
  prev->next = temp->next;

  // Free memory
  free(temp);
}

void display(struct Node *head)
{
  struct Node *temp = head;
  while (temp != NULL)
  {
    printf("%d ", temp->data);
    temp = temp->next;
  }
}
