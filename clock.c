#include <stdio.h>
#include <stdlib.h>

int main(){
    int referenceString[20] = {1,2,3,2,1,5,2,1,6,2,5,6,3,1,3,6,1,2,4,3}; // 참조 문자열

    int frameArray[3][20] = {0}; // 프레임 
    int tempArray[20] = {0};
    int bitArray[3] = {0};
    int tempIndex = 0;

    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 3; j++) {
            if(frameArray[j][i] == 0) {      
                frameArray[j][i] = referenceString[i];
                bitArray[j] = 1;
                tempIndex = j;
                tempArray[i]++;
                break;
            } else if(referenceString[i] == frameArray[j][i]) {      
                bitArray[j] = 1;
                tempIndex = j;
                break;
            } else if(j == 2) { // 프레임을 다 돌았는데 원하는 페이지가 없는 경우
                if(tempIndex == 2){
                    frameArray[0][i] = referenceString[i];
                    bitArray[0] = 1;
                    tempIndex = 0;
                } else {
                    frameArray[tempIndex+1][i] = referenceString[i];
                    bitArray[tempIndex+1] = 1;
                    tempIndex = tempIndex + 1;
                }
                tempArray[i]++;
            }
            bitArray[tempIndex] = 0;
        }

        // 프레임에 추가
        if(i < 19){
            for(int j = 0; j < 3; j++) {
                frameArray[j][i+1] = frameArray[j][i];
            }
        }
    }

    printf("출력 1\n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 20; j++){
            printf("%d ", frameArray[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    printf("출력 2\n");
    for(int i = 0; i < 20; i++){
        if(tempArray[i] != 0){
            printf("%d ", i);
        }
    }
    printf("\n");

}
