/* 
 * File:   CWindowTop2.h
 * Author: steve
 *
 * Created on 18. červen 2013, 17:54
 */

#ifndef CWINDOWTOP2_H
#define	CWINDOWTOP2_H
#include "CWindow.h"
#include <ncurses.h>

/*!
 * \brief Represents position (letters) window.
 */

class CWindowTop2 : public CWindow {
public:

/*
 * \brief Initialize class.
 */

    CWindowTop2() {
    }

/*!
 * \param height Height of allocated WINDOW.
 * \param width Width of allocated WINDOW.
 * \param x_pos Vertical position where WINDOW starts.
 * \param y_pos Horizontal position where WINDOW starts.
 *
 * Using inherited constructor from CWindow
 */

    CWindowTop2(const int &height, const int &width, const int &x_pos, const int &y_pos);
/*!
 * \brief Prints CWindowTop2. 
 */
    virtual void draw()const;
};

#endif	/* CWINDOWTOP2_H */

