/*
 * globals.h
 *
 *  Created on: 27.10.2012
 *      Author: mhelmich
 */

#ifndef GLOBALS_H_
#define GLOBALS_H_


#include "tbb/mutex.h"


#ifdef SUDOKU_MAIN
#define EXTERN
#else
#define EXTERN extern
#endif


EXTERN tbb::mutex coutLock;
EXTERN bool solutionFound;


#endif /* GLOBALS_H_ */
