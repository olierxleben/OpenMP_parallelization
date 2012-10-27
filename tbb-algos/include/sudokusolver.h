/*
 * sudokusolver.h
 *
 *  Created on: 27.10.2012
 *      Author: mhelmich
 */

#ifndef SUDOKUSOLVER_H_
#define SUDOKUSOLVER_H_


#include "tbb/task.h"
#include "sudoku.h"


class SudokuSolver : public tbb::task
{

private:
	Sudoku *puzzle;
	uint *counter;

public:
	SudokuSolver(Sudoku *p, uint* count);
	~SudokuSolver();

	tbb::task* execute();
};


#endif /* SUDOKUSOLVER_H_ */
