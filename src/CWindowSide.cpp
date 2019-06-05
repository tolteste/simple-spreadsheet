/* 
 * File:   CWindowSide.cpp
 * Author: steve
 * 
 * Created on 18. červen 2013, 17:52
 */

#include "CWindowSide.h"
#include "CWindowSide.h"

CWindowSide::CWindowSide(const int &height, const int &width, const int &x_pos, const int &y_pos) : CWindow(height, width, x_pos, y_pos) {
}

void CWindowSide::draw() const {
    int i;
    wclear(m_win);
    for (i = 0; i < LINES; i = i + 2) {
        if (i == COLS - 6)break;
        if (i / 2 < 10) {
            mvwprintw(m_win, i, m_width / 2, "%i", i / 2);
        } else if (i / 2 < 1000) {
            mvwprintw(m_win, i, m_width / 2 - 1, "%i", i / 2);
        }
    }
    wrefresh(m_win);
}