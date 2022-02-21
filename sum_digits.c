#include <stdio.h>
#include <stdlib.h>

unsigned int power(int n,int p){
	int pow=n;
	for (int i=1; i<p; i++){
		n *= pow;}
	if(p==0){return 1;}
	return n;}

int main(){
	unsigned int n,s,sum;
	scanf("%d %d",&n,&s);
	if (n>=1 && s>=1 && n<=s && 9*n>=s){
		unsigned int array[n];
		for (int i=power(10,n-1); i<=power(10,n)-1; i++){	
			unsigned int tmp=i;
			sum=0;
			for(int dig=0; dig<n; dig++){
				array[dig]=tmp%10;
				if (array[dig]==0)
					break;
				sum += array[dig];
				tmp/=10;
			}
			if(sum==s){	
				unsigned int dec=1 , no_null=1;
				for(int k=0; k<n-1; k++){
					if(array[k]<array[k+1])
						dec=0;
				}
				for(int i = 0; i < n; i++){
					if (array[i]==0)
						no_null=0;
				}
				if(dec&&no_null){
					for (int i=0; i<n; i++){
						if(i==n-1){
							printf("%d", array[i]);
							break;}
						printf("%d+", array[i]);
					}
					printf("=%d\n",s);
				}
			}
		}
		exit(0);
	}
	printf("Wrong input\n");
	exit(0);
}