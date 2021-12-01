#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define WINDOW_SIZE 3
#define NOT_SET -1

int sum(int *window, int windowSize)
{
    int sum = 0;
    for(int i=0; i<windowSize; i++)
    {
        printf("window[%d] = %d\n", i, window[i]);
        sum += window[i];
    }
    return sum;
}

void initializeArray(int *window, int windowSize)
{
    for(int i=0; i<windowSize; i++)
    {
        window[i] = 0;
    }
}

int main(int argc, char const *argv[])
{
    FILE *myFile;
    myFile = fopen("depths.txt", "r");

    int numberOfIncreases = 0;
    int currentNumber = NOT_SET;
    int previousWindowSum = NOT_SET;
    int currentWindowSum = NOT_SET;
    int window[WINDOW_SIZE];
    int windowIndex = 0;
    bool isWindowFull = false;
    int lineNumber = 1;

    initializeArray(window, WINDOW_SIZE);

    if (myFile == NULL){
        printf("Error Reading File\n");
        exit (0);
    }
    while (fscanf(myFile, "%d", &currentNumber) != EOF)
    {
        if(windowIndex == WINDOW_SIZE)
        {
            windowIndex = 0;
        }

        if(lineNumber == WINDOW_SIZE+1)
        {
            previousWindowSum = currentWindowSum;
        }

        window[windowIndex++] = currentNumber;
        currentWindowSum = sum(window,WINDOW_SIZE);

        printf("%d %d %d\n", previousWindowSum, lineNumber, currentWindowSum);
        isWindowFull = (lineNumber++ > WINDOW_SIZE);
        if (isWindowFull)
        {
            if(currentWindowSum > previousWindowSum)
            {
                numberOfIncreases++;
                printf(" - Increase! %d", numberOfIncreases);
            }
            previousWindowSum = currentWindowSum;
            printf("\n");
        }
    }

    printf("There were %d increases.", numberOfIncreases);

    fclose(myFile);

    return 0;
}
