/*
문제
9개의 서로 다른 자연수가 주어질 때, 이들 중 최댓값을 찾고 그 최댓값이 몇 번째 수인지를 구하는 프로그램을 작성하시오.

예를 들어, 서로 다른 9개의 자연수

3, 29, 38, 12, 57, 74, 40, 85, 61

이 주어지면, 이들 중 최댓값은 85이고, 이 값은 8번째 수이다.

입력
첫째 줄부터 아홉 번째 줄까지 한 줄에 하나의 자연수가 주어진다. 주어지는 자연수는 100 보다 작다.

출력
첫째 줄에 최댓값을 출력하고, 둘째 줄에 최댓값이 몇 번째 수인지를 출력한다.
*/

/*
변수는 scanf("%c", &a)을 넣어야 하고
배열의 이름과 같이 주소를 가리키는 것들은 
scanf("%s", arr) 와 같이 &를 붙이지 않아도 됩니다.
만약 배열의 특정 위치는 변수와 같으니 역시 &를 붙여야겠죠 
scanf("%c", &arr[2]) 이와 같이 말이죠.
*/

#include <stdio.h>
#define N 9

int main(void){
    int arr[N];
    for(int i=0;i<N;i++){
        scanf("%d\n",&arr[i]);
    }
    
    int max_val=arr[0];
    int max_index=0;
    
    for(int i=0;i<N;i++){
        if(max_val<arr[i]){
            max_val=arr[i];
            max_index=i;
        }
    }
    
    printf("%d\n",max_val);
    printf("%d\n",max_index+1);
}