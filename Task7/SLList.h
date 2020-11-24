#pragma once

class SLList
{
private:
	bool m_isFirst = false;
	SLList* m_nextElem = nullptr;
	int m_data = 0;	
	SLList();	
public:
	~SLList();
	static SLList* beginList(int data);
	int getData() const;
	void setData(int data);
	SLList* next() const;
	bool hasNext() const;	
	SLList* addElement(int data);
	void removeNext();
};