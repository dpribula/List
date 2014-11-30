/**
* @file listitem.h
* @author David Pribula
*/
#ifndef LISTITEM_H
#define LISTITEM_H

#include<iostream>

using namespace std;
template <typename T>
/**
*@brief class listitem
*/
class ListItem
{


public:
	/**
	*@brief type T
	*/
	typedef T ValueType;
	/**
	*@brief type ListItem<T>
	*/
	typedef ListItem<T> ItemType;
	/**
	*@brief constructor
	*/
	ListItem():nextItem(NULL), previousItem(NULL){}
	/**
	*@brief constructor
	*/
	ListItem(const ValueType& value) :nextItem(NULL), previousItem(NULL),m_value(value){}
	/**
	*@brief next item
	*@return itemtype
	*/
	ItemType* getNext() const{
		return nextItem;
	}
	/**
	*@brief previous item
	*@return itemType
	*/
	ItemType* getPrevious() const{
		return previousItem;
	}
	/**
	*@brief value
	*@return ValueType
	*/
	ValueType& getValue() {
		return m_value;
	}
	/**
	*@brief value
	*@return reference to calue
	*/
	ValueType  getValue() const{
		return m_value;
	}
	/**
	*@brief destructor
	*/
	virtual ~ListItem(){
		
	}
	/**
	*@brief friend class
	*/
	 template <class U>friend class List;
private:

	/**
	*@brief nextItem
	*/
	ItemType *nextItem;
	/**
	*@brief prvious Item
	*/
	ItemType *previousItem;
	/**
	*@brief value
	*/
	ValueType m_value;
};
#endif

