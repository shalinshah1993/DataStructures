#include<iostream.h>
#include<math.h>

class Heap{

	public:
		Heap(){
			i = 0;
		};

		void insert(int data){
			Array[++i] = data;
			j = i;
			while(Array[j] < Array[j/2] && j>1){
					temp = Array[j];
					Array[j] = Array[j/2];
					Array[j/2] = temp;

					j = j/2;
			}
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

		void display(){
			temp = 1;
			cout<<"The elements are:";
			while(temp != size+1){
				cout<<Array[temp]<<"\t";
				temp++;
			}
		};

	private:
		int size,i,temp,k,j;
		int Array[100];
};

int main(){

	Heap h;
	int num,a,temp;

	cout<<"Enter the num of element you want in heap:";
	cin >> num;
	h.setSize(num);
	temp = num;
	while(num != 0){
		cout << "Enter the element "<<temp-num+1<<" :";
		cin >> a;
		h.insert(a);
		num--;
	}

	h.display();

	cout<<"\nEnter the element for which u wanna find parent left right child:";
	cin >>num;
	cout<<"Parent:"<<h.getParent(num)<<endl;
	cout<<"Left Child:"<<h.getLeftChild(num)<<endl;
	cout<<"Right Child:"<<h.getRightChild(num)<<endl;

	return 0;
}