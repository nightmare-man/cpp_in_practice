#include "../include/std_lib_facilities.h"
namespace LSM {
	//只进行内存分配的版本
//不进行元素的构造析构
	//为什么需要vector_base?
	//原因在于reserve时，如果直接执行分配空间
	//并调用元素初始化时，初始化这一阶段可能
	//发生异常，进而造成内存没有回收
	//而添加一个vector_base 类，在reserve时
	//创建该对象用于分配内存，单独初始化
	//一旦初始化异常，调用vector_base析构函数，释放内存
	

	//与之对应的方案就是new 数组既分配空间又初始化
	//该方案需要用unique_ptr 来实现异常时回收内存
	template<typename T, typename A>
	struct Vector_base {
		A alloc;
		T* mem;
		int sz;
		int capacity;
		Vector_base(const A& a, int n) :alloc{ a }, sz{ 0 }, capacity{ n }, mem{ alloc.allocate(n) } {};
		~Vector_base() { alloc.deallocate(mem, capacity); }
	};
	//默认使用alloctor<T>作为
	//要求Element<T>&& Allocator<A>
	template<typename T, typename A = allocator<T>>
	class Vector :private Vector_base<T, A> {
		//继承了vector_base 作为私有成员
	private:
		A alloc;//默认构造
	public:
		using type_size = int;
		using iterator = T*;
		Vector(initializer_list<T> lst) :Vector_base<T,A>{alloc,int(lst.size())} {
			copy(lst.begin(), lst.end(), this->mem);
		};
		Vector():Vector_base<T, A>(alloc, 0){
			
		};
		~Vector() {};
		void reserve(type_size newsize) {
			if (newsize <= this->capacity) return;
			//分配一个新的vector空间 sz=0 cap=newsize
			//mem=alloc.allocate
			Vector_base<T, A> b{ alloc,newsize };
			//书上这里写反了三个参数是 b.mem b.mem+sz mem
			//应该从mem拷贝到新的b.mem
			uninitialized_copy(this->mem, this->mem + this->sz, b.mem);
			//挨个元素调用析构函数
			for (int i = 0; i < this->sz; i++) alloc.destroy(this->mem + i);
			//将this指向b b指向this
			swap<Vector_base<T, A>>(*this, b);
			//出该作用域 b指向的this调用析构 释放元素占用的内存空间
		}
		void resize(type_size newsize) {
			reserve(newsize);
			for (int i = *this->sz; i < newsize; i++) this->mem[i] = T();
			this->sz = newsize;
		}
		void push_back(T t);
		T& operator[](type_size idx) {
			return this->mem[idx];
		}

	};
	template<typename T,typename A >
	void Vector<T, A>::push_back(T t) {
		if (this->capacity == 0) reserve(8);
		else if (this->sz == this->capacity) reserve(2 * this->capacity);
		this->mem[this->sz] = t;
		this->sz++;
	}
};

int main() {
	LSM::Vector<int> a;
	a.push_back(4);
	cout << a[0];
}
