#include <stdio.h>
int main(void){
    int N;//카드 장수
    int M;//합이 가까운 값
    int values[N];
    
    scanf("%d %d ",&N,&M);
    for(int i=0;i<N;i++){
        scanf("%d ",&values[i]);
    }
    
    int sum;
    int sub;
    int min_can=100;
    
    int closest_now=values[0]+values[1]+values[2];
    for(int i=0;i<N-2;i++){
      for(int j=i+1;i<N-2;j++){
          for(int k=j+1;i<N-2;k++){
                sum=values[i]+values[j]+values[k];
                sub=M-sum;
                
                if(sub<0) return 0;
                
                else{
                    if(sub<min_can) min_can=sub;
                }
            }
      }  
    }
    printf("%d ",min_can);

   
                    
        
    
    
    
}