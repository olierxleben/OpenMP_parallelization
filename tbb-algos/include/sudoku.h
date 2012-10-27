/*
 * puzzle.h
 *
 *  Created on: 27.10.2012
 *      Author: mhelmich
 */

#ifndef PUZZLE_H_
#define PUZZLE_H_


#include <cstdlib>
#include <sys/types.h>


#define SUDOKU_DEFAULT_SIZE 9
#define SUDOKU_DEFAULT_CELLSIZE 3


typedef struct {
	uint x, y;
} Point;


class Sudoku
{
	unsigned int size, sqSize, cellSize;
	unsigned int* fields;

public:
	Sudoku(uint size=SUDOKU_DEFAULT_SIZE, uint cellSize=SUDOKU_DEFAULT_CELLSIZE);
	Sudoku(Sudoku *copyFrom);
	Sudoku(char* filename);
	~Sudoku();

	uint getSize() { return size; };
	uint getAt(uint x, uint y) const;
	void setAt(uint x, uint y, uint value);
	Point* getNextFree() const;
	bool isValuePossibleFor(uint x, uint y, uint value) const;
	void read(char* filename);
	void print();

private:
	void printHline();
};


#endif /* PUZZLE_H_ */
