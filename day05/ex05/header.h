#ifndef HEADER_H
# define HEADER_H

#include <string.h>

/*--------------------------------
  !! required structure
  --------------------------------*/

/*--------------------------------
  :) function you must implement
  --------------------------------*/
void	printUniquePermutations(char *str);


/*--------------------------------
  ?? test function used in main 
  --------------------------------*/

// DICTIONNARY

struct s_item {
  char          *key;
  int           value;
  struct s_item *next;
};

struct s_dict {
  struct s_item **items;
  int           capacity; //the capacity of the array 'items'
};

struct s_dict *dictInit(int capacity);
int dictInsert(struct s_dict *dict, char *key, int value); //return -1 if fail
int dictSearch(struct s_dict *dict, char *key);

/*--------------------------------
  &  your own other function
  --------------------------------*/
void add_letters(char *str, size_t *letters);
void printPermutations(char *front, char *str, size_t *letters) ;

#endif
