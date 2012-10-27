/*
 * puzzle.cpp
 *
 *  Created on: 27.10.2012
 *      Author: mhelmich
 */


#include "sudoku.h"
#include <iostream>
#include <cstdio>
#include <cstring>


using namespace std;


/**
 * Erstellt ein neues Sudoku.
 *
 * @param width  Breite
 * @param height Höhe
 */
Sudoku::Sudoku(uint s, uint cs) : size(s), sqSize(s*s), cellSize(cs)
{
	fields = new unsigned int[sqSize];

	for (int i=0; i < sqSize; i++)
	{
		fields[i] = 0;
	}
}


/**
 * Erstellt ein neues Sudoku als Kopie eines anderen Sudokus.
 *
 * @param copyFrom Ein Zeiger auf das zu kopierende Sudoku.
 */
Sudoku::Sudoku(Sudoku *copyFrom)
{
	size     = copyFrom->size;
	sqSize   = copyFrom->sqSize;
	cellSize = copyFrom->cellSize;

	fields = new unsigned int[sqSize];

	for (int i=0; i < sqSize; i++)
	{
		fields[i] = copyFrom->fields[i];
	}
}


Sudoku::Sudoku(char* filename)
{
	FILE* fp = fopen(filename, "r");
	int i=0, j=0;
	char c;

	size = 0;

	// Länge der ersten Zeile ermitteln.
	do { j++; c = getc(fp); }
	while(c != 10 && c != 13);

	// Dateizeiger zurücksetzen.
	fseek(fp, 0, SEEK_SET);

	size = j-1;
	sqSize = size*size;
	fields = new unsigned int[sqSize];

	do
	{
		c = getc(fp);
		if (c == 10 || c == 13) { continue; }

		fields[i++] = strtol(&c, NULL, 16);
	}
	while(c != EOF);

	fclose(fp);

	if (size % 3 == 0) { cellSize = 3; }
	else if (size % 4 == 0) { cellSize = 4; }
}


/**
 * Destruktor.
 */
Sudoku::~Sudoku(void)
{
	free(this->fields);
}


/**
 * Liefert den Wert an einer bestimmten Stelle.
 *
 * @param x
 */
uint Sudoku::getAt(uint x, uint y) const
{
	return this->fields[y*this->size+x];
}


void Sudoku::setAt(uint x, uint y, uint value)
{
	this->fields[y*size+x] = value;
}


Point* Sudoku::getNextFree() const
{
	Point* p;

	for(uint x=0; x < size; x++)
	{
		for(uint y=0; y < size; y++)
		{
			if(fields[y*size+x] == 0)
			{
				p = new Point;
				p->x = x;
				p->y = y;
				return p;
			}
		}
	}

	return NULL;
}


bool Sudoku::isValuePossibleFor(uint x, uint y, uint value) const
{
	// Zeilenweise überprüfen
	for(uint cx=0; cx < size; cx++)
	{
		if (cx == x) { continue; }
		if (this->getAt(cx,y) == value) { return false; }
	}

	// Spaltenweise überprüfen
	for(uint cy=0; cy < size; cy ++)
	{
		if (cy == y) { continue; }
		if (this->getAt(x,cy) == value) { return false; }
	}

	for(uint cx = (x/3) * 3; cx < (x/3+1) * 3; cx ++)
	{
		for(uint cy = (y/3) * 3; cy < (y/3+1) * 3; cy ++)
		{
			if (cx == x && cy == y) { continue; }
			if (this->getAt(cx,cy) == value) { return false; }
		}
	}

	return true;
}


void Sudoku::read(char* filename)
{
}


void Sudoku::printHline()
{
	for(uint x=0; x < size; x++)
	{
		cout << ((x % cellSize == 0) ? "+--" : "--");
	}
	cout << "+" << endl;
}


void Sudoku::print()
{
	for(uint y=0; y < size; y++)
	{
		if (y % cellSize == 0) { printHline(); }

		for(uint x=0; x < size; x++)
		{
			if (x % cellSize == 0) { cout << "|"; }

			if (fields[y*size+x] > 0 ) { printf("%2i", fields[y*size+x]); }
			else { cout << "  "; }
		}
		cout << "|" << endl;
	}
	printHline();
}
