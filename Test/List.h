#pragma once
#include <iostream>
#include "ListNode.h"

using namespace std;

class List
{
public:
	/// <summary>
	/// ������
	/// </summary>
	List();

	/// <summary>
	/// �Ҹ���
	/// </summary>
	~List();	// �Ҹ��ڿ� virtual�� ����� ���� ���̰� ����� ���Ѵٸ� ������ ����

	/// <summary>
	/// ����Ʈ�� ���� ���
	/// </summary>
	ListNode* pHead = nullptr;

	/// <summary>
	/// ����Ʈ�� ������ ���
	/// </summary>
	ListNode* pTail = nullptr;

	/// <summary>
	/// ����Ʈ�� ����(����� ������ �� �� ����� �ϴ� ���̶� unsigned(��ȣ����)���� ���� ����
	/// </summary>
	unsigned int length = 0;

	/// <summary>
	/// ����Ʈ�� �����͸� �߰��ϴ� �Լ�
	/// </summary>
	/// <param name="data">�߰��� ������</param>
	/// <param name="index">�߰��� ��ġ</param>
	void Insert(int data, int index);

	/// <summary>
	/// ����Ʈ���� Ư�� ��ġ�� ��带 �����ϴ� �Լ�
	/// </summary>
	/// <param name="index">������ ��ġ</param>
	void RemoveTargetIndex(int index);

	/// <summary>
	/// ����Ʈ���� Ư�� ���� ���� ��带 �����ϴ� �Լ�
	/// </summary>
	/// <param name="data">������ ������</param>
	void RemoveTargetData(int data);

	/// <summary>
	/// ����Ʈ���� ��� ��带 ������ �Լ�
	/// </summary>
	void Clear();

	/// <summary>
	/// ����Ʈ�� ����ϴ� �Լ�
	/// </summary>
	void Print();
};

// ���� : �������� �߰�/����/������ �����ϴ�.
// ���� : ���� �������� ������.