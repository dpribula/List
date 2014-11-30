/**
* @file list.h
* @author David Pribula
*/
#ifndef LIST_H
#define LIST_H

#include "listitem.h"
/**
*@brief ads
*/
template <typename T>
/**
*@brief dsa
*/
class List
{
public:
	/**
	*@brief dsa
	*/
	typedef typename ListItem<T>::ValueType ValueType;
	/**
	*@brief as
	*/
	typedef typename ListItem<T>::ItemType ItemType;
	/**
	*@brief da
	*/
	List():m_begin(NULL),m_end(NULL){}
	/**
	*@brief ads 
	*@param list
	*/
	List(const List<T>& list){
		ListItem<T>* temp = list.first();
		m_begin = NULL;
		m_end = NULL;
		while (temp != NULL){
			push_back(temp->getValue());
			temp = temp->getNext();
		}
		
	}
	/**
	*@brief constructor
	*@param begin dsa
	*@param end
	*/
	List(ItemType* begin, ItemType* end){
		ListItem<T>* temp = begin;
		m_begin = NULL;
		m_end = NULL;
		while (temp != end){
			push_back(temp->getValue());
			temp = temp->getNext();
		}
		if (temp!=NULL)
			insert_after(m_end, temp->getValue());
		

	}
	/**
	*@brief destructor
	*/
	~List(){
		ItemType* temp = m_begin;
		ItemType* temp2 = m_begin;
		if (m_begin == NULL)
			return;
		while (temp != NULL){
			temp = temp->nextItem;
			delete(temp2);
			temp2 = temp;
		}
	
		

		
	}
	/**
	*@brief dsa
	*@return itemType
	*/
	ItemType* first() const{
		return m_begin;
	}
	/**
	*@brief das
	*@return ItemType
	*/
	ItemType* last() const{
		return m_end;
	}
	/**
	*@brief dsa
	*@return bool
	*/
	bool empty() const{
		return m_begin == NULL;
	}
	/**
	*@brief
	*@param existing sad
	*@param v sa
	*@return sa
	*/
	ItemType* insert_after(ItemType* existing, const ValueType& v){
		ItemType* inserting = new ItemType(v);
		if (existing == NULL){
			if (m_begin == NULL){
				m_begin = inserting;
				m_end = inserting;
			}
			else{
				inserting->nextItem = m_begin;
				m_begin->previousItem = inserting;
				m_begin = inserting; 
			}
		}
		else{
			inserting->previousItem = existing;
			inserting->nextItem = existing->nextItem;
			
			if (existing->nextItem != NULL)
				existing->nextItem->previousItem = inserting;
			existing->nextItem = inserting;
			if (existing == m_end)
				m_end = inserting;
			
				
		}
		return inserting;

	}
	/**
	*@brief dsa
	*@param existing
	*@param v sa
	*@return dsa
	*/
	ItemType* insert_before(ItemType* existing, const ValueType& v){
		ItemType* inserting = new ItemType(v);
		if (existing == NULL){
			if (m_begin == NULL){
				m_begin = inserting;
				m_end = inserting;
			}
			else{
				inserting->previousItem = m_end;
				m_end->nextItem = inserting;
				m_end = inserting;
			}
		}
		else{
			inserting->nextItem = existing;
			inserting->previousItem = existing->previousItem;
			if (existing->previousItem != NULL)
				existing->previousItem->nextItem = inserting;
			existing->previousItem = inserting;

			if (existing == m_begin)
				m_begin = inserting;


		}
		return inserting;
	}
	/**
	*@brief das
	*@param v
	*@return das
	*/
	ItemType* push_back(const ValueType& v){
		return insert_after(m_end, v);
	}
	/**
	*@brief
	*@param v das
	*@return da
	*/
	ItemType* push_front(const ValueType& v){
		return insert_before(m_begin, v);
	}
	/**
	*@brief da
	*@return dsa
	*/
	ItemType* pop_front(){
		if (m_begin == NULL)
			return NULL;
		ItemType* pop = m_begin;
		
		if (m_end == m_begin)
		{
			m_end = NULL;
			m_begin = NULL;
		}
		else{
			m_begin = m_begin->nextItem;
			if (m_begin != NULL)
				m_begin->previousItem = NULL;
		}
		return pop ;
	}
	/**
	*@brief dsa
	*@return dsa
	*/
	ItemType* pop_back(){
		if (m_end == NULL)
			return NULL;
		ItemType* pop = m_end;
		if (m_end == m_begin)
		{
			m_end = NULL;
			m_begin = NULL;
		}
		else{
			m_end = m_end->previousItem;
			if (m_end != NULL)
				m_end->nextItem = NULL;
		}

		return pop;
	}
	/**
	*@brief dsa
	*@param i
	*/
	void remove(ItemType* i){
		if (i == NULL)
			return;
		if (m_begin == i || m_end == i){
			if (i == m_begin){

				m_begin = m_begin->nextItem;
				if (m_begin!=NULL)
					m_begin->previousItem = NULL;
			}
			if (i == m_end){
				m_end = m_end->previousItem;
				if (m_end!=NULL)
					m_end->nextItem = NULL;
			}
		}
		else{
			if (i->previousItem!=NULL)
				i->previousItem->nextItem = i->nextItem;
			if (i->nextItem!=NULL)
				i->nextItem->previousItem = i->previousItem;
		}
		i->nextItem = NULL;
		i->previousItem = NULL;
		delete(i);
		i = NULL;
		
		
		
		
		
	}
	/**
	*@brief das
	*@param begin sa
	*@param end dsa
	*/
	void remove(ItemType* begin, ItemType* end) {
		
		if (begin == end){
			remove(begin);
			return;
		}
		if (begin == NULL||end==NULL)
			return;
		
		ItemType* current=begin->nextItem;
		if (current == NULL){
			remove(begin);
		}
		while (current != end->nextItem){
			remove(current->previousItem);
				current = current->nextItem;
		}
		remove(end);
	
		
		
		
	}
	/**
	*@brief dsa
	*/
	void clear(){
		remove(m_begin, m_end);
	}
	/**
	*@brief
	*@param i dsa
	*@return dsa
	*/
	ItemType* unlink(ItemType* i){ 
		if (i == NULL)
			return NULL;
		if (m_begin == i || m_end == i){
			if (i == m_begin){

				m_begin = m_begin->nextItem;
				if (m_begin!=NULL)
					m_begin->previousItem = NULL;
			}
			if (i == m_end){
				m_end = m_end->previousItem;
				if (m_end!=NULL)
					m_end->nextItem = NULL;
			}
		}
		else{
			if (i->previousItem!=NULL)
				i->previousItem->nextItem = i->nextItem;
			if (i->previousItem!=NULL)
			i->nextItem->previousItem = i->previousItem;
		}
		
		return i;
	}
	/**
	*@brief dsa
	*/
	void reverse(){
		ItemType* current=m_end;
		ItemType* temp;
		while (current != NULL)
		{
			
			temp = current->nextItem;
			current->nextItem = current->previousItem;
			current->previousItem = temp;
			current = current->nextItem;
		}
		temp = m_begin;
		m_begin = m_end;
		m_end = temp;
	}
	
	
	/**
	*@brief
	*@param first sa
	*@param second dsa
	*/
	void swap(ItemType* first, ItemType* second){
		if (first == NULL || second == NULL)
			return;
		if (first == second)
			return;
		if (m_begin == first)
			m_begin = second;
		else{
			if (m_begin == second)
				m_begin = first;
		}
		if (m_end == first)
			m_end = second;
		else{
			if (m_end == second)
				m_end = first;
		}

		ItemType* temp = second->nextItem;
		second->nextItem = first->nextItem;
		if (second->nextItem != NULL)
			second->nextItem->previousItem = second;
		first->nextItem = temp;
		if (first->nextItem != NULL)
			first->nextItem->previousItem = first;
		temp = second->previousItem;
		second->previousItem = first->previousItem;
		if (second->previousItem != NULL)
			second->previousItem->nextItem = second;

		first->previousItem =temp;
		if (first->previousItem != NULL)
			first->previousItem->nextItem = first;
		
		
		
		
	}
	/**
	*@brief
	*@param begin1 das
	*@param end1 dsa
	*@param begin2 das
	*@param end2 das
	*/ 
	void swap(ItemType* begin1, ItemType* end1, ItemType* begin2, ItemType* end2){
		swap(begin1, begin2);
		swap(end1, end2);
		
	}
	/**
	*@brief da
	*@param out
	*@param l
	*/
	template <typename R> friend std::ostream& operator<<(std::ostream& out, const List<R>& l);
private:
	/** 
	*@brief das 
	*/
	ItemType *m_begin;
	/**
	*@brief das
	*/
	ItemType *m_end;

	
};
/**
*@brief da
*@param out
*@param l
*/
template <typename R> std::ostream& operator<<(std::ostream& out, const List<R>& l){ 
	if (out.good()){
		
		out << "{ ";
		ListItem<R>* temp = l.m_begin;
		if (temp == NULL){
			out << "}";
			return out;
		}
		if (temp != NULL){
			out << temp->getValue();
			temp = temp->getNext();
		}
		while (temp != NULL){
			
			out <<", " <<temp->getValue();
			temp = temp->getNext();
		};
		
		out << " }";
	}
	return out; 
}
#endif


