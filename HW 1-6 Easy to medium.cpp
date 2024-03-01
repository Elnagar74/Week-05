#include <iostream>
using namespace std;

typedef char type;

class Stack {
private:
	int size;
	int top;
	type* array;

public:
	Stack(int size) :
		size(size), top(-1) {
		array = new type[size];
	}

	~Stack() {
		delete[] array;
	}

	void push(type x) {
		if (isFull())
			return;
		array[++top] = x;
	}

	type pop() {
		if (isEmpty())
			return -1;
		return array[top--];
	}

	type peek() {
		if (isEmpty())
			return -1;
		return array[top];
	}

	int isFull() {
		return top == size - 1;
	}

	int isEmpty() {
		return top == -1;
	}

	void display() {
		for (int i = top; i >= 0; i--)
			cout << array[i] << " ";
		cout << endl;
	}
};

//-----------------------------------------------------------

// Problem #1

class Another_stack {
private:
	int size;
	int added_elements;
	int* arr;
	
public:
	Another_stack(int size) : size(size), added_elements(0) {
		arr = new int[size];
	}

	bool push(int value) {
		if (added_elements == size) return false;

		for (int i = added_elements - 1; i >= 0; --i) // Shifting all of the elements to the right.
			arr[i + 1] = arr[i];
		arr[0] = value; // Put new value to be the first.
		++added_elements;
		return true;
	}

	bool pop(int &temp) {
		if (added_elements == 0) return false;

		temp = arr[0];
		for (int i = 0; i < added_elements - 1; ++i)
			arr[i] = arr[i + 1];
		--added_elements;
		return true;
	}

	bool peek(int &temp) {
		if (added_elements == 0) return false;

		temp = arr[0];
		return true;
	}

	void display() {
		for (int i = 0; i < added_elements; ++i)
			cout << arr[i] << " ";
		cout << endl;
	}
};

//-------------------------

// Problem #2

string reverse_subwords(string line) {
	line += ' ';
	string res = "";
	Stack st(line.size());
	for (int i = 0; i < line.size(); i++) {
		if (line[i] == ' ') {
			while (!st.isEmpty()) {
				res += st.pop();
			}
			res += ' ';
		}
		else
			st.push(line[i]);
	}
	return res;
}

//-------------------------

// Problem #3

int reverse_num(int num) {
	if (num == 0)
		return 0;

	Stack st(18);
	while (num) {
		st.push(num % 10);
		num /= 10;
	}

	int t = 1;
	while (!st.isEmpty()) {
		num = st.pop() * t + num;
		t *= 10;
	}

	return num;
}

//-------------------------

// Problem #4

/*

class Solution {
public:
	bool isValid(string s) {
		stack<int> st;
		for (char c : s) {
			if (c == '(' || c == '{' || c == '[')
				st.push(c);
			else {
				if (st.empty())
					return false;
				else if (c == ')' && st.top() == '(')
					st.pop();
				else if (c == '}' && st.top() == '{')
					st.pop();
				else if (c == ']' && st.top() == '[')
					st.pop();
				else
					return false;
			}
		}
		if (st.empty())
			return true;
		return false;
	}
};

*/

//-------------------------

// Problem #5

/*

class Solution {
public:
	string removeDuplicates(string s) {
		cin.tie(0);
		cout.sync_with_stdio(0);

		stack<char> st;
		for(int i = s.size()-1; i >= 0; i--){
			if(st.empty())
				st.push(s[i]);
			else{
				if(s[i] == st.top())
					st.pop();
				else
					st.push(s[i]);
			}
		}
		s="";
		while(!st.empty()){
			s += st.top();
			st.pop();
		}
		return s;
	}
};

*/

//-------------------------


// Problem #6

class Two_stack {
private:
	int size;
	int top1 , top2;
	int* arr;

public:
	Two_stack(int size) : size(size) {
		arr = new int(size);
		top1 = -1, top2 = size;
	}

	void push(int id, int value) {
		if (top1 + 1 >= top2) return;
		if (id == 1) {
			arr[++top1] = value;
		}
		else {
			arr[--top2] = value;
		}
	}

	int pop(int id) {
		if (id == 1) {
			if (top1 == -1) return -1;
			return arr[top1--];
		}
		else {
			if (top2 == size) return -1;
			return arr[top2++];
		}
	}

	int peek(int id) {
		if (id == 1) {
			if (top1 == -1) return -1;
			return arr[top1];
		}
		else {
			if (top2 == size) return -1;
			return arr[top2];
		}
	}

	void display() {
		for (int i = top1; i >= 0; i--)
			cout << arr[i] << " ";

		cout << endl;

		for (int i = top2; i < size; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
};

//-------------------------

int main() {
	
	
	return 0;
}