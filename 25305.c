/*
문제
2022 연세대학교 미래캠퍼스 슬기로운 코딩생활에 $N$명의 학생들이 응시했다.

이들 중 점수가 가장 높은 $k$명은 상을 받을 것이다. 이 때, 상을 받는 커트라인이 몇 점인지 구하라.

커트라인이란 상을 받는 사람들 중 점수가 가장 가장 낮은 사람의 점수를 말한다.

입력
첫째 줄에는 응시자의 수 $N$과 상을 받는 사람의 수 $k$가 공백을 사이에 두고 주어진다.

둘째 줄에는 각 학생의 점수 $x$가 공백을 사이에 두고 주어진다.

출력
상을 받는 커트라인을 출력하라.
*/

#include <stdio.h>
#define SWAP(x,y,t) (t=x,x=y,y=t)
int main(void){
    int n,k;
    scanf("%d%d",&n,&k);
    int arr[n];
    
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    int maxval,maxindex,temp;
    for(int i=0;i<k;i++){
        maxval=arr[i];
        maxindex=i;
        for(int j=i+1;j<n;j++){
            if(maxval<arr[j]){
                maxval=arr[j];
                maxindex=j;
            }
        }
        SWAP(arr[i],arr[maxindex],temp);
    }
    printf("%d",arr[k-1]);
}
