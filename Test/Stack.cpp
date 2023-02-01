#include "Stack.h"

void Stack::Push(int data)
{	
	// Top 다음에 넣을 수 있으면 넣고
	// 가득 찼으면 "스택이 가득 차있습니다."라고 출력하기

	if (top < size - 1 )	// 스택이 가득 차있는지 확인
	{
		// 스택에 빈자리가 있다.
		top++;
		stack[top] = data;
	}
	else
	{
		// 스택이 가득 차 있다.
		cout << "스택이 가득 차있습니다." << endl;
	}

}

int Stack::Pop()
{
	int data = EMPTY;				// 기본 값으로 EMPTY 설정
	if (top > -1 && top < size)		// top이 적정한 범위인지 확인
	{
		data = stack[top];			// 적정범위 안쪽이면 data에 Top에 있는 데이터 복사
		top--;						// Top 감소
	}

	if (data == EMPTY)
	{
		cout << "스택이 비었습니다." << endl;		// 비어있으면 비어있다고 출력
	}

	return data;					// 결과 리턴
}

void Stack::Clear()
{
	top = STACK_IS_EMPTY;
	memset(stack, UINT32_MAX, sizeof(unsigned int) * size);
}

void Stack::Print()
{
	// [  ]
	// [  ]
	// [30] <- Top
	// [20]
	// [10]

	cout << "스택 출력" << endl;

	// 빈칸 출력하기
	int emptySize = size - top - 1;
	for (int i = 0; i < emptySize; i++)
	{
		cout << " [    ] " << endl;
	}

	if (top != STACK_IS_EMPTY)	// 스택이 비어있지 않으면 스택 내용 출력
	{
		// top부분 출력하기
		cout << " [ " << stack[top] << " ] <- Top" << endl;

		// top 아래쪽 출력하기
		for (int i = top - 1; i > -1; i--)
		{
			cout << " [ " << stack[i] << " ] " << endl;
		}
		cout << endl;
	}
}
