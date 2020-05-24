#pragma once
#include <stdbool.h>
#define USER_PRESSED_ESC 0

//Enables or disables a blinking cursor in the console.
void showCurs(bool visible);

//Moves a cursor to (x,y) in the console.
void gotoxy(int x, int y);

/*Makes a user to choose some option (printed before) using the keyboard arrows.
Returns the selected option or USER_PRESSED_ESC.
options - number of the options
x - left space for the text
y - start vertical position
space - distance between the options*/
int choose(int options, int x, int y, int space);