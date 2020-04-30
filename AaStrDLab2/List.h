#pragma once

#include<iostream>

using namespace std;

template<typename T>

class List

{

private:

	class Node {

	public:

		Node(T data = T(), Node* Next = nullptr) {

			this->data = data;

			this->Next = Next;

		}

		Node* Next;

		T data;

	};

	Node* head;

	Node* tail;

	int Size;

	void swap(T& a, T& b) {

		T c = a;

		a = b;

		b = c;

	}

	void share(T* mas, int first, int last)

	{

		T mid;

		int f = first, l = last;

		mid = mas[(f + l) / 2];

		do

		{

			while (mas[f] < mid) f++;

			while (mas[l] > mid) l--;

			if (f <= l)

			{

				swap(mas[f], mas[l]);

				f++;

				l--;

			}

		} while (f < l);

		if (first < l) share(mas, first, l);

		if (f < last) share(mas, f, last);

	}

public:

	void push_front(T obj) {

		if (head != nullptr) {

			Node* current = new Node;

			current->data = obj;

			current->Next = this->head;

			this->head = current;

		}

		else {

			this->head = new Node(obj);

		}

		this->Size++;

	}

	void push_back(T obj) {

		if (head != nullptr) {

			this->tail->Next = new Node(obj);

			tail = tail->Next;

		}

		else {

			this->head = new Node(obj);

			this->tail = this->head;

		}

		Size++;

	}

	void pop_front() {

		if (head != nullptr) {

			Node* current = head;

			head = head->Next;

			delete current;

			Size--;

		}

		else throw std::out_of_range("out_of_range");

	}

	void pop_back() {

		if (head != nullptr) {

			Node* current = head;

			while (current->Next != tail)

				current = current->Next;

			delete tail;

			tail = current;

			tail->Next = nullptr;

			Size--;

		}

		else throw std::out_of_range("out_of_range");

	}

	void insert(T obj, size_t k) {

		if (k >= size_t(0) && size_t(this->Size) > k) {

			if (this->head != nullptr) {

				if (k == size_t(0))

					this->push_front(obj);

				else

					if (k == this->Size - 1)

						this->push_back(obj);

					else

					{

						Node* current = new Node;

						Node* current1 = head;

						for (size_t i = 0; i < k - 1; i++) {

							current1 = current1->Next;

						}

						current->data = obj;

						current->Next = current1->Next;

						current1->Next = current;

						Size++;

					}

			}

		}

		else {

			throw std::out_of_range("out_of_range");

		}

	}

	T at(size_t k) {

		if (this->head != nullptr && k >= size_t(0) && k <= size_t(this->Size - 1)) {

			if (k == size_t(0))

				return this->head->data;

			else

				if (k == this->Size - 1)

					return this->tail->data;

				else

				{

					Node* current = head;

					for (size_t i = 0; i < k; i++) {

						current = current->Next;

					}

					return current->data;

				}

		}

		else {

			throw std::out_of_range("out_of_range");

		}

	}

	void remove(int k) {

		if (head != nullptr && k >= 0 && k <= Size - 1) {

			if (k == 0) this->pop_front();

			else

				if (k == this->Size - 1) this->pop_back();

				else

					if (k != size_t(0)) {

						Node* current = head;

						for (size_t i = 0; i < k - 1; i++) {

							current = current->Next;

						}



						Node* current1 = current->Next;

						current->Next = current->Next->Next;

						delete current1;

						Size--;

					}

		}

		else {

			throw std::out_of_range("out_of_range");

		}

	}

	size_t get_size() {

		return Size;

	}

	void print_to_console() {

		if (this->head != nullptr) {

			Node* current = head;

			for (int i = 0; i < Size; i++) {

				cout << current->data << ' ';

				current = current->Next;

			}

		}

	}

	void set(size_t k, T obj) {

		if (this->head != nullptr && this->get_size() >= k && k >= 0) {

			Node* current = head;

			for (int i = 0; i < k; i++) {

				current = current->Next;

			}

			current->data = obj;

		}

		else {

			throw std::out_of_range("out_of_range");

		}

	}

	bool isEmpty() {

		return (bool)(head);

	}

	void sort() {

		T* array = new T[this->Size];

		Node* cur = head;

		int i = 0;

		while (cur != nullptr) {

			array[i] = cur->data;

			cur = cur->Next;

			i++;

		}

		share(array, 0, this->Size - 1);

		cur = head;

		i = 0;

		while (cur != nullptr) {

			cur->data = array[i];

			cur = cur->Next;

			i++;

		}

	}

	void clear() {

		if (head != nullptr) {

			Node* current = head;

			while (head != nullptr) {

				current = current->Next;

				delete head;

				head = current;

			}

			Size = 0;

		}

	}

	List(Node* head = nullptr, Node* tail = nullptr, int Size = 0) :head(head), tail(tail), Size(Size) {}

	~List() {

		if (head != nullptr) {

			this->clear();

		}

	};

};
