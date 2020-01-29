#define _CRT_SECURE_NO_WARNINGS
#define TREE_LEN	50000
#define TRUE		1
#define FALSE		0

typedef int Data;

typedef struct {
	Data count_prob;
	Data count_ramen;
} Node;

typedef struct {
	Node treeArr[TREE_LEN];
	int numOfData;
	int idx;
} Tree;

void TreeInit(Tree* pointer_tree);
int TIsEmpty(Tree* pointer_tree);

#include <stdio.h>

int main(void) {
	int numOfProblem, numOfRamen, test_case, numOfPeople;
	Tree tree;

	scanf("%d", &test_case);

	for (int c = 0; c < test_case; c++) {
		scanf("%d", &numOfPeople);
		TreeInit(&tree);
		for (int n = 0; n < numOfPeople; n++) {
			scanf("%d %d", &numOfProblem, &numOfRamen);
			TreeInsert(&tree, numOfProblem, numOfRamen);
		}
	}
}

void TreeInit(Tree* pointer_tree) {
	pointer_tree->idx = 0;
	pointer_tree->numOfData = 0;
}

int TIsEmpty(Tree* pointer_tree) {
	if (pointer_tree->idx == 0)
		return TRUE;
	else return FALSE;
}

void TreeInsert(Tree* pointer_tree, Data problem, Data ramen) {
	if (TIsEmpty(pointer_tree)) {
		pointer_tree->idx++;

		pointer_tree->treeArr[pointer_tree->idx] = { problem, ramen };
	}
	else {
		Compare();
	}
}

int Compare(Tree* pointer_tree, Data problem, Data ramen) {
	for (int i = 1; i < pointer_tree->idx; i++) {
		if (pointer_tree->treeArr[pointer_tree->idx].count_prob > problem && pointer_tree->treeArr[pointer_tree->idx].count_ramen > ramen) {
			return;
		}
		else if (pointer_tree->treeArr[pointer_tree->idx].count_prob <= problem && pointer_tree->treeArr[pointer_tree->idx].count_ramen > ramen) {
			return GetLChildIDX(pointer_tree->idx);
		}
		else if (pointer_tree->treeArr[pointer_tree->idx].count_prob > problem&& pointer_tree->treeArr[pointer_tree->idx].count_ramen <= ramen) {
			return GetRChildIDX(pointer_tree->idx);
		}
		else if (pointer_tree->treeArr[pointer_tree->idx].count_prob <= problem && pointer_tree->treeArr[pointer_tree->idx].count_ramen <= ramen) {
			return GetParentIDX(pointer_tree->idx);
		}
	}
}

int GetParentIDX(int idx) {
	return idx / 2;
}

int GetLChildIDX(int idx) {
	return idx * 2;
}

int GetRChildIDX(int idx) {
	return GetLChildIDX(idx) + 1;
}
