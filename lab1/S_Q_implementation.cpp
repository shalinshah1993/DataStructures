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

		 int pop(){
			//Array[i] = null;
			--i;
			return Array[i+1];
		 };		 
		
		 int total(){
			return i+1; 
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
		int i ,k;
};

class Queue{

	private:
		int Array[10];
		int i , j , x , m , k ;

	public:
		Queue(){
			i = 0 ;
			x = -1 ;
			j = 0 ;
			m = i;
			//tail = j;	
		};

		int total(){
			return ( 10 - i + j ) % 10 ;			
		};
		
		void enqueue(int n){
			Array[++x % 10] = n ;
		 	j = (x+1) % 10;
		};

		int dequeue(){
			//Array[i % 10] = NULL;
			i++;
			m = i;
			return Array[i-1];	
		};	

		void display(){
			m = i;
			for(k = i ; k < j ; k++){
				cout << Array[m] << " ";
				++m;
			}
		};	

		int getHead(){
			return i;
		};

		int isEmpty(){
			if(i == j)
				return 1;
			else
				return 0;
		};


		int getTail(){
			return j - 1 ;
		} 	
};

int main(){

	Queue q1 ,q2 ;
	Stack s1 ,s2 ;
	int num ,num1 ,num2;
	int i , j , l , x , x1 , k ,temp ,temp1 ,temp2 , temp3 , t11, t12, t21, t22 ;

	cout << "Enter wat you wanna implement:\n1)Stack\n2)Queue\n3)Exit\n";
	cin >> num;

	while(num != 3){
		switch(num){
			case 1:
			//Implementing Stack
			while(num1 != 4){
				cout << "Enter the operation you wanna perform :\n1)Pop\n2)Push\n3)Display\n4)Exit"<<endl;
				cin >> num1 ;
				switch(num1){
					case 1:
					//Implementing a pop operation using Queue
					if(q1.isEmpty() == 1){
						t11 = q2.getHead();
						t12 = q2.getTail();
						for(i = t11 ; i < t12 ; i++){
							temp = q2.dequeue();
							q1.enqueue(temp);
						}
						q2.dequeue();
						//q1 = NULL;
					}
					else if(q2.isEmpty() == 1){
						t21 = q1.getHead();
						t22 = q1.getTail();
						for(j = t21 ; j < t22 ; j++){
							temp1 = q1.dequeue();
							q2.enqueue(temp1);
						}
						q1.dequeue();
						//q2 = NULL;	
					}
					else
						cout<<"Please enter element to pop!"<<endl;
					break;

					case 2:
					//Enqueue in the queue which is not empty
					cout<<"Enter the num you waannaa push:";
					cin >> x;
					if(q1.isEmpty() != 1) //Not Empty
						q1.enqueue(x);
					else if(q2.isEmpty() != 1)
						q2.enqueue(x);
					else
						q1.enqueue(x);
					break;

					case 3:
					if(q1.isEmpty() == 1)
						q2.display();
					else if(q2.isEmpty() == 1)
						q1.display();
					else
						cout<<"Stack is Empty"<<endl;
					break;

					case 4:
					return 0;
					break;
				}
			}
			break;
	
			case 2:
			//Implement Queue
			while(num2 != 4){
				cout << "Enter the operation you wanna perform:\n1)Enqueue\n2)Dequeue\n3)Display\n4)Exit"<<endl;
				cin >> num2;
				
				switch(num2){
					case 1:
					cout <<"Enter the num you waannaa enqueue:";
					cin >> x1;
					s1.push(x1);
					break;
	
					case 2:
					for(k=0 ; k < s1.total()-1 ; k++){
						temp2 = s1.pop();
						s2.push(temp2);
					}
					s1.pop();
					for(l = 0 ; l < s2.total() ; i++){
						temp3 = s2.pop();
						s1.push(temp3);
					}
					break;

					case 3:
					s1.display();
					break;

					case 4:
					return 0;
					break;
				}
			}
			break;

			case 3:
			return 0;
			break;
		}
	}
	return 0;
}