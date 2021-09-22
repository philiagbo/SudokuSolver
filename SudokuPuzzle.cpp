#include "SudokuPuzzle.h"
#include <iostream>
#include <chrono>
#include <fstream>

using namespace std;


SudokuPuzzle::SudokuPuzzle() {
	// Add code to initialise the SudokuPuzzle object
}



void SudokuPuzzle::solve(char filenameIn[]) {
	// Read puzzle from text file
	readPuzzle(filenameIn);

	// Get start time
	const auto startTime = std::chrono::high_resolution_clock::now();

	// Add code to solve the puzzle

	bool solved_Puzzle = false;
	int solvedCells;
	int passes_through_grid;
	do
	{		
		solved_Puzzle = true;
		solvedCells = 0;
		passes_through_grid = 0;
		for (int row = 0; row < 9; row++)
		{
			for (int column = 0; column < 9; column++)
			{
				//check if the cell has the number 0
				if (m_cellRows[row].GetCell(column)->get_value() == 0)
				{
					//if a cell has the number 0, the puzzle is unsolved
					solved_Puzzle = false;
					//determines what values can be added to the candidate list
					search_candidate_list(row, column);
					//if candidate list size has one value, set cell to that index value
					if (m_cellRows[row].GetCell(column)->get_candidateListSize() == 1)
					{
						m_cellRows[row].GetCell(column)->set_value(m_cellRows[row].GetCell(column)->get_candidateValue(0));						
					}				
				}
				else solvedCells++;
			}
			passes_through_grid++;
		}		
		output();
	} while (!solved_Puzzle);
	// Get end time
	const auto endTime = std::chrono::high_resolution_clock::now();
	const auto duration = (endTime - startTime).count();

	// Sample timing output in nanoseconds
	std::cout << duration << "ns" << std::endl;
	std::cout << solvedCells << std::endl;
	std::cout << passes_through_grid << std::endl;
	// Output the solved puzzle
	output();
}

//method to search the
void SudokuPuzzle::search_candidate_list(const int row, const int col)
{
	m_cellRows[row].GetCell(col)->clear();
	
	//defines a cells block
	const int blockIndex = (row / 3) * 3 + col / 3;
	
	//loops through the values in the cells candidate list
	for (int candidate = 1; candidate <= 9; candidate++)
	{
		bool value_possible = true;
		for (int index = 0; index < 9; index++)
		{
			// eliminating candidate values in the same block, row and column
			if (m_cellRows[row].GetCell(index)->get_value() == candidate ||
				m_cellColums[col].GetCell(index)->get_value() == candidate ||
				m_cellBlocks[blockIndex].GetCell(index)->get_value() == candidate)
			{
				value_possible = false;
				break;
			}
		}
		if (value_possible)
		{
			// adding the values left in the candidate to the candidate list
			m_cellRows[row].GetCell(col)->add_candidate(candidate);
		}
	}
}

void SudokuPuzzle::readPuzzle(char filenameIn[])
{
	// Add code to read in a puzzle from the text file and store within the SudokuPuzzle object
	ifstream sudoku_file(filenameIn);

	for (int row = 0; row < 9; row++)
	{
		for (int column = 0; column < 9; column++)
		{
			//variables for making each cell
			bool flag = false;
			int num;

			//reading in the number for each cell
			sudoku_file >> num;
			if (num != 0)
			{
				// the value is given in the data file
				flag = true;
			}
			m_cellRows[row].SetCell(column, new Cell(num, flag));
			m_cellColums[column].SetCell(row, m_cellRows[row].GetCell(column));
			
			//caluculating the cell blocks
			const int blockIndex = (row / 3) * 3 + column / 3;
			const int block_inside = column % 3 + row % 3 * 3;
			m_cellBlocks[blockIndex].SetCell(block_inside, m_cellRows[row].GetCell(column));
		}
	}
}


void SudokuPuzzle::output() const
{
	// Add code to output your solved puzzle
	ofstream OutFile("sudoku_solution.txt");
	if(OutFile.good())
	for (int row = 0; row < 9; row++)
	{
		for (int column = 0; column < 9; column++)
		{
			
			OutFile << m_cellRows[row].GetCell(column)->get_value();
			OutFile << " ";
		}
		OutFile << endl;
	}
	OutFile.close();

}