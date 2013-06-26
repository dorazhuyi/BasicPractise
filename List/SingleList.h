class Node
{
 public:
  Node(){data=0;next=NULL;}
  void set_value(int key){data = key;}
  void set_next(Node* p){next = p;}
  int Node_value(){return data;}
  Node* Node_next(){return next;}
 private:
  int data;
  Node* next;
};

class SingleList
{
 public:
  SingleList(){head = NULL;}
  bool isEmpty();
  int ListLength();
  Node* SearchNode(int);
  Node* Listhead();
  Node* Listrear();
  void Append(int,int);
  void AppendtoHead(int);
  void AppendtoRear(int);
  int DeleteNode(int);
  int DeleteHead();
  int DeleteRear();

  void display();
 private:
  Node* head;
};
