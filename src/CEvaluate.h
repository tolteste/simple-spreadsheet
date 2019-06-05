/* 
 * File:   CEvaluate.h
 * Author: steve
 *
 * Created on 11. červen 2013, 10:46
 */

#ifndef CEVALUATE_H
#define	CEVALUATE_H
#include <string>
#include "CWindow.h"
#include "CParser.h"
#include "CWindowMain.h"
#include <list>

/*!
 * \class CEvaluate
 * \brief Evaluates string into a double number.
 */

/*!
 * \fn CEvaluate::CEvaluate()
 * Initialize CEvaluate.
 */

/*!
 * \fn double CEvaluate::valuate(const std::string &str, CWindowMain *main,int activeX,int activeY)
 * Evaluates string into a double number or string is just transformed into a double.
 * \param str String to parse and evaluate.
 * \param main Pointer on CWindowMain \a m_main in CScreen.
 * \param activeY Vertical position of active cell.
 * \param activeX Horizontal position of active cell.
 * \return Evaluated number.
 */

/*!
 * \fn bool CEvaluate::isOperator(const char& x) const
 * Checks if passed char is an allowed operator.
 * \param x Char to check.
 * \return True if \a x is an operator.
 */

/*!
 * \fn bool CEvaluate::isDouble(std::string str)const
 * Checks if passed string is an double number.
 * \param str String to be checked.
 * \return True if \a str is double.
 */

/*!
 * \fn double CEvaluate::evaluateExpression(const std::string &str, CWindowMain* main,int activeX,int activeY)const
 * Evaluates string into a double number.
 * \param str String to evaluate.
 * \param main Pointer on CWindowMain \a m_main in CScreen.
 * \param activeY Vertical position of active cell.
 * \param activeX Horizontal position of active cell.
 * \return Evaluated number.
 */

/*!
 * \fn void CEvaluate::doOperation(std::list<SOutputElement>&output)
 * Do operation with operands and operator from \a output.
 * \param output Parsed string transformed into a list of SOutputElements.
 * \param it Iterator with position where to start operation in \a output.
 * \return Result of operation.
 */



class CEvaluate {
public:
    CEvaluate();
    double valuate(const std::string &str, CWindowMain *main,int activeX,int activeY);
private:
    bool isOperator(const char& x) const;
    bool isDouble(std::string str)const;
    double evaluateExpression(const std::string &str, CWindowMain* main,int activeX,int activeY)const;
    void doOperation(std::list<SOutputElement>&output, std::list<SOutputElement>::iterator &it)const;

};

#endif	/* CEVALUATE_H */

