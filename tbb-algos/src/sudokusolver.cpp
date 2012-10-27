/*
 * sudokutask.cpp
 *
 *  Created on: 27.10.2012
 *      Author: mhelmich
 */


#include <iostream>
#include <exception>
#include "globals.h"
#include "sudokusolver.h"


using namespace std;
using namespace tbb;


SudokuSolver::SudokuSolver(Sudoku *p, uint *c)
{
	puzzle = p;
	counter = c;
}


SudokuSolver::~SudokuSolver()
{

}


task* SudokuSolver::execute()
{
	if (solutionFound == true) { return NULL; }

	Point *p;

	//coutLock.lock();
	//cout << "Fortschritt: " << *counter << endl;
	//coutLock.unlock();

	*counter = *counter + 1;

	p = puzzle->getNextFree();
	if (p != NULL)
	{
		try
		{
			task_list list;
			uint task_count[puzzle->getSize()];
			uint count = 0, size = puzzle->getSize();
			Sudoku** children = new Sudoku*[puzzle->getSize()];

			for (uint i=1; i <= puzzle->getSize(); i++)
			{
				task_count[i-1] = 0;
				if (puzzle->isValuePossibleFor(p->x, p->y, i))
				{
					children[count] = new Sudoku(puzzle);
					children[count]->setAt(p->x, p->y, i);

					list.push_back(*new(allocate_child()) SudokuSolver(children[count], &(task_count[i-1])));
					count ++;
				}
			}

			free(puzzle);

			if (count > 0)
			{
				set_ref_count(count + 1);
				spawn_and_wait_for_all(list);

				//for (uint i=0; i < count; i++) { free (children[i]); }

				for (uint i=0; i < size; i++)
				{
					*counter += task_count[i];
				}
			}
		}
		catch(bad_alloc&)
		{
			coutLock.lock();
			cerr << "Jetzt ist Schluss.";
			coutLock.unlock();
		}
	}
	else
	{
		// Fertig.
		solutionFound = true;

		// Hinweis: Stdout muss per Lock geschützt werden; wenn mehrere Threads
		// gleichzeitig schreiben, gibts Chaos.
		coutLock.lock();
		cout << "Lösung gefunden: " << endl;
		puzzle->print();
		coutLock.unlock();
	}

	return NULL;
}
