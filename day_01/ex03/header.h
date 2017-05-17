#ifndef HEADER_H
# define HEADER_H

# define MAX_MESSAGE_LENGTH 255

/*--------------------------------
  !! required structure
  --------------------------------*/
struct s_item {
	int idx;
	struct s_item *next;
};

struct s_stack {
	struct s_item *item;
};

/*--------------------------------
  :) function you must implement
  --------------------------------*/
struct s_stack *initStack();
void push(struct s_stack *stack, int idx);
int pop(struct s_stack *stack);

char *console(void);

/*--------------------------------
  ?? test function used in main
  --------------------------------*/


/*--------------------------------
  &  your own other function
  --------------------------------*/

struct s_item *create_new_item(int idx);

#endif
