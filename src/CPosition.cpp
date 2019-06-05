/* 
 * File:   CPosition.cpp
 * Author: steve
 * 
 * Created on 18. červen 2013, 18:22
 */

#include "CPosition.h"

CPosition::CPosition(const int& height, const int& width, const int& x_pos, const int& y_pos) : CWindow(height, width, x_pos, y_pos) {
    m_xActive = 'A';
    m_yActive = 0;
}

void CPosition::draw() const {
    wclear(m_win);
    mvwprintw(m_win, 0, 0, "Active cell is: %c%i", m_xActive, m_yActive);
    wrefresh(m_win);
}

void CPosition::changePosition(const int& x, const int& y) {
    m_xActive = x + 'A';
    m_yActive = y;
    this->draw();
}