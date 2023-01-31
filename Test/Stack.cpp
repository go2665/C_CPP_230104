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
	// 데이터가 있으면 1개 꺼내서 리턴
	// 비어있으면 EMPTY 리턴
	return 0;
}

void Stack::Clear()
{
}

void Stack::Print()
{
	// [  ]
	// [  ]
	// [30] <- Top
	// [20]
	// [10]

	// 빈칸 출력하기
	int emptySize = size - top - 1;
	for (int i = 0; i < emptySize; i++)
	{
		cout << " [    ] " << endl;
	}

	// top부분 출력하기
	cout << " [ " << stack[top] << " ] <- Top" << endl;
	
	// top 아래쪽 출력하기
	for (int i = top-1; i > -1; i--)
	{
		cout << " [ " << stack[i] << " ] " << endl;
	}
	cout << endl;
}
