#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){
    int num,sqr,div=10,a,b;
    scanf("%d", &num);
    if(num>=0){
        sqr = num*num;
        for(int i=0;i<sqr;i++){
            if(num==1){
                printf("Kaprekar! 0 + 1 = %d\n",num);
                exit(0);}
            if(div<sqr){
                a = sqr / div;
                b = sqr % div;
                if(b==0){break;}
                if(a+b==num){
                    printf("Kaprekar! %d + %d = %d\n",a,b,num);
                    exit(0);
                }
                div*=10;
            }
        }
        printf("Not Kaprekar\n");
        exit(0);
    }
    printf("Wrong input");
    exit(0);}
