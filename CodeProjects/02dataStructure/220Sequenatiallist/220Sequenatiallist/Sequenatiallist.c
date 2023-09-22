#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// http://data.biancheng.net/view/296.html


/*˳���*/

// ���嶯̬��
#define InitSize 800
typedef struct {
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

	for (int j = L->length - 1; j >= i - 1; j--)
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
			return i + 1;
	return 0;
}



//���ӿռ��С
void IncreaseSize(SeqList* L, int len) {
	// �����ɱ�
	int* p = L->data;
	// ���ӿռ�
	L->data = (int*)malloc((L->MaxSize + len) * sizeof(int));
	// �������ݵ��±�
	for (int i = 0; i < L->length; i++)
	{
		L->data[i] = p[i];
	}
	L->MaxSize += len; //˳�����󳤶�����len
	free(p);
}

//���˳�����Ԫ�صĺ���
void displayList(SeqList* L) {
	int i;
	for (i = 0; i < L->length; i++) {
		printf("%d ", L->data[i]);
	}
	printf("\n");
}


// ����223�κ���01
bool DelMinElem(SeqList* L, int e) {
	if (L->length == 0)
		return false;

	int	Min = L->data[0]; //��Сֵ
	int index = 0; // ��Сֵ����
	for (int i = 0; i < L->length; i++)
		if (L->data[i] < Min) {
			Min = L->data[i];
			index = i;
		}

	L->data[index] = L->data[L->length - 1]; // ����Ԫ�أ���ɾ�� �
	L->length--;
	return true;

}

// ����223�κ���02
void ReverseList(SeqList* L) {
	for (int i = 0; i <= (L->length - 1) / 2; i++) {

		int temp = L->data[i];
		L->data[i] = L->data[L->length - 1 - i];
		L->data[L->length - 1 - i] = temp;
	}

}

// ����223�κ���03
bool DeleteElemX(SeqList* L, int x) {
	int k = 0;
	for (int i = 0; i < L->length; i++)
		if (L->data[i] != x) {
			L->data[k] = L->data[i];
			k++;
		}
	L->length = k;
}

// ����223�κ���04
/* ����
* bool DeleteBetwST(SeqList* L,int s,int t) {
	if (s >= t || L->length == 0)
		return false;
	int k = 0;
	for (int i = 0; i < L->length; i++) {
		if (L->data[i] <= s && L->data[i] >= t) {
			L->data[k] = L->data[i];
			k++;
		}
	}
	return true;
}
*/

/*����˼·���һ��
* ���������޸ı�ĳ���;�ڶ�����if�ж��������󣬵ڶ���if������������
* bool DeleteBetwST(SeqList* L, int s, int t) {
	if (s >= t && L->length == 0)
		return false;
	int indexS = 0;
	int indexT = 0;

	for (int i = 0; i < L->length; i++) {
		if(L->data[i] >= s)
			indexS =i;
		if(L->data[i] >= t&&i>indexS)
			indexT = i;
	}
	L->length = L->length - (indexT - indexS);
	for (indexT; indexT < L->length; indexT++) {
		L->data[indexS] = L->data[indexT];
		indexS++;
		L->length++;
	}
	return true;
}
*/

bool DeleteBetwST(SeqList* L, int s, int t) {
	if (s >= t || L->length == 0)
		return false;
	int indexS = -1;
	int indexT = -1;
	for (int i = 0; i < L->length; i++) {
		if (L->data[i] >= s && indexS == -1)
			indexS = i;
		if (L->data[i] > t && indexT == -1 && indexS != -1)
			indexT = i;
	}
	if (indexS == -1 || indexT == -1) // ����Ԫ�ض�С��s ����
		return false;
	for (int i = indexT, j = indexS; i < L->length; i++, j++) {
		L->data[j] = L->data[i];
	}
	L->length = L->length - (indexT - indexS);
	return true;
}

// �α�ʵ��
bool Del_s_t(SeqList* L, int s, int t) {
	int i, j;
	if (s >= t || L->length == 0)
		return false;
	for (i=0; L->data[i] < s && i < L->length; i++); // �ҵ���һ�����ڵ���s��ֵ
	if (i >= L->length) // ����Ԫ�ؾ�С��s ����
		return false;
	for (j = i; L->data[j] <= t && j < L->length; j++); // �ҵ���һ������t��ֵ
	for (; j < L->length; i++, j++)
		L->data[i] = L->data[j];

	L->length = i;
	return true;
}

// ����223�κ���05
bool DeleteBetwST_2(SeqList* L, int s, int t) {
	int* p = L->data;
	int i=0, j=0;
	if (s >= t || L->length == 0)
		return false;
	for (i; i < L->length; i++)
		if (p[i]<s || p[i]>t) {
			L->data[j] = p[i];
			j++;
		}
	L->length = j;
	return true;

}
 // �α�ʵ��
bool Del_s_t_2(SeqList* L, int s, int t) {
	int i = 0, k = 0;
	if (s >= t || L->length == 0)
		return false;
	for (i; i < L->length; i++)
		if (L->data[i] >= s && L->data[i] <= t)
			k++;
		else
			L->data[i - k] = L->data[i];
	L->length -=	k;
	return true;
}


// ����223�κ���06
//bool DeleteRepeat(SeqList* L) {
//	if (L->length == 0)
//		return false;
//	int i, k = 0;
//	for(i=1;i<L->length;i++)
//		L->data[i] // ��ǰԪ��
//}

//�α�ʵ��
bool Delete_Same(SeqList* L) {
	if (L->length == 0)
		return false;
	int i, j; //i�洢��һ������ͬ��Ԫ�أ�jΪ����ָ��
	for (i = 0, j = 1; j < L->length; j++)
		if (L->data[i] != L->data[j]) //������һ�����ϸ�Ԫ��ֵ��ͬ��Ԫ��
			L->data[++i] = L->data[j]; //�ҵ��󣬽�Ԫ��ǰ��
	L->length = i + 1;
	return true;

}

// ����223�κ���07
bool MergeList(SeqList* A, SeqList* B, SeqList* MergeList) {
	//ð�ݽⷨ

	if (A->length == 0 || A->length == 0)
		return false;
	int k = 0; //MergeList����
	for (int i = 0; i < A->length; i++) {
		MergeList->data[k] = A->data[i];
		k++;
	}

	for (int i = 0; i < B->length; i++) {
		MergeList->data[k] = B->data[i];
		k++;
	}

	MergeList->length = A->length + B->length;

	for (int i = 0; i < MergeList->length - 1; i++)//������
	{
		int j;
		for (j = 0; j < MergeList->length - i - 1; j++) {
			if (MergeList->data[j] > MergeList->data[j + 1]) {
				int temp = MergeList->data[j];
				MergeList->data[j] = MergeList->data[j + 1];
				MergeList->data[j + 1] = temp;
			}
		}
	}
	return true;
}

	//�α�ʵ��
//bool Merge(SeqList A, SeqList B, SeqList* C) { // ���ı�A B��ֵ
//	if (A.length + B.length > C->MaxSize)
//		return false;
//	int i = 0, j = 0, k = 0;
//	while (i < A.length && j < B.length) {
//		if (A.data[i] < B.data[j]) {
//			C->data[k] = A.data[i];
//			k++;
//			i++;
//		}
//		else
//			C->data[k++] = B.data[j++];
//
//	}
//	while(i<A.length)
//		C->data[k++]= A.data[i++];
//
//	while (j < B.length)
//		C->data[k++] = B.data[j++];
//	C->length = k;
//	return true;
//}


bool Merge(SeqList A, SeqList B, SeqList* C) {
	if (A.length + B.length > C->MaxSize)
		return false;
	int i = 0,j = 0, k = 0;
	while (i < A.length && j < B.length) {
		if (A.data[i] < B.data[j])
			C->data[k++] = A.data[i++];
		else
			C->data[k++] = B.data[j++];
	}

	while(i<A.length) // Aʣ��
		C->data[k++] = A.data[i++];

	while (j < B.length) // Bʣ��
		C->data[k++] = A.data[j++];

	C->length = k;
	return true;
}




// ����223�κ���08

//�α�ʵ��
void Reverse(int A[], int left, int right, int arraySize) {
	if (left >= right || right >= arraySize)
		return false;
	int mid = (left + right) / 2;
	for (int i = 0; i < mid; i++)
	{
		int temp = A[left + i];
		A[left + i] = A[right - i];
		A[right - i]=temp;
	}

}

void Exchange(int A[], int m, int n, int arraySize) {
	Reverse(A, 0, m + n - 1, arraySize);//n n-1 n-2 ������ 2 1 m m-1 m-2 ������ 2 1
	Reverse(A, 0, n - 1, arraySize);//1 2 ������n-1 n      m m-1������2 1
	Reverse(A, n, m + n - 1, arraySize);//1 2 ������n-1 n      1 2 ������ m-1 m
}

// ����223�κ���09
bool Search(SeqList* L, int x) {
	if (L->length == 0)
		return false;
	int  i = 0;
	for (i; i < L->length; i++) { 
		// �ҵ�������ֵ
		if (L->data[i] == x) {
			L->data[i] = L->data[i + 1];
			L->data[i + 1] = x;
			break;
		}
		// δ�ҵ� ���ص�һ������x���±�
		if (L->data[i] > x) {
			// ����Ԫ��x�󳤶ȴ���MaxSize,����
			if (L->length + 1 > L->MaxSize)
				return false;
			// ����Ԫ��
			for (int j = L->length; j > i; j--) {
				L->data[j] = L->data[j - 1];
			}
			L->data[i] = x;
			L->length += 1;
			break;
		}
	}
}

// �α�ʵ��
void SearchExchangeInsert(SeqList* L, int x) {
	int low = 0, high = L->length - 1, mid = 0;
	while (low < high) {
		mid = (low + high) / 2;
		if (L->data[mid] == x)
			break;
		else if (L->data[mid] > x) high = mid - 1;
		else low = mid + 1;
	}

	if (L->data[mid] == x && mid != L->length - 1) {
		int temp = L->data[mid];
		L->data[mid] = L->data[mid + 1];
		L->data[mid] = temp;
	}

	if (low > high) {
		int i = 0;
		for(i= L->length - 1;i>high;i--)
			L->data[i+1] = L->data[i];
		L->data[i + 1] = x;
	}
	
}



int main()
{
	// ˳���
	SeqList L = { NULL,0,0 };
	printf("�������\n");
	InitList(&L);
	printf("��ʼ���ɹ�\n");
	ListInsert2(&L, 1, 2);
	ListInsert2(&L, 2, 3);
	ListInsert2(&L, 3, 4);
	ListInsert2(&L, 4, 6);
	ListInsert2(&L, 5, 9);
	ListInsert2(&L, 6, 10);
	ListInsert2(&L, 7, 11);
	ListInsert2(&L, 8, 12);
	printf("����ɹ�\n");
	printf("L��������Ϊ��");
	displayList(&L);
	//printf("length��%d\n", L.length);
	//printf("MaxSize_before��%d\n", L.MaxSize);
	//IncreaseSize(&L, 5);
	//printf("���ӿռ�ɹ�\n");
	//printf("MaxSize_after��%d\n", L.MaxSize);

	//int e = 0;
	//ListDelete(&L, 1, &e);
	//printf("ɾ���ɹ�������ֵΪ%d\n", e);

	/*int i;
	i = LocateElem(&L, 2);
	if (i != 0)
		printf("���ҳɹ���λ��Ϊ%d\n", i);
	else
		printf("δ�ҵ�");

	printf("\n");*/

	//�κ���
	//01
	//int j;
	//j = DelMinElem(&L, &j);
	//printf("ɾ����СֵΪ��%d\n", j);

	//02
	//ReverseList(&L);
	//printf("��������Ϊ��");
	//displayList(&L);

	//03
	//DeleteElemX(&L, 2);
	//printf("��������Ϊ��");
	//displayList(&L);

	//04
	//bool b = DeleteBetwST(&L, 3, 9);
	//bool b = Del_s_t(&L, 3, 9);
	//printf("04����%d ��������Ϊ��", b);
	//displayList(&L);


	//05
	//bool c = Del_s_t_2(&L, 3, 9);
	//bool b = Del_s_t(&L, 3, 9);
	//printf("05����%d ��������Ϊ��", c);
	//displayList(&L);

	// 06
	//bool d=Delete_Same(&L);
	//printf("06����%d ��������Ϊ��", d);
	//displayList(&L);




	//06
	//A
	//SeqList A = { NULL,0,0 };
	//InitList(&A);
	//ListInsert2(&A, 1, 2);
	//ListInsert2(&A, 2, 3);
	//ListInsert2(&A, 3, 4);
	//ListInsert2(&A, 4, 6);
	//ListInsert2(&A, 5, 9);
	//printf("A��������Ϊ��");
	//displayList(&A);


	////B
	//SeqList B = { NULL,0,0 };
	//InitList(&B);
	//ListInsert2(&B, 1, 1);
	//ListInsert2(&B, 2, 2);
	//ListInsert2(&B, 3, 8);
	//ListInsert2(&B, 4, 10);

	//printf("B��������Ϊ��");
	//displayList(&B);

	////MergeList
	//SeqList List = { NULL,0,0 };
	//InitList(&List);

	//MergeList(&A, &B, &List);
	//printf("List��������Ϊ��");
	//displayList(&List);



	//09
	int x = 5;
	Search(&L, x);
	//SearchExchangeInsert(&L,x);
	printf("��������Ϊ%d,L��������Ϊ��",x);
	displayList(&L);









	return 0;
}


