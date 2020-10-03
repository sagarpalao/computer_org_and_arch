/**
@Aim: Program to implement  8 bit adder
@author: Roll No 73,77
*/
#include<stdio.h>
#include<conio.h>
int A[8];
int B[8];
int S[8];
int C[8];
int Cout;
int s_temp;
int c_temp;

void accept_A();
void print_S();
void accept_B();
void add(int c,int a,int b);

void main(){
	int i;
	clrscr();

	printf("Enter input A (8 bit): ");
	accept_A();

	printf("Enter input B (8 bit): ");
	accept_B();

	printf("Enter Cin: ");
	scanf("%d",&C[7]);

	for(i=7;i>=0;i--){
		add(C[i],A[i],B[i]);
		S[i]=s_temp;
		if(i!=0){
			C[i-1]=c_temp;
		}
		else{
			Cout=c_temp;
		}
	}

	printf("\nSum: ");
	print_S();
	printf("\nCout : %d",Cout);

	getch();
}
void accept_A(){
	int i;
	for(i=0;i<8;i++){
		scanf("%d",&A[i]);
	}
}
void accept_B(){
	int i;
	for(i=0;i<8;i++){
		scanf("%d",&B[i]);
	}
}
void print_S(){
	int i;
	for(i=0;i<8;i++){
		printf("%d",S[i]);
	}
}
void add(int c,int a,int b){
	s_temp= ( (!((!a&b) | (a&!b)) )&c ) |  ((!a&b) | (a&!b))&!c;
	c_temp= (a&b) | (b&c) | (a&c);
}
