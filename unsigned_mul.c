/**
	@aim: Program to multiply two 4 bit unsigned integer
	@author: Roll No 73,77
*/

#include<stdio.h>
#include<conio.h>
#define n 4

int A[n];
int M[n];
int Q[n];
int c;

void initialize();
void add();
void shift();
void printRes();

void main(){

	int i;
	clrscr();

	initialize();

	for(i=0;i<n;i++){
		if(Q[n-1]==0){
			shift();
		}
		else{
			add();
			shift();
		}
	}

	printRes();

	getch();
}

void initialize(){
	int i;
	printf("Enter Multiplicand: (4 bit) ");
	for(i=0;i<n;i++){
		scanf("%d",&M[i]);
	}
	printf("Enter Multiplier (4 bit): ");
	for(i=0;i<n;i++){
		scanf("%d",&Q[i]);
	}
	for(i=0;i<n;i++){
		A[i]=0;
	}
	c=0;
}

void add(){
	int i,ctemp;
	int stemp[n];
	int cin[n];

	cin[n-1]=0;
	for(i=n-1;i>=0;i--){
		stemp[i]=(M[i]+A[i]+cin[i])%2;
		ctemp=(M[i]&A[i]) | (A[i]&cin[i]) | (M[i]&cin[i]);
		if(i==0){
			c=ctemp;
		}
		else{
			cin[i-1]=ctemp;
		}
	}
	for(i=0;i<n;i++){
		A[i]=stemp[i];
	}
}

void shift(){
	int i;
	for(i=n-2;i>=0;i--){
		Q[i+1]=Q[i];
	}
	Q[0]=A[n-1];
	for(i=n-2;i>=0;i--){
		A[i+1]=A[i];
	}
	A[0]=c;
	c=0;
}

void printRes(){
	int i;
	printf("\nResult: ");
	for(i=0;i<n;i++){
		printf("%d",A[i]);
	}
	for(i=0;i<n;i++){
		printf("%d",Q[i]);
	}
}
