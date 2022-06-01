#include <stdio.h>
#include <stdlib.h>

#define N 100

typedef struct{
    int heap[N];
    int heapSize;
}HeapType;

//힙 초기화 함수
void init(HeapType* H){
    H->heapSize=0;
}

//힙 정렬 함수
void upHeap(HeapType* H){
    int i=H->heapSize;
    int key=H->heap[i];
    //1. 루트노드가 아니다
    //2. 자식노드 key > 부모노드 key
    while(i!=1&&key>H->heap[i/2]){
        H->heap[i]=H->heap[i/2];
        i/=2;
    }
    H->heap[i]=key;
}

//힙 삽입 함수
void insertItem(HeapType* H,int key){
    //1번 인덱스부터 차례로 삽입된다
    H->heapSize++;
    H->heap[H->heapSize]=key;
    
    //삽입된 노드와 부모 노드와의 크기를 비교한다
    upHeap(H);
}

void downHeap(HeapType* H){
    int item= H->heap[1];
    int parent=1, child=2;
    
    //자식노드가 힙크기보다 작거나 같은 경우
    while(child<=H->heapSize){
        //조건1: 자식노드가 힙크기보다 작은 경우: child의 형제노드가 있음
        //조건2: 형제노드(오른쪽)가 child(왼쪽)보다 큰 경우
        if(child<H->heapSize&H->heap[child+1]>H->heap[child]){
            child++; //child 인덱스를 더 큰 자식으로 바꾼다
        }
        
        //힙 조건을 만족하는 경우
        if(item>=H->heap[child]){
            break;
        }
        
        //힙 조건을 만족하지 않는 경우
        else{
            //부모와 자식의 위치를 바꾼다
            H->heap[parent]=H->heap[child]; 
            parent=child;
            child*=2;
        }
    }
    H->heap[parent]=item;
}

//힙정렬 함수 (제자리정렬)
//정렬이 끝나면 힙 사이즈가 0이 되므로 printHeap 으로는 출력 불가
//따라서 heapSort 함수 내부에서 출력해야 한다
void heapSort(HeapType* H){
    int n= H->heapSize;
    
    for(int i=1;i<=N;i++){
        //루트노드와 마지막 노드의 값을 교환한다
        int item=H->heap[1];
        H->heap[1]=H->heap[H->heapSize]; 
        //N값이 계속 변하기 때문에 인덱스로 heapSize 사용해야 한다
        H->heap[H->heapSize]=item;
        
        H->heapSize--;
        
        downHeap(H);
    }
    
    //출력
    for(int i=1;i<=n;i++){
        printf("(%d)",H->heap[i]);
    }
    printf("\n");
}

//힙 출력 함수
void printHeap(HeapType* H){
    for(int i=1;i<=H->heapSize;i++){
        printf("(%d)",H->heap[i]);
    }
}

int main(void){
    HeapType H;
    init(&H);
    
    insertItem(&H,90);
    insertItem(&H,60);
    insertItem(&H,80);
    insertItem(&H,50);
    insertItem(&H,30);
    insertItem(&H,70);
    insertItem(&H,10);
    insertItem(&H,20);
    insertItem(&H,40);
    
    printHeap(&H);
    //getchar();
    printf("\n");
    
    //insertItem(&H,80);
    //printHeap(&H);
    heapSort(&H);
    
    return 0;
    
}