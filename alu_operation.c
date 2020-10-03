/**
	Aim: Program to implement Arithmetic and Logical Unit
	
*/
 
#include<stdio.h>
#include<conio.h>
#define n 4
int mode;

int a[n];
int b[n];
int s[n];
int cout;

void add(){
    int i;
    int stemp,ctemp;
    int c[n];
    c[n-1]=0;

    for(i=n-1;i>=0;i--){
   	 stemp=(a[i]+b[i]+c[i])%2;
   	 ctemp=(a[i]&b[i]) | (b[i]&c[i]) | (a[i]&c[i]);
   	 s[i]=stemp;
   	 if(i==0){
   		 cout=ctemp;
   	 }
   	 else{
   		 c[i-1]=ctemp;
   	 }
    }
}

void sub(){
    int i;

    i=n-1;
    while(b[i]!=1){
   	 i--;
    }
    i--;
    while(i>=0){
   	 if(b[i]==1){
   		 b[i]=0;
   	 }
   	 else{
   		 b[i]=1;
   	 }
   	 i--;
    }
    add();
}

void increment_A(){
    b[0]=0;b[1]=0;b[2]=0;b[3]=1;
    add();
}

void increment_B(){
    a[0]=0;a[1]=0;a[2]=0;a[3]=1;
    add();
}

void A_Shift_Right(int r){
    int sign,i;
    sign=a[0];
    for(i=n-1-r;i>=0;i--){
   	 a[i+r]=a[i];
    }
    for(i=0;i<r;i++){
   	 a[i]=sign;
    }
}

void A_Shift_Left(int r){
    int i;
    for(i=r;i<n;i++){
   	 a[i-r]=a[i];
    }
    for(i=n-r;i<n;i++){
   	 a[i]=0;
    }
}

void AandB(){
    int i;
    for(i=0;i<n;i++){
   	 s[i]=a[i]&b[i];
    }
}

void AorB(){
    int i;
    for(i=0;i<n;i++){
   	 s[i]=a[i]|b[i];
    }
}

void compA(){
    int i;
    for(i=0;i<n;i++){
   	 a[i]=!a[i];
    }
}

void compB(){
    int i;
    for(i=0;i<n;i++){
   	 b[i]=!b[i];
    }
}

void L_Shift_Right(int r){
    int i;
    for(i=n-1-r;i>=0;i--){
   	 a[i+r]=a[i];
    }
    for(i=0;i<r;i++){
   	 a[i]=0;
    }
}

void L_Shift_Left(int r){
    int i;
    for(i=r;i<n;i++){
   	 a[i-r]=a[i];
    }
    for(i=n-r;i<n;i++){
   	 a[i]=0;
    }
}

void printA(){
    int i;
    for(i=0;i<n;i++){
   	 printf("%d",a[i]);
    }
}

void printB(){
    int i;
    for(i=0;i<n;i++){
   	 printf("%d",b[i]);
    }
}

void printS(){
    int i;
    for(i=0;i<n;i++){
   	 printf("%d",s[i]);
    }
}

void main(){

    int i,opt,r;
    clrscr();

    printf("Enter input A: ");
    for(i=0;i<n;i++){
   	 scanf("%d",&a[i]);
    }

    printf("Enter input B: ");
    for(i=0;i<n;i++){
   	 scanf("%d",&b[i]);
    }

    printf("Enter mode\n0.Logical\n1.Arithmetic\n");
    scanf("%d",&mode);

    if(mode==0){
   	 printf("\n1.Compliment A\n2. Compliment B\n3.A and B\n4.A or B\n5.Logical shift right A\n6.Logical shift left A\n");
   	 scanf("%d",&opt);

   	 switch(opt){
   		 case 1:
   			 compA();
   			 printA();
   			 break;
   		 case 2:
   			 compB();
   			 printB();
   			 break;
   		 case 3:
   			 AandB();
   			 printS();
   			 break;
   		 case 4:
   			 AorB();
   			 printS();
   			 break;
   		 case 5:
   			 printf("Enter shift rate: ");
   			 scanf("%d",&r);
   			 L_Shift_Right(r);
   			 printA();
   			 break;
   		 case 6:
   			 printf("Enter shift rate: ");
   			 scanf("%d",&r);
   			 L_Shift_Left(r);
   			 printA();
   			 break;
   		 default:
   			 printf("Invalid");
   	 }
    }
    else{
   	 printf("\n1.A add B\n2.A sub B\n3.Increment A\n4.Increment B\n5.Arithmetic shift right A\n6.Arithmetic shift left A\n");
   	 scanf("%d",&opt);

   	 switch(opt){
   		 case 1:
   			 add();
   			 printS();
   			 printf("Carry: %d",cout);
   			 break;
   		 case 2:
   			 sub();
   			 printS();
   			 break;
   		 case 3:
   			 increment_A();
   			 printS();
   			 break;
   		 case 4:
   			 increment_B();
   			 printS();
   			 break;
   		 case 5:
   			 printf("Enter shift rate: ");
   			 scanf("%d",&r);
   			 A_Shift_Right(r);
   			 printA();
   			 break;
   		 case 6:
   			 printf("Enter shift rate: ");
   			 scanf("%d",&r);
   			 A_Shift_Left(r);
   			 printA();
   			 break;
   		 default:
   			 printf("Invalid");
   	 }
    }

    getch();
}
