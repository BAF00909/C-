#pragma once

template<typename T>
typename std::vector<T> insert_sorted(std::vector<T> & v, T const& item) {
	v.insert(std::upper_bound(v.begin(), v.end(), item), item);
	return v;
}
