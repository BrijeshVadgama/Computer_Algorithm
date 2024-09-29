#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct stact{
	int top, stk[MAX];
}s1;

void push(int n){
	if(s1.top == MAX-1){
		printf("Stack Overflow..!");
	}
	else{
		s1.stk[++s1.top] = n;
		printf("Element is Pushed Successfully..!");
	}
}

int pop(){
	if(s1.top == -1){
		return -1;
	}
	else{
		return s1.stk[s1.top--];
	}
}

int peep(int index){
	if((s1.top-index+1) < 0){
		return -1;
	}
	else{
		return s1.stk[s1.top-index+1];
	}
}

void change(int index, int n){
	if((s1.top-index+1) < 0){
		printf("Element not found..!");
	}
	else{
		s1.stk[s1.top-index+1] = n;
		printf("Element is changed Successfully..!");
	}
}

void display(){
	if(s1.top == -1){
		printf("Stack Underflow..!");
	}
	else{
		int i;
		for(i=s1.top;i>=0;i--){
			printf("%d\t",s1.stk[i]);
		}
	}
}

void main(){
	s1.top = -1;
	int choice, n, x, index;
	while(1){
		system("cls");
		
		printf("=======> STAK OPERATIONS <=======\n");
		printf("1) PUSH\n2) POP\n3) PEEP\n4) CHANGE\n5) DISPLAY\n0) EXIT\n");
		printf("\nEnter Your Choice : ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
				printf("----> PUSH OPERATOIN <----\n");
				printf("Enter No to push : ");
				scanf("%d",&n);
				push(n);
				printf("\n--------------------\n");
				getch();
				break;
			case 2:
				printf("----> POP OPERATOIN <----\n");
				x = pop();
				if(x == -1){
					printf("Stack Underflow..!");
				}
				else{
					printf("Pop element is %d",x);
				}
				printf("\n--------------------\n");
				getch();
				break;
			case 3:
				printf("----> PEEP OPERATOIN <----\n");
				printf("Enter index to search an element : ");
				scanf("%d",&index);
				x = peep(index);
				if(x == -1){
					printf("Element not found..!");
				}
				else{
					printf("Elements %d is at %d",index,x);
				}
				printf("\n--------------------\n");
				getch();
				break;
			case 4:
				printf("----> CHANGE OPERATOIN <----\n");
				printf("Enter index to change an element : ");
				scanf("%d",&index);
				printf("Enter element to change : ");
				scanf("%d",&n);
				change(index, n);
				printf("\n--------------------\n");
				getch();
				break;
			case 5:
				printf("----> DISPLAY OPERATOIN <----\n");
				display();
				printf("\n--------------------\n");
				getch();
				break;
			case 0:
				exit(0);
				break;
			default:
				printf("Invalid Choice..!");
				getch();
				break;
		}
	}
}
