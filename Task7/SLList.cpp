#include "SLList.h"

SLList::SLList() = default;

SLList::~SLList()
{
	if (m_isFirst)
	{
		while (hasNext())
		{
			removeNext();
		}
	}
}

int SLList::getData() const
{
	return m_data;
}

void SLList::setData(int data)
{
	m_data = data;
}

SLList* SLList::next() const
{
	return m_nextElem;
}

bool SLList::hasNext() const
{
	return m_nextElem != nullptr;
}

SLList* SLList::beginList(int data)
{
	auto list = new SLList();
	list->m_isFirst = true;
	list->m_data = data;
	return list;
}

SLList* SLList::addElement(int data)
{
	auto list = new SLList();
	list->m_data = data;
	m_nextElem = list;
	return list;
}

void SLList::removeNext()
{
	auto to_remove = m_nextElem;
	m_nextElem = m_nextElem->m_nextElem;
	delete to_remove;
}