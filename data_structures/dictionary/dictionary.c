/*C Dictionary*/
#include <stdio.h>
#include <string.h>

// Define the struct for the dictionary entry
struct dictionary
{
  char word[50];
  char definition[200];
};

int main()
{
  // Create an array of dictionary entries
  struct dictionary dict[100];

  // Add some entries to the dictionary
  strcpy(dict[0].word, "apple");
  strcpy(dict[0].definition, "a round fruit with red or green skin and a white flesh");

  strcpy(dict[1].word, "banana");
  strcpy(dict[1].definition, "a long curved fruit with a yellow skin");

  strcpy(dict[2].word, "cherry");
  strcpy(dict[2].definition, "a small round fruit with a red or black skin and a stone in the middle");

  // Look up a word in the dictionary
  char word_to_lookup[50];
  printf("Enter a word to look up: ");
  scanf("%s", word_to_lookup);

  int i;
  for (i = 0; i < 100; i++)
  {
    if (strcmp(dict[i].word, word_to_lookup) == 0)
    {
      printf("%s: %s\n", dict[i].word, dict[i].definition);
      break;
    }
  }

  if (i == 100)
  {
    printf("Word not found in dictionary.\n");
  }

  return 0;
}
