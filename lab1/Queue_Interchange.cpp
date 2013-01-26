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

Queue q , q1 ,q2 ;
int rev[20];
int num , num1 , num2 , num3 , x1 , x = 0;
int temp1 ,temp2 ,temp3 ,temp4 ,temp5 ,temp6 ,temp7 ,temp8 ,temp9 ,temp10 ;

  while(num != 5){
	
	cout<<"Enter the operation you wannaa perform!!\n1)Enqueue\n2)Dequeue\n3)Interchange elements\n4)Display Queue\n5)Exit\n6)Interchange Range\n";
	cin >> num ;
	cout<<q.getHead()<<endl;
	
    switch(num){
    case 1:
      cout<<"Enter the element u wanna add:";
      cin >> num1;
      q.enqueue(num1);
      break;

    case 2:
      q.dequeue();
      break;
	
    case 3:
      q.display();
      cout<<"Enter the element1:";
      cin >> num2;
      cout<<"Enter the element2:";
      cin >> num3;

	//First element is lower and next is higher	      
		while(q.getHead() != num2){
			temp1 = q.dequeue();
			q1.enqueue(temp1);
		}
		temp2 = q.dequeue();	//The first element
		//cout << "Q_head"<<q.getHead() << endl;
		//cout << "Q1_head"<<q1.getHead() << endl;
		while(q.isEmpty() != 1){
			temp3 = q.dequeue();
			q2.enqueue(temp3);
		}
		//cout << "Q_head"<<q.getHead() << endl;
		//cout << "Q2_head"<<q2.getHead() << endl;
		//cout<< "chale 2";
		while(q1.isEmpty() != 1){
			temp4 = q1.dequeue();
			q.enqueue(temp4);
		}	
		//cout<< "Q1_head"<<q1.getHead()<<endl;
		while(q2.getHead() != num3){
			temp5 = q2.dequeue();
			q1.enqueue(temp5);
		}
		//q1.display();
		//cout<< "Q2_head"<<q2.getHead()<<endl;
		temp6 = q2.dequeue();	//The second element
		q.enqueue(temp6);
		//cout << "Q_head"<<q.getHead() << endl;
		//cout<< "Q2_head"<<q2.getHead()<<endl;
		//cout << "Q1_head"<<q1.getHead() << endl;
		//q.display();
		while(q1.isEmpty() != 1){
			temp7 = q1.dequeue();
			q.enqueue(temp7);
		}
		q.enqueue(temp2);	//The first element 
		//cout<< "chale 3";
		//q2.display();
		//q.display();
		while(q2.isEmpty() != 1){
			temp8 = q2.dequeue();
			q.enqueue(temp8);
		}
		/*
		cout << "Q1"<<q.dequeue()<<endl;
		cout << "Q2"<<q.dequeue()<<endl;
		cout << "Q3"<<q.dequeue()<<endl;
		cout << "Q4"<<q.dequeue()<<endl;
		cout << "Q5"<<q.dequeue()<<endl;
		cout << "Q6"<<q.dequeue()<<endl;
		cout << "Q7"<<q.dequeue()<<endl;
		cout << "Q8"<<q.dequeue()<<endl;
		cout << "Q9"<<q.dequeue()<<endl;
		cout << "Q10"<<q.dequeue()<<endl;
		cout << "Q11"<<q.dequeue()<<endl;
		*/
		q.display();
	break;

    case 4:
      q.display();
      break;

    case 5:
      return 0;
      break;

    case 6:
      q.display();
      cout<<"Enter the element1:";
      cin >> num2;
      cout<<"Enter the element2:";
      cin >> num3;

	//First element is lower and next is higher	      
		while(q.getHead() != num2){
			temp1 = q.dequeue();
			q1.enqueue(temp1);
		}
		temp2 = q.dequeue();	//The first element
		while(q.isEmpty() != 1){
			temp3 = q.dequeue();
			q2.enqueue(temp3);
		}
		while(q1.isEmpty() != 1){
			temp4 = q1.dequeue();
			q.enqueue(temp4);
		}	
		while(q2.getHead() != num3){
			temp5 = q2.dequeue();
			q1.enqueue(temp5);
		}
		temp6 = q2.dequeue();	//The second element
		q.enqueue(temp6);
		while(q1.isEmpty() != 1){
			temp7 = q1.dequeue();
			rev[x] = temp7;
			x++;
		}
		for(x1 = x-1 ; x1 >= 0 ; x1--){
			q.enqueue(rev[x1]);
		}
		q.enqueue(temp2);	//The first element 
		while(q2.isEmpty() != 1){
			temp8 = q2.dequeue();
			q.enqueue(temp8);
		}
		q.display();
	break;

    }
  }
  return 0;
}
