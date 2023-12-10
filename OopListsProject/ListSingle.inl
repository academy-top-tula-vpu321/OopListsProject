#pragma once
#include "ListSingle.h"

template <typename T>
ListSingle<T>::ListSingle() 
	: head{ nullptr }, size{} {}

template<typename T>
inline int ListSingle<T>::Size()
{
	return size;
}

template<typename T>
inline Node<T>* ListSingle<T>::Head()
{
	return head;
}

template<typename T>
inline void ListSingle<T>::PushBack(T value)
{
	Node<T>* newNode = new Node<T>();
	newNode->value = value;
	newNode->next = nullptr;

	if (head)
	{
		Node<T>* last{ head };
		while (last->next)
			last = last->next;

		last->next = newNode;
	}
	else
		head = newNode;
	
	size++;
}

template<typename T>
inline void ListSingle<T>::PushFront(T value)
{
	Node<T>* newNode = new Node<T>();
	newNode->value = value;
	newNode->next = head;

	head = newNode;
	size++;
}

template<typename T>
inline void ListSingle<T>::Insert(int index, T value)
{
	if (index <= 0 || !head)
	{
		PushFront(value);
		return;
	}
	if (index >= size - 1)
	{
		PushBack(value);
		return;
	}

	Node<T>* newNode = new Node<T>();
	newNode->value = value;
	newNode->next = head;

	Node<T>* current = head;
	for (int i{}; i < index - 1; i++)
		current = current->next;

	newNode->next = current->next;
	current->next = newNode;

	size++;
}

template<typename T>
inline void ListSingle<T>::List()
{
	Node<T>* current{ head };
	while (current)
	{
		std::cout << current->value << "\n";
		current = current->next;
	}
}

template<typename T>
inline T ListSingle<T>::PopBack()
{
	if (!head)
		throw 1;

	T value;

	if (size > 1)
	{
		Node<T>* last = head;
		while (last->next->next)
			last = last->next;

		value = last->next->value;
		delete last->next;
		last->next = nullptr;
	}
	else
	{
		value = head->value;
		delete head;
		head = nullptr;
	}

	size--;
	return value;
}

template<typename T>
inline T ListSingle<T>::PopFront()
{
	if (!head)
		throw 1;

	T value{ head->value };
	Node<T>* delNode{ head };

	head = head->next;
	delete delNode;
	size--;

	return value;
}

template<typename T>
inline T ListSingle<T>::Remove(int index)
{
	if (!head)
		throw 1;

	if (index <= 0)
		return PopFront();
	if (index >= size - 1)
		return PopBack();

	Node<T>* current{ head };
	for (int i{}; i < index - 1; i++)
		current = current->next;
	
	Node<T>* delNode{ current->next };
	current->next = current->next->next;

	T value = delNode->value;
	delete delNode;

	return value;
}

template<typename T>
inline ListSingleIterator<T> ListSingle<T>::Iterator()
{
	return ListSingleIterator<T>(this);
}


template<typename T>
inline void ListSingleIterator<T>::SetBegin()
{
	current = container->Head();
}

template<typename T>
inline bool ListSingleIterator<T>::Next()
{
	if (current->next)
	{
		current = current->next;
		return true;
	}

	current = nullptr;
	return false;
}

template<typename T>
inline T ListSingleIterator<T>::Current()
{
	return current->value;
}

template<typename T>
inline bool ListSingleIterator<T>::IsEnd()
{
	return !current;
}
