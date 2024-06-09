#include <stdio.h>
#include <stdlib.h>

int main() {
    int referenceString[20] = {1,2,3,2,1,5,2,1,6,2,5,6,3,1,3,6,1,2,4,3}; // 참조 문자열
    int frameArray[3][20] = {0}; // 프레임
    int tempArray[20] = {0}; 
    int currentFrames[3] = {0}; 
    int lastUsed[3] = {0};

    for (int i = 0; i < 20; i++) {
        int found = 0;
        for (int j = 0; j < 3; j++) {
            if (currentFrames[j] == referenceString[i]) { 
                found = 1;
                lastUsed[j] = i; 
                break;
            }
        }

        if (!found) { 
            tempArray[i] = 1;
            int futureUse[3] = {0};
            for (int p = 0; p < 3; p++) {
                int frameValue = currentFrames[p];
                int nextIndex = i + 1;
                int count = 0;
                while (nextIndex < 20 && frameValue != referenceString[nextIndex]) {
                    count++;
                    nextIndex++;
                }
                if (nextIndex >= 20) {
                    count = 20; // 현재 프레임에 있는 페이지가 더 이상 사용되지 않는 경우
                }
                futureUse[p] = count;
            }
            int max = futureUse[0];
            int replaceIndex = 0;
            for (int p = 1; p < 3; p++) {
                if (futureUse[p] > max) {
                    max = futureUse[p];
                    replaceIndex = p;
                } else if (futureUse[p] == max) {
                    if (lastUsed[p] < lastUsed[replaceIndex]) {
                        replaceIndex = p;
                    }
                }
            }
            currentFrames[replaceIndex] = referenceString[i];
            lastUsed[replaceIndex] = i;
        }

        for (int j = 0; j < 3; j++) {
            frameArray[j][i] = currentFrames[j];
        }
    }

    printf("출력 1\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 20; j++) {
            printf("%d ", frameArray[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    printf("출력 2\n");
    for (int i = 0; i < 20; i++) {
        if (tempArray[i] != 0) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
