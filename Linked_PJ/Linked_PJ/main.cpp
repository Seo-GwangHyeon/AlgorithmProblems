#include "Header.h"
template <class T>
void LinkedStack<T>::Push(T pushll)
{
	top = new LinkedStackNode<T>(pushll, top);//새 탑을 만들어 기존탑을 다음 노드로 넘긴다
}

template <class T>
void LinkedStack<T>::Pop()
{
	if (IsEmpty()) throw "Stack is empty. Cannot delete.";
	LinkedStackNode<T> *delNode = top;
	top = top->link;//탑을 빼고 기존 탑의 다음원소를 탑으로 변경한다.
	delete delNode;//탑을 해제한다.
}

template <class T>
bool LinkedStack<T>::IsEmpty()// 비어있으면 true값을 출력한다.
{
	return top == NULL;
}

template <class T>
void LinkedStack<T>::Print()//전체 원소를 출력한다
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
