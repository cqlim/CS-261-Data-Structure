#include <stdio.h>
#include <assert.h> 
#include <stdlib.h>
#include <float.h>
#include "cirListDeque.h"

/* Double Link Struture */
struct DLink {
	TYPE value;/* value of the link */
	struct DLink * next;/* pointer to the next link */
	struct DLink * prev;/* pointer to the previous link */
};

# define TYPE_SENTINEL_VALUE DBL_MAX 


/* ************************************************************************
 Deque ADT based on Circularly-Doubly-Linked List WITH Sentinel
 ************************************************************************ */

struct cirListDeque {
	int size;/* number of links in the deque */
	struct DLink *Sentinel;	/* pointer to the sentinel */
};
/* internal functions prototypes */
struct DLink* _createLink (TYPE val);
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, TYPE v);
void _removeLink(struct cirListDeque *q, struct DLink *lnk);



/* ************************************************************************
	Deque Functions
************************************************************************ */

/*
 create a new circular list deque
 
	pre:    none
 	post:	returns pointer to allocated deque q, q->Sentinel is allocated and q->size equals zero
 
 */

struct cirListDeque *createCirListDeque()
{
	struct cirListDeque *ptr = malloc(sizeof(struct cirListDeque));
	assert(ptr != NULL);
	ptr->size = 0;
	ptr->Sentinel = malloc(sizeof(struct DLink));
	ptr->Sentinel->next = ptr->Sentinel;
	ptr->Sentinel->prev = ptr->Sentinel;
	/* FIXME: you must write this */
	return ptr;
}


/* Create a link for a value.

	param: 	val		the value to create a link for
	pre:	none
	post:	a link to store the value
*/
struct DLink * _createLink (TYPE val)
{
	/* FIXME: you must write this */

	/*temporary return value..you may need to change it*/
	struct DLink *ptr = malloc(sizeof(struct DLink));
	assert(ptr != NULL);
	ptr->value = val;
	ptr->next = NULL;
	ptr->prev = NULL;
	return ptr;
}

/* Adds a link after another link

	param: 	q		pointer to the deque
	param: 	lnk		pointer to the existing link in the deque
	param: 	v		value of the new link to be added after the existing link
	pre:	q is not null
	pre: 	lnk is not null
	pre:	lnk is in the deque 
	post:	the new link is added into the deque after the existing link
*/
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, TYPE v)
{
	/* FIXME: you must write this */	 
	struct DLink *ptr = _createLink(v);
	ptr->next = lnk->next;
	ptr->prev = lnk;
	lnk->next->prev = ptr;
	lnk->next = ptr;
	q->size += 1;
}

/* Adds a link to the back of the deque

	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the back of the deque
*/
void addBackCirListDeque (struct cirListDeque *q, TYPE val) 
{
	/* FIXME: you must write this */
	assert(q != NULL);
	_addLinkAfter(q, q->Sentinel->prev, val);
}

/* Adds a link to the front of the deque

	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the front of the deque
*/
void addFrontCirListDeque(struct cirListDeque *q, TYPE val)
{
	/* FIXME: you must write this */	 
	assert(q != NULL);
	_addLinkAfter(q, q->Sentinel, val);
}

/* Get the value of the front of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the front of the deque
*/
TYPE frontCirListDeque(struct cirListDeque *q) 
{
	return q->Sentinel->next->value;
	/* FIXME: you must write this */	 
	/*temporary return value..you may need to change it*/
}

/* Get the value of the back of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the back of the deque
*/
TYPE backCirListDeque(struct cirListDeque *q)
{
	/* FIXME: you must write this */	 
	/*temporary return value..you may need to change it*/
	return q->Sentinel->prev->value;
}

/* Remove a link from the deque

	param: 	q		pointer to the deque
	param: 	lnk		pointer to the link to be removed
	pre:	q is not null and q is not empty
	post:	the link is removed from the deque
*/
void _removeLink(struct cirListDeque *q, struct DLink *lnk)
{
	/* FIXME: you must write this */	 
	assert(q != NULL && isEmptyCirListDeque(q) != 1);
	lnk->prev->next = lnk->next;
	lnk->next->prev = lnk->prev;
	free(lnk);
	q->size -= 1;
}

/* Remove the front of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the front is removed from the deque
*/
void removeFrontCirListDeque (struct cirListDeque *q) {
	/* FIXME: you must write this */	 
	assert(q != NULL && isEmptyCirListDeque(q) != 1);
	_removeLink(q, q->Sentinel->next);
}


/* Remove the back of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the back is removed from the deque
*/
void removeBackCirListDeque(struct cirListDeque *q)
{
  	/* FIXME: you must write this */	 
	assert(q != NULL && isEmptyCirListDeque(q) != 1);
	_removeLink(q, q->Sentinel->prev);
}

/* De-allocate all links of the deque, and the deque itself

	param: 	q		pointer to the deque
	pre:	none
	post:	All links (including Sentinel) are de-allocated
*/
void freeCirListDeque(struct cirListDeque *q)
{
	/* FIXME: you must write this */	 
	while (q->Sentinel->next != q->Sentinel && q->Sentinel->prev != q->Sentinel)
	{
		removeFrontCirListDeque(q);
	}
	free(q->Sentinel);
	free(q);
}

/* Check whether the deque is empty

	param: 	q		pointer to the deque
	pre:	q is not null
	ret: 	1 if the deque is empty. Otherwise, 0.
*/
int isEmptyCirListDeque(struct cirListDeque *q) {
	assert(q != NULL);
	if (q->size == 0 || (q->Sentinel->next == q->Sentinel && q->Sentinel->prev == q->Sentinel)) {
		return 1;
	}
	else {
		return 0;
	}
}

/* Print the links in the deque from front to back

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post: 	the links in the deque are printed from front to back
*/
void printCirListDeque(struct cirListDeque *q)
{
	/* FIXME: you must write this */	 
	struct DLink *ptr = q->Sentinel->next;
	printf("Deque contains: ");
	while (ptr != q->Sentinel)
	{
		printf("%f, ", ptr->value);
		ptr = ptr->next;
	}
	printf("\n");
}
