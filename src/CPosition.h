/* 
 * File:   CPosition.h
 * Author: steve
 *
 * Created on 18. červen 2013, 18:22
 */

#ifndef CPOSITION_H
#define	CPOSITION_H
#include "CWindow.h"
#include <ncurses.h>

/*!
 * \class CPosition
 * \brief Represents window where current position is shown.
 */

/*! 
 * \fn CPosition::CPosition()
 * \brief Initialize class.
 */

/*!
 * \fn CPosition::CPosition(const int &height, const int &width, const int &x_pos, const int &y_pos)
 * \param height Height of allocated WINDOW.
 * \param width Width of allocated WINDOW.
 * \param x_pos Vertical position where WINDOW starts.
 * \param y_pos Horizontal position where WINDOW starts.
 *
 * Using inherited constructor from CWindow
 */

/*!
 * \fn virtual void CPosition::draw()const;
 * \brief Prints CPosition. 
 */

/*! 
 * \fn void CPosition::changePosition(const int &x, const int &y)
 * \brief Change position of active cell.
 * \param x Horizontal position of active cell.
 * \param y Verical position of active cell.
 */
 


class CPosition : public CWindow {
public:

    CPosition() {
    }
    CPosition(const int &height, const int &width, const int &x_pos, const int &y_pos);
    virtual void draw()const;
    void changePosition(const int &x, const int &y);
private:
/*! \brief Horizontal position of active cell. 
*/ 
    int m_xActive;
/*! \brief Vertical position of active cell. 
*/ 
    int m_yActive;
};



#endif	/* CPOSITION_H */

