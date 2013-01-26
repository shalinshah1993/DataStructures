#include<iostream>

using namespace std;

struct TreapNode{
	int h_val,t_val;
}tp[20],final[20];

struct TreeNode{
	struct TreeNode *left , *right;
	struct TreapNode key;
}*root;

class Treap{
	public:
		Treap(){
			i = 0;
			size = 0;
		};
		
		void insert(int x,int y){
			++i;
			tp[i].h_val = x;
			tp[i].t_val = y;
		};		

		void setSize(int s){
			size = s;
			tp[0].h_val = s;
			tp[0].t_val = s ;
		};

		void heapBuild_downward(){
			k = size/2;
			while(k != 0){				///Ignore leaf nodes as they would be already sorted while checking the
				heapify_downward(k);		///internal nodes who are there parents
				k--;				///Go unless we donot reach the root node so 
			}
		};

		void heapify_downward(int sx){			///This methood will make each and every sub tree a haep
			if(2*sx <= size){		///First chech right child if exist later left and then replace
				if((2*sx+1) <= size){
					if(tp[2*sx].h_val <= tp[2*sx+1].h_val){
						if(tp[2*sx].h_val <= tp[sx].h_val){
							temp = tp[sx];	//Swapping left child if smaller
							tp[sx] = tp[2*sx];
							tp[2*sx] = temp;
							heapify_downward(2*sx);
						}
					}else{
						if(tp[2*sx+1].h_val <= tp[sx].h_val){
							temp = tp[sx];	//Swapping right child if smaller
	                                                tp[sx] = tp[2*sx+1];
        	                                        tp[2*sx+1] = temp;
                	                                heapify_downward(2*sx+1);
						}
					}
				}else{
					if(tp[2*sx].h_val <= tp[sx].h_val){
						temp = tp[sx];		//Swapping left child if less and right child 
                                                tp[sx] = tp[2*sx];	//doesnot exist
                                                tp[2*sx] = temp;
                                                heapify_downward(2*sx);
					}
				}				
			}
		};

		void BST(){
			int temp3 = 1;
			root = new TreeNode();
			root->key = tp[1];
			root->left = NULL;
			root->right = NULL;
			while(temp3 <= size){
					insertBST(tp[temp3],root);
					temp3++;
			}
			displayTree(root);
		};		
		
		struct TreeNode* insertBST(TreapNode value,TreeNode *node){
			if(node == NULL){
				node = new TreeNode();
				node->left = NULL;
				node->right = NULL;
				node->key = value;
				return node;
			}
			temp4 = node->key;
			//cout<<"inserting" <<value.t_val<<endl; 
			if(value.t_val < temp4.t_val){
				node->left = insertBST(value,node->left);
				temp5 = node->left;
			}else{
				node->right = insertBST(value,node->right);
				temp5 = node->right;
			}
//			return node;
		};

		void display(){
			temp1 = 1;
			cout<<"The elements are:";
			while(temp1 != size+1){
				cout<<"("<<tp[temp1].h_val<<","<<tp[temp1].t_val<<")"<<"\t";
				temp1++;
			}
			cout<<"\n";
		};	

		void displayTree(TreeNode *node){
			if(node == NULL)
				return ;

			cout << "("<<node->key.h_val << "," << node->key.t_val<<") ";
			displayTree(node->left);
			//cout<<"lya"<<node->key.t_val;
			displayTree(node->right);
			
		};		

	private:
		int i ,size , temp1 , k ;
		TreapNode temp ,temp4;
		TreeNode *node1,*temp5;
};

int main(){
	
	int temp,num,hval,tval;
	Treap t;

	cout<<"Enter the num of nodes for treap:";
	cin >> temp;
	num = temp;
	t.setSize(num);
	while(temp != 0){
		cout<< "Enter the Heap value "<< num - temp +1<<" :";
		cin >> hval;
		cout<< "Enter the Tree value "<< num - temp +1<<" :";
		cin >> tval;
		t.insert(hval,tval);
		temp--; 
	}
	t.display();
	t.heapBuild_downward();
	t.display();
	t.BST();
//	t.displayTree(root);
	
}
