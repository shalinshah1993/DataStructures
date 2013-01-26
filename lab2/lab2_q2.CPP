#include<iostream.h>

////////////LinkList/////////////////////////////////////

struct Tree{
		int data ;
		struct Tree *right , *left;
}*root , *child1 , *child2 , *child3 , *child4 , *child5 , *child6 ;

struct Node{				//////////////Node of a linked list storing a node
	
	struct Tree key ;
	struct Node *nextNode ;
}*temp ;

class LinkedList{

	public:
		LinkedList(){
			
			head = NULL ;
			tail = NULL ;
			temp = head ;
			//First assign space	
			root = new Tree();
			child1 = new Tree();
			child2 = new Tree();
			child3 = new Tree();
			child4 = new Tree();
			child5 = new Tree();
			child6 = new Tree();

			//Asigning the data as Binary Tree
			root->data = 4;			//	 4
			child1->data = 2 ;		//   2	     6
			child2->data = 6 ;		//1	3 5 	7
			child3->data = 1 ;		//The original BST
			child4->data = 3 ;
			child5->data = 5 ;
			child6->data = 7 ;			

			//Making the Tree
			root->left = child1 ;
			root->right = child2 ; 
			child1->left = child3 ;
			child1->right = child4 ;
			child2->left = child5 ;
			child2->right = child6 ;
			
			//Leaf has no children
			child3->left = NULL ;
			child3->right = NULL ;
			child4->left = NULL ;
			child4->right = NULL ;
			child5->left = NULL ;
			child5->right = NULL ;
			child6->left = NULL ;
			child6->right = NULL ;

		};		

//Inserts new node at the end of the List 
		void insert(Tree* data){
			node = new Node(); 	//Allocates space for struct at which node points
			node->key = *data ;
			temp = head ;
			node->nextNode = NULL ; 

			if(temp == NULL){
				temp = node;
				head = node;
				tail = head;
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
			if(head == NULL)
				cout << "Empty"<<endl;
			else{
				while(temp != tail){
					tempx = temp->key;
					cout<<tempx.data <<" ";
					temp = temp->nextNode;
				}
			tempx = temp->key;			
			cout<< tempx.data <<endl;
			}
		};
		
		struct Tree getHead(){
			return head->key ;
		};

		struct Tree getTail(){
			return tail->key ;
		};

		void del_head(){
				head = head->nextNode;			
		};			

		void del_tail(){
			temp = head;
			if(head != tail){
				while(temp->nextNode != tail){
					temp = temp->nextNode;
				}	
				tail = temp;
				tail->nextNode = NULL;
			}else{
			tail = NULL;
			head = NULL;
			//cout<<"The List is Empty";
			}
		};

		int isEmpty(){
			if(head == NULL)
				return 1;
			else 
 				return 0;
		};
	private:
		Node *node , *temp1 , *head , *tail ;
		Tree tempx;
};
//////////////////////////Queue////////////////////////////////////////////
class Queue{	
	public:
		Queue(){

		};
		
		void enqueue(struct Tree *t){
			l.insert(t);			
		};
		
		struct Tree dequeue(){
			Tree t = l.getHead();
			l.del_head();
			return t;
		};

		int isEmpty(){
			if(l.isEmpty() == 1)
				return 1;
			else 
				return 0; 
		};

		void display(){
			l.display();
		};

	private:
		 LinkedList l;
};
////////////////////////Stack////////////////////////////////////////////////////
class Stack{
	public:
		Stack(){

		};
		
		void push(Tree *tm){
			m.insert(tm);
		};
		
		struct Tree pop(){
			Tree tx = m.getTail();
			if(m.isEmpty() != 1)
				m.del_tail();
			else
				cout<<"The Stack is Empty";

			return tx;
		};

		int isEmpty(){
			if(m.isEmpty() == 1)
				return 1;
			else
				return 0;
		};


		void display(){
			m.display();
		};
		
	private:
		LinkedList m;
};
///////////////////////////////////////////Tree made using Structure////////////

class BST{
	public:
		BST(){  };
			
		void print(){
			cout << root->data << "\t" ;
			cout << child1->data << "\t" ;
			cout << child2->data << "\t" ;
			cout << child3->data << "\t" ;
			cout << child4->data << "\t" ;
			cout << child5->data << "\t" ;
			cout << child6->data << endl;
		};

		void preorder_traversal(Tree *Node1){		//print order
			if(Node1 == NULL)			// 1
				return;				//2 3
								//213
			cout << Node1->data << "\t" ;
			preorder_traversal(Node1->left);
			preorder_traversal(Node1->right);
		};

		void inorder_traversal(Tree *Node1){		//print order
			if(Node1 == NULL)			// 1
				return;				//2 3
								//123
			inorder_traversal(Node1->left);
			cout << Node1->data << "\t" ;
			inorder_traversal(Node1->right);
		};

		void postorder_traversal(Tree *Node1){		//print order
			if(Node1 == NULL)			// 1
				return;				//2 3
								//231
			postorder_traversal(Node1->left);
			postorder_traversal(Node1->right);
			cout << Node1->data << "\t" ;
		};

		void level_order_traversal(Tree *Node1){
			temp = new Tree();
			q.enqueue(Node1);
			while(q.isEmpty() != 1){
				Tree tx = q.dequeue();
				cout<<tx.data<<"\t";
				if(tx.left != NULL){
					q.enqueue(tx.left);
				}
				if(tx.right != NULL){
					q.enqueue(tx.right);
				}	
			}	
		};

		void zigzag_traversal(Tree *Node1){
			s1.push(Node1);
			int height = 0;

			while(s1.isEmpty() != 1 || s2.isEmpty() != 1){
				if(s1.isEmpty() == 1)
					height++;
				else if(s2.isEmpty() == 1)
					height++;
				Tree tx;
				if(height%2 == 0){			/////Even rows go from left -> right 
					if(s2.isEmpty() != 1){
						tx = s2.pop();
						cout<<tx.data<<"\t";
						if(tx.left != NULL)
							s1.push(tx.right);
						if(tx.right != NULL)
							s1.push(tx.left);
						final_height = height;
					}
				}else{
					if(s1.isEmpty() != 1){
						tx = s1.pop();
						cout<<tx.data<<"\t";
						if(tx.left != NULL)		//////Odd rows go from right->left
							s2.push(tx.left);
						if(tx.right != NULL)
							s2.push(tx.right);
						final_height = height;				
					}
				}
			}
//			cout<< Height of the tree:"<<final_height<<endl;
		};

	private:
		Stack s1,s2;
		int i ,final_height;
		Queue q;
		struct Tree *Node1 , *temp;
};

int main(){

	BST b ;
	
	cout << "The BST is :"<<endl;
	b.print();
	
	cout<< "Inorder Traversal:"<<endl;
	b.inorder_traversal(root);

	cout<< "\nPreorder Traversal:"<<endl;
	b.preorder_traversal(root);

	cout<< "\nPostorder Traversal:"<<endl;
	b.postorder_traversal(root);

	cout<<"\nLevelorder Traversal : "<<endl;
	b.level_order_traversal(root);	

	cout<<"\nZig-Zag Traversal : "<<endl;
	b.zigzag_traversal(root);	

	return 0;
}