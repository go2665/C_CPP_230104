#pragma once
#include <memory.h>
#include <iostream>

using namespace std;


class CircularQueue
{
public:		// 모든 것들이 사용 가능
	CircularQueue()
	{
		front = 0;
		rear = 0;
		memset(queue, EMPTY, sizeof(int) * Queue_Size);
	}

	/// <summary>
	/// 데이터 하나를 큐에 추가하는 함수
	/// </summary>
	/// <param name="data">추가할 데이터</param>
	void Enqueue(int data);

	/// <summary>
	/// 큐에서 데이터를 하나 제거하는 함수
	/// </summary>
	/// <returns>큐에서 제거한 데이터</returns>
	int Dequeue();

	/// <summary>
	/// 큐에서 데이터를 모두 제거하는 함수
	/// </summary>
	void Clear();

	/// <summary>
	/// 큐에 들어있는 모든 데이터를 출력하는 함수
	/// </summary>
	void Print();

protected:	// 나와 나를 상속 받은 것들만 사용 가능
private:	// 나만 사용 가능
	static const int Queue_Size = 6;	// 정적 상수. 모든 CircularQueue가 같은 값을 가진다.
	int queue[Queue_Size];				// 정적 상수를 이용해 배열 즉시 생성.

	const int EMPTY = INT32_MIN;

	int front = 0;
	int rear = 0;

	/// <summary>
	/// 큐가 비었는지 확인해주는 함수
	/// </summary>
	/// <returns>큐가 비었으면 true. 아니면 false</returns>
	inline bool IsEmpty() { return front == rear; }	// 인라인 함수라 함수가 호출되는 것이 아니라 컴퍼일러에 의해서 코드가 교체된다.

	/// <summary>
	/// 큐가 가득 찼는지 확인해주는 함수
	/// </summary>
	/// <returns>큐가 가득찼으면 true, 아니면 false</returns>
	inline bool IsFull() { return front == (rear + 1) % Queue_Size; }
};

