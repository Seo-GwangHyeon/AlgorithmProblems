#include "Header.h"

template <class T>
void LinkedStack<T>::Push(T pushll)
{
	top = new LinkedNode<T>(pushll, top);//새 탑을 만들어 기존탑을 다음 노드로 넘긴다
}

template <class T>
void LinkedStack<T>::Pop() 
{
	if (IsEmpty()) throw "Stack is empty. Cannot delete.";
	LinkedNode<T> *delNode = top;
	top = top->link;//탑을 빼고 기존 탑의 다음원소를 탑으로 변경한다.
	delete delNode;//탑을 해제한다.
}

template <class T>
bool LinkedStack<T>::IsEmpty() const// 비어있으면 true값을 출력한다.
{
	return top == NULL;
}

template <class T>
void LinkedStack<T>::Print() const//전체 원소를 출력한다
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
		
		this->rear->link = new LinkedNode<T>(pushll, NULL);//기존 rear의 링크를 새 rear로 설정하고 다음 값이 널 인 새 rear를 연결한다.
		this->rear = this->rear->link;
	//	

	}
}

template <class T>
void LinkedQueue<T>::Pop()
{
	if (IsEmpty()) throw "Queue is empty. Cannot delete.";
	LinkedNode<T> *delNode = front->link;
	front->link = front->link->link;//탑을 빼고 기존 탑의 다음원소를 탑으로 변경한다.
	delete delNode;//탑을 해제한다.
}

template <class T>
bool LinkedQueue<T>::IsEmpty() const// 비어있으면 true값을 출력한다.
{
	return front->link== rear;
}

template <class T>// 전체 원소 출력
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
