#pragma once
template <typename T>
struct Node
{
	T value;
	Node<T>* next;
	Node<T>* prev;
};

template <typename T>
class ListDouble
{
	Node<T>* head;
	Node<T>* tail;

	int size;
};

