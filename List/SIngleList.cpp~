#include <iostream>

using namespace std;

  SingleList(){head = NULL;}
  void AddNode(int,int);
  void AppendtoHead(int);
  void AppendtoRear(int);
  int DeleteNode(int);
  int DeleteHead();
  int DeleteRear();
  Node* SearchNode(int);
  void display();

bool SingleList::isEmpty()
{
  if(head == NULL) 
  {
   std::cout << "Empty List." << std::endl;
   return true;
  }
  return false;
}

int SingleList::ListLength()
{
  if(isEmpty())
  { 
    return 0;
  }
  Node* p = head;
  cnt=0;
  while(p!=NULL)
  {
    p=p->Node_next();
    cnt++;
  } 
  return cnt;
}


Node* SingleList::Listhead()
{ 
  return head;
}

Node* SingleList::Listrear()
{
  if(isEmpty()) return head;
  Node* p = head;
  while(p->Node_next() != NULL){ p = p->Node_next();}
  return p;
}

Node* SingleList::SearchNode(int key)
{
  if(!isEmpty())
  {
    Node* p = head;
    while(p->Node_value()!=key && p!=NULL) p = p->Node_next();
    return p;
  }
  return NULL;
}

void SingleList::AppendtoHead(int key)
{
  Node* p = new Node;
  p -> set_value(key);
  if (head == NULL) {p-> set_next(NULL);return;}
  else  p -> set_next(head -> Node_next());
  head = p;
}

void SingleList::AppendtoRear(int key)
{
  Node* p = new Node;
  p -> set_value(key);
  p -> set_next(NULL);
  Node* q = Listrear();
  if(q == NULL) {head = p;return;}
  q -> set_next(p);
  return;
}

void SingleList::AddNode(int key,int n)
{
  int len = ListLength();
  if(n > len+1)
  { 
     std::cout<< "Exceed the List." << std::endl;
     return;
    }    
  }
  Node* p = new Node;
  p -> set_value(key);
  if( n == len+1 ) 
  {
    p-> set_next(NULL);
    head = p;
    return;
  }
  Node* q = head; 
  for(int i=0;i<n-1;i++)
  {
    q = q->Node_next();
  }
  p -> set_next(q->Node_next());
  q -> set_next(p);
  return;
}



int SingleList::DeleteNode(int key)
{}

int SingleList::DeleteHead()
{}

int SingleList::DeleteRear()
{}


