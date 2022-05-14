#include <stdio.h>
int main(void){
    int H,M;
    scanf(" %d %d",&H,&M);
    
    if(M>=45) M-=45;
    else{
        M+=15;
        if(H==0) H=23;
        else H--;
    }
    printf("%d %d",H,M);
}