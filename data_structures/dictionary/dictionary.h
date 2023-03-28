#ifndef DICTIONARY_H
#define DICTIONARY_H

struct dictionary
{
  char word[50];
  char definition[200];
};

int lookup_word(struct dictionary *dict, int num_entries, char *word);
int add_word(struct dictionary *dict, int *num_entries, char *word, char *definition);
int remove_word(struct dictionary *dict, int *num_entries, char *word);

#endif
