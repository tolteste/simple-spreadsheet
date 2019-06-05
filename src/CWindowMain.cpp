/* 
 * File:   CWindowMain.cpp
 * Author: steve
 * 
 * Created on 18. červen 2013, 17:57
 */

#include "CWindowMain.h"
#include <string>
#include <vector>


CWindowMain::CWindowMain(const int &height, const int &width, const int &x_pos, const int &y_pos) : CWindow(height, width, x_pos, y_pos) {
    int j, i, cellWidth = 10, cellHeight = 2;
    m_2dArray = new CCell*[width / cellWidth];
    for (i = 0; i < width / cellWidth; i++) {
        m_2dArray[i] = new CCell[height / cellHeight];
        for (j = 0; j < height / cellHeight; j++) {
            CCell tmp(cellHeight, cellWidth, x_pos + i*cellWidth, y_pos + j * cellHeight);
            m_2dArray[i][j] = tmp;
        }
    }
}

void CWindowMain::draw() const {
    int i, k;
    for (i = 0; i < m_width / 10; i++) {
        for (k = 0; k < m_height / 2; k++) {
            m_2dArray[i][k].draw();
        }
    }
}

void CWindowMain::isActive(const int& x, const int& y, const bool isActive) {
    m_2dArray[x][y].isActive(isActive);
    wrefresh(m_2dArray[x][y].getWindow());
}

void CWindowMain::putVal(const int &x, const int &y, const double& val) {
    m_2dArray[x][y].putVal(val);
}

double CWindowMain::getVal(const int& x, const int& y) const {
    return m_2dArray[x][y].getVal();
}

WINDOW *CWindowMain::getWindow(const int & x, const int &y) const {
    return m_2dArray[x][y].getWindow();
}

void CWindowMain::drawCell(const int& x, const int& y) {
    m_2dArray[x][y].draw();
}

void CWindowMain::write(const int& x, const int& y, const std::string& str) {
    m_2dArray[x][y].write(str);
}

CWindowMain::~CWindowMain() {
    int i;
    for (i = 0; i < m_width / 10; i++) { // deleno 10 cellWidth
        delete [] m_2dArray [i];
    }
    delete [] m_2dArray;
}

std::string CWindowMain::getExp(const int& x, const int& y) const{
    return m_2dArray[x][y].getExp();
}

void CWindowMain::pushReference(const int& x, const int& y, const SPair & coordinates) {
    m_2dArray[x][y].references.push_back(coordinates);
}

void CWindowMain::clearReference(const int& x, const int& y) {
    m_2dArray[x][y].references.clear();
}


bool CWindowMain::cycle(const int& x, const int& y, const int& activeX, const int& activeY) {
    std::vector<SPair>::const_iterator it;
    for (it = m_2dArray[x][y].references.begin(); it != m_2dArray[x][y].references.end(); ++it) {
        if (it->first == activeX && it->second == activeY)
            return true;
        if (cycle(it->first-'A', it->second, activeX, activeY)) {

            return true;
        }

    }
    return false;
}
