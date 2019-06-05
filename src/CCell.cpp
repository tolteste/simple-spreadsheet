/* 
 * File:   CCell.cpp
 * Author: steve
 * 
 * Created on 18. červen 2013, 18:01
 */

#include "CCell.h"
#include <string>

CCell::CCell(const int &height, const int &width, const int &x_pos, const int &y_pos) : CWindow(height, width, x_pos, y_pos) {
    m_isActive = false;
    m_init = false;
    m_exp = "";
    m_value = 0;
}

void CCell::draw() const {
    int i;
    if (m_isActive) {
        mvwprintw(m_win, 0, 0, "|");
        mvwprintw(m_win, 0, 1, "        ");
        if (!m_drawString) {
            mvwprintw(m_win, 0, 1, "%.8g", m_value);

        } else {
            mvwprintw(m_win, 0, 1, "%.8s", m_exp.c_str());

        }
        mvwprintw(m_win, 0, 9, "|");
        mvwprintw(m_win, 1, 0, "~~~~~~~~~~");
        mvwprintw(stdscr, 2, 7, "                       ");
        mvwprintw(stdscr, 2, 7, "%g", m_value);
        std::string tmp;
        for (i = 0; i < COLS - 11; i++) {
            tmp.insert(tmp.begin(), ' ');
        }
        mvwprintw(stdscr, 1, 11, "%s", tmp.c_str());
        mvwprintw(stdscr, 1, 11, "%s", m_exp.c_str());
    } else {
        mvwprintw(m_win, 0, 0, "          ");
        mvwprintw(m_win, 1, 0, "          ");
        if (!m_drawString) {
            if (m_exp.size() > 0 || m_init) {
                mvwprintw(m_win, 0, 1, "%.8g", m_value);
            } else {
                mvwprintw(m_win, 0, 1, "          ");
            }
        } else {
            mvwprintw(m_win, 0, 1, "%.8s", m_exp.c_str());
        }
    }
    wrefresh(m_win);
    refresh();

}

void CCell::write(const std::string& str) {
    m_exp = str;
    m_init = true;
    m_drawString = true;
}

WINDOW* CCell::getWindow()const {
    return m_win;
}

void CCell::putVal(const double& val) {
    m_value = val;
    m_init = true;
    if (!m_drawString)
        m_exp.clear();
    m_drawString = false;
}

double CCell::getVal() const {
    return m_value;
}

void CCell::isActive(bool isActive) {
    m_isActive = isActive;
}

const CCell& CCell::operator =(const CCell& x) {
    m_exp = x.m_exp;
    m_height = x.m_height;
    m_width = x.m_width;
    m_x_pos = x.m_x_pos;
    m_y_pos = x.m_y_pos;
    m_isActive = x.m_isActive;
    m_win = newwin(m_height, m_width, m_y_pos, m_x_pos);
    m_value = x.m_value;
    m_init = m_init;
    return *this;
}

std::string CCell::getExp() const {
    return m_exp;
}

