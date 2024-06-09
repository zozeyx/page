#include <stdio.h>
#include <stdlib.h>

//노드 구조체
typedef struct Node {
    int data;
    struct Node* next;
} Node;

//큐 구조체
typedef struct {
    Node* front;
    Node* rear;
} Queue;

//큐 초기화
void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// 큐가 비어 있는지 확인하는 함수
int isEmpty(Queue* q) {
    return q->front == NULL;
}

//큐에 데이터 추가하는 함수
void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = newNode;
    } else {
        q->rear->next = newNode;
    }
    q->rear = newNode;
}

// 큐에서 데이터를 제거하는 함수 
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }

    Node* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return value;
}

int main(){

    Queue myQueue;
    initQueue(&myQueue); 

    int arr[20] = {1,2,3,2,1,5,2,1,6,2,5,6,3,1,3,6,1,2,4,3};    //참조 문자열
    int frame[3][20] = {0};     //프레임 
    int temp_arr[20] = {0};

    for(int i=0; i<20; i++) {
        for(int j=0; j<3; j++) {
            if(frame[j][i] == 0) {      //프레임이 없을때
                frame[j][i] = arr[i];
                enqueue(&myQueue, arr[i]);
                temp_arr[i]++;
                break;
            } else if(arr[i] == frame[j][i]) {      //프레임에 원하는 페이지가 있는 경우
                break;
            } else if(j == 2) {      //프레임을 다 돌았는데 원하는 페이지가 없는 경우
                int temp = dequeue(&myQueue);
                for(int p=0; p<3; p++) {
                    if(frame[p][i] == temp) {
                        frame[p][i] = arr[i];
                        enqueue(&myQueue, arr[i]);
                        temp_arr[i]++;               
                        break;
                    }
                }
            }
        }

        //프레임에 추가
        if(i < 19){
            for(int j=0; j<3; j++) {
                frame[j][i+1] = frame[j][i];
            }
        }
    }

    printf("출력 1\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<20; j++){
            printf("%d ", frame[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    printf("출력 2\n");
    for(int i=0; i<20; i++){
        if(temp_arr[i] != 0){
            printf("%d ", i);
        }
    }
    printf("\n");

}
