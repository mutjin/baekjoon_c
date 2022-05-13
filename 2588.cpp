#include <stdio.h>
int main(void){
    int A,B;
    scanf("%d%d",&A,&B);
    
    int B100=B/100;
    int B10=B%100/10;
    int B1=B%10;
    
    printf("%d\n",B1*A);
    printf("%d\n",B10*A);
    printf("%d\n",B100*A);
    printf("%d\n",B*A);
}