#include "Cell.h"
#pragma once

class CellGroup
{
public:
	CellGroup();
	~CellGroup();

	void SetCell(int index, Cell*  const cell) ;

	//get cell pointer method
	Cell* GetCell(int index) const;

private:
	Cell* m_cellPointer[9];
	

};

