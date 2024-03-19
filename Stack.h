#pragma once
#include <vector>

using namespace std;

template <typename T>
class Stack {
private:
	vector<T> vec;
public:
	void push(const T& item) {
		vec.push_back(item);
	}

	T top() const {
		return vec[vec.size() - 1];
	}

	void pop() {
		vec.pop_back();
	}

	size_t size() {
		return vec.size();
	}

	bool empty() {
		return vec.empty();
	}

	auto begin() {
		return vec.begin();
	}

	auto end() {
		return vec.end();
	}
};