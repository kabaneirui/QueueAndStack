//Êý×éÕ»

#include <iostream>

using namespace std;


/*class Stack
{
private:
	int size;
	int top;
	int *date;
public:
	Stack(int s = 10)
	{
		size = s;
		top = -1;
		date = new int[s];
	}
	
	~Stack()
	{
		delete [] date;
	}
	void push(int d);
	int pop();
	int isEmpty();
};

int Stack::isEmpty()
{
	if(top == -1)
		return 0;
	if(top >= 0 && top < size)
		return 1;
}

void Stack::push(int d)
{
	if(top == size-1)return;
	date[++top] = d;
}

int Stack::pop()
{
	if(isEmpty == 0)throw;
	return date[top--];
}

void main()
{
	Stack s(3);
	s.push(5);
	s.push(8);
	s.push(9);
	s.push(7);
	cout<<s.pop()<<" "<<s.pop()<<" "<<s.pop()<<endl;
}
*/
//Á´±íÕ»

class Node
{
public:
	int node;
	Node * next;
	Node(int n)
	{
		node = n;
	}
	Node(Node &n)
	{
		node = n.node;
	}
};
class Stack
{
private:
	int size;	
public:
	 Node *top;
	 int num;
	Stack(int s)
	{
		size = s;
		top = NULL;
		num = -1;
	}
	
	~Stack()
	{
		delete [] Stack::top;
	}
	void push(Node &d);
	Node pop();
	int isEmpty();
};

int Stack::isEmpty()
{
	if( num == -1)
		return 0;
	else 
		return 1;
}

void Stack::push(Node &n)
{
	if(num == size-1)return;
	if(top == NULL)
	{
		top = &n;
		top->next = NULL;
		cout<<top->node;
	}		
	else
	{
	n.next = top;
	top = &n;
	}
	num++;
}

Node Stack::pop()
{
	if(isEmpty() == 0)
		return NULL;
	num--;
	Node n(*top);
	Node * temp = top;
	top = top->next;
	delete [] temp;
	return n;
}

void main()
{
	Node node1(5);
	Node node2(8);
	Node node3(9);
	Node node4(3);
	Stack s(3);
	s.push(node1);
	//s.push(node2);
	//s.push(node3);
	//cout<<s.pop().node<<" "<<s.pop().node<<" "<<s.pop().node<<endl;
}