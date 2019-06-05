/* 
 * File:   CWindow.h
 * Author: steve
 *
 * Created on 30. květen 2013, 16:32
 */

#ifndef CWINDOW_H
#define	CWINDOW_H
#include <ncurses.h>
#include <string>

/*! 
 * \class CWindow
 * \brief Abstract class for WINDOWS.
 */

class CWindow {
public:
/*! \brief Initializes CWindow variables.
 * \param height Height of allocated WINDOW.
 * \param width Width of allocated WINDOW.
 * \param x_pos Vertical position where WINDOW starts.
 * \param y_pos Horizontal position where WINDOW starts.
 */
    CWindow(const int &height, const int &width, const int &x_pos, const int &y_pos);

    CWindow() {
    };
    virtual void draw() const = 0;
/*!
 * \return Pointer on allocated WINDOW.
 */
    virtual WINDOW* getWindow() const;

protected:
/*! \brief Pointer on alocated WINDOW. */
    WINDOW* m_win;
/*! \brief Vertical position where WINDOW starts. */
    int m_x_pos;
/*! \brief Horizontal position where WINDOW starts. */
    int m_y_pos;
/*! \brief Height of allocated WINDOW. */
    int m_height;
/*! \brief Width of allocated WINDOW. */
    int m_width;
    virtual ~CWindow();
};


#endif	/* CWINDOW_H */

