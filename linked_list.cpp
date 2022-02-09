//#include "linked_list.h"

linked_list::linked_list(){
	head = NULL;
	cnt=0;
}

bool linked_list::insert(Node *n){
	if(head==NULL){
		head = n;
		cnt++;
		return true;
	}else{
		n->next = head;
		head = n;
		cnt++;
		return true;
	}
}

linked_list::~linked_list(){
	Node *temp;
	cout<<"\nStart destoying\n";
	while(head!=NULL){
		temp = head;
		head = head->next;
		delete temp;
	}
	cout<<"\nThe List was destoyed\n";
}

void linked_list::print_list(){
	Node *temp = head;
	while(temp != NULL){
		cout<<temp->first_name<<" ";
		cout<<temp->last_name<<" ";
		cout<<temp->id<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

bool linked_list::search(int key){
	Node *temp = head;
	while(temp != NULL){ //list is not empty
		if(temp->id == key){
			cout<<"Found"<<endl;
			return true;
		}else{
			temp = temp->next; // goes to next node
		}
	}
	cout<<"\nNot Found\n";
	return false;
}

int linked_list::size(){
	return cnt;
}

bool linked_list::remove(int key){
	if(head != NULL && head->id == key){
		Node *temp = head;
		head = head->next;
		delete temp;
		return true;
	}else{
		Node *pre, *cur;
		pre = head;
		cur = pre->next;
		while(cur != NULL && cur->id != key){
			pre = cur;
			cur = cur->next;
		}
		if(cur != NULL){
			pre->next = cur->next;
			delete cur;
			cout<<"Removed"<<endl;
			return true;
		}else{
			cout<<"NO SUCH KEY IN THE LIST\n";
			return false;
		}
	}
}

void linked_list::copy_list(Node *another){
	Node *ori_move,*copy_move;
	if(another == NULL){
		cout<<"\nEmpty\n";
	}else{
		head = new Node;
		head->first_name = another->first_name;
		head->last_name = another->last_name;
		head->id = another->id;
		ori_move = another;
		copy_move = head;
		while(ori_move->next != NULL){
			ori_move = ori_move->next;
			copy_move->next = new Node;
			copy_move = copy_move->next;
			copy_move->first_name = ori_move->first_name;
			copy_move->last_name = ori_move->last_name;
			copy_move->id = ori_move->id;
			copy_move->next = NULL;
		}
	}
}

linked_list::linked_list(linked_list *other){
	if((*other).head == NULL){
		this->head = NULL;
		cout<<"\nEMPTY Nothing copied\n";
	}else{
		Node *other_move, *copy_move;
		this->head = new Node;
		head->first_name = other->head->first_name;
		head->last_name = other->head->last_name;
		head->id = other->head->id;
		head->next = NULL;
		other_move = other->head;
		copy_move = this->head;
		while(other_move->next != NULL){
			other_move = other_move->next;
			copy_move->next = new Node;
			copy_move = copy_move->next;
			copy_move->first_name = other_move->first_name;
			copy_move->last_name = other_move->last_name;
			copy_move->id = other_move->id;
			copy_move->next = NULL;
		}
	}
}
char linked_list::menu(){
	char choice;

	cout<<"\t\tMENU\n";
	cout<<"\t 1\tINSERT NODE\n";
	cout<<"\t 2\tREMOVE NODE\n";
	cout<<"\t 3\tSEARCH NODE\n";
	cout<<"\t 4\tMODIFY NODE\n";
	cout<<"\t 5\tPRINT LIST\n";
	cout<<"\t 6\tEXIT\n";
	cout<<"\nENTER your choice: ";
	cin>> choice;

	return choice;
}
