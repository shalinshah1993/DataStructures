
#include<iostream.h>
class Heap{

	public:
		Heap(){
		        Array[0]=0;
                        Array[1]=1;
                         Array[2]=3;
                         Array[3]=5;
                        Array[4]=7;
                         Array[5]=9;
                        Array[6]=11;
                        Array[7]=13;
                         Array[8]=15;
                         Array[9]=17;
                         Array[10]=19;



                        heapsize=10;
		};

	        	void insert(int data){
			Array[heapsize] = data;
			j = heapsize;
			while(Array[j] < Array[j/2] && j>1){
					temp = Array[j];
					Array[j] = Array[j/2];
					Array[j/2] = temp;

					j = j/2;
			}
		};
                void setSize(){
		heapsize=heapsize+1;
		};
                void Display(){
			temp = 1;
//			cout<<"The elements are:";
			while(temp!= heapsize+1){
				cout<<Array[temp]<<"\t";
				temp++;
			}
		};
	private:
		int size,temp,heapsize,j;
		int Array[20];
};

int main()
{
	Heap h;
	int a;
        
        cout<<"Enter the element you want to add:";
        cin>>a;
        cout<<"The original heap was:";
        h.Display();
        cout<<endl;
        cout<<"The heap after inserting the new element is:";
        h.setSize();
        h.insert(a);
        h.Display();
       cout<<endl;


}
