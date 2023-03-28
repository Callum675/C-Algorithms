/*Build:
gcc dictionary.c main.c -o main*/
#include <stdio.h>
#include <string.h>
#include "dictionary.h"

int main()
{
  struct dictionary dict[100];
  int num_entries = 0;

  // Add some initial entries to the dictionary
  add_word(dict, &num_entries, "apple", "a round fruit with red or green skin and a white flesh");
  add_word(dict, &num_entries, "banana", "a long curved fruit with a yellow skin");
  add_word(dict, &num_entries, "cherry", "a small round fruit with a red or black skin and a stone in the middle");

  // Loop to get user input and perform dictionary operations
  int done = 0;
  while (!done)
  {
    printf("\nEnter an operation (lookup/add/remove/quit): ");
    char operation[10];
    scanf("%s", operation);

    if (strcmp(operation, "lookup") == 0)
    {
      // Look up a word in the dictionary
      char word_to_lookup[50];
      printf("Enter a word to look up: ");
      scanf("%s", word_to_lookup);

      int index = lookup_word(dict, num_entries, word_to_lookup);
      if (index != -1)
      {
        printf("%s: %s\n", dict[index].word, dict[index].definition);
      }
      else
      {
        printf("Word not found in dictionary.\n");
      }
    }
    else if (strcmp(operation, "add") == 0)
    {
      // Add a new entry to the dictionary
      char new_word[50];
      char new_definition[200];
      printf("Enter a new word: ");
      scanf("%s", new_word);
      printf("Enter a definition for %s: ", new_word);
      scanf("%s", new_definition);

      if (add_word(dict, &num_entries, new_word, new_definition))
      {
        printf("Added new word to dictionary.\n");
      }
      else
      {
        printf("Dictionary is full, unable to add new word.\n");
      }
    }
    else if (strcmp(operation, "remove") == 0)
    {
      // Remove an entry from the dictionary
      char word_to_remove[50];
      printf("Enter a word to remove: ");
      scanf("%s", word_to_remove);

      if (remove_word(dict, &num_entries, word_to_remove))
      {
        printf("Removed word from dictionary.\n");
      }
      else
      {
        printf("Word not found in dictionary.\n");
      }
    }
    else if (strcmp(operation, "quit") == 0)
    {
      // Quit the program
      done = 1;
    }
    else
    {
      // Invalid operation entered
      printf("Invalid operation.\n");
    }
  }

  return 0;
}
