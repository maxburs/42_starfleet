#ifndef HEADER_H
# define HEADER_H

# include <string.h> //size_t

/*--------------------------------
  !! required structure
  --------------------------------*/
struct s_player {
  char  *timeStamp;
  int   score;
  char  *name;
};

/*--------------------------------
  :) function you must implement
  --------------------------------*/
struct s_player **mergeSort(struct s_player **players);

/*--------------------------------
  ?? test function used in main
  --------------------------------*/
struct s_player **genRandomPlayers(int n);
struct s_player *createRandomPlayer(char *name, char *timeStamp);
void printPlayers(struct s_player **players);

/*--------------------------------
  &  your own other function
  --------------------------------*/

struct s_player **find_terminator(struct s_player **players);
void merge(struct s_player **group, struct s_player **terminator, size_t group_size);
size_t new_group_size(struct s_player **group, struct s_player **terminator, size_t group_size);

#endif
