#include "dictionary.h"
#include <string.h>

int lookup_word(struct dictionary *dict, int num_entries, char *word)
{
  int i;
  for (i = 0; i < num_entries; i++)
  {
    if (strcmp(dict[i].word, word) == 0)
    {
      return i;
    }
  }
  return -1;
}

int add_word(struct dictionary *dict, int *num_entries, char *word, char *definition)
{
  if (*num_entries >= 100)
  {
    return 0;
  }
  strcpy(dict[*num_entries].word, word);
  strcpy(dict[*num_entries].definition, definition);
  (*num_entries)++;
  return 1;
}

int remove_word(struct dictionary *dict, int *num_entries, char *word)
{
  int index = lookup_word(dict, *num_entries, word);
  if (index == -1)
  {
    return 0;
  }
  for (int i = index; i < (*num_entries - 1); i++)
  {
    strcpy(dict[i].word, dict[i + 1].word);
    strcpy(dict[i].definition, dict[i + 1].definition);
  }
  (*num_entries)--;
  return 1;
}
