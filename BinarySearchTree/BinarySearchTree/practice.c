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
//int count;
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
	printf("���� %d\n", height(root));
		printf("1) insert\n");
		printf("2) delete\n");
		printf("3) display(DFS)\n : ");
		scanf("%d", &select);
		printf("15 %d\n", in_order(root,15));
		printf("25 %d\n", in_order(root, 25));
		printf("30 %d\n", in_order(root, 30));
		printf("near 32 %d\n", near(root, 32));
		
		if (select == 1)
		{
			scanf("%d", &temp_insert);
			insert(&root, temp_insert);
		}
		else if (select == 2)
		{
			scanf("%d", &temp_delete);
			delete(&root, temp_delete);
		}
		else if (select == 3)
		{
			level_order(root);
			_getch();
		}
		else if(select==4)
		{
			printf("%d���� ���\n",counter(root));
		}

	return 0;
}

NODE* search(NODE *t, int id)
{
	while (t != NULL && t->id != id)
	{
		if (t->id > id)
		{//���ϸ� Ž��
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
	NODE *temp = *t; // temporary node.

	new_node->id = id;
	new_node->parent = NULL;
	new_node->left = NULL;
	new_node->right = NULL;

	// if there is not any node.
	if (temp == NULL)
	{//�� Ʈ���� �ٷ� new_node�� �߰��Ѵ�.
		*t = new_node;
		return;
	}

	// find the position that new node will be inserted.
	while (temp != NULL)
	{
		new_node->parent = temp;//new_node�� parent�� ����Ű�����Ѵ�.
		//
		if (temp->id > id)//id�� new_node�� id�̴�
		{//����id�� ������ left child�� �̵�
			temp = temp->left;
		}
		else
		{//����id�� ũ�� right child�� �̵�
			temp = temp->right;
		}
	}

	//parent�� new_node�� ����Ű�����Ѵ�
	if ((new_node->parent)->id > id)
	{//����id�� ������ left child
		(new_node->parent)->left = new_node;//temp->left
	}
	else
	{//����id�� ũ�� right child
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
		printf("�ش� id ����\n");
		return;
	}

	// �����ҳ�尡 �ڽ��� ���°��
	if (temp->left == NULL && temp->right == NULL)
	{
		if (temp == *t)
		{//��Ʈ 1���� Ʈ���ΰ��
			*t = NULL;
		}
		else if ((temp->parent)->id > id)
		{//left child�ϰ��
			(temp->parent)->left = NULL;
		}
		else
		{//right child�ϰ�� 
			(temp->parent)->right = NULL;
		}
		free(temp);
	}

	else if (temp->left == NULL)
	{//right child�� �����ϴ°��
		temp->id = (temp->right)->id;
		//right child�� del_node�� �ְ� right child�� �����
		delete(&(temp->right), (temp->right)->id);
	}
	
	else if (temp->right == NULL)
	{//left child�� �����ϴ°��
		temp->id = (temp->left)->id;
		//left child�� del_node�� �ְ� left child�� �����
		delete(&(temp->left), (temp->left)->id);
	}
	else
	{//2���� child�� ������ �ִ°��
		del_node = temp;

		temp = temp->left;
		//left child�߿�
		while (temp->right != NULL)
		{//left child�߿� ���� ū���� ã�´�.
			temp = temp->right;
		}

		del_node->id = temp->id;
		//�����Ϸ��� ��忡 leftt child�߿� ���� ū�� �� �����Ѵ�.
		delete(&(del_node->left), temp->id);//�׸��� ������ġ�� ���� �����Ѵ�.
	}
}

void push(NODE* node) {
	if (rear == MAX - 1) {
		return;
	}

	rear++;
	queue[rear] = node;
}

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
}

int counter(NODE * root)
{
	NODE* temp;
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
	temp = search(root, id);
	printf("%d�� ����\n", temp->id);
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
		heig = -1;//��Ʈ�� ������ ���� 0�̹Ƿ�
	}
	else {
		hl = height(root->left);
		hr = height(root->right);
		if (hl >= hr)
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
	{//�������� ������ 0��ȯ
		return 0;
	}
	//�����ϴ°��
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
		if (temp->id < id)
		{
			order++;
			printf("%d order %d\n",id, order);
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
	//�����ϴ°��
	front = -1;
	rear = -1;
	if (t == NULL) {
		return 0;
	}
	push(t);
	while (1) {
		temp = pop();
		if (temp == NULL) {
			break;
		}
		temp_near = (temp->id > id ? temp->id - id : id - temp->id);
		if (temp_near < near)
		{
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
{
	exit(0);
}