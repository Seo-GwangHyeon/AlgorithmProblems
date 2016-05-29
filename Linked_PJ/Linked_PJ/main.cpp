#include "Header.h"

template <class T>
void LinkedStack<T>::Push(T pushll)
{
	top = new LinkedNode<T>(pushll, top);//�� ž�� ����� ����ž�� ���� ���� �ѱ��
}

template <class T>
void LinkedStack<T>::Pop() 
{
	if (IsEmpty()) throw "Stack is empty. Cannot delete.";
	LinkedNode<T> *delNode = top;
	top = top->link;//ž�� ���� ���� ž�� �������Ҹ� ž���� �����Ѵ�.
	delete delNode;//ž�� �����Ѵ�.
}

template <class T>
bool LinkedStack<T>::IsEmpty() const// ��������� true���� ����Ѵ�.
{
	return top == NULL;
}

template <class T>
void LinkedStack<T>::Print() const//��ü ���Ҹ� ����Ѵ�
{
	LinkedNode<T> *temp = top;
	while (temp)
	{
		cout << temp->data << " ";
		temp = temp->link;
	}
	cout << endl;
}
//---------------------------------------------------------------------

template <class T>
void LinkedQueue<T>::Push(T pushll)
{
	if (this->IsEmpty())
	{
		//this->front->link = this->rear;
		this->rear = new LinkedNode<T>(pushll, 0);
	}
	else
	{
		
		this->rear->link = new LinkedNode<T>(pushll, NULL);//���� rear�� ��ũ�� �� rear�� �����ϰ� ���� ���� �� �� �� rear�� �����Ѵ�.
		this->rear = this->rear->link;
	//	

	}
}

template <class T>
void LinkedQueue<T>::Pop()
{
	if (IsEmpty()) throw "Queue is empty. Cannot delete.";
	LinkedNode<T> *delNode = front->link;
	front->link = front->link->link;//ž�� ���� ���� ž�� �������Ҹ� ž���� �����Ѵ�.
	delete delNode;//ž�� �����Ѵ�.
}

template <class T>
bool LinkedQueue<T>::IsEmpty() const// ��������� true���� ����Ѵ�.
{
	return front->link== rear;
}

template <class T>// ��ü ���� ���
void LinkedQueue<T>::Print() const
{
	LinkedNode<T> *temp = this->front->link;
	while (1)
	{
		cout << temp->data << " ";
		temp = temp->link;
	}
	cout << endl;
}

int main()
{
	/*LinkedStack<int> A;
	for (int i = 0; i<15; i++)
	{
		A.Push(i + 1);
		A.Print();
	}
	for (int i = 0; i<15; i++)
	{
		A.Pop();
		A.Print();
	}*/
	LinkedQueue<int> b;
	for (int i = 0; i<15; i++)
	{
		b.Push(i + 1);
		b.Print();
	}
	//b.Print();
	for (int i = 0; i<14; i++)
	{
		b.Pop();
		b.Print();
	}


	return 0;
}
