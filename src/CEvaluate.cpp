/* 
 * File:   CEvaluate.cpp
 * Author: steve
 * 
 * Created on 11. červen 2013, 10:46
 */

#include "CEvaluate.h"
#include <string>
#include "CParser.h"
#include "CWindow.h"
#include <sstream>
using namespace std;

CEvaluate::CEvaluate() {
}

bool CEvaluate::isDouble(std::string str) const {
    double number;
    stringstream ss;
    ss.str(str);
    ss >> number;
    if (ss.get() == EOF && !ss.fail()) {
        return true;
    }
    return false;
}

double CEvaluate::valuate(const std::string& str, CWindowMain* main, int activeX, int activeY) {
    double number;
    if (isDouble(str)) {
        stringstream ss;
        ss.str(str);
        ss >> number;
        return number;
    }
    number = evaluateExpression(str, main, activeX, activeY);

    return number;
}

bool CEvaluate::isOperator(const char& x) const {
    return (x == '+' || x == '-' || x == '*' || x == '/');
}

void CEvaluate::doOperation(list<SOutputElement>&output, list<SOutputElement>::iterator &it) const {
    double number1, number2;
    string err;
    switch (it->op) {
        case '+':
            it--;
            number2 = it->number;
            it = output.erase(it);
            it--;
            number1 = it->number;
            it = output.erase(it);
            it->number = number1 + number2;
            it->sign = 'n';
            break;
        case '-':
            it--;
            it--;
            number1 = it->number;
            it = output.erase(it);
            number2 = it->number;
            it = output.erase(it);
            it->number = number1 - number2;
            it->sign = 'n';
            break;
        case '/':
            it--;
            it--;
            number1 = it->number;
            it = output.erase(it);
            number2 = it->number;
            if (number2 == 0) {
                err.append("ERROR: You can't divide with zero");
                throw err;
            }
            it = output.erase(it);
            it->number = number1 / number2;
            it->sign = 'n';
            break;
        case '*':
            it--;
            number2 = it->number;
            it = output.erase(it);
            it--;
            number1 = it->number;
            it = output.erase(it);
            it->number = number1 * number2;
            it->sign = 'n';
            break;
    }
}

double CEvaluate::evaluateExpression(const std::string& str, CWindowMain* main, int activeX, int activeY) const {
    list<SOutputElement> output;
    list<SOutputElement>::iterator it;
    CParser parser;
    output = parser.makeOutput(str, main, activeX, activeY);


    it = output.begin();
    while (output.size() != 1) {
        if (it->sign == 'c' && isOperator(it->op)) {
            doOperation(output, it);
        } else {
            it++;
        }
    }
    return it->number;
}


