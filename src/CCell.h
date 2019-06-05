/* 
 * File:   CCell.h
 * Author: steve
 *
 * Created on 18. červen 2013, 18:01
 */

#ifndef CCELL_H
#define	CCELL_H
#include "CWindow.h"
#include <ncurses.h>
#include <vector>
#include "SPair.h"

/*! \class CCell
 * \brief Represents one cell in sheet
 *
 * Each cell allocates its own WINDOW using ncurses. 
 */

/*!
 * \fn void virtual CCell::draw()const
 * \brief Print cell on screen.
 */

/*!
 * \fn CCell::CCell(const int &height, const int &width, const int &x_pos, const int &y_pos)
 * 
 * \param height Height of allocated WINDOW.
 * \param width Width of allocated WINDOW.
 * \param x_pos Vertical position where WINDOW starts.
 * \param y_pos Horizontal position where WINDOW starts.
 *
 * Using inherited constructor from CWindow
 */


/*!
 * \fn CCell::CCell()
 * 
 * Initialize private member variables.
 */

/*!
 * \fn void CCell::write(const std::string &str)
 * 
 * Takes parameter and writes it into Cell.
 * 
 * \param str String which is going to be saved in cell.
 */

/*!
 * \fn std::string CCell::getString()const;
 * 
 * \return String which is saved in cell.
 */

/*! 
 * \fn const CCell& CCell::operator=(const CCell &x)
 * 
 * Overloads operator =. Sets first argument member variables on values equal to second argument.
 */

/*!
 * \fn virtual WINDOW* CCell::getWindow()const
 * 
 * \return Pointer on WINDOW which was allocated by cell.
 */

/*!
 * \fn void CCell::isActive(bool isActive)
 * 
 * Sets  \a m_isActive which says if cell is active.
 * 
 * \param isActive Says if cell is active.
 */

/*!
 * \fn void CCell::putVal(const double & val)
 * 
 * Sets double \a m_value.
 * 
 */ 

/*!
 * \fn double CCell::getVal()const
 * 
 * \return Value set in \a m_value.
 */

/*!
 * \fn std::string CCell::getExp()const
 * 
 * \return String set in \a m_exp
 */






class CCell : public CWindow {
public:
    CCell(const int &height, const int &width, const int &x_pos, const int &y_pos);

    CCell() {
        m_exp="";
        m_height = 0;
        m_width = 0;
        m_win = NULL;
        m_x_pos = 0;
        m_y_pos = 0;
        m_init = false;
        m_isActive = false;
        m_drawString = false;
    }
    void virtual draw()const;
    void write(const std::string &str);
    std::string getString()const;
    const CCell& operator=(const CCell &x);
    virtual WINDOW* getWindow()const;
    void isActive(bool isActive);
    void putVal(const double & val);
    double getVal()const;
    std::string getExp()const;
/*!
 * Saves coordinates of cells which are used in \a m_exp.
 */
    std::vector<SPair> references;
private:
/** 
 * \brief Says if cell is active.
 */
    bool m_isActive;
/**
 * \brief Counted value
 */
    double m_value;
/** 
 * \brief Represets expresion written in cell.
 */

    std::string m_exp;
/**
 * \brief Says if cell was initialzed.
 */

    bool m_init;
/** 
 * \brief Says if \a m_exp is being printed or if \a m_value.
 */
    bool m_drawString;
};

#endif	/* CCELL_H */

