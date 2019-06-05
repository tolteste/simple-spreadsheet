/* 
 * File:   CScreen.h
 * Author: steve
 *
 * Created on 28. květen 2013, 14:57
 */

#ifndef CSCREEN_H
#define	CSCREEN_H

#include "CWindow.h"
#include "CWindowTop.h"
#include "CWindowSide.h"
#include "CWindowTop2.h"
#include "CWindowMain.h"
#include "CError.h"
#include "CPosition.h"
#include "CWindowHelp.h"

/*!
 * \class CScreen 
 * \brief Represents screen of a computer.
 */

/*!
 * \fn CScreen::CScreen()
 * \brief Initializes CSreen.
 */

/*! 
 * \fn void CSreen::movement()
 * \brief Where all counting a moving takes place.
 */

/*! 
 * \fn void CSreen::interface()
 * \brief Ncurses WINDOWS initializer.
 */

class CScreen {
public:
    CScreen();
    ~CScreen();
    void movement();
    void interface();
private:
/*! Size of top bar */
    int m_downSize;
/*! Size of side bar */
    int m_sideSize;
/*! WINDOW for sheet. */
    CWindowMain*main;
/*! WINDOW for sidebar */
    CWindowSide* side;
/*! WINDOW for top bar */
    CWindowTop* top;
/*! WINDOW for letters */
    CWindowTop2* top2;
/*! WINDOW for position indicator. */
    CPosition *position;
/*! WINDOW for error indicator. */
    CError* error;
/*! WINDOW for help window. */
    CWindowHelp* help;
/*! Horizontal position of active cell. */
    int m_activeX;
/*!  Vertical position of active cell. */  
   int m_activeY;

};

#endif	/* CSCREEN_H */

