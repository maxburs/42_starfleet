#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/

//BST NODE

struct s_node {
	char            *actionName;
	int             actionId;
	struct s_node   *right;
	struct s_node   *left;
};

//GRAPH

struct s_call {
	char            *action;
	struct s_person *subject;
};

struct s_person {
	char            *name;
	struct s_call   **calls;
	int             visited; //0 = FALSE, 1 = TRUE
	struct s_person **connectedPeople;
};

struct s_graph {
	struct s_person **people;
};


/*--------------------------------
  :) function you must implement
  --------------------------------*/
char **findCulprit(struct s_graph *graphPeople, struct s_node *actionRoot, int actionId);


/*--------------------------------
  ?? test function used in main 
  --------------------------------*/

//QUEUE

struct s_queueItem {
  struct s_person *person;
  struct s_queueItem *next;
};

struct s_queue {
  struct s_queueItem *first;
  struct s_queueItem *last;
};

struct s_queue *queueInit(void);
void enqueue(struct s_queue *queue, struct s_person *person);
struct s_person *dequeue(struct s_queue *queue);
void queuePrint(struct s_queue *queue);

//OTHER

struct s_node *getActionTree(char *filename);
struct s_graph *getPeople(char *filename);


/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif
