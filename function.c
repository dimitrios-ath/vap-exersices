#include <stdio.h>
#include <stdlib.h>

int function(int x){
	if (x==0)
		return 2;
	if (x==1)
		return 3;
	else
		return 2*function(x-1)+3*function(x-2);
}

int main()
{
	int num;
	scanf("%d",&num);
	while(num>=0){
		printf("%d\n", function(num));
		scanf("\n%d",&num);
	}
	return 0;
}