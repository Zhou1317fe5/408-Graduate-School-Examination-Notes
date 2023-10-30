#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

// https://blog.csdn.net/HorseCoder/article/details/112215592

// ����˳��洢
/*
#define MAXLEN 255
typedef struct {
	char ch[MAXLEN];
	int length;
}HString;
*/


// �Ѵ洢

typedef struct {
	char* data; //����������洢����chָ�򴮵Ļ���ַ
	int length;
}String;


//���Ļ�������
//��ʼ�� 
void InitStr(String* S) {
	S->data = (char*)malloc(sizeof(char));
	S->length = 0;
	for (int i = 0; i < S->length; i++) {
		S->data[i] = '0';
	}
}
//��ֵ����
bool StrAssign(String str, char s[]) {
	
	return true;
}
//���Ʋ���

//�пղ���
bool StrEmpty(String S) {
	return S.length == 0;
}
//�Ƚϲ���
int StrCompare(String S, String T) {
	for (int i = 0; i < S.length && i < T.length; i++) {
		if (S.data[i] != T.data[i]) {
			return S.data[i] - T.data[i];
		}
		// ��ɨ�����еĶ���� ���ȴ���ַ�������
	}
	return S.length - T.length;
}
//�󴮳�

//���Ӵ�
bool SubString(String* Sub, String S, int pos, int len) {
	if (pos + len - 1 > S.length)
		return false;
	
	for (int i = pos; i < pos+len; i++) 
		Sub->data[i-pos+1] = S.data[i];
	Sub->length = len;
	return true;
}
//������

// ��λ����
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

//��ղ���

//���ٴ�