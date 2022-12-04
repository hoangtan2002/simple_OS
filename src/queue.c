#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/* TODO: put a new process to queue [q] */	
	int idx=0;
	// if(q->size==0){
	// 	q->proc[0] = proc;
	// 	q->size++;
	// }
	// else{
	// 	//enqueue in increasing order of priority
	// 	for(;idx < q->size; idx++){
	// 		if(proc->prio < q->proc[idx]->prio) break;	
	// 	}
	// 	for(int i=q->size; i>idx; i--){
	// 		q->proc[i] = q->proc[i-1];
	// 	}
	// 	q->proc[idx] = proc;
	// 	q->size++;
	// }
	q->proc[q->size++] = proc;
}

struct pcb_t * dequeue(struct queue_t * q) {
	/* TODO: return a pcb whose prioprity is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
	// if(q->size == 0) return NULL;
	// struct pcb_t* to_return = q->proc[--q->size];
	// return to_return;

	struct pcb_t* to_return = NULL;
	// if(q->size!=0){
	// 	to_return = q->proc[q->size-1];
	// 	q->proc[q->size-1] = NULL;
	// 	q->size--;
	// }
	if(q->size!=0){
		to_return = q->proc[0];
		for(int i=0; i<q->size-1; i++){
			q->proc[i] = q->proc[i+1];
		}
		q->proc[q->size-1] = NULL;
		q->size--;
	}
	return to_return;
}

