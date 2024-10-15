#include <iostream>
using namespace std;


class Queue {
	struct Node {
		int data;
		Node* next;
		Node* prev;
	};
	Node* head;
	Node* tail;
public:
	Queue() {
		head = nullptr;
		tail = nullptr;
	}
	~Queue() {
		while (head) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}
	void push(int data) {
		Node* temp = new Node;
		temp->data = data;
		temp->next = nullptr;
		temp->prev = tail;
		if (tail) {
			tail->next = temp;
		}
		tail = temp;
		if (!head) {
			head = temp;
		}
	}
	void pop() {
		if (head) {
			Node* temp = head;
			head = head->next;
			if (head) {
				head->prev = nullptr;
			}
			delete temp;
		}
	}
	int front() {
		if (head) {
			return head->data;
		}
		return 0;
	}
	bool empty() {
		return head == nullptr;
	}
};

int main() {
	Queue q;
	q.push(1);
	q.push(2);
	q.push(3);
	while (!q.empty()) {
		cout << q.front() << endl;
		q.pop();
	}
	return 0;
}