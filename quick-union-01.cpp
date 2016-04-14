#include<iostream>

using namespace std;

class QuickUnion {
private:
	int *id;
	int size;
	int root(int i) {
		while(i != id[i]) {
			i = id[i];
		}
		return i;
	}
public:
	QuickUnion(int n) {
		size = n;
		id = new int[n];
		for(int i=0;i<size;i++) {
			id[i] = i;
		}
	}
	~QuickUnion() {
		delete [] id;
	}
	bool connectedPQ(int p, int q) {
		return root(p) == root(q);
	}
	void unionPQ(int p, int q) {
		int i = root(p);
		int j = root(q);
		id[i] = j;
	}
	void print() {
		for(int i=0;i<size;i++) {
			cout << id[i] << " ";
		}
		cout << endl;
	}
};

int main() {
	QuickUnion qu(5);
	qu.unionPQ(0,1);
	qu.unionPQ(1,2);
	qu.unionPQ(2,3);
	cout << qu.connectedPQ(0,3) << endl;
	qu.print();
	return 0;
}
