#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// http://data.biancheng.net/view/296.html
 

/*顺序表*/

// 定义动态表
#include <stdlib.h>
#define InitSize 100
typedef struct{
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

	for (int j = L->length - 1; j >= i-1; j--)
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
			return i+1;
	return 0;
}



//增加空间大小
void IncreaseSize(SeqList* L, int len) {
	// 拷贝旧表
	int* p = L->data;
	// 增加空间
	L->data= (int*)malloc((L->MaxSize + len) * sizeof(int));
	// 复制数据到新表
	for (int i = 0; i < L->length; i++)
	{
		L->data[i] = p[i];
	}
	L->MaxSize +=  len; //顺序表最大长度增加len
	free(p);
}

//输出顺序表中元素的函数
void displayList(SeqList *L) {
	int i;
	for (i = 0; i < L->length; i++) {
		printf("%d ", L->data[i]);
	}
	printf("\n");
}

int main()
{
	// 顺序表
	SeqList L={ NULL,0,0 }; 
	printf("声明完成\n");
	InitList(&L);
	printf("初始化成功\n");
	ListInsert2(&L, 1, 1);
	ListInsert2(&L, 2, 2);
	printf("插入成功\n");
	printf("表中数据为：");
	displayList(&L);
	printf("length：%d\n", L.length);
	printf("MaxSize_before：%d\n", L.MaxSize);
	IncreaseSize(&L, 5);
	printf("增加空间成功\n");
	printf("MaxSize_after：%d\n", L.MaxSize);

	int e = 0;
	ListDelete(&L, 1, &e);
	printf("删除成功，返回值为%d\n", e);

	int i;
	i=LocateElem(&L, 2);
	if (i != 0)
		printf("查找成功，位序为%d\n", i);
	else
		printf("未找到");




	




	return 0;
}


