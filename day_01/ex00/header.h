#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required
  --------------------------------*/
# define CS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 !?:;,.$&<>()+*-_="

struct s_node {
	char c;
	struct s_node *prev;
	struct s_node *next;
};

/*--------------------------------
  :) function you must implement
  --------------------------------*/
char *precious(int *text, int size);

/*--------------------------------
  ?? test function used in main
  --------------------------------*/


/*--------------------------------
  &  your own other function
  --------------------------------*/

struct s_node *move(struct s_node *list, int move);
struct s_node *build_list(char *cs);
void push_node(struct s_node **list, struct s_node *node);
void free_list(struct s_node *node);

#endif
