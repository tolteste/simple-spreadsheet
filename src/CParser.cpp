/* 
 * File:   CParser.cpp
 * Author: steve
 * 
 * Created on 8. červen 2013, 23:24
 */

#include "CParser.h"
#include <string>
#include <istream>
#include <sstream>
#include "CScreen.h"
#include "CEvaluate.h"
#include <list>
#include <limits.h>
#include <math.h>
using namespace std;

SOperator::SOperator() {
    op = ' ';
    precedence = 0;
}

SOperator& SOperator::operator =(const SOperator& x) {
    if (this != &x) {
        op = x.op;
        precedence = x.precedence;
    }
    return *this;
}

SOutputElement::SOutputElement() {
    sign = ' ';
    number = 0;
}

CParser::CParser() {
}

void CParser::rateOperator(SOperator& op, const char& ch) const {
    if (ch == '+' || ch == '-') {
        op.op = ch;
        op.precedence = 1;
        return;
    }
    if (ch == '*' || ch == '/') {
        op.op = ch;
        op.precedence = 2;
        return;
    }
}

bool CParser::isOperator(const char& x) const {
    return (x == '+' || x == '-' || x == '*' || x == '/');
}

bool CParser::compareOperators(const SOperator& x, const SOperator& y) const {
    return x.precedence > y.precedence;
}

bool CParser::isInt(const int& number) const {
    if (number == INT_MAX) return false;
    return true;
}

bool CParser::cycleDetection(const int& activeX, const int& activeY, const int& checkX, const int& checkY, CWindowMain* main) const {
    if (main->cycle(checkX-'A',checkY,activeX,activeY)) {
        return true;
    }
    return false;
}

list<SOutputElement> CParser::makeOutput(const string &exp, CWindowMain *main, int activeX, int activeY) {
    int ch, pos;
    bool isFirst = true;
    string err;
    double number;
    SOperator op;
    SOutputElement outElem;
    main->clearReference(activeX, activeY);
    m_operatorStack.push_back(op); //have to compare with something
    stringstream ss;
    ss.str(exp);
    while (true) {
        ch = ss.get();
        if (ch == EOF) {
            break;
        }
        if (ch >= 'A' && ch <= 'A' + ceil((COLS - 11) / 10)) {
            isFirst = false;
            pos = INT_MAX;
            ss >> pos;
            if (!isInt(pos) || pos > (LINES - 7) / 2) {
                err.append("ERROR: Invalid input");
                throw err;
                break;
            }
            //cycle detection  
            stringstream ss2;
            ss2 << (char) (activeX + 'A');
            ss2 << activeY;
            string hlp = ss2.str();
            if (cycleDetection(activeX + 'A', activeY, ch, pos, main) || std::string::npos != exp.find(hlp)) {
                ss.clear();
                err.append("ERROR: Cycle detected");
                throw err;
                break;
            }
            SPair coordinates (ch,pos);
            main->pushReference(activeX, activeY,coordinates);
            number = main->getVal(ch - 'A', pos);
            outElem.number = number;
            outElem.sign = 'n';
            m_output.push_back(outElem);
            continue;

        } else { //recognize operator and check if its - to find out if -4+5 expression is possible
            if (isOperator(ch)) {
                if (isFirst && ch == '-') {
                } else {
                    if (isFirst && (ch == '/' || ch == '+' || ch == '*')) {
                        err.append("ERROR: Invalid input");
                        throw err;
                        break;
                    }
                    isFirst = false;
                    rateOperator(op, ch);
                    if (compareOperators(op, m_operatorStack.back())) {
                        m_operatorStack.push_back(op);
                    } else {
                        SOperator tmp;
                        tmp = m_operatorStack.back();
                        m_operatorStack.pop_back();
                        m_operatorStack.push_back(op);
                        outElem.op = tmp.op;
                        outElem.sign = 'c';
                        m_output.push_back(outElem);
                    }
                    continue;
                }
            }

            if ((ch <= '9' && ch >= '0') || (ch == '-' && isFirst == true)) {
                isFirst = false;
                ss.putback(ch);
                ss >> number;
                outElem.number = number;
                outElem.sign = 'n';
                m_output.push_back(outElem);
                if (ss.fail()) {
                    ss.clear();
                    err.append("ERROR: Invalid input");
                    throw err;
                    break;
                }
            } else {
                if (ch == '(') {
                    isFirst=false;
                    recursion(ss, activeX, activeY, main);
                    continue;
                }
                //fail
                err.append("ERROR: Invalid input");
                throw err;
                break;
            }
        }
    }
    list<SOperator>::const_iterator it;
    int i = m_operatorStack.size();
    while (i > 1) {
        op = m_operatorStack.back();
        m_operatorStack.pop_back();
        outElem.op = op.op;
        outElem.sign = 'c';
        m_output.push_back(outElem);
        i--;
    }

    return m_output;
}

void CParser::recursion(stringstream &ss, int activeX, int activeY, CWindowMain* main) {
    SOutputElement outElem;
    string str;
    int counter = 1;
    char ch = ' ';
    while (ch != EOF) {
        ch = ss.get();
        if (ch == '(') {
            str.insert(str.end(), ch);
            counter++;
            continue;
        }
        if (ch == ')') counter--;
        if (counter == 0) break;
        str.insert(str.end(), ch);
    }
    CEvaluate eval;
    outElem.number = eval.valuate(str, main, activeX, activeY);
    outElem.sign = 'n';
    m_output.push_back((outElem));
}