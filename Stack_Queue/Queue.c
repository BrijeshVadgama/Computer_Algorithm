// queue

#include<stdio.h>
#include<stdlib.h>
#define MAX 5

struct queue {
	int arr[MAX];
	int f,r;	
}q;

void enqueue() {
	int x;
	if(q.r == MAX - 1) {
		printf("\nQueue is Oveflow.!");
	} 
	else {
		if(q.f == -1) 
			q.f = 0;
		
		printf("\nEnter Integer Value to Enqueue in Queue: ");
		scanf("%d",&x);
		q.r++;
		q.arr[q.r] = x;
	}
}

int dequeue() {
	if(q.f == -1) {
		return -1;
	} else {
		if(q.f == q.r) 
			q.f = q.r = -1;
		else
			q.f++;
			
		return q.f;
	}
}

void display() {
	int i;
	if(q.f == -1) {
		printf("\nQueue is Underflow!");
	} else {
		for(i = q.f; i <= q.r; i++) {
			printf("%d\t",q.arr[i]);
		}
	}
}

void main(){
	int choice, x;
	q.r=-1;
	q.f=-1;
	while(1) {
		printf("\n1. Enqueue in Queue\n2. Dequeue from Queue\n3. Display\n0. Exit");
		printf("\nEnter Your Choice: ");
		scanf("%d",&choice);
		
		switch(choice) {
			case 1:
				enqueue();
				break;
				
			case 2:
				y = dequeue();
				if(y == -1) 
					printf("Queue is Underflow.!");
				else
					printf("\nDequeued Element is: %d", y);
				break;
				
			case 3:
				printf("\n===== Queue Elements =====\n");
				display();
				printf("\n==========\n");
				break;
				
			case 0:
				exit(0);
				
			default:
				printf("\nInvalid Choice!");
		}
	}
}
