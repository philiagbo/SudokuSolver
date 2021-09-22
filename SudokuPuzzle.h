#pragma once
#include "Cell.h"
#include "CellGroup.h"

using namespace std;

// Add your code here

class SudokuPuzzle {
public:
	SudokuPuzzle();


	void solve (char filenameIn[]);
	void readPuzzle(char filenameIn[]);
	// Add your code here

	void search_candidate_list(int row, int col);

	void output() const;


private:	
	// Add your code here
	CellGroup m_cellColums[9];
	CellGroup m_cellBlocks[9];
	CellGroup m_cellRows[9];

};