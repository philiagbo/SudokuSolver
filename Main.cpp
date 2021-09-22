#include "SudokuPuzzle.h"
#include <fstream>

using namespace std;

int main(const int argc, char **) {
	SudokuPuzzle puzzle;

	puzzle.solve("sudoku_puzzle.txt"); 

	return 0;
}
