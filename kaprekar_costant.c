#include <stdlib.h>
#include <stdio.h>

int main(){
    unsigned int num,digits[4], max_num=0, min_num=0, tmp=0, counter=0;
    scanf("%d", &num);
    if(num>=1000 && num<=9999){
    	if(num%10==(num/10)%10 && (num/10)%10==(num/100)%10 && (num/100)%10==(num/1000)%10){
       			printf("Wrong input\n");
    			exit(0);}
        while (num!=6174){
            digits[0]=(num/1000)%10;
            digits[1]=(num/100)%10;
            digits[2]=(num/10)%10;
            digits[3]=(num)%10;
            int j=0,k;
            while (j<=3){ //asceding order
                k=0;
                for(;k<=3; k++){
                    if(digits[k]>digits[k+1]){
                        tmp=digits[k];
                        digits[k]=digits[k+1];
                        digits[k+1]=tmp;
                    }
                }
                j++;
            }
            min_num = digits[0]*1000+digits[1]*100+digits[2]*10+digits[3];
            max_num = digits[3]*1000+digits[2]*100+digits[1]*10+digits[0];
            printf("max:%d min: %d diff:%d\n",max_num,min_num,max_num-min_num);
            num=max_num-min_num;
            counter++;
        }
        printf("Took %d turns\n",counter);
        exit(0);
    }
    printf("Wrong input\n");
    exit(0);
}
