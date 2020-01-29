#define TRUE	1
#define FALSE	0

#define HEAP_LEN	100

typedef int HData;
typedef int Priority;

typedef struct _heapElem
{
	Priority pr;	// ���� �������� ���� �켱����
	HData problem;
	HData ramen;
} HeapElem;

typedef struct _heap
{
	int numOfData;
	HeapElem heapArr[HEAP_LEN];
} Heap;

/*** Heap ���� ����� ****/
void TreeInit(Heap* ph);
int HIsEmpty(Heap* ph);

void HInsert(Heap* ph, HData, HData);
HData HDelete(Heap* ph);

int main(void) {
	int numOfProblem, numOfRamen, test_case, numOfPeople;
	Heap tree;

	scanf("%d", &test_case);

	for (int c = 0; c < test_case; c++) {
		scanf("%d", &numOfPeople);
		TreeInit(&tree);
		for (int n = 0; n < numOfPeople; n++) {
			scanf("%d %d", &numOfProblem, &numOfRamen);
			HInsert(&tree, numOfPeople, numOfRamen)
		}
	}
}












void TreeInit(Heap* ph)
{
	ph->numOfData = 0;
}

int HIsEmpty(Heap* ph)
{
	if (ph->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

int GetParentIDX(int idx)
{
	return idx / 2;
}

int GetLChildIDX(int idx)
{
	return idx * 2;
}

int GetRChildIDX(int idx)
{
	return GetLChildIDX(idx) + 1;
}

int GetHiPriChildIDX(Heap* ph, int idx)
{
	if (GetLChildIDX(idx) > ph->numOfData)    // �ڽ� ��尡 ���ٸ�
		return 0;

	else if (GetLChildIDX(idx) == ph->numOfData)    // ���� �ڽ� ��尡 ������ �����
		return GetLChildIDX(idx);

	else   // ���� �ڽ� ���� ������ �ڽ� ����� �켱������ ��
	{
		if (ph->heapArr[GetLChildIDX(idx)].pr
						> ph->heapArr[GetRChildIDX(idx)].pr)
			return GetRChildIDX(idx);
		else
			return GetLChildIDX(idx);
	}
}

void HInsert(Heap* ph, HData problem, HData ramen)
{
	int idx = ph->numOfData + 1;
	HeapElem nelem = { problem, ramen };

	while (idx != 1)
	{
		if (pr < (ph->heapArr[GetParentIDX(idx)].pr))
		{
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		else
			break;
	}

	ph->heapArr[idx] = nelem;
	ph->numOfData += 1;
}

HData HDelete(Heap* ph)
{
	HData retData = (ph->heapArr[1]).data;    // ������ ������ �ӽ� ����
	HeapElem lastElem = ph->heapArr[ph->numOfData];

	int parentIdx = 1;    // ��Ʈ ����� Index
	int childIdx;

	while (childIdx = GetHiPriChildIDX(ph, parentIdx))
	{
		if (lastElem.pr <= ph->heapArr[childIdx].pr)
			break;

		ph->heapArr[parentIdx] = ph->heapArr[childIdx];
		parentIdx = childIdx;
	}

	ph->heapArr[parentIdx] = lastElem;
	ph->numOfData -= 1;
	return retData;
}