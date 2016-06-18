//Stack
#include <iostream>
#include <deque>
#include <stack>
#include <list>
#include <algorithm>

using namespace std;


//==========源代码==========
template< class T,class Sequence = deque<T> >

class Stack
{
	friend bool operator== __STL_NULL_TMPL_ARGS (const stack<T, Sequence>& x, const stack<T,Sequence>& y);
	friend bool operator< __STL_NULL_TMPL_ARGS  (const stack<T, Sequence>& x, const stack<T, Sequence>& y);

public:
	typedef typename Sequence::value_type value_type;
	typedef typename Sequence::size_type size_type;
	typedef typename Sequence::reference reference;
	typedef typename Sequence::const_reference const_reference;
protected:
	Sequence c;			//底层容器
public:
	//一下完全利用Sequence c 的操作，完成 stack 的操作
	bool empty() const { return c.empty(); }
	size_type size() const { return c,size(); }
	const_reference top() const { return c.back(); }
	reference top() { return c.back(); }
	//deque是两头可进出， stack 是末端进，末端出 （所以后进者先出）
	void push(const value_type& x) { c.push_back(x); }
	void pop() { c.pop_back(); }
};

template <class T,class Sequence>

bool operator==(const stack<T, Sequence>& x, const stack<T,Sequence>& y)
{
	return x.c == y.c;
}

template <class T,class Sequence>

bool operator<(const stack<T, Sequence>& x, const stack<T, Sequence>& y)
{
	return x.c < y.c;
}

//list 做底层容器
int main()
{
	stack< int, list<int> > istack;
	istack.push(1);
	istack.push(3);
	istack.push(5);
	istack.push(7);

	cout << istack.size() << endl;	//4
	cout << istack.top() << endl;   //7

	istack.pop(); cout << istack.top() << endl;	//5
	istack.pop(); cout << istack.top() << endl;	//3
	istack.pop(); cout << istack.top() << endl;	//1

	cout << istack.size() <<endl;	//1
	return 0;
}



//数组栈


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

/*
//链表栈

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

  */
