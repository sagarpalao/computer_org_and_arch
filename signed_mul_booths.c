/**
	@Aim: Program to implement Booths algorithm to multiply signed integer
	@Author: Roll No.: 73, 77
*/

#include<stdio.h>
#include<conio.h>

int A[5];
int Q[5];
int M[5];
int M2[5];
int q1;
int cnt;

void acceptM();
void acceptQ();
void init();
void shift();
void add();
void sub();
void multiply();
void compute2M();

void main(){
	int i;

	clrscr();

	init();

	acceptM();
	printf("\n");
	for(i=0;i<5;i++){
		printf("%d",M[i]);
	}

	acceptQ();
	printf("\n");
	for(i=0;i<5;i++){
		printf("%d",Q[i]);
	}

	multiply();

	printf("\n\n\n");
	for(i=0;i<5;i++){
		printf("%d",A[i]);
	}
	for(i=0;i<5;i++){
		printf("%d",Q[i]);
	}
	printf("\n\n\n");

	getch();
}

void init(){
	int i;
	cnt=5;
	q1=0;
	for(i=0;i<5;i++){
		A[i]=0;
	}
}

void acceptM(){

	int m,i;
	printf("\n\nEnter Multiplicand: ");
	scanf("%d",&m);

	if(m>=0){
		M[0]=0;
		for(i=4;i>=1;i--){
			M[i]=m%2;
			m=m/2;
		}
	}
	else{
		M[0]=0;
		m=abs(m);
		for(i=4;i>=1;i--){
			M[i]=m%2;
			m=m/2;
		}
		i=4;
		while(i>=0){
			if(M[i]==1){
				break;
			}
			else{
				i--;
			}
		}
		i--;
		while(i>=0){
			if(M[i]==1){
				M[i]=0;
			}
			else{
				M[i]=1;
			}
			i--;
		}
	}

}

void acceptQ(){

	int m,i;
	printf("\n\n\nEnter Multiplier: ");
	scanf("%d",&m);

	if(m>=0){
		Q[0]=0;
		for(i=4;i>=1;i--){
			Q[i]=m%2;
			m=m/2;
		}
	}
	else{

		Q[0]=0;
		m=abs(m);
		for(i=4;i>=1;i--){
			Q[i]=m%2;
			m=m/2;
		}
		i=4;
		while(i>=0){
			if(Q[i]==1){
				break;
			}
			else{
				i--;
			}
		}
		i--;
		while(i>=0){
			if(Q[i]==1){
				Q[i]=0;
			}
			else{
				Q[i]=1;
			}
			i--;
		}
	}
}

void compute2M(){
	int i;
	i=4;
		while(i>=0){
			if(M[i]==1){
				M2[i]=M[i];
				break;
			}
			else{
				M2[i]=M[i];
				i--;
			}
		}
		i--;
		while(i>=0){
			if(M[i]==1){
				M2[i]=0;
			}
			else{
				M2[i]=1;
			}
			i--;
		}
}


void multiply(){
	int i;
	compute2M();

	for(i=0;i<5;i++){
		printf("%d",M2[i]);
	}

	while(cnt!=0){

		if((Q[4]==0 && q1==0)||(Q[4]==1 && q1==1)){
			shift();
		}
		else if(Q[4]==0 && q1==1){
			add();
			shift();
		}
		else{
			sub();
			shift();
		}

		cnt--;
	}

}

void add(){
	int i;
	int stemp,ctemp;
	int c[5];
	c[4]=0;

	for(i=4;i>=0;i--){
		stemp=(A[i]+M[i]+c[i])%2;
		ctemp=(A[i]&M[i])|(M[i]&c[i])|(A[i]&c[i]);
		A[i]=stemp;
		if(i!=0){
			c[i-1]=ctemp;
		}
	}
}

void sub(){
	int i,stemp,ctemp;
	int c[5];
	c[4]=0;

	for(i=4;i>=0;i--){
		stemp=(A[i]+M2[i]+c[i])%2;
		ctemp=(A[i]&M2[i])|(M2[i]&c[i])|(A[i]&c[i]);
		A[i]=stemp;
		if(i!=0){
			c[i-1]=ctemp;
		}
	}
}

void shift(){
	int i;
	q1=Q[4];

	for(i=3;i>=0;i--){
		Q[i+1]=Q[i];
	}

	Q[0]=A[4];

	for(i=3;i>=0;i--){
		A[i+1]=A[i];
	}

}
