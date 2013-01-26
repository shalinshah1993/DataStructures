#include<iostream.h>

using namespace std;

//Make structture to make a node and save info
struct Node{
	
	int key ;
	struct Node *nextNode ;
}*head , *tail , *temp ;

class LinkedList{

	public:

		LinkedList(){
			head = NULL ;
			tail = NULL ;
			temp = head ;
		};		

//Inserts new node at the end of the List 
		void insert(int data){
			node = new Node(); 	//Allocates space for struct at which node points
			node->key = data ;
			temp = head ;
			node->nextNode = NULL ; 

			if(temp == NULL){
				temp = node;
				head = node;
			}else{
				while(temp->nextNode != NULL){
					temp = temp->nextNode;	//Reaches at the end of List
				}
				temp->nextNode = node ;
				tail = node ;
				
			}
		};
	
		void display(){
			temp = head;
			cout<<"The contents of list are:";
			while(temp != tail){
				cout<< temp->key<<" ";
				temp = temp->nextNode;
			}
			cout<< temp->key <<endl;
		};
		
		int getHead(){
			return head->key ;
		};

		int getTail(){
			return tail->key ;
		};

		void del(int data){
	//		Node temp  = new Node();
			temp = head ;
			temp1 = temp->nextNode;
		
			cout<<"chaale che"<<endl;		
			
			if(temp == NULL){
				cout<<"List is Empty";
			}
			else if(head->key == data ){
				head = head->nextNode;
			}			
			else{
				while(temp1->key != data){
					temp = temp1 ;
					temp1 = temp1->nextNode ;
				}
				temp->nextNode = temp1->nextNode ;
				temp1->nextNode = NULL ;
			}	//delete temp ;
		};

		void search(int data){
			int i = 0;
			temp = head;
			
			if(temp == NULL)
				cout << "No element in list";   
			else{
				while(temp->key != data && temp->nextNode != NULL){
					temp = temp->nextNode;
					i++;
				}
			}

			if(i == 0)
				cout << "No such element exists"<<endl;
			else
				cout << "The position is :" << i+1 << endl;
		};
		
		void reverse(){
			pre = head;
			tail = head;
			cur = head->nextNode ;
			if(cur != NULL){
				next = cur->nextNode ;
				pre->nextNode = NULL ;
			}
			while(cur != NULL){
				next = cur->nextNode ;
				cur->nextNode = pre ;
				pre = cur ;
				cur = next ;
			}
		head = pre ;
		};

	private:
		Node *node , *temp1 , *pre , *next , *cur;
};

int main(){
	
	LinkedList l ;
	int num , num1 , num2 ,num3;

	while(num != 6){
		cout<<"Enter the operation u wanna perform:\n1)Insert\n2)Search\n3)Display\n4)delete\n5)Reverse\n6)Exit\n";
		cin >> num ;
		
		switch(num){
			case 1:
			cout<<"Enter the num u wanna insert:";
			cin >> num1 ;
			l.insert(num1);
			break;

			case 2:
			cout<<"Enter the num u wanna insert:";
			cin >> num2 ;
			l.search(num2);
			break;

			case 3:
			l.display();
			break;

			case 4:
			cout<<"Enter the num u wanna delete:";
			cin >> num3 ;			
			l.del(num3);
			break;

			case 5:
			l.reverse();
			l.display();
			break;
		
			case 6:
			return 0;
			break;
		}		
	}

	return 0;
}