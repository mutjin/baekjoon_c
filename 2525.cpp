#include <stdio.h>
int main(void){
    int A,B; //현재시, 현재분
    int C;
    scanf("%d%d",&A,&B);
    scanf("%d",&C); //요리필요시간
    
    int C_HOUR=C/60;
    int C_MIN=C%60;
    
    int D_HOUR,D_MIN;
    
    if(B+C_MIN>=60){
        D_MIN=B+C_MIN-60;
        D_HOUR=A+C_HOUR+1;
        
        if(D_HOUR>=24) D_HOUR-=24;
    }
    else{
        D_MIN=B+C_MIN;
        D_HOUR=A+C_HOUR;
        
        if(D_HOUR>=24) D_HOUR-=24;
    }
    printf("%d %d\n",D_HOUR,D_MIN);
}