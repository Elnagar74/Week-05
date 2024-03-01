#include <iostream>
using namespace std;


class Stack {
private:
	int size;
	int top;
	int* arr;

public:
	Stack(int size) :
		size(size), top(-1) {
		arr = new int[size];
	}

	~Stack() {
		delete[] arr;
	}

	void push(int x) {
		if (isFull())
			return;
		arr[++top] = x;
	}

	int pop() {
		if (isEmpty())
			return -1;
		return arr[top--];
	}

	int peek() {
		if (isEmpty())
			return -1;
		return arr[top];
	}

	int isFull() {
		return top == size - 1;
	}

	int isEmpty() {
		return top == -1;
	}

	void display() {
		for (int i = top; i >= 0; i--)
			cout << arr[i] << " ";
		cout << endl;
	}

	void insert_at_bottom(int value) {
		for (int i = top; i >= 0; i--) // Time complixity = O(n)
			arr[i + 1] = arr[i];
		arr[0] = value, top++;
	}

	void insert_at_bottom_rec(int value) {
		if (isEmpty())
			push(value);
		else {
			int cur = pop();
			insert_at_bottom_rec(value);
			push(cur);
		}
	}

};

//-----------------------------------------------------------

// Problem #1

/*

class Solution {
public:
	vector<int> asteroidCollision(vector<int>& asteroids) {
		stack<int> st;
		for (auto i : asteroids) {
			if (i >= 0 || st.empty())
				st.push(i);
			else {
				while (!st.empty() && abs(i) > st.top() && st.top() > 0)
					st.pop();

				if (st.empty() || st.top() < 0)
					st.push(i);
				else if (abs(i) == st.top())
					st.pop();
			}
		}

		vector<int> res(st.size());
		for (int i = st.size() - 1; i >= 0; i--)
			res[i] = st.top(), st.pop();
		return res;
	}
};

*/

//----------------------

// Problem #2

//Without recursion.
/*

void insert_at_bottom(int value) {
	for (int i = top; i >= 0; i--) // Time complixity = O(n)
		arr[i + 1] = arr[i];
	arr[0] = value, top++;
}

*/

//With recursion.
/*

void insert_at_bottom_rec(int value) {
		if (isEmpty())
			push(value);
		else {
			int cur = pop();
			insert_at_bottom_rec(value);
			push(cur);
		}
}

*/

//----------------------



int main()
{

	return 0;
}

