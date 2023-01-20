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
	void RemoveTargetData(int data);

	/// <summary>
	/// 리스트에서 모든 노드를 제거할 함수
	/// </summary>
	void Clear();

	/// <summary>
	/// 리스트를 출력하는 함수
	/// </summary>
	void Print();
};

// 장점 : 데이터의 추가/삽입/삭제가 편리하다.
// 단점 : 랜덤 엑세스가 느리다.
