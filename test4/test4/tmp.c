////입력
////입력의 첫줄에는 테스트 케이스의 수 c(1 <= c <= 100)가 주어집니다.
////그 후 c줄에 각 하나의 문자열로 테스트 케이스가 주어집니다.
////이 문자열은 공백 없이 “() {}[]”에 포함된 글자로만 주어지며 길이는 1~10000이하입니다.
////출력
////각 테스트 케이스 마다, 주어진 괄호 문자열이 짝이 잘 맞는다면 “yes”를, 안 맞는다면
////“no”를 한 줄에 출력 합니다
//
////예제입력
////3
////() ()
////({ [}] )
////({ }[() { }])
////예제 출력
////yes
////no
////yes
//#define _CRT_SECURE_NO_WARNINGS
//#define TRUE		1
//#define FALSE		0
//#define STACK_LEN	10000
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef char Data;
//
//typedef struct {
//	Data stack[STACK_LEN];
//	int top;
//} Stack;
//
//void StackInit(Stack* pstack);
//int SIsEmpty(Stack* pstack);
//
//void SPush(Stack* pstack, Data data);
//Data SPop(Stack* pstack);
//Data SPeek(Stack* pstack);
//
//int Compare(Stack* pstack, Data data);
//void Garbage(Stack* pstack);
//
//int main(void) {
//	int n, i, len;																	//n: 테스트 횟수, i: 반복문 인덱스, len: 각 문자열 길이
//	char str[100][10000];															//동적 2차원 문자열배열
//
//	Stack stack;																	//괄호 검사 위한 스택 선언
//
//	StackInit(&stack);
//
//	printf("예제 입력\n");
//	scanf("%d", &n);
//
//	for (i = 0; i < n; i++) {														//n만큼 문자열 입력받음
//		//while (getchar() != '\n');
//		//str[i] = (char*)malloc(10000 * sizeof(char));
//		scanf("%s", str[i]);
//	}
//
//	for (i = 0; i < n; i++) {
//		len = strlen(str[i]);														//각 문자열의 길이
//
//		for (int j = 0; j < len; j++) {												//i: n번째 입력받은 문자열, j: n번째 문자열의 요소
//			if (str[i][j] == '(' || str[i][j] == '{' || str[i][j] == '[')
//				SPush(&stack, str[i][j]);											//열린괄호라면 스택에 집어넣음
//			else if (str[i][j] == ')' || str[i][j] == '}' || str[i][j] == ']') {	//닫힌괄호라면 조건문ㄱㄱ
//				if (Compare(&stack, str[i][j])) SPop(&stack);						//짝이 맞다면 스택에서 꺼내버림
//				else {																//짝이 맞지않다면 NO출력 후 반복문 탈출
//					printf("NO\n");
//					break;
//				}
//			}
//		}
//		if (SIsEmpty(&stack))														//정상적으로 스택이 비워졌다면 YES출력
//			printf("YES\n");
//		else Garbage(&stack);														//아직 찌꺼기가 남아있다면 함수로 스택 비움
//	}																				//왜? 다음 문자열도 검사해야 하니까^^7
//	return 0;
//}
//
//void StackInit(Stack* pstack) {
//	pstack->top = -1;
//}
//int SIsEmpty(Stack* pstack) {
//	if (pstack->top == -1) return TRUE;
//	else return FALSE;
//}
//
//void SPush(Stack* pstack, Data data) {
//	if (pstack->top == STACK_LEN - 1) {
//		printf("ERROR\n");
//		return;
//	}
//
//	pstack->top++;
//	pstack->stack[pstack->top] = data;
//}
//Data SPop(Stack* pstack) {
//	int rtop;
//
//	/*if (SIsEmpty(pstack)) {
//		printf("memory error\n");
//		return -1;
//	}*/
//
//	rtop = pstack->top;
//	pstack->top--;
//
//	return pstack->stack[rtop];
//}
//Data SPeek(Stack* pstack) {
//	/*if (SIsEmpty(pstack)) {
//		printf("memory error\n");
//		return -1;
//	}*/
//
//	return pstack->stack[pstack->top];
//}
//
//int Compare(Stack* pstack, Data data) {
//	if (SPeek(pstack) == '(' && data == ')') return TRUE;
//	else if (SPeek(pstack) == '{' && data == '}') return TRUE;
//	else if (SPeek(pstack) == '[' && data == ']') return TRUE;
//	else return FALSE;
//}
//
//void Garbage(Stack* pstack) {
//	while (!SIsEmpty(pstack))
//		SPop(pstack);
//}