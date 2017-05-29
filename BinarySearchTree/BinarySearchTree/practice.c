#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define MAX 1000

typedef struct node {
	int id;
	struct node *left;
	struct node *right;
	struct node *parent;//parent
}NODE;
NODE* queue[MAX];
int front, rear;
NODE* search(NODE *, int);
void insert(NODE **, int);
void delete(NODE **, int);
void level_order(NODE* root);
int counter(NODE* root);
void ancestor(NODE* root,int id);
int height(NODE* root);
int in_order(NODE*, int id);
int near(NODE*,int id);
void quit();
int main(void)
{
	NODE *root = NULL;
	int select = 0;
	int temp_insert = 0, temp_delete = 0;

	printf("-----------case 1 -----------\n");
	insert(&root, 50);
	insert(&root, 30);
	insert(&root, 70);
	insert(&root, 25);
	insert(&root, 40);
	insert(&root, 60);
	insert(&root, 80);
	insert(&root, 15);
	insert(&root, 35);
	insert(&root, 45);
	level_order(root);
	printf("height %d\n", height(root));
	printf("counter %d\n", counter(root));
	printf("ancestor 45 \n" ); ancestor(root, 45);
	printf("in_order 80 %d\n", in_order(root,80));
	printf("near 28 %d\n", near(root,28));
	printf("delete 15 25\n");
	delete(&root, 15);
	delete(&root, 25);
	level_order(root);


	printf("-----------case 2 -----------\n");
	root = NULL;
	insert(&root, 2);	insert(&root, 1);
	insert(&root, 4);insert(&root, 7);
	insert(&root, 8);
	insert(&root, 6);
	insert(&root, 5);
	insert(&root, 3);
	level_order(root);
	printf("height %d\n", height(root));
	printf("counter %d\n", counter(root));
	printf("ancestor 5 \n"); ancestor(root, 5);
	printf("in_order 5 %d\n", in_order(root, 5));
	printf("near 13 %d\n", near(root, 13));
	printf("delete 5 4\n");
	delete(&root, 5);
	delete(&root, 4);
	level_order(root);

	return 0;
}

NODE* search(NODE *t, int id)
{
	while (t != NULL && t->id != id)
	{
		if (t->id > id)
		{//비교하며 탐색
			t = t->left;
		}
		else
		{
			t = t->right;
		}
	}
	return t;
}


void insert(NODE **t, int id)
{
	NODE *new_node = (NODE *)malloc(sizeof(NODE));
	NODE *temp = *t; 

	new_node->id = id;
	new_node->parent = NULL;
	new_node->left = NULL;
	new_node->right = NULL;

	if (temp == NULL)
	{//빈 트리면 바로 new_node를 추가한다.
		*t = new_node;
		return;
	}

	while (temp != NULL)
	{
		new_node->parent = temp;//new_node가 parent를 가리키도록한다.
		//
		if (temp->id > id)//id는 new_node의 id이다
		{//현재id가 작으면 left child로 이동
			temp = temp->left;
		}
		else
		{//현재id가 크면 right child로 이동
			temp = temp->right;
		}
	}

	//parent가 new_node를 가리키도록한다
	if ((new_node->parent)->id > id)
	{//현재id가 작으면 left child
		(new_node->parent)->left = new_node;//temp->left
	}
	else
	{//현재id가 크면 right child
		(new_node->parent)->right = new_node;//temp->right
	}
}

void delete(NODE **t, int id)
{
	NODE *temp = NULL;
	NODE *del_node = NULL;

	temp = search(*t, id);

	// if there is not id.
	if (temp == NULL)
	{
		printf("해당 id 없음\n");
		return;
	}

	// 삭제할노드가 자식이 없는경우
	if (temp->left == NULL && temp->right == NULL)
	{
		if (temp == *t)
		{//루트 1개인 트리인경우
			*t = NULL;
		}
		else if ((temp->parent)->id > id)
		{//left child일경우
			(temp->parent)->left = NULL;
		}
		else
		{//right child일경우 
			(temp->parent)->right = NULL;
		}
		free(temp);
	}

	else if (temp->left == NULL)
	{//right child가 존재하는경우
		temp->id = (temp->right)->id;
		//right child를 del_node에 넣고 right child를 지운다
		delete(&(temp->right), (temp->right)->id);
	}
	
	else if (temp->right == NULL)
	{//left child가 존재하는경우
		temp->id = (temp->left)->id;
		//left child를 del_node에 넣고 left child를 지운다
		delete(&(temp->left), (temp->left)->id);
	}
	else
	{//2개의 child를 가지고 있는경우
		del_node = temp;

		temp = temp->left;
		//left child중에
		while (temp->right != NULL)
		{//left child중에 가장 큰값을 찾는다.
			temp = temp->right;
		}

		del_node->id = temp->id;
		//삭제하려는 노드에 leftt child중에 가장 큰값 을 대입한다.
		delete(&(del_node->left), temp->id);//그리고 원래위치에 값을 제거한다.
	}
}
//큐 연산 push
void push(NODE* node) {
	if (rear == MAX - 1) {
		return;
	}
	rear++;
	queue[rear] = node;
}
//큐 연산 pop
NODE* pop() {
	NODE* node = NULL;

	if (front == rear) {
		return node;
	}
	front++;
	node = queue[front];
	return node;
}
void level_order(NODE* root) {
	NODE* temp;

	front = -1;
	rear = -1;
	if (root == NULL) {
		return;
	}

	push(root);

	while (1) {
		temp = pop();
		if (temp == NULL) {
			break;
		}

		printf("%d ", temp->id);
		if (temp->left != NULL) {
			push(temp->left);
		}
		if (temp->right != NULL) {
			push(temp->right);
		}
	}
	printf("\n");
}

int counter(NODE * root)
{
	NODE* temp;//똑같이 순환해서 갯수를 측정한다
	int sum = 0;
	front = -1;
	rear = -1;
	if (root == NULL) {
		return 0;
	}
	push(root);
	while (1) {
		temp = pop();
		if (temp == NULL) {
			break;
		}
		sum++;
		if (temp->left != NULL) {
			push(temp->left);
		}
		if (temp->right != NULL) {
			push(temp->right);
		}
	}
	return sum;
}
void ancestor(NODE* root,int id)
{
	NODE *temp = NULL;
	temp = search(root, id);//해당 노드를 찾아서
	printf("%d의 조상\n", temp->id);//조상까지 올라간다
	while (temp->parent != NULL)
	{
		printf("%d ", temp->parent->id);
		temp = temp->parent;
	}
	printf("\n");
}
int height(NODE* root)
{
	int heig, hl, hr;
	if (root == NULL) {
		heig = -1;//루트만 있을때 높이 0이므로
	}
	else {
		hl = height(root->left);
		hr = height(root->right);
		if (hl >= hr)//큰 child의 높이를 계산한다
			heig = hl + 1;
		else
			heig = hr + 1;
	}
	return heig;
}

int in_order(NODE* root, int id)
{
	NODE* temp = search(root, id);
	int order = 1;
	if(temp ==NULL)
	{//존재하지 않으면 0반환
		return 0;
	}
	//존재하는경우
	front = -1;
	rear = -1;
	if (root == NULL) {
		return 0;
	}//레벨순환을 해서 몇번째로 작은지 구한다
	push(root);
	while (1) {
		temp = pop();
		if (temp == NULL) {
			break;
		}
		if (temp->id < id)
		{//비교하는 부분
			order++;
		}
		if (temp->left != NULL) {
			push(temp->left);
		}
		if (temp->right != NULL) {
			push(temp->right);
		}
	}
	return order;
}
int near(NODE* t, int id)
{
	int near=100000000;
	int that = 0;
	int temp_near = 0;
	NODE *temp;
	//존재하는경우
	front = -1;
	rear = -1;
	if (t == NULL) {
		return 0;
	}//레벨 순환을 하여 가장 차가 적은 노드를 구한다
	push(t);
	while (1) {
		temp = pop();
		if (temp == NULL) {
			break;
		}
		temp_near = (temp->id > id ? temp->id - id : id - temp->id);
		if (temp_near < near)
		{//비교해서 that에 해당노드의 id값을 저장한다
			near = temp_near;
			that = temp->id;
		}
		if (temp->left != NULL) {
			push(temp->left);
		}
		if (temp->right != NULL) {
			push(temp->right);
		}
	}
	return that;
}
void quit()
{//종료
	exit(0);
}