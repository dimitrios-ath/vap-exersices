#include <stdio.h>
#include <stdlib.h>

int main(){
	int num,len=0,tmp,incr=1,decr=1;
	scanf("%d",&num);
	if (num>=10){
		tmp=num;
		while(tmp){ // digit counter
			len++;
			tmp/=10;}
		int digits[len];
		tmp=num;
		for(int i=0; i<len; i++){ // insert data to array
			digits[len-i-1]=tmp%10;
			tmp/=10;}
		for(int j=0; j<len-1; j++){
			if(digits[j]>digits[j+1]) // check if it's decreasing
				incr=0;
			if(digits[j]<digits[j+1]) // check if it's increasing
				decr=0;}
		if(incr){
			printf("Increasing\n");
			exit(0);}
		if(decr){
			printf("Decreasing\n");
			exit(0);}
		printf("Bouncing\n");
		exit(0);
	}
	printf("Wrong Input\n");
	exit(0);
}