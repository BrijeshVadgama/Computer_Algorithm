// linkded list

#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *link;
};

struct node *create(int n) {
	struct node *new = (struct node *)malloc(sizeof(struct node));
	new->data = n;
	new->link = NULL;
	return struct node *new;
}

void InsertEnd(struct node **ptr, int n) {
	struct node *newnode = create(n);
	if(ptr == NULL) {
		*ptr = newnode;
		return;
	}
	
	struct node *current = *ptr;
	while(current->link != NULL) {
		current = current->link;
	}
	
	current->link = NULL;
} 

void main(){
	struct node *ptr = NULL;
	int choice;
	
	while(1) {
		printf("\n1. Insert At End\n2. Delete From End\n3. Delete\n4. Display\n0. Exit");
		printf("\nEnter Your Choice: ");
		scanf("%d",&choice);
		
		switch(choice) {
			case 1:
				
				break;
				
			case 2:
				
				break;
				
			case 3:
				
				break;
				
			case 4:
				display();
				break;
				
			case 0:
				exit(0);
				
			default:
				printf("\nInvalid Choice.!");
		}
	}
}
