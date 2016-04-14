#include <iostream>

using namespace std;

class QuickFind {
private:
	int* id;
	int size;
public:
	QuickFind(int n) {
		id = new int[n];
		size = n;
		for(int i=0;i<size;i++)
			id[i] = i;
	}
	~QuickFind() {
		delete [] id;
	}
	bool connectedPQ(int p, int q) {
		return id[p] == id[q];
	}
	void unionPQ(int p, int q) {
		int pid = id[p];
		int qid = id[q];
		for(int i=0;i<size;i++) {
			if(id[i] == pid) {
				id[i] = qid;
			}
		}
	}
	void print() {
		for(int i=0;i<size;i++) {
			cout << id[i] << " ";
		}
		cout << endl;
	}
};

int main() {
	QuickFind qf(5);
	qf.unionPQ(0,1);
	qf.unionPQ(1,2);
	qf.unionPQ(2,3);
	cout << qf.connectedPQ(0,4) << endl;
	qf.print();
	return 0;
}
