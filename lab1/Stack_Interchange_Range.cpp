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
		
                int top(){
		  return Array[i] ;
                }
  
		int isEmpty(){
			if(i == -1)
				return 1;
			else 
				return 0;
		};

	private:
		int Array[20];
		int i ,k;
};


int main(){
  
 
  int num ,num1 , a , b, i ; 
  int temp , temp1 ,temp2 , temp3 , temp4 , temp5 , temp6 , temp7 ;
  Stack s , s1 , s2 ;

  while(num != 5){
    cout << "Enter the operation you wanna perform :\n1)Push\n2)Pop\n3)Display\n4)Interchange"<<endl;
    cin >> num ;

    switch(num){
    case 1:
      cout<<"Enter the num you wanna push:";
      cin>>num1;
      s.push(num1);
      cout << "The num of elements in stack :" << s.total() << endl;
    break;

    case 2:
      s.pop();
    break;

    case 3:
      s.display();
//	cout<< s.top();
    break;

    case 4:
      s.display();
      cout<<"Enter the element 1:";
      cin >> a;
      cout<<"Enter the element 2:";
      cin >> b;
//Upper element shoul be entered first an lower next
			while(1){
				if(s.top() == a){
					s.pop();
					s1.push(a);
					break;
				}
				temp1 = s.pop();
				s1.push(temp1);
			}			
			while(1){
				if(s.top() == b){
					s.pop();
					s2.push(b);
					break;
				}
				temp2 = s.pop();
				s2.push(temp2);
			}
			temp3 = s1.pop();
			s.push(temp3);
			temp4 = s2.pop();
			s1.push(temp4);
			while(s2.isEmpty() != 1){
				temp5 = s2.pop();
				s1.push(temp5); 
			}
			while(s1.top() != temp4){
				temp7 = s1.pop();
				s.push(temp7);
			}			
			while(s1.isEmpty() != 1){
				temp6 = s1.pop();
				s.push(temp6); 
			}	
      cout << "Stack with interchanged elements :";
      s.display();
    break;
  }
}
  return 0;
}

