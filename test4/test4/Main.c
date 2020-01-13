//입력
//입력의 첫줄에는 테스트 케이스의 수 c(1 <= c <= 100)가 주어집니다.
//그 후 c줄에 각 하나의 문자열로 테스트 케이스가 주어집니다.
//이 문자열은 공백 없이 “() {}[]”에 포함된 글자로만 주어지며 길이는 1~10000이하입니다.
//출력
//각 테스트 케이스 마다, 주어진 괄호 문자열이 짝이 잘 맞는다면 “yes”를, 안 맞는다면
//“no”를 한 줄에 출력 합니다

//예제입력
//3
//() ()
//({ [}] )
//({ }[() { }])
//예제 출력
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
	int n, i, len;																	//n: 테스트 횟수, i: 반복문 인덱스, len: 각 문자열 길이
	char str[STACK_LEN];															//1차원 문자열배열
	int check[100] = { T };															//YES OR NO 체크하기 위한 배열

	Stack stack;																	//괄호 검사 위한 스택 선언

	printf("예제 입력\n");															//테스트 횟수 입력
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		StackInit(&stack);

		scanf("%s", str);															//괄호 입력

		len = strlen(str);															//각 문자열의 길이

		for (int j = 0; j < len; j++) {												//j: 문자열의 요소
			if (str[j] == '(' || str[j] == '{' || str[j] == '[')
				SPush(&stack, str[j]);												//열린괄호라면 스택에 집어넣음
			else if (str[j] == ')' || str[j] == '}' || str[j] == ']') {				//닫힌괄호라면 조건문ㄱㄱ
				if (Compare(&stack, str[j])) SPop(&stack);							//짝이 맞다면 스택에서 꺼내버림
				else {																//짝이 맞지않다면 check배열에 F입력하고 반복문 나감
					check[i] = F;
					break;
				}
			}
		}
		if (!SIsEmpty(&stack)) check[i] = F;										//반복문을 다 돌렸는데도 스택에 괄호가 남아있다면 F
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