#include<iostream>

using namespace std;

class Queue{

	private:
		int Array[20];
		int i , j , x , m , k ,dummy_head , dummy_tail;

	public:
		Queue(){
			i = 0 ;
			x = -1 ;
			j = 0 ;
			m = i;
			//tail = j;	
		};

		int total(){
			return ( 20 - i + j ) % 20 ;			
		};
		
		void enqueue(int n){
			Array[++x % 20] = n ;
			dummy_tail = Array[j];
		 	j = (x+1) % 20;
		};

		int dequeue(){
			//Array[i % 10] = NULL;
			dummy_head = Array[i];
			++i;
			i = i % 20;
			m = i;
			return dummy_head;	
		};	

		void display(){
			m = i;
			k = Array[m];
			while(k !=  dummy_tail){
				cout << Array[m % 20] << " ";
				++m; 
				k = Array[m%20];
			}
		cout<<Array[m % 20]<<endl;
		};	

		int getHead(){
			return Array[i%20];
		};

		int isEmpty(){
			if(i == j)
				return 1;
			else
				return 0;
		};

		int getTail(){
			return dummy_tail ;
		} 	
};

int main(){
	
	int l , num ,i;	
	//int a,b;
	Queue s;
		
	
	
	while( l != 3){
	
if(s.isEmpty()==1)
	cout<<"EMpty"<<endl;
else
	cout<<"Not Empty"<<endl;
		cout<<"Enter the operation you wannaa perform!!\n1)Enqueue\n2)Dequeue\n3)Display Queue\n4)Exit\n5)Reverse\n";
		cin >> l ;
	
		switch(l){
			case 1:
			cout << "Enter the num you wanna add to Queue : ";
			cin >> num ;
			s.enqueue(num);
			cout<<"No of Elements in Queue are " << s.total() << endl;
			break;

			case 2:
			s.dequeue();
			cout<<"No of Elements in Stack are " << s.total() << endl ;
			break;

			case 4:
			return 0;
			break;	

			case 3:
			s.display();
			break;

			case 5:
/*			
			int Array[20];
			i = 0;
			while(s.isEmpty() != 1){
			Array[i] = s.dequeue();
			i++;
			}
			while(i != -1){
			cout<< Array[i]<<" ";
			i--;
			}
			break;

			default:
			cout << "You entered an invalid choice !!!!!!Please enter again" << endl;
*/			break;
		}	
	}
	return 0;
}