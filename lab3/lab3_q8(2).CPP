#include<iostream>

struct Node
{
     int x,y;
};


struct LCRS_Node
{
   Node key;
   LCRS_Node *parent;
   LCRS_Node *leftchild;
   LCRS_Node *rightchild;
};

class Treap
{
     Node elements[50];
     int size,min;
     LCRS_Node *LCRS_root;

   public:

     void getelements()
     {
	   cout<<"Enter the size of the treap : ";
	   cin>>size;
	   cout<<"Enter the elements : \n ";

	   for(int i=0;i<size;i++)
	   {
		  cout<<"Element "<<i+1<<": ";
		  cin>>elements[i].x;
		  cin>>elements[i].y;
	   }

	   build_treap();
	   cout<<"Treap (Inorder Traversal) : ";
	   display(LCRS_root);
     };

     void build_treap()
     {
	  int k,j=size;
	  for(int i=0;i<size;i++)
	  {

	       min=elements[i].y;
	       for(k=i;k<size;k++)
	       {
		     if(elements[k].y<min)
		     {
			   Node temp=elements[k];
			   elements[k]=elements[i];
			   elements[i]=temp;

		     }
	       }

	       LCRS_Node  *newnode=new LCRS_Node();
	       newnode->key=elements[i];
	       newnode->leftchild=NULL;
	       newnode->rightchild=NULL;

	       if(i==0)
	       {

		       newnode->parent=NULL;
		       LCRS_root=newnode;

	       }
	       else
	       {

		       LCRS_Node *temp=LCRS_root;
		       while(((temp->leftchild!=NULL) &&  ((newnode->key.x) < (temp->key.x))) || ((temp->rightchild!=NULL) &&  ((newnode->key.x) > (temp->key.x))) )
		       {
			     if((newnode->key.x) < (temp->key.x))  		       
				     temp=temp->leftchild;
			     else
				     temp=temp->rightchild;
		       }
		       if((newnode->key.x) < (temp->key.x))  		       
		       {

			      temp->leftchild=newnode;
			      newnode->parent=temp;

		       }
		       else
		       {

			      temp->rightchild=newnode;
			      newnode->parent=temp;
		       }
	       }

	  }
     };

     void display(LCRS_Node *Node1)
     {		//print inorder traversal
			if(Node1 == NULL)			// 1
				return;				//2 3
								//123
			display(Node1->leftchild);
			cout << "( "<<Node1->key.x<<", "<<Node1->key.y << ")\t" ;
			display(Node1->rightchild);
     };

};

int main()
{
   Treap treap;
   treap.getelements();
   return 0;
}
