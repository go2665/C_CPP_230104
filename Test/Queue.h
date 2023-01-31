#pragma once
#include <iostream>
#include "QueueNode.h"

using namespace std;

class Queue
{
public:		// 모든 것들이 사용 가능
	~Queue()
	{
		Clear();	// 노드가 남아있는 상태에서 삭제했을 때를 대비
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
	QueueNode* pFront = nullptr;	// Front의 주소
	QueueNode* pRear = nullptr;		// Rear의 주소

	const int QUEUE_EMPTY = INT32_MIN;	// 큐가 비었을 때 Dequeue하면 리턴이 되는 값
};

