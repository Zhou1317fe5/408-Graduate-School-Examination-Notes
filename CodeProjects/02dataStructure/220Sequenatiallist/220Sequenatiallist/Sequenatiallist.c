#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// http://data.biancheng.net/view/296.html


/*顺序表*/

// 定义动态表
#define InitSize 800
typedef struct {
	int* data;
	int MaxSize;
	int length;
}SeqList;

//初始化
void InitList(SeqList* L) {
	//用ma11oc函数申请一片连续的存储空间
	L->data = (int*)malloc(InitSize * sizeof(int));
	L->length = 0;
	L->MaxSize = InitSize;
}



// 插入操作
#include  <stdbool.h>
bool ListInsert1(SeqList* L, int i, int e)
{
	// 判断i的范围是否有效
	if (i<1 || i>L->length + 1) { // length+1为表尾
		return false;
	}

	// 判断当前空间是否已经满了
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


// 插入操作修改
/*对于插入位置为 L->length + 1（即表尾）的情况进行了处理，并且在循环中使用了相同的索引，使得代码更加简洁。*/
bool ListInsert2(SeqList* L, int i, int e)
{
	// 判断i的范围是否有效
	if (i<1 || i>L->length + 1) { // length+1为表尾
		return false;
	}

	// 判断当前空间是否已经满了
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

// 删除操作
	//按位删除
bool ListDelete(SeqList* L, int i, int* e) {
	if (i<1 || i>L->length)
		return false;

	*e = L->data[i - 1];
	for (int j = i; j < L->length; j++)
		L->data[j - 1] = L->data[j];

	L->length--;
	return true;
}


// 查找操作
	// 按值查找
int LocateElem(SeqList* L, int e) {
	for (int i = 0; i < L->length; i++)
		if (L->data[i] == e)
			return i + 1;
	return 0;
}



//增加空间大小
void IncreaseSize(SeqList* L, int len) {
	// 拷贝旧表
	int* p = L->data;
	// 增加空间
	L->data = (int*)malloc((L->MaxSize + len) * sizeof(int));
	// 复制数据到新表
	for (int i = 0; i < L->length; i++)
	{
		L->data[i] = p[i];
	}
	L->MaxSize += len; //顺序表最大长度增加len
	free(p);
}

//输出顺序表中元素的函数
void displayList(SeqList* L) {
	int i;
	for (i = 0; i < L->length; i++) {
		printf("%d ", L->data[i]);
	}
	printf("\n");
}


// 王道223课后题01
bool DelMinElem(SeqList* L, int e) {
	if (L->length == 0)
		return false;

	int	Min = L->data[0]; //最小值
	int index = 0; // 最小值索引
	for (int i = 0; i < L->length; i++)
		if (L->data[i] < Min) {
			Min = L->data[i];
			index = i;
		}

	L->data[index] = L->data[L->length - 1]; // 交换元素，即删除 填补
	L->length--;
	return true;

}

// 王道223课后题02
void ReverseList(SeqList* L) {
	for (int i = 0; i <= (L->length - 1) / 2; i++) {

		int temp = L->data[i];
		L->data[i] = L->data[L->length - 1 - i];
		L->data[L->length - 1 - i] = temp;
	}

}

// 王道223课后题03
bool DeleteElemX(SeqList* L, int x) {
	int k = 0;
	for (int i = 0; i < L->length; i++)
		if (L->data[i] != x) {
			L->data[k] = L->data[i];
			k++;
		}
	L->length = k;
}

// 王道223课后题04
/* 错误
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

/*看完思路后第一版
* 错误不能先修改表的长度;第二三个if判断条件错误，第二个if都会进入语句内
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
	if (indexS == -1 || indexT == -1) // 所有元素都小于s 返回
		return false;
	for (int i = indexT, j = indexS; i < L->length; i++, j++) {
		L->data[j] = L->data[i];
	}
	L->length = L->length - (indexT - indexS);
	return true;
}

// 课本实现
bool Del_s_t(SeqList* L, int s, int t) {
	int i, j;
	if (s >= t || L->length == 0)
		return false;
	for (i=0; L->data[i] < s && i < L->length; i++); // 找到第一个大于等于s的值
	if (i >= L->length) // 所有元素均小于s 返回
		return false;
	for (j = i; L->data[j] <= t && j < L->length; j++); // 找到第一个大于t的值
	for (; j < L->length; i++, j++)
		L->data[i] = L->data[j];

	L->length = i;
	return true;
}

// 王道223课后题05
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
 // 课本实现
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


// 王道223课后题06
//bool DeleteRepeat(SeqList* L) {
//	if (L->length == 0)
//		return false;
//	int i, k = 0;
//	for(i=1;i<L->length;i++)
//		L->data[i] // 当前元素
//}

//课本实现
bool Delete_Same(SeqList* L) {
	if (L->length == 0)
		return false;
	int i, j; //i存储第一个不相同的元素，j为工作指针
	for (i = 0, j = 1; j < L->length; j++)
		if (L->data[i] != L->data[j]) //查找下一个与上个元素值不同的元素
			L->data[++i] = L->data[j]; //找到后，将元素前移
	L->length = i + 1;
	return true;

}

// 王道223课后题07
bool MergeList(SeqList* A, SeqList* B, SeqList* MergeList) {
	//冒泡解法

	if (A->length == 0 || A->length == 0)
		return false;
	int k = 0; //MergeList索引
	for (int i = 0; i < A->length; i++) {
		MergeList->data[k] = A->data[i];
		k++;
	}

	for (int i = 0; i < B->length; i++) {
		MergeList->data[k] = B->data[i];
		k++;
	}

	MergeList->length = A->length + B->length;

	for (int i = 0; i < MergeList->length - 1; i++)//总轮数
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

	//课本实现
//bool Merge(SeqList A, SeqList B, SeqList* C) { // 不改变A B的值
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

	while(i<A.length) // A剩余
		C->data[k++] = A.data[i++];

	while (j < B.length) // B剩余
		C->data[k++] = A.data[j++];

	C->length = k;
	return true;
}




// 王道223课后题08

//课本实现
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
	Reverse(A, 0, m + n - 1, arraySize);//n n-1 n-2 ··· 2 1 m m-1 m-2 ··· 2 1
	Reverse(A, 0, n - 1, arraySize);//1 2 ···n-1 n      m m-1···2 1
	Reverse(A, n, m + n - 1, arraySize);//1 2 ···n-1 n      1 2 ··· m-1 m
}

// 王道223课后题09
bool Search(SeqList* L, int x) {
	if (L->length == 0)
		return false;
	int  i = 0;
	for (i; i < L->length; i++) { 
		// 找到，交换值
		if (L->data[i] == x) {
			L->data[i] = L->data[i + 1];
			L->data[i + 1] = x;
			break;
		}
		// 未找到 返回第一个大余x的下标
		if (L->data[i] > x) {
			// 加上元素x后长度大于MaxSize,返回
			if (L->length + 1 > L->MaxSize)
				return false;
			// 插入元素
			for (int j = L->length; j > i; j--) {
				L->data[j] = L->data[j - 1];
			}
			L->data[i] = x;
			L->length += 1;
			break;
		}
	}
}

// 课本实现
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

// 王道223课后题10
//课本实现
/*有误
* void Reverse2(int A[], int start,int end) { // start 和 end 为下标
	int i, temp;
	for (i = 0; i < (start+end) / 2; i++) {
		temp = A[start+i];
		A[start + i]=A[end -i];
		A[end - i]=temp;
	}
}

void Converse(int A[], int n, int p) {
	Reverse2(A,0,n-1);
	Reverse2(A,0,n-1-p);
	Reverse2(A,n-p,n-1);
}
*/



void Reverse2(int A[], int start, int end) { // start 和 end 为下标
	int i, temp;
	for (i = 0; i < (end-start+1) / 2; i++) {
		temp = A[start + i];
		A[start + i] = A[end - i];
		A[end - i] = temp;
	}
}


void Converse(int A[], int n, int p) {
	Reverse2(A, 0, p - 1);
	Reverse2(A, p, n - 1);
	Reverse2(A, 0, n - 1);
}



// 王道223课后题11
void Merge2(int* A[], int* B[], int *C[], int sizeA,int  sizeB)
{
	int i=0, j=0, k = 0;
	while (i < sizeA && j < sizeB) {
		if (A[i] > B[j])
			C[k++] = B[j++];
		else
			C[k++] = A[i++];
	}

	while (i < sizeA) {//A剩余
		C[k++] = A[i++];
	}

	while (j < sizeB) {
		C[k++] = B[j++];
	}
}
int find(int* A[], int* B[], int *C[], int sizeA, int  sizeB) {
	Merge2(A, B, C, sizeA,   sizeB);
	return C[(sizeA+ sizeB-1) / 2];

}

// 课本实现
int M_Search(int A[], int B[], int n) 
{
	int lefta = 0, righta = n - 1, mida, leftb = 0, rightb = n - 1, midb;// 分别表示A B的首位 末尾 中位下标
	while (lefta != righta || leftb != rightb)
	{
		mida = (lefta + righta) / 2;
		midb = (leftb + rightb) / 2;
		if (A[mida] == B[midb])
			return A[mida];
		if (A[mida] < B[midb])
		{
			if ((lefta + rightb) % 2 == 0)
			{ //元素个数为奇数
				lefta = mida;
				rightb = midb;
			}
			else
			{//元素个数为偶数
				lefta = mida + 1;
				rightb = midb;
			}
		}
		else
		{
			if ((lefta + rightb) % 2 == 0)
			{ //元素个数为奇数
				righta = mida;
				leftb = midb;
			}
			else
			{//元素个数为偶数
				righta = mida;
				leftb = midb + 1;
			}

		}
		return A[mida] < B[midb] ? A[mida] : B[midb];
	}

}


// 王道223课后题12
int Find_X(int A[],int n)
{
	for (int i = 0; i < n; i++) 
	{
		int count = 0;
		for (int j = 0; j < n; j++)
		{
			
			if (A[j] == A[i])
				count++;
		}
		if (count > n / 2)
			return A[i];
	}
	return -1;
}

//课本实现
int Majority(int A[], int n)
{
	int i, c, count = 1;				//c用来保存候选主元素，count用来计数
	c = A[0];							// 设置A[0]为候选主元素
	for (i = 1; i < n; i++)				//查找候选主元素
		if (A[i] == c)
			count++;					// 对A中的候选主元素计数
		else
			if (count > 0)				// 处理不是候选主元素的情况
				count--;
			else						// 更换候选主元素，重新计数
			{
				c = A[i];
				count = 1;
			}
	if (count > 0)
		for (i = count = 0; i < n; i++)	//统计候选主元素的实际出现次数
			if (A[i] == c)
				count++;
	if (count > n / 2)return c;			// 确认候选主元素
	else return -1;						//不存在主元素
}
// 王道223课后题13
//课本实现
int findMissMin(int A[], int n)
{
	int* B = (int*)malloc(n * sizeof(int));
	memset(B, 0, sizeof(int) * n);

	for (int i = 0; i < n; i++)
	{
		if (A[i] > 0 && A[i] <= n)
			B[A[i]] = 1;
	}
	int i;
	for (i = 1; i <= n; i++)
		if (0 == B[i]) break;
	return i;
}

// 王道223课后题14
#include <math.h>
int minDistance(int A[], int B[],int a,int b)
{
	//求AB最小
	int mindistance = abs(A[0]-B[0]);
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
			mindistance=abs(A[i] - B[j]) < mindistance ? abs(A[i] - B[j]) : mindistance;
	}

	return mindistance;
}

int findMinDistance(int A[], int B[],int C[], int a, int b,int c)
{
	int ab = minDistance(A, B, a, b);
	int bc = minDistance(B, C, b, c);
	int ca = minDistance(C, A, c, a);

	return ab + bc + ca;
}

//课本实现
#define INI_MAX 0x7fffffff
int abs_(int a)
{
	if (a < 0) return -a;
	else return a;
}

int findMinoTrip(int A[], int length_a, int B[], int length_b, int C[],int length_c)
{
	int i = 0, j=0, k = 0, D_min = INI_MAX, D;
	while (i < length_a && j < length_b && k < length_c)
	{
		D = abs_(A[i] - B[j]) + abs_(B[j] - C[k]) + abs_(C[k] - A[i]);
		if (D < D_min) D_min = D;
		if (A[i] < B[j] && A[i] < C[k]) i++;
		else if (B[j] < A[i] && B[j] < C[k]) j++;
		else k++;
	}

	return D_min;
}


// main()函数
int main()
{
	// 顺序表
	SeqList L = { NULL,0,0 };
	printf("声明完成\n");
	InitList(&L);
	printf("初始化成功\n");
	ListInsert2(&L, 1, 2);
	ListInsert2(&L, 2, 3);
	ListInsert2(&L, 3, 4);
	ListInsert2(&L, 4, 6);
	ListInsert2(&L, 5, 9);
	ListInsert2(&L, 6, 10);
	ListInsert2(&L, 7, 11);
	ListInsert2(&L, 8, 12);
	printf("插入成功\n");
	printf("L表中数据为：");
	displayList(&L);
	//printf("length：%d\n", L.length);
	//printf("MaxSize_before：%d\n", L.MaxSize);
	//IncreaseSize(&L, 5);
	//printf("增加空间成功\n");
	//printf("MaxSize_after：%d\n", L.MaxSize);

	//int e = 0;
	//ListDelete(&L, 1, &e);
	//printf("删除成功，返回值为%d\n", e);

	/*int i;
	i = LocateElem(&L, 2);
	if (i != 0)
		printf("查找成功，位序为%d\n", i);
	else
		printf("未找到");

	printf("\n");*/

	//课后题
	//01
	//int j;
	//j = DelMinElem(&L, &j);
	//printf("删除最小值为：%d\n", j);

	//02
	//ReverseList(&L);
	//printf("表中数据为：");
	//displayList(&L);

	//03
	//DeleteElemX(&L, 2);
	//printf("表中数据为：");
	//displayList(&L);

	//04
	//bool b = DeleteBetwST(&L, 3, 9);
	//bool b = Del_s_t(&L, 3, 9);
	//printf("04返回%d 表中数据为：", b);
	//displayList(&L);


	//05
	//bool c = Del_s_t_2(&L, 3, 9);
	//bool b = Del_s_t(&L, 3, 9);
	//printf("05返回%d 表中数据为：", c);
	//displayList(&L);

	// 06
	//bool d=Delete_Same(&L);
	//printf("06返回%d 表中数据为：", d);
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
	//printf("A表中数据为：");
	//displayList(&A);


	////B
	//SeqList B = { NULL,0,0 };
	//InitList(&B);
	//ListInsert2(&B, 1, 1);
	//ListInsert2(&B, 2, 2);
	//ListInsert2(&B, 3, 8);
	//ListInsert2(&B, 4, 10);

	//printf("B表中数据为：");
	//displayList(&B);

	////MergeList
	//SeqList List = { NULL,0,0 };
	//InitList(&List);

	//MergeList(&A, &B, &List);
	//printf("List表中数据为：");
	//displayList(&List);



	//09
	//int x = 5;
	//Search(&L, x);
	//SearchExchangeInsert(&L,x);
	//printf("插入数字为%d,L表中数据为：",x);
	//displayList(&L);

	//10
	//int A[] = { 2,3,4,5,6,7,8 };
	//printf("数组为：");
	//for (int i = 0; i < 7; i++) {
	//	printf("%d ", A[i]);
	//}

	//Converse(A,7,2);
	//printf("循环左移后数组为：");
	//for (int i = 0; i < 7; i++) {
	//	printf("%d ", A[i]);
	//}



	//11
	//int A[] = { 1,4,6,8,12,16 };
	//int B[] = { 3,5,9,13,15,17 };
	//int C[12] = {0,0};

	//int sizeA = sizeof(A) / sizeof(A[0]);
	//int sizeB = sizeof(B) / sizeof(B[0]);
	//int ret = find(&A, &B, &C, sizeA, sizeB);
	//printf("AB中位数为：%d\n", ret);

	//printf("C数组为：");
	//for (int i = 0; i < 12; i++) {
	//	printf("%d ", C[i]);
	//}


	//课本实现
	//int ret=M_Search(A, B, 6);
	//printf("11ret=%d\n", ret);



	//12
	//int A[] = { 2,2,2,1,12, 2};
	//int ret = Find_X(A, 6);
	//printf("12 ret = %d\n", ret);


	//13
	//int A[] = { 2,2,2,1,12, 2};
	//printf("13 未出现的最小正整数为：%d\n", findMissMin(A, 6));


	//14
	int A[] = { -1,0,9};
	int B[] = { -25,-10,10,11};
	int C[] = { 2,9,17,30,41};
	//int ret = findMinDistance(A,B,C,3,4,5);
	//printf("14三元组最小距离为：%d\n", ret);

	//课本实现
	int ret = findMinoTrip(A,3,B,4,C,5);
	printf("14三元组最小距离为：%d\n", ret);

	return 0;
}


