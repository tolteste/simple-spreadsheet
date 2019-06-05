/* 
 * File:   CWindowSide.h
 * Author: steve
 *
 * Created on 18. červen 2013, 17:52
 */

#ifndef CWINDOWSIDE_H
#define	CWINDOWSIDE_H
#include "CWindow.h"
#include <ncurses.h>

/*!
 * \brief Represents sidebar.
 */
class CWindowSide : public CWindow {
public:
/*
 * \brief Initialize class.
 */
    CWindowSide() {
    }
/*!
 * \param height Height of allocated WINDOW.
 * \param width Width of allocated WINDOW.
 * \param x_pos Vertical position where WINDOW starts.
 * \param y_pos Horizontal position where WINDOW starts.
 *
 * Using inherited constructor from CWindow
 */
    CWindowSide(const int &height, const int &width, const int &x_pos, const int &y_pos);
/*!
 * \brief Prints CWindowSide. 
 */
    virtual void draw()const;
};

#endif	/* CWINDOWSIDE_H */

