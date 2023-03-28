#include <stdio.h>
#include "list.h"

int main()
{
  struct Node *head = NULL;

  // Insert some data into the linked list
  insert(&head, 5);
  insert(&head, 10);
  insert(&head, 15);

  // Display the linked list
  display(head); // Output: 15 10 5

  // Delete some data from the linked list
  delete (&head, 10);

  // Display the linked list again
  display(head); // Output: 15 5

  return 0;
}
