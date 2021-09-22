#include "Cell.h"

Cell::Cell()
{
	set_value(0);
	set_given(false);
}

//specific constructor
Cell::Cell(const int  value , const bool given)
{
	set_value(value);

	//flag is false if value is pre-defined
	set_given(given);

	//sets candidate list size to 9
	for (int i = 1; i <= 9; i++)
	{
		m_candidateList.push_back(i);
	}
}

Cell::~Cell()
= default;

//bool Cell::Candidate_list_search(int value)
//{
//	 
//	for (int i = 0; i < m_candidateList.size(); i++)
//	{
//		if (value == m_candidateList[i])
//		{
//			add_candidate(value);
//			return false;
//		}
//	}
//}

//returns the candidate index value
int Cell::get_candidateValue(const int  index) const
{
	return m_candidateList[index];
}

//adds values from the candidate list
void Cell::add_candidate(const int value_to_be_added)
{
	m_candidateList.push_back(value_to_be_added);
}

void Cell::clear()
{ // clears all values in the candidate list
	m_candidateList.clear();
}

//returns the value in a cell
int Cell::get_value() const
{
	return m_value;
}

// returns if the value in the cell was alread given
bool Cell::get_flag() const
{
	return m_given;
}

// returns the length of a cells candidate list
int Cell::get_candidateListSize() const
{
	return m_candidateList.size();
}


void Cell::set_value(const int new_value)
{
	m_value = new_value;
}

void Cell::set_given(const bool new_given)
{
	 m_given = new_given;
}

