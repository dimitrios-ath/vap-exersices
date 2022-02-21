#include <stdio.h>
#include <stdlib.h>

int power(int n,int p){
	int pow=n;
	for (int i=1; i<p; i++){
		n *= pow;}
	if(p==0){return 1;}
	return n;}

int main(){
	int num, len=0, tmp, sum=0, digit;
	scanf("%d",&num);
	if(num>0){
		tmp=num;
		while(tmp>0){ //digit counter
			tmp/=10;
			len+=1;}
		tmp=num;		
		while(tmp>0){
			digit = tmp % 10;
			tmp /= 10;
			sum += power(digit, len);}
		if (num==sum) //armstrong number check
			{printf("yes");}
		else
			{printf("no");}
		exit(0);
	}
	printf("Wrong Input\n");
	exit(0);}