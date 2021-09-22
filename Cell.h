#pragma once
#include <vector>;
using namespace std;

class Cell {
public:
	Cell();
	~Cell();

	Cell(int value, bool flag);

	//bool Candidate_list_search(int value);

	//getters
	int get_value() const;
	bool get_flag() const;
	int get_candidateListSize() const;
	int get_candidateValue(int index) const;

	//setters
	void set_value(int new_value);
	void set_given(bool new_flag);
	void add_candidate(int value_to_be_removed);
	
	void clear();


private:
	vector <int> m_candidateList;
	int m_value;
	bool m_given;
};

