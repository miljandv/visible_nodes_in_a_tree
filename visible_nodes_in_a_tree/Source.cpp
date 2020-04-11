#include <iostream>
using namespace std;

struct tree {
	int x;
	tree* l;
	tree* r;
	tree(int xx, tree* ll, tree* rr):l(ll),r(rr),x(xx) {}
};
struct elem {
	elem* down;
	tree* me;
	elem(elem* down_, tree* me_) :down(down_), me(me_) {}
};
struct stack {
	static elem* top;
	void push(tree* t) {
		if (!top) { top = new elem(nullptr, t); }
		else {
			top = new elem(top, t);
		}
	}
	tree* pop() {
		tree* temp = top->me;
		top = top->down;
		if (!top)top = nullptr;
		return temp;
	}
	bool isempty() {
		return !top;
	}
};
elem* stack::top = nullptr;
int num = 0;
void traverse(tree* node, int max) {
	if (!node)return;
	if (node->x >= max) { num++; max = node->x; }
	traverse(node->l, max);
	traverse(node->r, max);
}
int solution(tree* T) {
	tree* temp = T; num++;
	if (T == nullptr)return -1;
	traverse(T->l, T->x);
	traverse(T->r, T->x);
	return num;
}

int main() {
	tree* A = new tree(5, new tree(3, new tree(20, nullptr, nullptr), new tree(21, nullptr, nullptr)), new tree(10, new tree(7, nullptr, nullptr), nullptr));
	cout << solution(A);
}