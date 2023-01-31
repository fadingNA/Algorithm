//
// Created by Nonthachai Plodthong on 5/12/2022 AD.
//

#ifndef MULTIINHERITANCE_PUSH_BACK_H
#define MULTIINHERITANCE_PUSH_BACK_H

#include <iostream>
#include "Title.h"
#include "Debug.h"


namespace sdds {
	int main_vehicle();

	int main_debug();

	int main_array();

	template<typename T>
	class List {
		struct Node {
			T data{};
			Node *next{}; // store address of next element
			Node *previous{}; // store address of previous element;
			Node *left{};
			Node *right{};
		};

		struct iteration {
			// create some aliases for types used internally by algorithms.
			using iterator_category = std::forward_iterator_tag;
			using differnt_type = std::ptrdiff_t;
			using value_type = T;
			using pointer = T *;
			using reference = T &;
			Node *current{};

			bool operator!=(const iteration &it) const { // comparison yes or no BOOL
				return current != it.current;
			}

			bool operator==(const iteration &it) const { // query should mark const prevent any change
				return current == it.current;
			}

			iteration &operator++() {
				if (current != nullptr)
					current = current->next;
				return *this;
			}

			T &operator*() {
				return current->data;
			}
		};

		//size_t m_cnt;
		Node *head{}; // first element of the list
		Node *tail{};

		// last element of the list
	public:
		//TODO add rules of 5
		List() = default;

		List<T> &operator=(const List<T> &object) {
			//self assestment
			if (this != &object) {
				Node *tmp = head; // <-
				//delete self
				while (head) {
					tmp = head->next;
					delete head;
					head = tmp;
				}
				//shallow copy
				tmp = object.head;
				while (tmp != nullptr) {
					this->push_back(tmp->data);
					tmp = tmp->next; // <- re-use tmp
				}
			}
			return *this;
		}

		List<T> &operator=(List<T> &&move) {
			//self assestment
			if (this != &move) {
				Node *tmp = head;
				while (head) {
					tmp = head->next;
					delete head;
					head = tmp;
					//head++;
				}
				head = nullptr;
				tail = nullptr;
				tmp = move.head;
				while (tmp) {
					this->push_back(tmp->data);
					tmp = tmp->next;
					//head++;
				}
				move->head = nullptr;
				move->tail = nullptr;
			}
			return *this;
		}

		List<T>(List<T> &&movel) {
			*this = std::move(movel);
		}

		List<T>(const List<T> &l) {
			*this = l;
		}

		~List<T>() {
			Node *tmp = head;
			while (head) {
				tmp = head->next;
				delete head;
				head = tmp;
				// we keep doing that until head is null and loop will stop.
				// head become nullptr itself
				//head++;
			}
		}

		// add data at the end;
		void push_back(T datas) { // recevied data
			Node *tmp = new Node();
			/*-> (pointer)*/
			tmp->data = datas; // set data taken;
			tmp->next = nullptr; // set next of the list to null
			tmp->previous = tail; // set previous = last element of the list;

			if (head == nullptr) {
				this->head = tmp;  /*list << empty  * add [head =tmp] [tail=tmp]*/
			} else {
				this->tail->next = tmp;
			}
			this->tail = tmp;
		}

		void pop_front() {
			Node *tmp = new Node();
			tmp->next = nullptr;
			tmp->previous = tail;
			if (head != nullptr) {
				this->head = this->head->next;
			}
		}

		void pop_back() {
			Node *tmp = new Node();
			tmp->next = nullptr;
			tmp->previous = tail;
			if (tail != nullptr) {
				this->tail = this->tail->previous;
			}
		}

		size_t size() {
			size_t i = 0;
			Node *tmp = head;
			while (tmp != nullptr) {
				tmp = tmp->next;
				i++;
			}
			return i;
		}


		iteration begin() {
			return iteration{head};
		}

		iteration end() {
			if (tail->next != nullptr) {
				return iteration{tail->next};
			}
			return iteration{};
		}

		List<T> &sort() {
			Node *tmp = head;
			while (tmp) {
				tmp = head->next;
				if (tmp > head) {
					this->push_back(tmp);
					tmp->next;
				}
			}
			return *tmp;
		}

		bool operator!=(const List<T> &ok) {
			return head != ok.head;
		}

		std::ostream &operator<<(std::ostream &os) {
			os << " | " << head << " | " << '\n';
			head->next;
			os << " | " << tail << " | " << '\n';
			return os;
		}
	};

}
#endif //MULTIINHERITANCE_PUSH_BACK_H
