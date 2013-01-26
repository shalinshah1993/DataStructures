#include<iostream>

using namespace std;

struct Tree{
		int data ;
		struct Tree *right , *left , *parent ;
}*root , *child1 , *child2 , *child3 , *child4 , *child5 , *child6 ;

class BST{
	public:
		BST(){  
		        //temp = root ;
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
			
			//Defining the parent of each node
			root->parent = NULL ;
			child1->parent = root ;
			child2->parent = root ;
			child3->parent = child1 ;
			child4->parent = child1 ;
			child5->parent = child2 ;
			child6->parent = child2 ;

			//Leaf has no children
			child3->left = NULL ;
			child3->right = NULL ;
			child4->left = NULL ;
			child4->right = NULL ;
			child5->left = NULL ;
			child5->right = NULL ;
			child6->left = NULL ;
			child6->right = NULL ;
 		//	temp = root ;
		};

		void inorder(Tree* node){
			if(node == NULL)
				return;
	
			inorder(node->left);
			cout << node->data << "\t";
			inorder(node->right); 
		};

		struct Tree* insert(int x,Tree *node){
			if(node == NULL){
				node = new Tree();
				node->data = x;
				node->left = NULL;
				node->right = NULL;
				return node;
			}

			if(x <= node->data){
				node1 = insert(x,node->left);
				node1->parent = node;
				node->left = node1;
			}else{
				node1 = insert(x,node->right);
				node1->parent = node;
				node->right = node1;
			}
		
			return node;
		};

		struct Tree* min(struct Tree* temp1){
			while(temp1->left != NULL){
				temp1 = temp1->left;
			}
			return (temp1);
		};

		struct Tree* max(struct Tree* temp2){
                        while(temp2->right != NULL){
                                temp2 = temp2->right;
                        }
                        return (temp2);
                };

		struct Tree* search(int key,Tree *node){
			Tree *abc;
			if(node == NULL)
				return NULL;			
			
			if(node->data == key)
				return node;
			if(key < node->data ){
				abc =  search(key , node->left);
			}else if(key > node->data){
				abc =  search(key , node->right);
			}

			return abc;
		};	

		struct Tree* successor(int n){
			node =  search(n,root);
			if(node != NULL){
				if(n == (max(root))->data)
					return temp;
				if(node->right != NULL){
					temp = node->right;
					while(temp->left != NULL)
						temp = temp->left;
					return temp;
				}else{
					temp = node->parent;
					while(temp->right == node){
						temp = temp->parent;
					}
					return temp;
				}
			}else{
				cout << "No such element exist" << endl;
				return NULL;
			}
		};

		struct Tree* predecessor(int n){
			node = search(n,root);
			if(node != NULL){
				if(n == (min(root))->data)
					return temp;
				if(node->left != NULL){
					temp = node->left;
					while(temp->right != NULL){
						temp = temp->right;
					}
					return temp;
				}else{
					temp = node->parent;
					while(temp->left == node){
						temp = temp->parent;
					}
					return temp;
				}
			}else
				return NULL;
		};

		int size(Tree *node){
				if(node == NULL)
					return 0;

				if(node->left != NULL || node->right != NULL)
					return (1 + size(node->left) + size(node->right));
				
				return 1;
		};	

		int depth(Tree *node){
			if(node == NULL)
				return 0;

			if(node->parent != NULL)
				return 1+depth(node->parent);

			return 0;
		};

		int height(Tree *node){
			if(node == NULL)
				return 0;
		
			lheight = height(node->left);
			rheight = height(node->right);

			if(lheight > rheight)
				return (1 + lheight);
			else 
				return (1 + rheight); 
		};

 		int del(int x){
			temp3 = search(x,root);
			if(temp3 != NULL){
				//No roots case
				if(temp3->left == NULL && temp3->right == NULL){
					if(temp3->parent != NULL){
						temp4 = temp3->parent;
						if(temp4->left != NULL){
							if(temp4->left->data == temp3->data){
								temp4->left = NULL;
								//delete temp3;
							}
						}
						if(temp4->right != NULL){
							if(temp4->right->data == temp3->data){
								temp4->right = NULL;
								//delete temp3;
							}
						}
					}else{
						temp3 = NULL;
					}
					return 1;
				}
				//One root Case
				if((temp3->left != NULL && temp3->right == NULL) || (temp3->left == NULL && temp3->right != NULL)){
					if(temp3->left != NULL){
						temp3->data = temp3->left->data;
						temp3->left = NULL;
					}
					else if(temp3->right != NULL){
						temp3->data = temp3->right->data;
						temp3->right = NULL;
					}
				return 1;	
				}
				//Two root Case										
				if(temp3->left != NULL && temp3->right != NULL){
					temp4 = successor(temp3->data);
					if(temp4->right != NULL){
						while(temp4->right != NULL){				//This is an exception where there is right node of successor the case for which 
							temp4 = successor(temp4->data);			//we need to recursively go till the last successor for which there is no right node
						}							//and 2 pointers are req for doing this things
						temp5 = temp4->parent;
						temp6 = predecessor(temp4->data);
						temp6->data = temp4->data;						
						if(temp5->left != NULL){
							if(temp5->left->data == temp4->data)
								temp5->left = NULL;
						}
						if(temp5->right != NULL){
							if(temp5->right->data == temp4->data)
								temp5->right = NULL;
						}	
	
						while(temp6->data != temp3->data){
							temp7 = temp6;
							temp6 = predecessor(temp6->data);
							temp6->data = temp7->data;
						}
					}
					if(temp4->right == NULL){
						temp3->data = temp4->data;
						temp5 = temp4->parent;
						if(temp5->left != NULL){
							if(temp5->left->data == temp4->data)
								temp5->left = NULL;
						}
						if(temp5->right != NULL){
							if(temp5->right->data == temp4->data)
								temp5->right = NULL;
						}		
					}
					return 1;
				}
			}else
				return 0;
		};

	private:
		Tree *temp , *temp1 , *temp2 , *temp3 , *temp4 , *node , *node1 , *temp5 , *temp6 , *temp7;
		int lheight , rheight ;

};

int main(){
	
	int temp , temp1 ;
	BST t;
	Tree *tempx,*tempy,*tempz;

	//cout << "The no of Nodes are : "<< t.size(root);
	cout << "The tree is : \n";
	t.inorder(root); 
	while(temp != 0){
		cout << "\n1)MINIMUM\n2)MAXIMUM\n3)HEIGHT\n4)DEPTH\n5)SEARCH\n6)PREDECESSOR\n7)SUCCESSOR\n8)INSERT\n9)DELETE\nEnter the operation you wanna perform :";
		cin >> temp;
		switch(temp){
				
			case 1:
				tempy = t.min(root);
				cout << "The minimum node is : " << tempy->data << endl;
				break;

			case 2:
				tempx = t.max(root);
				cout << "\nThe maximum node is : " << tempx->data << endl;
				break;

			case 3:
				cout << "\nEnter the node for which you wanna height : ";
				cin >> temp1;
				cout << "The height of the node is : " << t.height(t.search(temp1,root));
				break;
			
			case 4:
				cout << "\nEnter the node for which you wanna depth : ";
				cin >> temp1;
				cout << "The depth of the node is : " << t.depth(t.search(temp1,root));
				break;
			
			case 5:
				cout << "Enter the node you wanna search : ";
				cin >> temp1;
				tempz = t.search(temp1,root);
				if(tempz != NULL)
					cout << "Node data : "<<tempz->data<<endl;
				else
					cout << "it is NULLLLLLLL" << endl;
				break;

			case 6:
				cout << "Enter the node for which you wanna predecessor : ";
			        cin >> temp1;
				tempy = t.predecessor(temp1);
				if(tempy != NULL)
		   	        	cout << "The Predecessor of " << temp1 <<  " is : " << tempy->data << endl;
				else
					cout << "The Predecessor does not exist"<<endl;
				break;

			case 7:
				cout << "Enter the node for which you wanna successor : ";
				cin >> temp1;
				tempx = t.successor(temp1);
				if(tempx != NULL)
					cout << "The Successor of " << temp1 <<  " is : " << tempx->data << endl;
				else
					cout << "The Successor does not exist"<<endl;
				break;

			case 8:
				cout << "Enter the node you wanna isnert : ";
				cin >> temp1;
				t.insert(temp1,root);
				cout << "The new Tree is : " << endl;
				t.inorder(root);
				break;

			case 9:
				cout << "Enter the node you wanna delete : ";
				cin >> temp1;
				int x = t.del(temp1);
				if(x != 0){
					cout << "The new Tree : "<<endl;
					t.inorder(root);
					cout << (root->left)->data;
				}else
					cout << "No such Node exist"<<endl;
				break;		
		}
	}
	return 0;
}