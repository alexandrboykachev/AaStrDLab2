#pragma once

template<class T, class T1>

class haffman {

public:

	haffman(T symbol = T(), T1 num_of_entry = T1()) :symbol(symbol), num_of_entry(num_of_entry) {}

	T symbol;

	T1 num_of_entry;

	template<class T, class T1> friend bool operator >(const haffman<T, T1>& a, const haffman<T, T1>& b);

	template<class T, class T1> friend bool operator <(const haffman<T, T1>& a, const haffman<T, T1>& b);

};

template<class T, class T1> inline bool operator> (const haffman<T, T1>& a, const haffman<T, T1>& b) {

	return a.num_of_entry > b.num_of_entry;

}

template<class T, class T1> inline bool operator< (const haffman<T, T1>& a, const haffman<T, T1>& b) {

	return a.num_of_entry < b.num_of_entry;

}
