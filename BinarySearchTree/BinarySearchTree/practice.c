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
	NODE *temp = *t; 

	new_node->id = id;
	new_node->parent = NULL;
	new_node->left = NULL;
	new_node->right = NULL;

	if (temp == NULL)
	{//�� Ʈ���� �ٷ� new_node�� �߰��Ѵ�.
		*t = new_node;
		return;
	}

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
//ť ���� push
void push(NODE* node) {
	if (rear == MAX - 1) {
		return;
	}
	rear++;
	queue[rear] = node;
}
//ť ���� pop
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
	NODE* temp;//�Ȱ��� ��ȯ�ؼ� ������ �����Ѵ�
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
	temp = search(root, id);//�ش� ��带 ã�Ƽ�
	printf("%d�� ����\n", temp->id);//������� �ö󰣴�
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
		if (hl >= hr)//ū child�� ���̸� ����Ѵ�
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
	}//������ȯ�� �ؼ� ���°�� ������ ���Ѵ�
	push(root);
	while (1) {
		temp = pop();
		if (temp == NULL) {
			break;
		}
		if (temp->id < id)
		{//���ϴ� �κ�
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
	//�����ϴ°��
	front = -1;
	rear = -1;
	if (t == NULL) {
		return 0;
	}//���� ��ȯ�� �Ͽ� ���� ���� ���� ��带 ���Ѵ�
	push(t);
	while (1) {
		temp = pop();
		if (temp == NULL) {
			break;
		}
		temp_near = (temp->id > id ? temp->id - id : id - temp->id);
		if (temp_near < near)
		{//���ؼ� that�� �ش����� id���� �����Ѵ�
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
{//����
	exit(0);
}