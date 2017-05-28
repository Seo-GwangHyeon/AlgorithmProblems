// Binary Search Tree 로 data를 운영하는 시스템

/*
1. Binary Search Tree(BST)를 이용한 data관리하는 program

2. Data는 0보다 큰 정수 (1~100 사이의 값) 이며, 구조체는 Linked List를 사용한다.


3. 연산들

(1) insert(id) : Data를 읽어서 BST에 삽입한다. 같은 data값ㅇ느 없다고 생각한다.
(입력값이 잘못 들어오면 error message를 출력하고 다시 입력받는다.

(2) delete(id) : id 값을 삭제한다. id 값이 없을 경우 없다고 출력한다.
(자식이 둘일 경우 왼쪽 subtree에서 가장 큰 원소와 대치한다)

(3) count() : 원소의 개수를 출력한다.

(4) height() : BST의 높이를 출력한다.

(5) level_order() : 레벨순회 방식으로 방문한 원소를 출력한다.

(6) ancestor(id) : 원소의 조상 node들을 출력한다.

(7) Terminal(): 단말 node의 개수를 출력한다.

(8) min_order(id) : id 값을 갖는 원소가 몇번째로 작은 원소인지 출력한다.
원소가 없을 경우에는 0을 출력한다.

(9) near(id) : id 값은 BST에 없는 값이며, 출력하는 원소는 id 값과 가장 차이가 적은 원소를 출력한다.
차이 값이 같을 경우는 값이 작은 원소를 출력한다.

(10) quit() : program을 끝낸다.

*/
#include <stdio.h>

struct node
{
	int data;
	struct node *right;
	struct node	*left;
};

void insert(struct node *tree, int id);
void delete(id);
int count();
int height();
void level_order();
void ancestor(id);
int min_order(id);
void near(id);
void quit();

void init(struct node *tree, int id);


int main()
{
	
	int arr1[] = { 2,1,7,8,6,3,5,4 };
	
	return 0;
}

void insert(struct node* tree, int id)
{
	
}

void init(struct node *tree, int id)
{

}

void delete(id)
{

}
int count()
{
	return 0;
}
int height()
{
	return 0;
}
void level_order()
{

}
void ancestor(id)
{

}
int min_order(id)
{
	return 0;
}
void near(id)
{

}
void quit()
{

}
