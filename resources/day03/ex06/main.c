#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{
	struct s_node *actionTree;
	struct s_graph *graph;
	char **culprits;

	printf("Creating the graph ...");
	actionTree = getActionTree("actions.txt");
	graph = getPeople("people.txt");
	printf(" finished.\n");
	culprits = NULL;

	/*-------------------
	launch your test here
	--------------------*/
	
	// printf("------------- %s\n", "Cereal bar robbery");
	// culprits = findCulprit(graph, actionTree, 612);
	// if (culprits) {
	// 	for (int i = 0; culprits[i]; i++) {
	// 		printf("%s\n", culprits[i]);
	// 	}
	// }
	
	return (0);
}



// Function used for the test
// Don't go further :)

//QUEUE

void enqueue(struct s_queue *queue, struct s_person *person) {
	struct s_queueItem* elem;

	if (!(elem = (struct s_queueItem *)malloc(sizeof(struct s_queueItem))))
		return;
	elem->person = person;
	elem->next = NULL;
	if (queue->last) {
		queue->last->next = elem;
	}
	queue->last = elem;
	if (queue->first == NULL) {
		queue->first = queue->last;
	}
}

struct s_person *dequeue(struct s_queue *queue) {
	struct s_queueItem *elem;
	struct s_person *person;

	if (queue->first == NULL)
		return (NULL);
	elem = queue->first;
	person = elem->person;
	queue->first = elem->next;
	if (queue->first == NULL) {
		queue->last = NULL;
	}
	free(elem);
	return (person);
}

void queuePrint(struct s_queue *queue) {
	struct s_queueItem* tmp;

	tmp = queue->first;
	printf("queue:\n");
	while (tmp) {
		printf("%s\n", tmp->person->name);
		tmp = tmp->next;
	}
}

struct s_queue *queueInit(void)
{
	struct s_queue *queue;

	queue = malloc(sizeof(struct s_queue));
	if (!queue)
		return (NULL);
	queue->first = NULL;
	queue->last = NULL;
	return (queue);
}

//OTHER

struct s_node* newNodeBST(int actionId, char *actionName)
{
    struct s_node* node = (struct s_node*)malloc(sizeof(struct s_node));
    node->actionName = actionName;
    node->actionId   = actionId;
    node->left   = NULL;
    node->right  = NULL;
    // node->height = 1;
    return(node);
}

struct s_node* insertBST(struct s_node* node, int actionId, char *actionName)
{
    if (node == NULL)
        return (newNodeBST(actionId, actionName));
    if (actionId < node->actionId)
        node->left  = insertBST(node->left, actionId, actionName);
    else if (actionId > node->actionId)
        node->right = insertBST(node->right, actionId, actionName);
    else
    	return (node);
    return (node);
}

struct s_node *getActionTree(char *filename) {
	FILE			*f;
	int				actionId;
	char			*actionName = NULL;
	struct s_node	*bst = NULL;
	size_t 			linecap = 0;
	ssize_t 		linelen;

	if (!(f = fopen(filename, "r"))) {
		printf("Couldn't find %s\n", filename);
		exit(1);
	}
	while (fscanf(f, "%d ", &actionId) > 0 && (linelen = getline(&actionName, &linecap, f)) > 0) {
		actionName[linelen - 1] = 0;
		bst = insertBST(bst, actionId, actionName);
		actionName = NULL;
	}
	return (bst);
}

struct s_person **getNetwork(FILE *f) {
	long int		id2;
	int				i, size;
	struct s_person	**connectedPeople;

	fscanf(f, "%d\n", &size);
	if (!(connectedPeople = (struct s_person **)malloc(sizeof(struct s_person *) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size && fscanf(f, "%ld\n", &id2) > 0) {
		connectedPeople[i] = (struct s_person *)(id2 + 1);
		i++;
	}
	connectedPeople[i] = NULL;
	return (connectedPeople);
}

struct s_call **getCalls(FILE *f) {
	long int		idSubject;
	char			*actionName = NULL;
	size_t 			linecap = 0;
	ssize_t 		linelen;
	int				i, size;
	struct s_call	**calls;

	fscanf(f, "%d\n", &size);
	if (!(calls = (struct s_call **)malloc(sizeof(struct s_call *) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size && fscanf(f, "%ld ", &idSubject) > 0 && (linelen = getline(&actionName, &linecap, f)) > 0) {
		actionName[linelen - 1] = 0;
		if (!(calls[i] = (struct s_call *)malloc(sizeof(struct s_call))))
			return (NULL);
		calls[i]->subject = (struct s_person *)(idSubject + 1);
		calls[i]->action = actionName;
		i++;
		actionName = NULL;
	}
	calls[i] = NULL;
	return (calls);
}

void update(struct s_graph *graph) {
	struct s_person	**people;
	struct s_person	**connectedPeople;
	struct s_call	**calls;

	people = graph->people;
	for (int i = 0; people[i]; i++) {
		connectedPeople = people[i]->connectedPeople;
		for (int j = 0; connectedPeople[j]; j++) {
			connectedPeople[j] = people[(int)(connectedPeople[j]) - 1];
		}
		calls = people[i]->calls;
		for (int j = 0; calls[j]; j++) {
			calls[j]->subject = people[(int)(calls[j]->subject) - 1];
		}
	}
}

struct s_graph *getPeople(char *filename) {
	FILE			*f;
	struct s_graph *graph;
	size_t 			linecap = 0;
	ssize_t 		linelen;
	int				i, size;
	char			*name = NULL;

	if (!(graph = (struct s_graph *)malloc(sizeof(struct s_graph))))
		return (NULL);
	if (!(f = fopen(filename, "r"))) {
		printf("Couldn't find %s\n", filename);
		exit(1);
	}
	fscanf(f, "%d\n", &size);
	if (!(graph->people = (struct s_person **)malloc(sizeof(struct s_person *) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size && (linelen = getline(&name, &linecap, f)) > 0) {
		name[linelen - 1] = 0;
		if (!(graph->people[i] = (struct s_person *)malloc((sizeof(struct s_person)))))
			return (NULL);
		graph->people[i]->name = name;
		if (!(graph->people[i]->connectedPeople = getNetwork(f)))
			return (NULL);
		if (!(graph->people[i]->calls = getCalls(f)))
			return (NULL);
		name = NULL;
		i++;
	}
	graph->people[i] = NULL;
	update(graph);
	return (graph);
}
