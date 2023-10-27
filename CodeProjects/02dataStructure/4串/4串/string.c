#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

// https://blog.csdn.net/HorseCoder/article/details/112215592

// 定长顺序存储
/*
#define MAXLEN 255
typedef struct {
	char ch[MAXLEN];
	int length;
}HString;
*/


// 堆存储

typedef struct {
	char* data; //按串长分配存储区，ch指向串的基地址
	int length;
}String;


//串的基本操作
//初始化 
void InitStr(String* S) {
	S->data = (char*)malloc(sizeof(char));
	S->length = 0;
	for (int i = 0; i < S->length; i++) {
		S->data[i] = '0';
	}
}
//赋值操作
bool StrAssign(String str, char s[]) {
	
	return true;
}
//复制操作

//判空操作
bool StrEmpty(String S) {
	return S.length == 0;
}
//比较操作
int StrCompare(String S, String T) {
	for (int i = 0; i < S.length && i < T.length; i++) {
		if (S.data[i] != T.data[i]) {
			return S.data[i] - T.data[i];
		}
		// 若扫描所有的都相等 长度大的字符串更长
	}
	return S.length - T.length;
}
//求串长

//求子串
bool SubString(String* Sub, String S, int pos, int len) {
	if (pos + len - 1 > S.length)
		return false;
	
	
	for (int i = 0; i < len; i++) {
		Sub->data[i] = S.data[i + pos];
	}
	Sub->length = len;
}
//串联串

//清空操作

//销毁串