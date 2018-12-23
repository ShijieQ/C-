#include<cmath>
#include<ctime>
#include<stack>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<windows.h>
//#pragma GCC optimize(3)

using namespace std;
typedef int KeyType;
typedef int DataType;
const int MaxSize = 5e7 + 10;

typedef struct entry {
	KeyType key;
	DataType data;
}Entry;

typedef struct list {
	int n;
	Entry D[MaxSize];
}List;

List l, l_temp;
void Init(int k) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	l.n = k;
	freopen("data.in", "w", stdout);
	srand((int)time(NULL));
	for (int i = 0; i < k; i++) {
		l.D[i].key = int(rand());
		l_temp.D[i].key = l.D[i].key;
		printf("%d\n", l.D[i].key);
	}
	fclose(stdout);
}

void Reversion() {
	for (int i = 0; i < l.n; i++) {
		l.D[i] = l_temp.D[i];
	}
	return;
}

void Result() {
	int length = l.n;
	for (int i = 0; i < length; i++) {
		cout << l.D[i].key << "  ";
		if ((i + 1) % 10 == 0) {
			cout << endl;
		}
	}
	cout << endl;
	return;
}

long SelectSort() {
	clock_t begin = clock();
	int length = l.n;
	for (int i = 0; i < length; i++) {
		int temp = i;
		for (int j = i + 1; j < length; j++) {
			if (l.D[temp].key > l.D[j].key) {
				temp = j;
			}
		}
		swap(l.D[i], l.D[temp]);
	}
	clock_t end = clock();
	return end - begin;
}

long InsertSort() {
	clock_t begin = clock();
	int length = l.n;
	for (int i = 1; i < length; i++) {
		Entry temp = l.D[i];
		int j;
		for (j = i - 1; j >= 0; j--) {
			if (temp.key < l.D[j].key) {
				l.D[j + 1] = l.D[j];
			}
			else {
				break;
			}
		}
		l.D[j + 1] = temp;
	}
	clock_t end = clock();
	return end - begin;
}

long BubbleSort() {
	clock_t begin = clock();
	int length = l.n;
	for (int i = 0; i < length; i++) {
		bool flag = 0;
		for (int j = 0; j < length - i - 1; j++) {
			if (l.D[j].key > l.D[j + 1].key) {
				swap(l.D[j].key, l.D[j + 1].key);
				flag = 1;
			}
		}
		if (!flag) {
			break;
		}
	}
	clock_t end = clock();
	return end - begin;
}

long QuickSort() {
	clock_t begin = clock();
	stack<pair<int, int> > s;
	s.push(make_pair(0, l.n - 1));
	while (!s.empty()) {
		pair<int, int> temp = s.top();
		s.pop();
		if (temp.first >= temp.second) {
			continue;
		}
		int mid = temp.first - 1;
		Entry flag = l.D[temp.second];
		for (int i = temp.first; i <= temp.second - 1; i++) {
			if (l.D[i].key < flag.key) {
				mid++;
				swap(l.D[i], l.D[mid]);
			}
		}
		swap(l.D[++mid], l.D[temp.second]);
		s.push(make_pair(temp.first, mid - 1));
		s.push(make_pair(mid + 1, temp.second));
	}
	clock_t end = clock();
	return end - begin;
}

Entry temp[MaxSize];
long MergeSort() {
	clock_t begin = clock();
	int low, n1, n2, size = 1;
	while (size < l.n) {
		int k = 0;
		low = 0;
		while (low + size <= l.n) {
			n1 = size;
			if (low + size * 2 < l.n) {
				n2 = size;
			}
			else {
				n2 = l.n - low - size;
			}
			int i = low, j = low + n1;
			while (i <= low + n1 - 1 && j <= low + n1 + n2 - 1) {
				if (l.D[i].key <= l.D[j].key) {
					temp[k++] = l.D[i++];
				}
				else {
					temp[k++] = l.D[j++];
				}
			}
			while (i <= low + n1 - 1) {
				temp[k++] = l.D[i++];
			}
			while (j <= low + n1 + n2 - 1) {
				temp[k++] = l.D[j++];
			}
			low += n1 + n2;
		}
		for (int i = 0; i < l.n; i++) {
			l.D[i] = temp[i];
		}
		size *= 2;
	}
	clock_t end = clock();
	return end - begin;
}

void AdjustDown(int b, int r) {
	Entry temp = l.D[b];
	for (int j = 2 * b + 1; j <= r; j = j * 2 + 1) {
		if (j < r && l.D[j].key < l.D[j + 1].key) {
			j++;
		}
		if (temp.key > l.D[j].key) {
			break;
		}
		l.D[b] = l.D[j];
		b = j;
	}
	l.D[b] = temp;
}

long HeapSort() {
	clock_t begin = clock();
	for (int i = (l.n - 2) / 2; i >= 0; i--) {
		AdjustDown(i, l.n - 1);
	}
	for (int i = l.n - 1; i >= 0; i--) {
		swap(l.D[0], l.D[i]);
		AdjustDown(0, i - 1);
	}
	clock_t end = clock();
	return end - begin;
}

bool cmp(Entry a, Entry b){
    return a.key < b.key;
}

int main() {
	clock_t be = clock();
	Init(100000);
	clock_t ed = clock();
	freopen("main.out", "w", stdout);
	cout << "After Init is :" << endl;
	cout << "time used : " << ed - be << "ms" << endl;
	cout << "Initial data is :" << endl;
//	Result();
	cout << "After SelectSort is :" << endl;
	cout << "time used : " << SelectSort() << "ms" << endl;
//	Result();
	Reversion();
	cout << "After InsertSort is :" << endl;
	cout << "time used : " << InsertSort() << "ms" << endl;
//	Result();
	Reversion();
	cout << "After BubbleSort is :" << endl;
	cout << "time used : " << BubbleSort() << "ms" << endl;
//	Result();
	Reversion();
	cout << "After QuickSort is :" << endl;
	cout << "time used : " << QuickSort() << "ms" << endl;
//	Result();
	Reversion();
	cout << "After MergeSort is :" << endl;
	cout << "time used : " << MergeSort() << "ms" << endl;
//	Result();
	Reversion();
	cout << "After HeapSort is :" << endl;
	cout << "time used : " << HeapSort() << "ms" << endl;
//	Result();
	Reversion();
    cout << "After Sort is :" << endl;
    clock_t begin = clock();
    sort(l.D, l.D + l.n, cmp);
    clock_t end = clock();
	cout << "time used : " << end - begin << "ms" << endl;
	return 0;
}

