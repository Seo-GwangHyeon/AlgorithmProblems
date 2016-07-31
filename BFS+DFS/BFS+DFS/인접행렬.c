#include <stdio.h>
#define MAX_VERTICES 10
#define N  50

#define QUEUE_SIZE 100
#define EMPTY -1


void read_graph(char *file_name);
void write_graph(void);


int adj_mat[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int n;		// ���� ����� ����


//ť���� ������ �Լ�
int queue[QUEUE_SIZE];
int front;
int rear;

int isFull();
int QisEmpty();
void Queuepush(int item);
void Queuepop();
int getFront();
void queueInit();
void printQueue();
//����
#define StackSize 100
int top = 0;
int s[StackSize];

void StackInit()
{
	top = 0;
	for (int i = 0; i < StackSize; i++)
	{
		s[i] = 0;
	}
}

void Stackpush(int d)
{
	s[top] = d;
	top++;
}

void Stackpop()
{
	if (top == 0) { printf("empty\n"); }
	else {
		s[top] = 0;
		top--;
	}
}
int getTop()
{
	return s[top - 1];
}
FILE *fout;
void BFS(int v);
void DFS(int i);
int main(void)
{
	char infile[20], outfile[20];
	fout = fopen("result_adjmatrix.out", "w");

	read_graph("data_adjmatrix.in");
	fprintf(fout,"\n\n�׷��� ������� ���\n");
	write_graph();
	
	fprintf(fout,"BFS\n");
	for (int i = 0; i < n; i++)
	{
		BFS(i);
		fprintf(fout,"\n");
	}
	fprintf(fout,"DFS\n");
	for (int i = 0; i < n; i++)
	{
		DFS(i);
		fprintf(fout,"\n");
	}
	return 0;

}

/* �׷��� �Է�: ������� ǥ�� */
void read_graph(char *file_name)
{
	int i, j;
	FILE *fp = fopen(file_name, "r");
	if (fp == NULL) return;
	fscanf(fp, "%d\n", &n);
	for (i = 0; i<n; i++)
		for (j = 0; j<n; j++)
			fscanf(fp, "%d", &adj_mat[i][j]);
	fclose(fp);
}

/* �׷��� ��� : ������� ǥ�� */
void write_graph(void)
{
	int i,j;

	fprintf(fout,"�׷����� �������� : %d \n\n", n);
	for (i = 0; i<n; i++) {
		for (j = 0; j<n; j++) {
			fprintf(fout," %d ", adj_mat[i][j]);
		}
		fprintf(fout,"\n");
	}

}

void BFS(int v)
{
	for (int m = 0; m < n; m++)
	{
		visited[m] = 0;
	}
	int counter = 0;
	visited[v] = 1;
	queueInit();
	Queuepush(v);//ť�� v�� �־��ش�
	fprintf(fout,"%d -> ", v);
	counter++;
	while (!QisEmpty())
	{
		v = getFront();//front�� v�� �ִ´�
		Queuepop();
		for (int w = 0; w < n; w++)
		{
			if ((visited[w]==0) && adj_mat[v][w])//�ʺ� Ž���� ���ؼ� w�� ���� ���� ��� Ž���ؼ� edge�� ������ Ž�������Ѵ�
			{
				Queuepush(w);//w�� push�Ѵ�.
				visited[w] = 1;//�湮�Ѱ����� ǥ��
				fprintf(fout,"%d ", w );//���
				counter++;
				if (counter<n)
					fprintf(fout," -> ");
			}
		}
	}
}
void DFS(int i) {
	for (int m = 0; m < n; m++)
	{
		visited[m] = 0;
	}
	int counter = 0;
	StackInit();
	visited[i] = 1;
	Stackpush(i);
	fprintf(fout,"%d ->", i);
	counter++;
	i = getTop();
	while (top != 0)
	{
		for (int w = 0; w < n; w++)
		{
			if ((!visited[w]) && adj_mat[i][w])
			{
				Stackpush(w);
				visited[w] = 1;
				counter++;
				fprintf(fout,"%d ", w);
				if (counter<n)
					fprintf(fout," -> ");
				i = getTop();
				w = 0;
			}
		}
		Stackpop();
		i = getTop();
	}
}
//ť���� �Լ���
void queueInit()
{
	memset(queue, EMPTY, sizeof(int)*QUEUE_SIZE);
	front = 0;
	rear = 0;
}
int isFull()
{
	if ((rear + 1) % QUEUE_SIZE == front)
		return 1;
	else
		return 0;
}
int QisEmpty()
{
	if (front == rear)
		return 1;
	else
		return 0;
}
void Queuepush(int item)
{
	rear = (rear + 1) % QUEUE_SIZE;
	queue[rear] = item;
}
void Queuepop()
{
	front = (front + 1) % QUEUE_SIZE;
	queue[front] = EMPTY;
}
int getFront()
{
	return front;
	//return queue[ (front + 1 ) % QUEUE_SIZE ];
}
void printQueue()
{
	int i = 0, j = 0;
	for (i = (front + 1) % QUEUE_SIZE, j = 0; i < QUEUE_SIZE; i++, j++)
	{
		printf("%d", getFront());

	}
}