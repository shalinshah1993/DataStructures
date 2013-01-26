#include<iostream>
///////parent = [(i - 2)/k +1] and child(i,j) = k(i-2)+j+1 
using namespace std;
int b[100];
int create()
 {
   int j;
   cout<<"\n Enter the number of terms you want to enter : ";
   cin>>j;
   for(int i=0;i<j;i++)
      { cout<<"\n Enter number : ";
        cin>>b[i];
      }
   return j;
 }

void p7()
 { int x,y,k,i;
   int j=create();
   cout<<"\n Enter the value of k for k-array tree : ";
   cin>>k;
   cout<<"\n Enter index of node whose parent you want to find : ";
   cin>>x;
   if(x==1)
     cout<<"\n It is the root.";
   else
     { y=(k+x-2)/k;
       cout<<"\n The index of the parent of "<<x<<" node is "<<y;
     }
   cout<<"\n Enter index of parent whose children you want to find : ";
   cin>>y;
   cout<<"\n Enter child index : ";
   cin>>i;
   x=k*(y-1)+2+i;
   if(x>j)
     cout<<"\n It is the leaf.";
   else
     cout<<"\n The index of the "<<i<<" child of "<<y<<" is "<<x;
 }
 
int main(){
p7();
return 0;
};