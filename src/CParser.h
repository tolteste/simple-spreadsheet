/* 
 * File:   CParser.h
 * Author: steve
 *
 * Created on 8. červen 2013, 23:24
 */

#ifndef CPARSER_H
#define	CPARSER_H
#include <string>
#include "CWindow.h"
#include "CWindowMain.h"
#include <list>

/*! 
 * \struct SOperator
 * \brief Represents operator with his precedence.
 */

/*!
 * \fn SOperator::SOperator()
 * \brief Initializes SOperator
 */

/*! 
 * \fn SOperator& SOperator::operator=(const SOperator &x)
 * \brief Overloaded operator =.
 */

/*! 
 * \struct SOutputElement
 * \brief Represents element in parsed output
 */

/*!
 * \fn SOutputElement::SOutputElement()
 * \brief Initialize SOutputElement
 */

/*!
 * \class CParser
 * \brief Parses mathematical expresion
 * 
 * Parses string into list of SOutputElements by using Shunting-yard algorithm.
 */

/*! 
 * \fn CParser::CParser()
 * Initialize CParser
 */

/*! 
 * \fn std::list<SOutputElement> CParser::makeOutput(const std::string &exp,  CWindowMain *main, int activeX, int activeY)
 * Parses string into list of SOutputElements by using Shunting-yard algorithm.
 * \param exp String to parse.
 * \param main Pointer on CWindowMain \a m_main in CScreen.
 * \param activeY Vertical position of active cell.
 * \param activeX Horizontal position of active cell.
 * \return List of parsed SOutputElements.
 */

/*!
 * \fn bool CParser::compareOperators(const SOperator &x, const SOperator &y)const
 * \brief Compare two operators.
 * \param x First operator.
 * \param y Second operator. 
 * \return True if first one has higher precendence.
 */

/*!
 * \fn bool CParser::isOperator(const char &x)const
 * \brief Checks if \a is an operator.
 * \param x Char to check.
 * \return True if \a x is an operator
 */

/*!
 * \fn void CParser::rateOperator(SOperator &op, const char &ch)const
 * \brief Rates operator precedence.
 * \param op SOperator where rating is saved.
 * \param ch Operator to rate.
 */

/*!
 * \fn bool CParser::isInt(const int &number)const
 * \brief Checks if \a number is int.
 * \param number Number to check.
 * \return True if \a number is int.
 */
 
/*!
 * \fn void CParser::recursion(std::stringstream &ss, int activeX, int activeY,CWindowMain* main)
 * \brief Allows using parenthesis in expressions.
 * Creates a new CEvaluate and pass him a shorter expresion.
 * \param ss Mathematical expression.
 * \param activeX Horizontal position of active cell.
 * \param activeY Vertical position of active cell.
 * \param main Pointer on CWindowMain \a m_main in CScreen.
 */

/*! 
 * \fn bool CParser::cycleDetection(const int& activeX, const int& activeY, const int& checkX, const int& checkY,CWindowMain* main)const
 * \brief Check cycle expressions.
 * \param activeX Horizontal position of active cell.
 * \param activeY Vertical position of active cell.
 * \param checkX Horizontal position of cell where to check. 
 * \param checkY Vertical position of cell where to check.
 * \param main Pointer on CWindowMain \a m_main in CScreen.
 * \return True if cycle is detected.
 */

struct SOperator {
    SOperator();
/*! Precedence of operator */
    int precedence;
/*! operator */   
    char op;
    SOperator& operator=(const SOperator &x); 
};

struct SOutputElement {    
    double number;
    
    char op;
/*! Says if operator in op is inserted or value in number is inserted. 'c' for op and 'n' for number. */    
    char sign;
    SOutputElement();
};

class CParser {
public:
    CParser();
    std::list<SOutputElement> makeOutput(const std::string &exp,  CWindowMain *main, int activeX, int activeY);
private:
    std::list<SOperator> m_operatorStack;
    std::list<SOutputElement> m_output;
    bool compareOperators(const SOperator &x, const SOperator &y)const;
    bool isOperator(const char &x)const;
    void rateOperator(SOperator &op, const char &ch)const;
    bool isInt(const int &number)const;
    void recursion(std::stringstream &ss, int activeX, int activeY,CWindowMain* main);
    bool cycleDetection(const int& activeX, const int& activeY, const int& checkX, const int& checkY,CWindowMain* main)const;
    CWindowMain* m_main;
};



#endif	/* CPARSER_H */

