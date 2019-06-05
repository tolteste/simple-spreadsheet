/* 
 * File:   CWindowMain.h
 * Author: steve
 *
 * Created on 18. červen 2013, 17:57
 */

#ifndef CWINDOWMAIN_H
#define	CWINDOWMAIN_H
#include <string>
#include "CWindow.h"
#include "CCell.h"

/*!
 * \brief Represents sheet window.
 */

class CWindowMain : public CWindow {
public:
/*
 * \brief Initialize class.
 */
    CWindowMain() {
    };
/*!
 * \param height Height of allocated WINDOW.
 * \param width Width of allocated WINDOW.
 * \param x_pos Vertical position where WINDOW starts.
 * \param y_pos Horizontal position where WINDOW starts.
 */
    CWindowMain(const int &height, const int &width, const int &x_pos, const int &y_pos);

/*!
 * \brief Prints CWindowMain. 
 */
    virtual void draw()const;
/*!
 * \return WINDOW allocated on position \a x \a y in \a m_2dArray.
 * \param x Horizontal position.
 * \param y Vertical position.
 */
    virtual WINDOW* getWindow(const int &x, const int &y)const;
/*!
 * \brief Prints cell on position \a x \a y in \a m_2dArray.
 * \param x Horizontal position.
 * \param y Vertical position.
 */
    void drawCell(const int &x, const int &y);
/*!
 * \brief Set \a isActive variable on position \a x \a y in \a m_2dArray.
 * \param x Horizontal position.
 * \param y Vertical position.
 * \param isActive Bool value.
 */
    void isActive(const int &x, const int &y, const bool isActive);
/*!
 * \brief Set \a m_val variable on position \a x \a y in \a m_2dArray.
 * \param x Horizontal position.
 * \param y Vertical position.
 * \param val Double value.
 */
    void putVal(const int &x, const int &y, const double &val);
/*!
 * \brief Return \a m_val variable on position \a x \a y in \a m_2dArray.
 * \param x Horizontal position.
 * \param y Vertical position.
 * \return Double value.
 */
    double getVal(const int &x, const int &y)const;
/*!
 * \brief Set \a m_exp variable on position \a x \a y in \a m_2dArray.
 * \param x Horizontal position.
 * \param y Vertical position.
 * \param str String value.
 */
    void write(const int &x, const int &y, const std::string &str);
/*!
 * \brief Return \a m_exp variable on position \a x \a y in \a m_2dArray.
 * \param x Horizontal position.
 * \param y Vertical position.
 * \return String value.
 */
    std::string getExp(const int & x, const int & y)const;
/*!
 * \brief Push pair into a vector on coordinates \a x, \a y.
 * \param coordinates Says that cell x, y references on cell with coordinates in SPair
 * \param x Horizontal position.
 * \param y Vertical position.
 */
    void pushReference(const int&x, const int &y,const SPair & coordinates);
/*!
 * \brief Clears vector of references on position \a x,\a y.
 * \param x Horizontal position.
 * \param y Vertical position.
 */
    void clearReference(const int&x, const int &y);
/*!
 * \brief Check cycle expressions.
 * Method is looking for cell with coordinates \a activeX, \a activeY in referece vector in cell with coordinates \a x, \a y.
 * \param x Horizontal position.
 * \param y Vertical position.
 * \param activeX Horizontal position of cell we need to check.
 * \param activeY Vertical position of cell we need to check.
 * \return True when cycle is detected.
 */
    bool cycle(const int&x, const int &y,const int& activeX,const int & activeY);
    ~CWindowMain();
private:
/*!
 * \brief 2D array of CCell.
 */
    CCell** m_2dArray;
};


#endif	/* CWINDOWMAIN_H */

