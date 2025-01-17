#ifndef STACK_H
#define STACK_H

#include "Node.h"

template <typename T>

class Stack
{
public:
	Stack();
	~Stack();

public:
	bool isEmpty() const;
	void push(T);
	T pop();
	T peek() const;

private:
	Stack(const Stack<T> &);
	Stack<T>& operator=(const Stack<T> &);

private:
	Node<T>* top;
};

template <typename T>
Stack<T>::Stack() : top(NULL)
{ }

template <typename T>
Stack<T>::~Stack()
{
	while (!isEmpty())
		pop();
}

template <typename T>
bool Stack<T>::isEmpty() const
{
	return !top;
}

template <typename T>
void Stack<T>::push(T element)
{
	Node<T>* replacement = new Node<T>(element);
	replacement->setNext(top);
	top = replacement;
}

template <typename T>
T Stack<T>::peek() const
{
	if (isEmpty())
		throw std::exception("Stack is empty");

	return top->getData();
}

template <typename T>
T Stack<T>::pop()
{
	if (isEmpty())
		throw std::exception("Stack is empty");

	T data = top->getData();
	Node<T>* copy = const_cast<Node<T>*> (top->getNext());

	delete top;
	top = copy;

	return data;
}

#endif // STACK_H
