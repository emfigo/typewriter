#include "reader.h"

struct node *read_words(const char *paragraph){
  char *string = malloc(50 * sizeof(char));
  char *letter = malloc(4 * sizeof(char));
  int i, max = strlen(paragraph);
  struct node *words = NULL;
  
  if( paragraph == NULL ){
    return NULL;
  }

  for( i = 0; i < max; i++ ){
    if(paragraph[i] != ' '){
      sprintf(letter,"%c", paragraph[i]);
      strcat(string, letter);
    }

    if((paragraph[i] == ' ') || (i == max - 1)){
      create_word(&words, string);
      strcpy(string, "");
    }
  }

  free(string);
  free(letter);
  return words;
}

void create_word(struct node **words, const char *word){
  struct node *new_word = malloc(sizeof(struct node));
  int string_size = strlen(word);

  new_word -> word = malloc(string_size * sizeof(char));
  strcpy(new_word -> word, word);
  new_word -> next = NULL;

  if(*words == NULL){
    *words = new_word;
  }else{
    struct node *pointer = *words;

    while(pointer -> next != NULL){
      pointer = pointer -> next;
    }

    pointer -> next = new_word;
    pointer = NULL;
  }

  new_word = NULL;
}
