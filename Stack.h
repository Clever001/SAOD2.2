#pragma once
#include <vector>

using namespace std;

template <typename T>
class Stack {
private:
	vector<T> vec;
public:
	void Push(const T& item) {
		vec.push_back(item);
	}

	T Top() const {
		return vec[vec.size() - 1];
	}

	void Pop() {
		vec.pop_back();
	}

	size_t Size() {
		return vec.size();
	}

	bool Empty() {
		return vec.empty();
	}

	auto begin() {
		return vec.begin();
	}

	auto end() {
		return vec.end();
	}
};