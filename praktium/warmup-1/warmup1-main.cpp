//============================================================================
// Name        : PVA-Praktikum.cpp
// Author      : Martin Helmich
// Version     :
// Copyright   : 
// Description : Hello World in C, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "tbb/parallel_for.h"
#include "tbb/blocked_range.h"

#define N 10

using namespace std;
using namespace tbb;

int input[N];
int output[N];

class NumberSimplifyer
{
public:
	// Der "const"-Modifier ist entgegen anderer Angaben SEHR wichtig!
	void operator() (const blocked_range<unsigned int>& range) const
	{
		for (unsigned int i = range.begin(); i != range.end(); ++i)
		{
			if (input[i] == 0) { output[i] = 0; }
			else if (input[i] < 0) { output[i] = -1; }
			else { output[i] = 1; }
		}
	}
};

/**
 * Gibt eine Liste schšn formatiert auf der Kommandozeile aus.
 */
void printList(int* list, unsigned int count)
{
	for(int i=0; i < count; i ++)
	{
		printf("%3i ", list[i]);
	}
	cout << endl;
}

int main(void)
{
	// Zufallszahlengenerator initialisieren (ja ich wei§, einfach die Systemzeit nehmen ist unsicher!)
	// Eingabevektor mit Zufallszahlen fŸllen.
	srand((unsigned int) time(NULL));
	for(int i=0; i < N; i ++)
	{
		input[i] = (rand() % 200) - 100;
	}

	// Eingabevektor ausgeben.
	printList(&input[0], N);

	// Feuer frei!
	parallel_for(blocked_range<unsigned int>(0, N), NumberSimplifyer());

	// Ausgabevektor ausgeben.
	printList(&output[0], N);
}
