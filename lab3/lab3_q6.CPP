#include<iostream.h>

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

		void display(){
			temp = 1;
			cout<<"\nThe elements are:";
			while(temp != size+1){
				cout<<Array[temp]<<"\t";
				temp++;
			}
			cout<<endl;
		};
		void alter(int index,int value)
		{
			 cout<<"The key value of the node originally was : "<<Array[index];
			 Array[index]=value;
			 j=index;
			 if(Array[j]<Array[j/2])
			 {
			     while(Array[j] < Array[j/2] && j>1){
					temp = Array[j];
					Array[j] = Array[j/2];
					Array[j/2] = temp;

					j = j/2;
			     }
			 }
			 else
			 {
			     i=1;
			     k=j;
			     while(i==1)
			     {
			       if(2*k+1<=size)
			       {
				      if(Array[2*k]>Array[2*k+1])
					       small=2*k+1;
				      else
					       small=2*k;
			       }
				else if(2*k<=size)
				       small=2*k;
				if(Array[small]<Array[k])
				{
					temp = Array[small];
					Array[small] = Array[k];
					Array[k] = temp;

					k =small;

				}
				else
				    i=0;
			     }
			 }


		}

	private:
		int size,i,temp,k,j,small;
		int Array[100];
};

int main(){

	Heap h;
	int num,a,i,temp;

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
	cout<<"Enter the index of the node which u want to alter : ";
	cin>>i;
	cout<<"Enter new key value : ";
	cin>>a;
	h.alter(i,a);
	h.display();
	return 0;
}
