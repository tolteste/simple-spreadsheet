/* 
 * File:   SPair.h
 * Author: steve
 *
 * Created on 19. červen 2013, 22:10
 */

#ifndef SPAIR_H
#define	SPAIR_H

/*! 
 * /brief Represents pair of integers.
 */

struct SPair {
    SPair(){};
    SPair(const int &x,const int &y);
    int first;
    int second;
};

#endif	/* SPAIR_H */

