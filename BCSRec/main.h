#pragma once

#define MIN_DIMENSION 1
#define MAX_DIMENSION 100
#define MAX_INPUT_LENGTH 256

// Rectangle operations
void setLength(int input, int* length);
void setWidth(int input, int* width);
int getPerimeter(int length, int width);
int getArea(int length, int width);

// UI functions
void printWelcomeMenu(void);
void printOptions(void);
int getIntInput(const char* message);



