//============================================================================
// Name        : TBB-Kandane.cpp
// Author      : Martin Helmich
// Version     :
// Copyright   : 
// Description : Hello World in C, Ansi-style
//============================================================================

#include <iostream>

#define SUDOKU_MAIN

#include "tbb/task.h"
#include "globals.h"
#include "sudoku.h"
#include "sudokusolver.h"


using namespace std;
using namespace tbb;


int main(int argc, char* argv[])
{
	Sudoku *p;
	uint count = 0;

	cout << "Lade " << argv[1] << "..." << endl;
	p = new Sudoku(argv[1]);
	//p->read(argv[1]);

	p->print();

	solutionFound = false;
	SudokuSolver &root = *new(task::allocate_root()) SudokuSolver(p, &count);
	task::spawn_root_and_wait(root);

	cout << "Lösung wurde in " << count << " Tasks gefunden." << endl;
}
