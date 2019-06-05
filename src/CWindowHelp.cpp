/* 
 * File:   CWindowHelp.cpp
 * Author: steve
 * 
 * Created on 18. červen 2013, 18:26
 */

#include "CWindowHelp.h"

CWindowHelp::CWindowHelp(const int& height, const int& width, const int& x_pos, const int& y_pos) : CWindow(height, width, x_pos, y_pos) {
}

void CWindowHelp::draw() const {
    wclear(m_win);
    box(m_win, 0, 0);
    mvwprintw(m_win, 1, m_width / 2 - 2, "HELP");
    mvwprintw(m_win, 2, 1, "You can write expression into cell by pressing \"ENTER\"");
    mvwprintw(m_win, 3, 1, "You can reevaluate cells by pressing \"r\"");
    mvwprintw(m_win, 4, 1, "You can move between cells by pressing arrow keys");
    mvwprintw(m_win, 5, 1, "For writing a string put \"\\\" as a first character");
    mvwprintw(m_win, 6, 1, "Press any key to continue");
    wrefresh(m_win);
    getch();
}


