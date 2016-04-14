#include <iostream>

using namespace std;

class WeightedQuickUnion {
private:
	int *id,*sz;
	int size;
	int root(int p) {
		while(p != id[p]) {
			id[p] = id[id[p]];
			p = id[p];
		}
		return p;
	}
public:
	WeightedQuickUnion(int n) {
		size = n;
		id = new int [n];
		sz = new int [n];
		for(int i=0;i<size;i++) {
			id[i] = i;
			sz[i] = 1;
		}
	}
	~WeightedQuickUnion() {
		delete [] id;
		delete [] sz;
	}
	bool connectedPQ(int p, int q) { return root(p) == root(q); }
	void unionPQ(int p,int q) {
		int i = root(p);
		int j = root(q);
		if(sz[i] < sz[j]) { id[i] = j; sz[j] += sz[i]; }
		else					{ id[j] = i; sz[i] += sz[j]; }
	}
	void print() {
		for(int i=0;i<size;i++) {
			cout << id[i] << " ";
		}
		cout << endl;
	}
};

int main() {
	WeightedQuickUnion wqu(10);
	wqu.unionPQ(4,3);
	wqu.unionPQ(3,8);
	wqu.unionPQ(6,5);
	wqu.unionPQ(9,4);
	wqu.unionPQ(2,1);
	wqu.unionPQ(5,0);
	wqu.unionPQ(7,2);
	wqu.unionPQ(6,1);
	wqu.unionPQ(7,3);
	wqu.print();
	return 0;
}
