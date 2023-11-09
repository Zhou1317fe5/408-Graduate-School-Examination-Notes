#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h> 
#include <stdlib.h>

//二叉树的链式存储
typedef struct BiTNode {
	int data; // 数据域
	struct BiTNode* lchild, * rchild; // 左右孩子指针
}BiTNode,*BiTree;



