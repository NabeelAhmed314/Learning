#include <iostream>
// static

using namespace std;

// Data structures C++; 
//
// Linked List | Heap, Stack
//
//class Person {
//public:
//	int age;
//	std::string name;

//	Person(int age, string name) {
//		this->age = age;
//		this->name = name;
//	}

//	void TellName() {
//		cout << name;
//	}
//};

class Node {
private:
	int data;
	Node* link;

	Node* head;
	Node* curr;
	Node* temp;

public:
	Node() {
		head = NULL;
		curr = NULL;
		temp = NULL;
	};
	void AddNode(int addData) {
		Node* n = new Node();
		n->data = addData;
		n->link = NULL;

		if (head != NULL) {
			curr = head;
			while (curr->link != NULL)
				curr = curr->link;
			curr->link = n;
		}
		else {
			head = n;
		}
	};
	void DeleteNode(int delData) {
		Node* delptr = NULL;
		temp = head;
		curr = head;
		while (curr != NULL && curr->data != delData) {
			temp = curr;
			curr = curr->link;
		}
		if (curr == NULL) {
			cout << delData << " was not in the list\n";
			delete delptr;
		}
		else {
			delptr = curr;
			curr = curr->link;
			temp->link = curr;
			delete delptr;
			cout << delData << " is deleted\n";
		}

	};
	void PrintNode() {
		curr = head;
		if (curr == NULL) {
			cout << "No data to show\n";
		}
		while (curr != NULL) {
			cout << curr->data << endl;
			curr = curr->link;
		}
	};
};

void main()
{
	Node List;
	List.PrintNode();
	List.AddNode(10);
	List.AddNode(11);
	List.AddNode(12);
	List.AddNode(13);
	List.DeleteNode(13);
	List.PrintNode();
	List.DeleteNode(12);
	List.PrintNode();

}

// STACK Allocation at Compile Time
// Limited, Fast, AutoControl, Auto GarbageCollection
// HEAP Allocation at Runtime.
// No Garbage Collection, Slow, Limitless
