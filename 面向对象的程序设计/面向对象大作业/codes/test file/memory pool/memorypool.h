#pragma once
#include "stdafx.h"
#include <climits>
#include <cstddef>   //ptrdiff_t size_t
#include<new> //placement new
#include<iostream>
using namespace std;
#define BUFFER_SIZE 1024

template <typename T>
struct block {
	block *next;
};   //�����ڴ����һ��С���飬���Դ�Ϊ����ĵ�λ����СΪsizeof(T)


template <typename T>
class buffer
{
private:
	static const size_t blockSize = sizeof(T);     //һ��block��С
	unsigned char* body = new unsigned char[blockSize * BUFFER_SIZE];//����һ��buffer�Ŀռ�,����bodyΪ�׵�ַ

public:  //�ӿڶ���
	typedef T value_type;
	typedef T* pointer;
	typedef const T* const_pointer;
	typedef T& reference;
	typedef const T& const_reference;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	buffer() {};
	pointer blockaddress(size_type count) {//��blockΪ��λ�õ�ÿ�η���ռ�ĵ�ַ
		return reinterpret_cast<pointer>(body + blockSize * count);
	}
	buffer * next;   //��һ��ָ��
};


template <typename T>
class memorypool {
public:
	//�ӿڶ���
	typedef T value_type;
	typedef T* pointer;
	typedef const T* const_pointer;
	typedef T& reference;
	typedef const T& const_reference;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	memorypool(memorypool &&memorypool) = delete;   //�ƶ����캯��
	memorypool(const memorypool &memorypool) {};    //��������
	memorypool& operator =(memorypool &&memorypool) = delete;   //�ƶ���ֵ����
	memorypool& operator =(const memorypool &memorypool) = delete;  //ɾ��Ĭ�Ͽ������캯��
	memorypool() {
		firstbuffer->next = NULL;
		freeSlots = NULL;   //��ʼʱû�пյ��ڴ�
	}
	~memorypool()
	{
		while (firstbuffer != nullptr) {
			buffer<T> *temp = firstbuffer;
			firstbuffer = firstbuffer->next;
			delete temp;     //����ͷſռ�
		}
		while (overmem != nullptr) {
			pointer temp = reinterpret_cast<pointer> (overmem);  //ǿ��ת��Ϊpointer����
			overmem = overmem->next;
			::operator delete(temp);    //ͨ���ײ��ɾ����ʽʵ���ͷ�
		}
	}
	pointer allocate(size_type n) {
		if (n == 1) {
			if (freeSlots != nullptr) {  //��������д��ڿռ䣬��ô�͵��ô˴��Ŀռ�
				block<T> *temp = freeSlots;
				freeSlots = freeSlots->next;
				return reinterpret_cast<pointer>(temp);
			}
			else if (buffercount + 1 >= BUFFER_SIZE) {  //�������Ϊ���ҵ�ǰbuffer��������ô����ϵͳ�����µ�buffer
				buffer<T>*p = new buffer<T>;
				p->next = firstbuffer->next;
				firstbuffer->next = p;
				currentbuffer = p;  //��ǰbufferΪ�������buffer p
				buffercount = 0;   //��ʼ������
			}
			return currentbuffer->blockaddress(buffercount++);  //�����׵�ַ��ͬʱ������һ
		}
		else {
			if (n > BUFFER_SIZE)
			{   //����nֱ�ӳ���һ��buffer���޵������ֱ�ӵ���new����ʹ��memory pool
				pointer temp = (pointer)::operator new (sizeof(T)*n);
				block<T> * temp1 = reinterpret_cast<block<T> *>(temp);  //ת������
				temp1->next = overmem;
				overmem =temp1;   //���ռ���������������
				return temp;    //���ظÿռ�ĳ�ʼ��ַ
			}
			else if (buffercount + n >= BUFFER_SIZE) {  //�����ǰbufferδ��������Ҫ����Ŀռ��뵱ǰʹ����Ӵ����ܿռ�������ôֱ�ӿ�����buffer������bufferʣ��Ŀռ�ȫ��ת�Ƶ�freeSlots������
				buffer<T>*p = new buffer<T>;
				p->next = firstbuffer->next;
				firstbuffer->next = p;
				int k = buffercount;
				while (k < buffercount) {
					block<T> * temp = reinterpret_cast<block<T> *>(currentbuffer->blockaddress(k));
					temp->next = freeSlots;
					freeSlots = temp;  //û������Ĳ���ǰ��
					k++;
				} 
				buffercount = 0;  //��ʼ������
				currentbuffer = p; //��ǰbufferΪ�������buffer p
			}
			buffercount += n;
			return currentbuffer->blockaddress(buffercount - n);  // ���ط�����ڴ���׵�ַ
		}
	}

	void deallocate(pointer p, size_type n) {
		if (p != nullptr) {    //�����ͷŵĿռ䣬ֱ�ӷ����������У�ע��ǰ��
			block<T> *temp = reinterpret_cast<block<T> *>(p);
			temp->next = freeSlots;
			freeSlots = temp;
		}
	}
	void construct(pointer p, value_type value) {
		new (p) T(value); //����������ڴ�ռ��Ϲ������
	}
	void destroy(pointer p) {
		p->~T();   //��������
	}
	pointer address(reference x) {  //���طǳ����������ͱ�����ַ
		return (pointer)&x;
	}
	const_pointer address(reference x) const {  //���س����������ͱ�����ַ
		return (const_pointer)&x;
	}
	size_type max_size() const {       // �������ɷ�����ڴ�
		return size_type(UINT_MAX / sizeof(T));
	}
	void newElement(value_type value)   //���ڴ������һ����������ռ䣬�����ö���Ĺ��캯��
	{
		pointer temp = allocate();
		construct<value_type>(temp, value);
		return temp;
	}

	void deleteElement(pointer p)    //�������󣬽��ڴ�ռ�黹���ڴ��
	{
		if (p != nullptr)
		{
			p->~value_type();
			deallocate(p, 1);
		}
	}
private:
	block<T>* freeSlots;  //������ſհ׵��ڴ�ռ䣬ÿ�����µĿռ䱻�ͷ�ʱ����ӵ���ָ���ǰ��
	block<T>* overmem = NULL; //��ų���buffer��С���ڴ�
	buffer<T> * firstbuffer = new buffer<T>;   //buffer�׵�ַ
	buffer<T> * currentbuffer = NULL;   //��ŵ�ǰbuffer��ַ
	size_type buffercount = BUFFER_SIZE;  //��������ʾ��ǰbuffer���ĵ���block��
};


template<typename T>
class MyAllocator {
private:	
	allocator<T> *rebindMyAllocator= NULL;   //���ñ�׼allocator����rebindMyAllocator
	memorypool<T> mp;

public:
	//�ӿڶ���
	typedef T value_type;
	typedef T* pointer;
	typedef const T* const_pointer;
	typedef T& reference;
	typedef const T& const_reference;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	template<class U>
	struct rebind {
		typedef MyAllocator<U> other;
	};
	MyAllocator() {};
	template <class U>
	MyAllocator(const MyAllocator<U> &other)
	{
		if (!std::is_same<T, U>::value)
			rebindMyAllocator = new allocator<T>();
	}
	~MyAllocator() {
		delete rebindMyAllocator;
	}
	pointer allocate(size_type n, const void *hint = 0)  //��׼��allocate����ӿ�
	{

		if (rebindMyAllocator)
			return rebindMyAllocator->allocate(n, hint);
		T* temp = mp.allocate(n);
		return temp;
	}
	void deallocate(pointer p, size_type n)    //��׼��deallocate����ӿ�
	{
		if (rebindMyAllocator) {
			rebindMyAllocator->deallocate(p, n);
			return;
		}
		mp.deallocate(p, n);
	}
	void construct(pointer p, value_type value) {
		mp.construct(p, value);
	}
	void destroy(pointer p) {
		mp.destroy(p);
	}
	pointer address(reference x) {  //���طǳ����������ͱ�����ַ
		mp.address(x);
	}
	const_pointer address(reference x) const {  //���س����������ͱ�����ַ
		mp.address(x);
	}
	size_type max_size() const {       // �������ɷ�����ڴ�
		return size_type(UINT_MAX / sizeof(T));
	}
	void newElement(value_type value)   //���ڴ������һ����������ռ䣬�����ö���Ĺ��캯��
	{
		mp.newElement(value);
	}

	void deleteElement(pointer p)    //�������󣬽��ڴ�ռ�黹���ڴ��
	{
		mp.deleteElement(p);
	}
};