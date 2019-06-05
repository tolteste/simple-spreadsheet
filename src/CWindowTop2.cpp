/* 
 * File:   CWindowTop2.cpp
 * Author: steve
 * 
 * Created on 18. červen 2013, 17:54
 */

#include "CWindowTop2.h"

CWindowTop2::CWindowTop2(const int &height, const int &width, const int &x_pos, const int &y_pos) : CWindow(height, width, x_pos, y_pos) {
}

void CWindowTop2::draw() const {
    int i;
    char k = 'A';
    for (i = 5; i < COLS; i = i + 10) {
        mvwprintw(m_win, 0, i, "%c", k++);
    }
    wrefresh(m_win);
}

