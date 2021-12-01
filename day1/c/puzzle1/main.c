#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    FILE *myFile;
    myFile = fopen("depths.txt", "r");

    int numberOfIncreases = 0;
    int previousNumber = -1;
    int currentNumber = -1;

    if (myFile == NULL){
        printf("Error Reading File\n");
        exit (0);
    }
    while (fscanf(myFile, "%d", &currentNumber) != EOF)
    {
            printf("previous = %d && current = %d", previousNumber, currentNumber);
        if(previousNumber != -1 && currentNumber > previousNumber)
        {
            numberOfIncreases++;
            printf(" - Increase! %d", numberOfIncreases);
        }
        previousNumber = currentNumber;
        printf("\n");
    }
    
    printf("There were %d increases.", numberOfIncreases);

    fclose(myFile);

    return 0;
}
