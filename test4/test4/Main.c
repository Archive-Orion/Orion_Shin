//�Է�
//�Է��� ù�ٿ��� �׽�Ʈ ���̽��� �� c(1 <= c <= 100)�� �־����ϴ�.
//�� �� c�ٿ� �� �ϳ��� ���ڿ��� �׽�Ʈ ���̽��� �־����ϴ�.
//�� ���ڿ��� ���� ���� ��() {}[]���� ���Ե� ���ڷθ� �־����� ���̴� 1~10000�����Դϴ�.
//���
//�� �׽�Ʈ ���̽� ����, �־��� ��ȣ ���ڿ��� ¦�� �� �´´ٸ� ��yes����, �� �´´ٸ�
//��no���� �� �ٿ� ��� �մϴ�

//�����Է�
//3
//() ()
//({ [}] )
//({ }[() { }])
//���� ���
//yes
//no
//yes
#define _CRT_SECURE_NO_WARNINGS
#define TRUE		1
#define FALSE		0
#define STACK_LEN	10000
#define T			0
#define F			1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char Data;

typedef struct {
	Data stack[STACK_LEN];
	int top;
} Stack;

void StackInit(Stack* pstack);
int SIsEmpty(Stack* pstack);

void SPush(Stack* pstack, Data data);
Data SPop(Stack* pstack);
Data SPeek(Stack* pstack);

int Compare(Stack* pstack, Data data);
void Garbage(Stack* pstack);

int main(void) {
	int n, i, len;																	//n: �׽�Ʈ Ƚ��, i: �ݺ��� �ε���, len: �� ���ڿ� ����
	char str[STACK_LEN];															//1���� ���ڿ��迭
	int check[100] = { T };															//YES OR NO üũ�ϱ� ���� �迭

	Stack stack;																	//��ȣ �˻� ���� ���� ����

	printf("���� �Է�\n");															//�׽�Ʈ Ƚ�� �Է�
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		StackInit(&stack);

		scanf("%s", str);															//��ȣ �Է�

		len = strlen(str);															//�� ���ڿ��� ����

		for (int j = 0; j < len; j++) {												//j: ���ڿ��� ���
			if (str[j] == '(' || str[j] == '{' || str[j] == '[')
				SPush(&stack, str[j]);												//������ȣ��� ���ÿ� �������
			else if (str[j] == ')' || str[j] == '}' || str[j] == ']') {				//������ȣ��� ���ǹ�����
				if (Compare(&stack, str[j])) SPop(&stack);							//¦�� �´ٸ� ���ÿ��� ��������
				else {																//¦�� �����ʴٸ� check�迭�� F�Է��ϰ� �ݺ��� ����
					check[i] = F;
					break;
				}
			}
		}
		if (!SIsEmpty(&stack)) check[i] = F;										//�ݺ����� �� ���ȴµ��� ���ÿ� ��ȣ�� �����ִٸ� F
	}
	for (i = 0; i < n; i++) {
		if (check[i] == T)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

void StackInit(Stack* pstack) {
	pstack->top = -1;
}
int SIsEmpty(Stack* pstack) {
	if (pstack->top == -1) return TRUE;
	else return FALSE;
}

void SPush(Stack* pstack, Data data) {
	if (pstack->top == STACK_LEN - 1) {
		printf("ERROR\n");
		return;
	}

	pstack->top++;
	pstack->stack[pstack->top] = data;
}
Data SPop(Stack* pstack) {
	int rtop;

	/*if (SIsEmpty(pstack)) {
		printf("memory error\n");
		return -1;
	}*/

	rtop = pstack->top;
	pstack->top--;

	return pstack->stack[rtop];
}
Data SPeek(Stack* pstack) {
	/*if (SIsEmpty(pstack)) {
		printf("memory error\n");
		return -1;
	}*/

	return pstack->stack[pstack->top];
}

int Compare(Stack* pstack, Data data) {
	if (SPeek(pstack) == '(' && data == ')') return TRUE;
	else if (SPeek(pstack) == '{' && data == '}') return TRUE;
	else if (SPeek(pstack) == '[' && data == ']') return TRUE;
	else return FALSE;
}

/*void Garbage(Stack* pstack) {
	while (!SIsEmpty(pstack))
		SPop(pstack);
}*/