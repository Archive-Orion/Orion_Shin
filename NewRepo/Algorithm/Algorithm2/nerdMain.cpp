#include <iostream>
#include <map>

using namespace std;
map<int, int> nerd;

int Compare(int problem, int ramen) {
	if (nerd.empty()) {
		nerd[problem] = ramen;
		return nerd.size();
	}
	else {
		map<int, int>::iterator iter = nerd.begin();
		for (pair<int, int> atom : nerd) {
			if (iter->first > problem&& iter->second > ramen)
				return nerd.size();
			else if (iter->first < problem && iter->second < ramen)	
				return nerd.size();
			else {
				nerd[problem] = ramen;
				return nerd.size();
			}
		}
	}
}

int main(void) {
	int testcase, people, problem, ramen;

	cin >> testcase;
	for (int c = 0; c < testcase; c++) {
		cin >> people;
		int count = 0;
		for (int n = 0; n < people; n++) {
			cin >> problem >> ramen;
			count += Compare(problem, ramen);
		}
		printf("%d\n", count);
	}
}
