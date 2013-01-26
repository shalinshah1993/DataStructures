#include<iostream>

using namespace std;

class Stack{

	public:
		Stack(){
			//size = s ;
			i = -1 ;	
		};

       		void push(int x){
			Array[++i] = x ;
		};

		void pop(){
			//Array[i] = null;
			--i;
		};		 
		
		int total(){
			return i; 
		};

		void display(){
			for(k = 0 ; k <= i ; k++)
				cout << Array[k]<<" ";
			k = 0 ; 
		};

		int isEmpty(){
			if(i == -1)
				return 1;
			else 
				return 0;
		};
			
	private:
		int Array[10];
		int i, k;
};

int main(){

	int j  , x , num;	
	Stack s;

	if(s.isEmpty() == 1)
		cout << "Stack is Empty"<<endl;
	else if(s.isEmpty() == 0)
		cout << "Stack is not Empty"<<endl;  
	
	while(j != 3){	
	
	cout<<"Enter the operation you wannaa perform!!\n1)Push\n2)Pop\n3)Exit\n4)Display"<<endl;
	cin >> j ;
	

		switch(j){
			case 1:
			cout << "Enter the num you wanna add to stack : ";
			cin >> num ;
			s.push(num);
			cout<<"No of Elements in Stack are " << s.total() + 1 << endl;
			break;

			case 2:
			s.pop();
			cout<<"No of Elements in Stack are " << s.total() + 1 << endl ;
			break;

			case 3:
			return 0;
			break;	

			case 4:
			s.display();
			break;
			
			default:
			cout << "You entered an invalid choice !!" << endl;
			break;
		}	
	}
	return 0;
}