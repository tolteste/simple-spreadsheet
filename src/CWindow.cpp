/* 
 * File:   CWindow.cpp
 * Author: steve
 * 
 * Created on 30. květen 2013, 16:32
 */

#include "CWindow.h"
#include <ncurses.h>
#include <string>
#include <sstream>
#include <limits.h>
using namespace std;


CWindow::CWindow(const int &height, const int &width, const int &x_pos, const int &y_pos) {
    m_height = height;
    m_width = width;
    m_x_pos = x_pos;
    m_y_pos = y_pos;
    m_win = newwin(m_height, m_width, m_y_pos, m_x_pos);
}

CWindow::~CWindow() {
    delwin(m_win);
}

WINDOW* CWindow::getWindow() const {
    return m_win;
}
