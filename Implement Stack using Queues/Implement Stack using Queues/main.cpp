#include <queue>
#include <vector>
#include <iostream>
using namespace std;

class Stack {
private:
	queue<int> q;
public:
	// Push element x onto stack.
	void push(int x) {
		q.push(x);
	}

	// Removes the element on top of the stack.
	void pop() {
		queue<int> p;
		if (q.size() == 1) { //pay attention
			q.pop();
			return;
		}
		int len = q.size();
		for (int i = 0; i < len - 1; i++) {
			int d = q.front();
			q.pop();
			p.push(d);
		}
		q.pop();
		q = p;
	}

	// Get the top element.
	int top() {
		queue<int> p;
		int d;
		int len = q.size();
		for (int i = 0; i < len; i++) {
			d = q.front();
			q.pop();
			p.push(d);
		}
		q = p;
		return d;
	}

	// Return whether the stack is empty.
	bool empty() {
		return q.empty();
	}
};

int main() {
	Stack s;
	s.push(1); s.push(2);
	cout << s.top() << endl; 
	s.pop();
	s.pop(); 
	cout << s.empty() << endl;
	return 0;
}