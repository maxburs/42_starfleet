#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/
struct s_player {
	int   score;
	char  *name;
};

/*--------------------------------
  :) function you must implement
  --------------------------------*/
void insertionSort(struct s_player **players);

/*--------------------------------
  ?? test function used in main
  --------------------------------*/
struct s_player **genRandomPlayers(int n);
struct s_player *createRandomPlayer(char *name);
void printPlayers(struct s_player **players);

/*--------------------------------
  &  your own other function
  --------------------------------*/

struct s_player **find_end(struct s_player **players);
void insert(struct s_player **array, struct s_player **player);
void insert_at(struct s_player **player, struct s_player **new_position);

#endif
