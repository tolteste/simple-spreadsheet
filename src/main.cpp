/* 
 * File:   main.cpp
 * Author: steve
 *
 * Created on 23. květen 2013, 16:40
 */
/*!
 * \mainpage 
 * This project was made by Štefan Töltési.
 *\section Description
 * Program is calculating written expresions. It supports unlimited ammount of parethesis. 
* \section Controls
* You can move between cells in sheet by using arrowkeys. For help press "h" and when you want to quit press F4. If you want to write into a cell press "ENTER"
 * 
 * 
 *
*/


#include <cstdlib>
#include "CScreen.h"
#include <ncurses.h>


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    CScreen screen;
    screen.movement();
    
    
    return 0;
}

