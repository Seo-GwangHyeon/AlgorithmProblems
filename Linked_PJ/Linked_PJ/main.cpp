#include "Header.h"
template <class T>
void LinkedStack<T>::Push(T pushll)
{
	top = new LinkedStackNode<T>(pushll, top);//�� ž�� ����� ����ž�� ���� ���� �ѱ��
}

template <class T>
void LinkedStack<T>::Pop()
{
	if (IsEmpty()) throw "Stack is empty. Cannot delete.";
	LinkedStackNode<T> *delNode = top;
	top = top->link;//ž�� ���� ���� ž�� �������Ҹ� ž���� �����Ѵ�.
	delete delNode;//ž�� �����Ѵ�.
}

template <class T>
bool LinkedStack<T>::IsEmpty()// ��������� true���� ����Ѵ�.
{
	return top == NULL;
}

template <class T>
void LinkedStack<T>::Print()//��ü ���Ҹ� ����Ѵ�
{
	LinkedStackNode<T> *temp = top;
	while (temp)
	{
		cout << temp->data << " ";
		temp = temp->link;
	}
	cout << endl;
}



int main()
{
	LinkedStack<int> A;
	for (int i = 0; i<15; i++)
	{
		A.Push(i + 1);
		A.Print();
	}
	for (int i = 0; i<15; i++)
	{
		A.Pop();
		A.Print();
	}


	return 0;
}
