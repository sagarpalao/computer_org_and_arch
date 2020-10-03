/**
	@AIM: PROGRAM TO IMPLEMENT LRU PAGE REPLACEMENT ALGORITHM
	@AUTHOR: ROLL NO.: 73, 77
*/
#include<stdio.h>
#include<conio.h>
#include<string.h>
#define n 4
void main()
{
	int i,empty,pf,k,j;
	char s[20],a[n],x,c;

	clrscr();
	printf("Enter the sequence:");
	gets(s);
	
	empty=n;
	pf=0;

	for(i=0;i<strlen(s);i++)
	{
		c=s[i];

		for(k=0;k<n;k++){
			if(c==a[k]){
				break;
			}
		}

		if(k!=n){
			for(j=k-1;j>=0;j--){
				a[j+1]=a[j];
			}
			a[0]=s[i];
		}
		else{
			pf++;
			for(j=n-1;j>=0;j--){
				a[j+1]=a[j];
			}
			a[0]=s[i];
			if(empty!=0)
				empty--;

		}

		printf("%c : ",s[i]);
		for(j=0;j<n-empty;j++){
			printf("\t%c",a[j]);
		}
		printf("\n");
	}

	printf("\n\nPage Fault: %d",pf);

	getch();
}
