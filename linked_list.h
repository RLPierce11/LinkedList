#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

struct Node
{
	string first_name, last_name;
	int id;
	Node *next;
};

class linked_list{
	public:
		linked_list();
		~linked_list();
		linked_list(linked_list*);
		bool insert(Node *);
		bool search(int);
		int size();
		bool remove(int);
		void print_list();
		void copy_list(Node *);
		char menu();
	private:
		Node *head;
		int cnt;
};
#include "linked_list.cpp"
#endif
