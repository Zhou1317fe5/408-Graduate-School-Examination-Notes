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
	
	for (int i = pos; i < pos+len; i++) 
		Sub->data[i-pos+1] = S.data[i];
	Sub->length = len;
	return true;
}
//串联串

// 定位操作
int Index(String S, String T) {
	if (S.length < T.length)
		return 0;

	
	for (int i = 0; i < S.length; i++) {
		String* Sub;
		SubString(Sub, S, i + 1, T.length);
		if (StrCompare(*Sub, T) == 0)
			return i + 1;
	}
	return 0;
}

int Index2(String S, String T) {
	int i = 1, n = S.length, m = T.length;
	String* Sub;
	while (i < n - m + 1) {
		SubString(Sub, S, i, m);
		if (StrCompare(*Sub, T) != 0) ++i;
		else return i;
	}
	return 0;
}

//清空操作

//销毁串