#include <stdio.h>
#include <stdlib.h>

int main(){

    int referenceString[20] = {1,2,3,2,1,5,2,1,6,2,5,6,3,1,3,6,1,2,4,3};    // 참조 문자열
    int frameArray[3][20] = {0}; // 프레임 
    int tempArray[20] = {0};

    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 3; j++) {
            if(referenceString[i] == frameArray[j][i]){
                int tempIndex = j;
                if(tempIndex == 1){
                    frameArray[tempIndex][i] = frameArray[tempIndex-1][i];
                } else if(tempIndex == 2){
                    frameArray[tempIndex][i] = frameArray[tempIndex-1][i];
                    frameArray[tempIndex-1][i] = frameArray[tempIndex-2][i];
                }
                frameArray[0][i] = referenceString[i];
                break;
            } else if(j == 2){
                frameArray[j][i] = frameArray[j-1][i];
                frameArray[j-1][i] = frameArray[j-2][i];
                frameArray[j-2][i] = referenceString[i];
                tempArray[i]++;
            }
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
