/* 
 * File:   CWindowHelp.h
 * Author: steve
 *
 * Created on 18. červen 2013, 18:26
 */

#ifndef CWINDOWHELP_H
#define	CWINDOWHELP_H
#include  "CWindow.h"
#include <ncurses.h>

/*!
 * \brief Represents help window.
 */

class CWindowHelp : public CWindow{
public:
/*
 * \brief Initialize class.
 */
    CWindowHelp(){}
/*!
 * \param height Height of allocated WINDOW.
 * \param width Width of allocated WINDOW.
 * \param x_pos Vertical position where WINDOW starts.
 * \param y_pos Horizontal position where WINDOW starts.
 *
 * Using inherited constructor from CWindow
 */

     CWindowHelp(const int &height, const int &width, const int &x_pos, const int &y_pos);

/*!
 * \brief Prints CWindowHelp. 
 */
    virtual void draw()const;
private:

};

#endif	/* CWINDOWHELP_H */

