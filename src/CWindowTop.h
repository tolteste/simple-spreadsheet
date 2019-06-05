/* 
 * File:   CWindowTop.h
 * Author: steve
 *
 * Created on 18. červen 2013, 17:36
 */

#ifndef CWINDOWTOP_H
#define	CWINDOWTOP_H
#include <ncurses.h>

/*!
 * \brief Represents topbar.
 */

class CWindowTop : public CWindow {
public:
/*
 * \brief Initialize class.
 */
    CWindowTop() {
    }
/*!
 * \param height Height of allocated WINDOW.
 * \param width Width of allocated WINDOW.
 * \param x_pos Vertical position where WINDOW starts.
 * \param y_pos Horizontal position where WINDOW starts.
 *
 * Using inherited constructor from CWindow
 */
    CWindowTop(const int &height, const int &width, const int &x_pos, const int &y_pos);

/*!
 * \brief Prints CWindowTop. 
 */
    virtual void draw()const;
};

#endif	/* CWINDOWTOP_H */

