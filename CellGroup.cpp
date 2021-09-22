#include "CellGroup.h"

using namespace std;

CellGroup::CellGroup()
{
	for (int i = 0; i < 9; i++)
	{
		m_cellPointer[i] = nullptr;
	}
}

CellGroup::~CellGroup() = default;

Cell* CellGroup::GetCell(int index) const
{
	return m_cellPointer[index];
}
void CellGroup::SetCell(const int index, Cell*  const cell)
{
	m_cellPointer[index] =  cell;
}
