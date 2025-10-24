#include <stdio.h>
#include <stdbool.h>
#include "main.h"

int main(void) {
    int length = MIN_DIMENSION;
    int width = MIN_DIMENSION;
    bool continueProgram = true;
    
    while (continueProgram) {
        printWelcomeMenu();
        printOptions();
        
        int menuInput = getIntInput("Enter menu option number:");
        
        switch (menuInput) {
            case 1:
                printf("\nRectangle: length=%d, width=%d\n\n", length, width);
                break;
            case 2: {
                int input = getIntInput("Enter rectangle length:");
                setLength(input, &length);
                break;
            }
            case 3: {
                int input = getIntInput("Enter rectangle width:");
                setWidth(input, &width);
                break;
            }
            case 4:
                printf("\nPerimeter: %d\n\n", getPerimeter(length, width));
                break;
            case 5:
                printf("\nArea: %d\n\n", getArea(length, width));
                break;
            case 6:
                continueProgram = false;
                break;
            default:
                printf("\nInvalid option. Please try again.\n\n");
                break;
        }
    }
    return 0;
}

int getIntInput(const char* message) {
    int input;
    int result;
    
    do {
        printf("\n%s\n", message);
        result = scanf("%d", &input);
        
        // Clear input buffer
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        
        if (result != 1) {
            printf("Invalid input. Please enter a number.\n");
        }
    } while (result != 1);
    
    return input;
}

void setLength(int input, int* length) {
    if (input >= MIN_DIMENSION && input <= MAX_DIMENSION) {
        *length = input;
        printf("Length set to %d\n", input);
    } else {
        printf("Invalid length. Must be between %d and %d\n", MIN_DIMENSION, MAX_DIMENSION);
    }
}

void setWidth(int input, int* width) {
    if (input >= MIN_DIMENSION && input <= MAX_DIMENSION) {
        *width = input;
        printf("Width set to %d\n", input);
    } else {
        printf("Invalid width. Must be between %d and %d\n", MIN_DIMENSION, MAX_DIMENSION);
    }
}

int getPerimeter(int length, int width) {
    return 2 * (length + width);
}

int getArea(int length, int width) {
    return length * width;
}

void printWelcomeMenu(void) {
    printf(" **********************\n");
    printf("**     Welcome to     **\n");
    printf("**  Rectangle Calc    **\n");
    printf(" **********************\n");
}

void printOptions(void) {
    printf("1. Show Rectangle Dimensions\n");
    printf("2. Set Rectangle Length\n");
    printf("3. Set Rectangle Width\n");
    printf("4. Calculate Perimeter\n");
    printf("5. Calculate Area\n");
    printf("6. Exit\n");
}