#pragma once
#include <iostream>

struct list_node {
	int data;
	list_node* next;
};

template<bool Const>
class list_of_ints_iterator {
	friend class list_of_ints;
	friend class list_of_ints_iterator<!Const>;
	using node_pointer = std::conditional_t<Const, const list_node*, list_node*>;
	node_pointer ptr_;
	explicit list_of_ints_iterator(node_pointer p) : ptr_(p) {}
public:
	// Члены typedef для поддержки std::iterator_traits
	using difference_type = std::ptrdiff_t;
	using value_type = int;
	using pointer = std::conditional_t<Const, const int*, int*>;
	using reference = std::conditional_t<Const, const int&, int&>;
	using iterator_category = std::forward_iterator_tag;
	reference operator*() const { return ptr_->data; }
	auto& operator++() { ptr_ = ptr_->next; return *this; }
	auto operator++(int) { auto result = *this; ++* this; return result; }
	// Поддержка сравнения между типами iterator и const_iterator
	template<bool R>
	bool operator==(const list_of_ints_iterator<R>& rhs) const
	{
		return ptr_ == rhs.ptr_;
	}
	template<bool R>
	bool operator!=(const list_of_ints_iterator<R>& rhs) const
	{
		return ptr_ != rhs.ptr_;
	}
	// Поддержка неявного преобразования iterator в const_iterator
	operator list_of_ints_iterator<true>() const
	{
		return list_of_ints_iterator<true>{ptr_};
	}
};

class list_of_ints {
	list_node* head_ = nullptr;
	list_node* tail_ = nullptr;
	int size_ = 0;
public:
	using const_iterator = list_of_ints_iterator<true>;
	using iterator = list_of_ints_iterator<false>;
	// Функции-члены begin и end
	iterator begin() { return iterator{ head_ }; }
	iterator end() { return iterator{ nullptr }; }
	const_iterator begin() const { return const_iterator{ head_ }; }
	const_iterator end() const { return const_iterator{ nullptr }; }
	// Другие поддерживаемые операции
	int size() const { return size_; }
	void push_back(int value) {
		list_node* new_tail = new list_node{ value, nullptr };
		if (tail_) {
			tail_->next = new_tail;
		}
		else {
			head_ = new_tail;
		}
		tail_ = new_tail;
		size_ += 1;
	}
	~list_of_ints() {
		for (list_node* next, *p = head_; p != nullptr; p = next) {
			next = p->next;
			delete p;
		}
	}
};