/* 
 * File:   CError.cpp
 * Author: steve
 * 
 * Created on 18. červen 2013, 18:20
 */

#include "CError.h"

CError::CError(const int& height, const int& width, const int& x_pos, const int& y_pos) : CWindow(height, width, x_pos, y_pos) {
}

void CError::draw(const std::string &str) const {
    mvwprintw(m_win, 0, m_width / 2 - str.size() / 2, "%s", str.c_str());
    wrefresh(m_win);
    noecho();
    getch();
    wclear(m_win);
    wrefresh(m_win);
}