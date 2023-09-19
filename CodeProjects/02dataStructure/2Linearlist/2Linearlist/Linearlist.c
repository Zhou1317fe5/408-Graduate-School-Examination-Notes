#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// http://data.biancheng.net/view/296.html
 

/*˳���*/

// ���嶯̬��
#include <stdlib.h>
#define InitSize 100
typedef struct{
	int* data;
	int MaxSize;
	int length;
}SeqList;

//��ʼ��
void InitList(SeqList* L) {
	//��ma11oc��������һƬ�����Ĵ洢�ռ�
	L->data = (int*)malloc(InitSize * sizeof(int));
	L->length = 0;
	L->MaxSize = InitSize;
}



// �������
#include  <stdbool.h>
bool ListInsert1(SeqList* L, int i, int e)
{
	// �ж�i�ķ�Χ�Ƿ���Ч
	if (i<1 || i>L->length + 1) { // length+1Ϊ��β
		return false;
	}

	// �жϵ�ǰ�ռ��Ƿ��Ѿ�����
	if (L->length > L->MaxSize) {
		return false;
	}

	for (int j = L->length - 1; j >= i-1; j--)
	{
		L->data[j + 1] = L->data[j];
	}
	L->data[i - 1] = e;
	(L->length)++;
	return true;
}


// ��������޸�
/*���ڲ���λ��Ϊ L->length + 1������β������������˴���������ѭ����ʹ������ͬ��������ʹ�ô�����Ӽ�ࡣ*/
bool ListInsert2(SeqList* L, int i, int e)
{
	// �ж�i�ķ�Χ�Ƿ���Ч
	if (i<1 || i>L->length + 1) { // length+1Ϊ��β
		return false;
	}

	// �жϵ�ǰ�ռ��Ƿ��Ѿ�����
	if (L->length >= L->MaxSize) {
		return false;
	}

	for (int j = L->length; j >= i; j--)
	{
		L->data[j] = L->data[j - 1];
	}
	L->data[i - 1] = e;
	(L->length)++;
	return true;
}

// ɾ������
	//��λɾ��
bool ListDelete(SeqList* L, int i, int* e) {
	if (i<1 || i>L->length)
		return false;

	*e = L->data[i - 1];
	for (int j = i; j < L->length; j++)
		L->data[j - 1] = L->data[j];

	L->length--;
	return true;
}


// ���Ҳ���
	// ��ֵ����
int LocateElem(SeqList* L, int e) {
	for (int i = 0; i < L->length; i++)
		if (L->data[i] == e)
			return i+1;
	return 0;
}



//���ӿռ��С
void IncreaseSize(SeqList* L, int len) {
	// �����ɱ�
	int* p = L->data;
	// ���ӿռ�
	L->data= (int*)malloc((L->MaxSize + len) * sizeof(int));
	// �������ݵ��±�
	for (int i = 0; i < L->length; i++)
	{
		L->data[i] = p[i];
	}
	L->MaxSize +=  len; //˳�����󳤶�����len
	free(p);
}

//���˳�����Ԫ�صĺ���
void displayList(SeqList *L) {
	int i;
	for (i = 0; i < L->length; i++) {
		printf("%d ", L->data[i]);
	}
	printf("\n");
}

int main()
{
	// ˳���
	SeqList L={ NULL,0,0 }; 
	printf("�������\n");
	InitList(&L);
	printf("��ʼ���ɹ�\n");
	ListInsert2(&L, 1, 1);
	ListInsert2(&L, 2, 2);
	printf("����ɹ�\n");
	printf("��������Ϊ��");
	displayList(&L);
	printf("length��%d\n", L.length);
	printf("MaxSize_before��%d\n", L.MaxSize);
	IncreaseSize(&L, 5);
	printf("���ӿռ�ɹ�\n");
	printf("MaxSize_after��%d\n", L.MaxSize);

	int e = 0;
	ListDelete(&L, 1, &e);
	printf("ɾ���ɹ�������ֵΪ%d\n", e);

	int i;
	i=LocateElem(&L, 2);
	if (i != 0)
		printf("���ҳɹ���λ��Ϊ%d\n", i);
	else
		printf("δ�ҵ�");




	




	return 0;
}


