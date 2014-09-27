#include "printer.h"

void printer(const struct node *paragraph){
  while(paragraph != NULL) {
    printf("%s\n", paragraph -> word);
    paragraph = paragraph -> next;
  }
}

