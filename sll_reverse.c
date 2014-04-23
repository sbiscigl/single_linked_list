/* code to practice reversing a singly linked list*/

/*include system libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*structure for a single linked node*/
typedef struct sll_node{
	/*data container for the value in the node*/
	int value;
	/*data container for a pointer to the next node*/
	struct sll_node * next;
} sll_node;

/*structure for a single linked list*/
typedef struct sll{
	/*pointer to the head of the list*/
	sll_node * head;
}sll;

/*constuctor for node*/
void init_node(sll_node * the_node, int value){
	the_node->next  = NULL;
	the_node->value = value;
}

/*constuctor for list*/
void init_list(sll * list){
	list->head = NULL;
}

/*insert into a list*/
void insert_node(sll_node * the_node, sll * list){
	/*temp pointer for list travseral*/
	sll_node * travseral = list->head;
	/*empty list case*/
	if(list->head == NULL){
		list->head = the_node;
	}
	else{
		while(travseral->next != NULL){
			/*travese list*/
			travseral = travseral->next;
		}
		/*insert node*/
		travseral->next = the_node;
	}
}

/*function that reverses a list*/
void reverse_list(sll * list){
	/*create temp variables to reverse list*/
	sll_node * ptr_cur = list->head;
	sll_node * ptr_tail = NULL;
	sll_node * ptr_nxt;
	/*traverse list and reverse*/
	while(ptr_cur->next != NULL){
		ptr_nxt = ptr_cur->next;
		ptr_cur->next = ptr_tail;
		ptr_tail = ptr_cur;
		ptr_cur = ptr_nxt;
	}
}

/*driver of program, main program*/
int main(){
	/*program starting*/
	printf("program starting...........");
	printf("OK\n");

	/*seeding time*/
	printf("seeding time...............");

	srand(time(NULL));


	printf("OK\n");

	/*create array of nodes*/
	printf("creating alot of nodes");

	/*variable for a random varibale*/
	int random_value;

	sll_node * node_array;
	node_array = (sll_node*)malloc(sizeof(sll_node)*1000);

	for (int i = 0; i < 1000; i++){	
		if(i%100 == 0){
			printf(".");
		}
		random_value = rand() % 10 + 1;
		init_node(&node_array[i], random_value);
	}

	printf("OK\n");

	/*
	for (int i = 0; i < 1000; i++){	
		printf("%i, ", node_array[i].value);
		if(i%25 == 0){
			printf("\n");
		}
	}
	*/

	/*creating a list*/

	printf("creating a list............");

	sll * final_list;
	final_list = (sll*)malloc(sizeof(sll));

	printf("OK\n");

	printf("populating list............");

	for (int i = 0; i < 1000; ++i){
		insert_node(&node_array[i],final_list);
	}

	printf("OK\n");

	/*reverse the list*/

	printf("reversing the list.........");
	reverse_list(final_list);
	printf("OK\n");

	printf("validating reversed list...");

	// int validation_flag = 1;
	// sll_node * temp_ptr = final_list->head;
	// for (int i = 0; i < 1000; i++){
	// 	printf("the pointers value : %i\n", temp_ptr->value);
	// 	printf("the expected value : %i\n", node_array[999-i].value);
	// 	if(temp_ptr->value == node_array[999-i].value){
	// 		/*LET IT RIIIIIIIIDE*/
	// 		printf("this might happen a lot\n");
	// 	}
	// 	else{
	// 		validation_flag = 0;
	// 	}
	// 	temp_ptr = temp_ptr->next;
	// }

	// if(validation_flag == 1){
	// 	printf("OK\n");
	// }
	// else{
	// 	printf("FAIL\n");
	// }

	/*end of program*/
	return 0;
}