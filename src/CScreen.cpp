/* 
 * File:   CScreen.cpp
 * Author: steve
 * 
 * Created on 28. květen 2013, 14:57
 */

#include "CScreen.h"
#include "CWindow.h"
#include <ncurses.h>
#include <string>
#include "CEvaluate.h"
using namespace std;

CScreen::CScreen() {
    m_downSize = 5;
    m_sideSize = 6;
    m_activeX = 0;
    m_activeY = 0;
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    refresh();
    interface();
}

CScreen::~CScreen() {
    delete top;
    delete top2;
    delete position;
    delete main;
    delete side;
    delete error;
    delete help;
    endwin();
}

void CScreen::interface() {

    top = new CWindowTop(m_downSize, COLS, 0, 0);
    top->draw();
    position = new CPosition(1, 25, COLS - 25, m_downSize / 2);
    position->draw();
    side = new CWindowSide(LINES - m_downSize, m_sideSize, 0, m_downSize + 1); //+1 kvuli pismenum nahore
    side->draw();
    top2 = new CWindowTop2(1, COLS - m_sideSize, m_sideSize, m_downSize);
    top2->draw();
    main = new CWindowMain(LINES - m_downSize - 1, COLS - m_sideSize, m_sideSize, m_downSize + 1);
    main->isActive(m_activeX, m_activeY, true);
    main->draw();
    error = new CError(1, COLS, 0, 3);
    help= new CWindowHelp(8,57,0,LINES-8);
}

void CScreen::movement() {
    int c = 0;
    int x;
    double value;
    char str[100];
    string exp,fill;
    CEvaluate eval;
    
    for(x=0;x<COLS-11;x++)
            fill.insert(fill.begin(),' ');
    
    while (c != KEY_F(4)) {
        keypad(main->getWindow(m_activeX, m_activeY), TRUE);
        c = mvwgetch(main->getWindow(m_activeX, m_activeY), 0, 1);
        mvwprintw(stdscr, 1, 11, "%s",fill.c_str());
        switch (c) {
            case '\n':
                echo();
                main->putVal(m_activeX, m_activeY, 0);
                mvwgetnstr(stdscr, 1, 11, str, COLS-11);
                exp.append(str);

                refresh();
                if (str[0] != '\\') {
                    if (exp.size() != 0) {
                        try {
                            value = eval.valuate(exp, main, m_activeX, m_activeY);
                        } catch (string err) {
                            error->draw(err);
                            exp.clear();
                            continue;
                        }
                        main->write(m_activeX, m_activeY, exp);
                        main->putVal(m_activeX, m_activeY, value);
                    }
                } else {
                    main->write(m_activeX, m_activeY, exp);
                }
                main->drawCell(m_activeX, m_activeY);
                noecho();
                exp.clear();
                continue;
            case KEY_UP:
                if (m_activeY != 0) {
                    main->isActive(m_activeX, m_activeY, false);
                    main->drawCell(m_activeX, m_activeY);
                    m_activeY--;
                    main->isActive(m_activeX, m_activeY, true);
                    main->drawCell(m_activeX, m_activeY);
                    position->changePosition(m_activeX, m_activeY);
                }
                continue;
            case KEY_DOWN:
                if (m_activeY < (LINES - 6) / 2 - 1) {
                    main->isActive(m_activeX, m_activeY, false);
                    main->drawCell(m_activeX, m_activeY);
                    m_activeY++;
                    main->isActive(m_activeX, m_activeY, true);
                    main->drawCell(m_activeX, m_activeY);
                    position->changePosition(m_activeX, m_activeY);
                }
                continue;
            case KEY_LEFT:
                if (m_activeX != 0) {
                    main->isActive(m_activeX, m_activeY, false);
                    main->drawCell(m_activeX, m_activeY);
                    m_activeX--;
                    main->isActive(m_activeX, m_activeY, true);
                    main->drawCell(m_activeX, m_activeY);
                    position->changePosition(m_activeX, m_activeY);
                }
                continue;
            case KEY_RIGHT:
                if (m_activeX < (COLS - m_sideSize) / 10 - 1) {
                    main->isActive(m_activeX, m_activeY, false);
                    main->drawCell(m_activeX, m_activeY);
                    m_activeX++;
                    main->isActive(m_activeX, m_activeY, true);
                    main->drawCell(m_activeX, m_activeY);
                    position->changePosition(m_activeX, m_activeY);
                }
                continue;
            case 'r':
                int i, j, k;
                j = ((LINES - m_downSize - 1) / 2)*((COLS - m_sideSize) / 10);
                for (; j > 0; j--) {
                    for (i = 0; i < (COLS - m_sideSize) / 10; i++) {
                        for (k = 0; k < (LINES - m_downSize - 1) / 2; k++) {
                            string tmp = main->getExp(i, k);
                            if (tmp.size() != 0 && *tmp.begin() != '\\') {
                                value = eval.valuate(tmp, main, i, k);
                                main->write(i,k,tmp);
                                main->putVal(i, k, value);
                            }
                        }
                    }
                }
                main->draw();

                continue;
            case 'h':
                help->draw();
                top->draw();
                side->draw();
                top2->draw();
                main->draw();
                position->draw();
                continue;
        }


    }
}
