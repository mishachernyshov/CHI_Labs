#pragma once
template <class A, class B>
class Pair {
public:
	Pair() {}

	Pair(const A& objectA, const B& objectB) {
		a_value = A(objectA);
		b_value = B(objectB);
	}

	const A& getKey() const {
		return a_value;
	}

	const B& getValue() const {
		return b_value;
	}
private:
	A a_value;
	B b_value;
};
