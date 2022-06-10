/*
문제
N개의 숫자가 공백 없이 쓰여있다. 이 숫자를 모두 합해서 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 숫자의 개수 N (1 ≤ N ≤ 100)이 주어진다. 둘째 줄에 숫자 N개가 공백없이 주어진다.

출력
입력으로 주어진 숫자 N개의 합을 출력한다.
*/

#include <stdio.h>
#include <string.h>
int main(void){
    int n;
    scanf("%d",&n);
    
    char arr[n];
    int sum=0;
    
    scanf("%s",arr);
    
    for(int i=0;i<strlen(arr);i++){
        sum+=arr[i]-48; //1은 아스키코드로 49
    }
    
    printf("%d",sum);
    
}