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
	
	
	for (int i = 0; i < len; i++) {
		Sub->data[i] = S.data[i + pos];
	}
	Sub->length = len;
}
//������

//��ղ���

//���ٴ�