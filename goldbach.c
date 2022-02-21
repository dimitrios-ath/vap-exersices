#include <stdio.h>
#include <stdlib.h>

int is_prime(int n){
     if (n <= 1) return 0;
     if (n % 2 == 0 && n > 2) return 0;
     for(int i=3; i < n/2; i+=2){
         if (n % i == 0)
             return 0;}
     return 1;}

int main(){
	int num,p,q,p_pr=0,q_pr=0;
	scanf("%d",&num);
	if(!(num%2) && num>2){
		for (int p=2; p<=num/2; p++){	
			q = num-p;
			p_pr=0;
			q_pr=0;
			if(is_prime(p) && !(p_pr)) {p_pr=1;}
			if(is_prime(q) && p_pr) {q_pr=1;}
			if (p_pr && q_pr){
				printf("%d+%d=%d\n",p,q,num);
				exit(0);
			}
		}
	}
	printf("Wrong Input\n");
	exit(0);}