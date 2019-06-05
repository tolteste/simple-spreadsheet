/* 
 * File:   CWindowTop.cpp
 * Author: steve
 * 
 * Created on 18. červen 2013, 17:36
 */

#include "CWindow.h"
#include "CWindowTop.h"

CWindowTop::CWindowTop(const int &height, const int &width, const int &x_pos, const int &y_pos) : CWindow(height, width, x_pos, y_pos) {
}

void CWindowTop::draw() const {
    mvwhline(m_win, m_height - 1, 0, 0, COLS);
    mvwprintw(m_win, 0, 0, "For help press \"h\"   For exit press \"F4\"");
    mvwprintw(m_win, 1, 0, "Expresion:");
    mvwprintw(m_win, 2, 0, "Value:");
    wrefresh(m_win);

}
