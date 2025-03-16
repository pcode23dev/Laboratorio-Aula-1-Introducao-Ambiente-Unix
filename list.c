/*
 * list.c - implementation of the integer list functions 
 */


#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "list.h"



list_t* lst_new()
{
   list_t *list;
   list = (list_t*) malloc(sizeof(list_t));
   list->first = NULL;
   return list;
}


void lst_destroy(list_t *list)
{
	struct lst_iitem *item, *nextitem;

	item = list->first;
	while (item != NULL){
		nextitem = item->next;
		free(item);
		item = nextitem;
	}
	free(list);
}


void insert_new_process(list_t *list, int pid, time_t starttime)
{
	lst_iitem_t *item;

	item = (lst_iitem_t *) malloc (sizeof(lst_iitem_t));
	item->pid = pid;
	item->starttime = starttime;
	item->endtime = 0;
	item->next = list->first;
	list->first = item;
}


void update_terminated_process(list_t *list, int pid, time_t endtime)
{
	int isFound = 0;
	lst_iitem_t *item = list->first;

	if (item){
		printf("> > > Finishing process with PID: %d\n", pid);
		do{
			if (item->pid == pid){
				isFound = 1;
				item->endtime = endtime;
			} 
			item = item->next;
		} while (item != NULL && isFound != 1); 
	} else {
		printf("> > > Process list empyte");
	}
	
	isFound == 1 ? printf("      Process finished\n"): printf("      Process not found\n");

}


void lst_print(list_t *list)
{
	lst_iitem_t *item;

	printf("\n> > > Process list with start and end time:\n");
	item = list->first;
	//while(1){ /* use it only to demonstrate gdb potencial */
	while (item != NULL){
		printf("PID: %d\t -> StartTime: %s", item->pid, ctime(&(item->starttime)));
		printf("\t -> EndTime: %s", ctime(&(item->endtime)));
		item = item->next;
	}

	printf("> > >  End of list.\n\n");
}
