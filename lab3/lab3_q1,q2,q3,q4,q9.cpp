#include<iostream>
#include<math.h>
#include<cmath>

class Heap{

	public:
		Heap(){
			i = 0;
		};

		void insert(int data){
			Array[++i] = data;
			//j = i;
			/*while(Array[j] < Array[j/2] && j>1){
					temp = Array[j];
					Array[j] = Array[j/2];
					Array[j/2] = temp;

					j = j/2;
			}*/
		};

		void setSize(int s){
			size = s;
			Array[0] = s;
		};

		int getParent(int x){
			k = 1;
			while(Array[k] != x){
				k++;
			}
		k=floor(k/2);
		if(k > 0)
			return Array[k];
		else
			return 0;
		};

		int getLeftChild(int x){
			k = 1;
			while(Array[k] != x){
				k++;
			}
		if(2*k <= size)
			return Array[2*k];
		else
			return 0;
		};


		int getRightChild(int x){
			k = 1;
			while(Array[k] != x){
				k++;
			}
		if(2*k+1 <= size)
			return Array[2*k+1];
		else
			return 0;
		};

		int getHeight(int x){
			i = 1;
			while(x != Array[i] && i <= size){
				i++;
			}
			if(i > size){
				cout<< "\n NO such Element exist";
				return 0;
			}else
				return floor(log2(i));
		};

		void display(){
			temp = 1;
			cout<<"The elements are:";
			while(temp != size+1){
				cout<<Array[temp]<<"\t";
				temp++;
			}
			cout<<"\n";
		};

///////////////This is downward Heap coz going from n/2 to root////////////////////////////
		void heapBuild_downward(){
			k = size/2;
			while(k != 0){			///Ignore leaf nodes as they would be already sorted while checking the
				heapify_downward(k);		///internal nodes who are there parents
				k--;			///Go unless we donot reach the root node so 
			}
		};

		void heapify_downward(int sx){			///This methood will make each and every sub tree a haep
			if(2*sx <= size){		///First chech right child if exist later left and then replace
				if((2*sx+1) <= size){
					if(Array[2*sx] <= Array[2*sx+1]){
						if(Array[2*sx] <= Array[sx]){
							temp = Array[sx];	//Swapping left child if smaller
							Array[sx] = Array[2*sx];
							Array[2*sx] = temp;
							heapify_downward(2*sx);
						}
					}else{
						if(Array[2*sx+1] <= Array[sx]){
							temp = Array[sx];	//Swapping right child if smaller
	                                                Array[sx] = Array[2*sx+1];
        	                                        Array[2*sx+1] = temp;
                	                                heapify_downward(2*sx+1);
						}
					}
				}else{
					if(Array[2*sx] <= Array[sx]){
						temp = Array[sx];		//Swapping left child if less and right child 
                                                Array[sx] = Array[2*sx];	//doesnot exist
                                                Array[2*sx] = temp;
                                                heapify_downward(2*sx);
					}
				}				
			}
		};

////////////////This is upward heap as each node is compared with itz parent going from 1 to n///////////////////////
	void heapBuild_upward(){
		k = 1;
		while(k <= size){
			heapify_upward(k);
			k++;
		}
	};

	void heapify_upward(int x){						//Swap always the child with it parent for < condition and check condition   
		if(2*x <= size){					//like donward heaap but interpret differently ie no parent->child but child 
			if(2*x+1 <= size){				//->parent so in upward go up and in downard go down 
				if(Array[2*x] <= Array[2*x+1]){
					heapify_upward(2*x);
					if(Array[2*x] < Array[x]){
						temp = Array[x];
						Array[x] = Array[2*x];
						Array[2*x] = temp;
					}
				}else{
					heapify_upward(2*x+1);		//Heapify first so ll reach at leaf and then start to cmp with parent 
					if(Array[2*x+1] < Array[x]){
						temp = Array[x];
						Array[x] = Array[2*x+1];
						Array[2*x+1] = temp;
					}
				}
			}else{
					if(Array[2*x] <= Array[x]){
						heapify_upward(2*x+1);		//Child < its parent
						temp = Array[x];		//Swapping left child if less and right child 
                                                Array[x] = Array[2*x];		//doesnot exist
                                                Array[2*x] = temp;
                                                heapify_upward(2*x);
					}
			}
		}
	};

////////////////New heap after removing first elment and repeating the process to sort the haep in reverse order ie max heap//////////////////////
	int remove(){
		//cout<<temp1<<endl;
		temp1 = Array[1];
		Array[1] = Array[size];
		size--;
		//cout<<temp1<<endl;
		heapBuild_downward();
		//cout<<temp1<<endl;
		return temp1; 
	}; 
	
	void sort(){
		j = size;
		k1 = size;
		//cout<< temp1<<"/t";
		while(k1 >= 1){
			temp = remove();	//Removing the last element from root and setting its value to last element reducing 
			Array[k1] = temp;	//size so that element will not be heapified 
			k1-- ;
		}
		size =j;
	};

///////////////Making an alternating heap assuming a complete tree also called min-max heap///////////////////////////////////////////////////
	void altHeap(){
		int ix,temp3,temp4,h,temp5;
		h = getHeight(Array[2]);
		while(pow(2,h+1) < size){						//go till 2^h+1 < size else not coz then garbage will be swapped if goes inside
			if(h%2 != 0){							//odd height levels > descendents always and even < descendents
				int no = pow(2,h);
				for(temp3 = pow(2,h) ; temp3 < pow(2,h+1) ; temp3++){
					if(2*no <= size){
						if(2*no+1 <= size){
							if(Array[2*no] < Array[2*no+1]){
								temp4 = Array[no];
								Array[no] = Array[2*no+1];
								Array[2*no+1] = temp4;
							}else if(Array[2*no] >= Array[2*no+1]){
								temp4 = Array[no];
								Array[no] = Array[2*no];
								Array[2*no] = temp4;		
							}
						}
					}else if(Array[no] < Array[2*no]){
							temp4 = Array[no];
							Array[no] = Array[2*no];
							Array[2*no] = temp4;
					}
					no++;
				}
			}
			h++;
		}
	};


	private:
		int size,i,temp,k1,j,temp1,k;
		int Array[100],Array2[100],Array3[100];
};

int main(){

	Heap h;
	int num,a,temp;

	cout<<"Enter the num of element you want in heap:";
	cin >> num;
	h.setSize(num);
	temp = num;
	for(;num != 0;num--){
		cout << "Enter the element "<<temp-num+1<<" :";
		cin >> a;
		h.insert(a);
	}


	h.display();
	h.heapBuild_downward();	//Arbitary aray is converted to a heap 
	h.display();		//and its displayed
	h.sort();		//Sorting the elements of the heap 
	h.display();		//and displaying them 
	h.remove();
	h.display();
/*
	cout<<"\nEnter the element for which u wanna find parent left right child:";
	cin >>num;
	cout<<"Parent:"<<h.getParent(num)<<endl;
	cout<<"Left Child:"<<h.getLeftChild(num)<<endl;
	cout<<"Right Child:"<<h.getRightChild(num)<<endl;
*/
	h.altHeap();
	h.display();
	
	return 0;
}
