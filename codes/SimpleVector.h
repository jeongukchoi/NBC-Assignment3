#ifndef SIMPLEVECTOR_H_
#define SIMPLEVECTOR_H_

#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
class SimpleVector {
private:
	T* data;
	int currentSize;
	int currentCapacity;

	// resize: 인자로 받은 정수 값으로 배열의 크기 재할당
	// 1. newCapacity 의 크기로 새로운 배열을 생성하고 기존 data 배열의 값을 복사해 넣는다.
	// 2. 기존 data 는 메모리 해제하고 data가 새로운 배열을 가리키도록 변경한다.
	void resize(int newCapacity) {
		if (newCapacity > currentCapacity) {
			T* newData = new T[newCapacity]; // newCapacity 크기로 새로운 배열 newData 생성
			memcpy(newData, data, sizeof(data[0]) * currentSize); // 원래 data 에서 newData 로 복사 (memory to memory)
			delete[] data; // 기존에 동적 할당된 data 배열 메모리 해제
			data = newData; // data 가 newData 를 가리키도록 포인터 대입
			currentCapacity = newCapacity; // 현재 capacity 업데이트
			cout << "Resized to capacity of " << currentCapacity << endl;
		}
	}

public:
	// 기본 생성자: currentSize, currentCapacity, data 배열 초기화
	SimpleVector(int capacity = 10) : currentSize(0), currentCapacity(capacity) { data = new T[capacity]; }
	
	// 복사 생성자
	SimpleVector(const SimpleVector& other) {
		// other 의 size, capacity, data를 현재 객체의 각 필드에 대입
		currentCapacity = other.currentCapacity;
		currentSize = other.currentSize;
		data = new T[currentCapacity];
		memcpy(data, other.data, sizeof(other.data[0]) * currentSize);
	}

	// 소멸자: 동적으로 할당된 배열 data 메모리 해제
	~SimpleVector() { delete[] data; /** 궁금하면 data 주소 체크해보기 - cout << "deleteing " << data << "...\n"; **/ }
	
	// 배열의 맨 끝에 value 추가
	void push_back(const T& value) {
		// 현재 원소 갯수가 배열의 크기보다 작을 경우 삽입
		if (currentSize < currentCapacity) {
			data[currentSize] = value;
			currentSize++;
		}

		// 현재 원소 갯수가 배열의 크기보다 크거나 같을 경우 resize 후 삽입
		else {
			cout << "SimpleVector is full. ";
			resize(currentCapacity + 5);
			data[currentSize] = value;
			currentSize++;
		}
	}

	// 맨 끝 원소 제거
	void pop_back() {
		// 현재 원소 갯수 카운트를 감소시켜 무시함. 추후 push_back에 의해 덮어씌워지도록 만듦
		if (currentSize > 0) {
			currentSize--;
		}
		else {
			cout << "Cannot pop_back. SimpleVector is empty.\n";
		}
	}

	// 현재 원소 갯수 반환
	int size() { return currentSize; }

	// 현재 내부 배열의 크기 반환
	int capacity() { return currentCapacity; }

	// 현재 원소 오름차순 정렬
	void sortData() {
		if (currentSize > 1) {
			// std::sort()에 시작위치, 끝위치+1 인자로 전달
			sort(data, data + currentSize);
			cout << "Data successfully sorted.\n";
		}
		else {
			cout << "Cannot sort. Not enough data in SimpleVector.\n";
		}
	}

	// 인덱스 i 에 위치한 원소 반환
	T at(int i) const {
		if (i >= 0 && i < currentSize) {
			return data[i];
		}
		else {
			cout << "Index " << i << " is out of range. Index must be less than " << currentSize << endl;
			return 0;
		}
	}
};

#endif
