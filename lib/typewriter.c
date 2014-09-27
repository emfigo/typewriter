#include "printer.h"
#include "reader.h"

void free_structure(struct node *words){
  struct node *prev;
  struct node *current;

  current = words;
  while(current != NULL){
    prev = current;
    current = current -> next;
    free(prev);
  }
}

int main(int argc, char *argv[]){
  struct node *words;

  if( argv[1] == NULL ){
    printf("You need to specify a paragraph to read\n");
    return -1;
  }

  words = read_words(argv[1]);
  
  printer(words);
  
  free_structure(words);

  return 0;
}
