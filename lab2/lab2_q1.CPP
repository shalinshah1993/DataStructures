#include<iostream.h>
#include<conio.h>
struct Node
{
  char key;
  int no_children;
  int child_index;
  Node *child;
  Node *siblings;
}*root;

void enqueue(Node *i);
Node *dequeue();

struct LINK
{
  Node *item;
  LINK *next;
}*head,*tail;

struct LCRS_Node
{
   char key;
   LCRS_Node *parent;
   LCRS_Node *leftchild;
   LCRS_Node *rightchild;
}*LCRS_root;

struct LINK2
{
  LCRS_Node *item;
  LINK2 *next;
}*head2,*tail2;

void enqueue_link2(LCRS_Node *i);
LCRS_Node *dequeue_link2();

void create_tree()
{
  int num,i;
  Node *temp1,*newnode;
  Node *temp;
  static char key=65;
  if(head==NULL)
    return;

   temp=dequeue();
   cout<<"Enter No. of children for "<<temp->key<<" : ";
   cin>>num;
   temp->no_children=num;
   temp1=temp;
   if(num==0)
   {
     temp->child=NULL;
     temp->child_index=0;
   }
   else
   {
   cout<<"Children of "<<temp->key<<" : ";
   for(i=0;i<num;i++)
   {

    newnode=new Node();
    newnode->key=++key;
    newnode->child_index=i+1;
    cout<<key<<" ";
    if(i==0)
       temp1->child=newnode;
    else
       temp1->siblings=newnode;
    temp1=newnode;
    enqueue(newnode);
   }
   cout<<endl<<endl;
   temp1->siblings=NULL;
  }

  create_tree();

}

void enqueue(Node *i)      //Insert at end
{
   LINK *temp=new LINK();
   temp->item=i;
   temp->next=NULL;
   if(tail==NULL)
   {
     head = temp;
     tail=temp;
   }
   else
   {
      tail->next=temp;
      tail=temp;
    }
}

Node *dequeue()
{
  LINK *temp1;
  Node *item;
  if(head==NULL)
   item=NULL;

  else
  {
     temp1=head;
     head=head->next;
     if(head==NULL)
	tail=NULL;
     item=temp1->item;
     delete temp1;
  }
  return item;


}
void enqueue_link2(LCRS_Node *i)      //Insert at end
{
   LINK2 *temp=new LINK2();
   temp->item=i;
   temp->next=NULL;
   if(tail2==NULL)
   {
     head2 = temp;
     tail2=temp;
   }
   else
   {
      tail2->next=temp;
      tail2=temp;
    }
}

LCRS_Node *dequeue_link2()
{
  LINK2 *temp1;
  LCRS_Node *item;
  if(head2==NULL)
   item=NULL;

  else
  {
     temp1=head2;
     head2=head2->next;
     if(head2==NULL)
	tail2=NULL;
     item=temp1->item;
     delete temp1;
  }
  return item;


}

void create_LCRS()
{
  int i=0,num;
  LCRS_Node *temp,*newnode,*parent;
  Node *temp1,*temp2;
  if(head==NULL)
    return;
  temp1=dequeue();//node dequeue
  temp=dequeue_link2();//LCRS dequeue
  parent=temp;
  num=temp1->no_children;
  if(num==0)
  {
     temp->leftchild=NULL;
  }
  while(i<num)
  {
   newnode=new LCRS_Node();
   if(i==0)
   {
     newnode->parent=parent;
     parent->leftchild=newnode;
     temp1=temp1->child;
     newnode->key=temp1->key;
     parent=newnode;

   }
   else
   {
     newnode->parent=parent;
     parent->rightchild=newnode;
     temp1=temp1->siblings;
     newnode->key=temp1->key;
     parent=newnode;
   }
   enqueue(temp1);
   enqueue_link2(newnode);
   newnode->rightchild=NULL;
   i++;
  }

  cout<<"Left   child of "<<temp->key<<" is ";
  if(temp->leftchild==NULL)
     cout<<"NULL"<<endl;
  else
     cout<<temp->leftchild->key<<endl;
  cout<<"Right  child of "<<temp->key<<" is ";
  if(temp->rightchild==NULL)
     cout<<"NULL"<<endl;
  else
     cout<<temp->rightchild->key<<endl;
  cout<<endl;
  create_LCRS();


}

void decode_LCRS()
{
  int i=0;
  LCRS_Node *temp1;
  Node *temp,*temp2,*newnode,*parent;
  if(head==NULL)
    return;
  temp=dequeue();//node dequeue
  temp1=dequeue_link2();//LCRS dequeue
  parent=temp;
  if(temp1->leftchild==NULL)
  {
     temp->no_children=0;
     temp->child=NULL;
     cout<<"Children of "<<parent->key<<" : NULL"<<endl;
  }

  else
    {
     do
     {
	 newnode=new Node();
	 if(i==0)
	 {
	   parent->child=newnode;
	   parent->child_index=++i;
	   temp1=temp1->leftchild;
	   newnode->key=temp1->key;
	   cout<<"Children of "<<parent->key<<" : "<<newnode->key;
	   parent=newnode;
	   temp2=newnode;


	 }
	 else
	 {
	   parent->siblings=newnode;
	   parent->child_index=++i;
	   temp1=temp1->rightchild;
	   newnode->key=temp1->key;
	   cout<<" "<<newnode->key;
	   parent=newnode;
	 }

	 enqueue(newnode);
	 enqueue_link2(temp1);
     }while(temp1->rightchild!=NULL);
     temp2->no_children=i;
     newnode->siblings=NULL;
     cout<<endl;
    }
  decode_LCRS();


}

int main()
{
  head=NULL;
  tail=NULL;
  root=NULL;
  root=new Node();
  root->siblings=NULL;
  root->key=65;
  enqueue(root);
  create_tree();
  cout<<"\nApplying LCRS... \n\n ";
  head=NULL;
  tail=NULL;
  head2=NULL;
  tail2=NULL;
  LCRS_root->parent=NULL;
  LCRS_root->key=root->key;
  LCRS_root->rightchild=NULL;
  enqueue(root);
  enqueue_link2(LCRS_root);
  create_LCRS();
  getch();

  cout<<"\nDecoding LCRS.....\n";
  head=NULL;
  tail=NULL;
  head2=NULL;
  tail2=NULL;
  enqueue(root);
  enqueue_link2(LCRS_root);
  decode_LCRS();

  getch();
  return 0;
}
