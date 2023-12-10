#pragma once
template <typename T>
class ListSingleIterator;

template <typename T>
struct Node
{
	T value;
	Node<T>* next;
};

template <typename T>
class ListSingle
{
	Node<T>* head;
	int size;
public:
	ListSingle();
	~ListSingle() {};

	int Size();
	Node<T>* Head();

	void PushBack(T value);
	void PushFront(T value);
	void Insert(int index, T value);

	void List();

	T PopBack();
	T PopFront();
	T Remove(int index);

	ListSingleIterator<T> Iterator();
};

template <typename T>
class ListSingleIterator
{
	ListSingle<T>* container;
	Node<T>* current;
public:
	ListSingleIterator(ListSingle<T>* container)
		: container{ container }, current{container->Head()} {};
	
	void SetBegin();
	bool Next();
	T Current();

	bool IsEnd();
};

#include "ListSingle.inl"


