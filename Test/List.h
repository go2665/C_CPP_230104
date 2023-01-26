#pragma once
#include <iostream>
#include "ListNode.h"

using namespace std;

class List
{
public:
	/// <summary>
	/// 생성자
	/// </summary>
	List();

	/// <summary>
	/// 소멸자
	/// </summary>
	~List();	// 소멸자에 virtual은 상속할 때는 붙이고 상속을 안한다면 붙이지 마라

	/// <summary>
	/// 리스트의 시작 노드
	/// </summary>
	ListNode* pHead = nullptr;

	/// <summary>
	/// 리스트의 마지막 노드
	/// </summary>
	ListNode* pTail = nullptr;

	/// <summary>
	/// 리스트의 길이(절대로 음수가 될 수 없어야 하는 값이라 unsigned(부호없음)으로 변수 생성
	/// </summary>
	unsigned int length = 0;

	/// <summary>
	/// 리스트에 데이터를 추가하는 함수
	/// </summary>
	/// <param name="data">추가할 데이터</param>
	/// <param name="index">추가할 위치</param>
	void Insert(int data, int index);

	/// <summary>
	/// 리스트에서 특정 위치의 노드를 제거하는 함수
	/// </summary>
	/// <param name="index">제거할 위치</param>
	void RemoveTargetIndex(int index);
		
	/// <summary>
	/// 리스트에서 특정 값을 가진 노드를 제거하는 함수
	/// </summary>
	/// <param name="data">제거할 데이터</param>
	/// <returns>삭제에 성공하면 true. 실패하면 false</returns>
	bool RemoveTargetData(int data);

	/// <summary>
	/// 리스트에서 data가 있는 위치를 리턴
	/// </summary>
	/// <param name="data">찾을 데이터</param>
	/// <returns>data가 있는 위치.없으면 NOT_FOUND 리턴 </returns>
	int FindPosition(int data);

	/// <summary>
	/// 리스트에서 모든 노드를 제거할 함수
	/// </summary>
	void Clear();

	/// <summary>
	/// 리스트를 출력하는 함수
	/// </summary>
	void Print();

private:
	const int NOT_FOUND = -1;
};

// 장점 : 데이터의 추가/삽입/삭제가 편리하다.
// 단점 : 랜덤 엑세스가 느리다.
