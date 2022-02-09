#include "linked_list.h"

int main(){
	
	linked_list bluesky;
	Node *temp;
	bool done = false;
	
	do{
		char choice = bluesky.menu();
		switch(choice){
			case '1':
				temp = new Node;
				cout<<"\nEnter your first name: ";
				cin>>temp->first_name;
				cout<<"\nEnter your last name: ";
				cin>>temp->last_name;
				cout<<"\nEnter your ID: ";
				cin>>temp->id;
				bluesky.insert(temp);
				break;
			case '2':
			case '3':
			case '4':
			case '5': bluesky.print_list(); break;
			case '6': cout<<"\nTHANK YOU FOR USING THE SYSTEM\n";
				done = true;
		}
	}while(!done);

	return 0;
}
