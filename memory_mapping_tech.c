/** 
@AIM: To study Mapping Techniques 
@AUTHOR: Roll No.: 73,77 
*/ 

#include<stdio.h> 
#include<conio.h> 
#include<math.h> 
#include<stdlib.h> 
 
void direct(double mm,double ca,double block); 
void associative(double mm,double ca,double block); 
void set(double mm,double ca,double block,double nset); 
 
void main(){ 

 double mm,ca,block,word,nset; 
 int n; 

 clrscr(); 
 printf("Enter the main memory size in bytes\n"); 
 scanf("%lf",&mm); 
 printf("Enter the cache size in bytes\n"); 
 scanf("%lf",&ca); 
 printf("Enter the block size in bytes\n"); 
 scanf("%lf",&block); 

 printf("enter 1 for direct, 2 for fully associative,3 for set 
			associative\n");  
 scanf("%d",&n); 

 switch(n){ 
 	case 1:
			direct(mm,ca,block); 
			break; 
 	case 2:
			associative(mm,ca,block); 
			break; 
 	case 3:
			printf("enter the value of no of lines in set\n"); 			scanf("%lf",&nset); 
			set(mm,ca,block,nset); 
		break; 
 	default:
			printf("enter 1,2 or 3\n");  
			break; 
 } 
 getch(); 
}  

void direct(double mm,double ca,double block) { 

 double bit,wb,bb,tag,a,b; 
 bit=log(mm)/log(2.0); 
 wb=log(block)/log(2.0); 
 a=ca/block; 
 bb=log(a)/log(2.0); 
 tag=bit­wb­bb; 

 printf("Tag =%lf\n",ceil(tag)); 
 printf("Block =%lf\n",ceil(bb)); 
 printf("Word =%lf\n",ceil(wb)); 
} 
 
void associative(double mm,double ca,double block) {
 
 double bit,wb,bb,tag,a,b; 
 bit=log(mm)/log(2.0); 
 wb=log(block)/log(2.0); 
 tag=bit­wb; 

 printf("Tag =%lf\n",ceil(tag)); 
 printf("Word =%lf\n",ceil(wb)); 
}
  
void set(double mm,double ca,double block,double nset) { 

 double bit,wb,bb,tag,a,b; 
 bit=log(mm)/log(2.0); 
 wb=log(block)/log(2.0); 
 a=ca/block; 
 a=a/nset; 
 bb=log(a)/log(2.0); 
 tag=bit­wb­bb; 

 printf("Tag =%lf\n",ceil(tag)); 
 printf("Set =%lf\n",ceil(bb)); 
 printf("Word =%lf\n",ceil(wb)); 
} 
