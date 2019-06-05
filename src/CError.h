/* 
 * File:   CError.h
 * Author: steve
 *
 * Created on 18. červen 2013, 18:20
 */

#ifndef CERROR_H
#define	CERROR_H
#include "CWindow.h"
#include <ncurses.h>

/*!
 * \class CError
 * \brief Represents window with errors when exception is thrown.
 */

/*! 
 * \fn CError::CError
 * \brief Initialize class.
 */

/*!
 * \fn CError::CError(const int &height, const int &width, const int &x_pos, const int &y_pos)
 * \param height Height of allocated WINDOW.
 * \param width Width of allocated WINDOW.
 * \param x_pos Vertical position where WINDOW starts.
 * \param y_pos Horizontal position where WINDOW starts.
 *
 * Using inherited constructor from CWindow
 */

/*!
 * \fn virtual void CError::draw(const std::string &str)const;
 * Prints CError. 
 * \param str Error for printing.
 */

class CError : public CWindow {
public:

    CError() {
    }
    CError(const int &height, const int &width, const int &x_pos, const int &y_pos);
    void draw(const std::string &str)const;
    void draw()const{};
};


#endif	/* CERROR_H */

