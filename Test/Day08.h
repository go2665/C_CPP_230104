#pragma once

#include <iostream>

using namespace std;

/// <summary>최소값을 구하는 함수</summary>
/// <param name="datas">최소값을 구할 데이터들이 들어있는 배열</param>
/// <param name="count">배열의 크기</param>
/// <returns>datas에 있는 값 중 가장 작은 값</returns>
int Min1(int datas[], int count);

/// <summary>최소값을 구하는 함수</summary>
/// <param name="pData">최소값을 구할 데이터들이 연속으로 들어있는 메모리 주소</param>
/// <param name="count">pData에 들어있는 데이터 갯수</param> 
/// <returns>pData에 있는 값 중 가장 작은 값</returns>
int Min2(int* pData, int count);

/// <summary>최대값을 구하는 함수</summary>
/// <param name="pData">최대값을 구할 데이터들이 연속으로 들어있는 메모리 주소</param>
/// <param name="count">pData에 들어있는 데이터 갯수</param> 
/// <returns>pData에 있는 값 중 가장 큰 값</returns>
int Max(int* pData, int count);

/// <summary>value값을 min보다 크거나 같고 max보다 작거나 같게 만드는 함수</summary>
/// <param name="value">변경하거나 유지할 값</param> 
/// <param name="min">value가 가질 수 있는 최소값</param>
/// <param name="max">value가 가질 수 있는 최대값</param>
/// <returns>변경되거나 원래대로인 value</returns>
int Clamp(int value, int min, int max);

float Clamp(float value, float min, float max);


template <typename T>					// 템플릿에 사용할 타입이름을 임시로 T라고 하자
inline T ClampTemplate(T value, T min, T max)
{
	if (value < min)
	{
		value = min;
	}
	else if (value > max)
	{
		value = max;
	}
	return value;
}

// inline : 함수 길이가 짧을 때 컴파일러가 함수 호출 대신 코드를 대체함.

// 구조체 : 종류가 다른 여러 데이터를 하나로 묶어 놓고 싶을 때 사용
struct PlayerInfo
{
	char name[32];
	int level = 1;
	float exp = 50.0f;
};

void Print_PlayerInfo(PlayerInfo* pInfo);
void Print_PlayerInfo_Deep(PlayerInfo info);

// 깊은 복사와 얕은 복사
// 깊은 복사는 완전한 사본을 만드는 것
//	장점 : 원본과 아무런 연관이 없는 별도의 메모리가 잡힌다.
//	단점 : 시간이 많이 걸린다.(새 메모리 확보 + 복사)
// 얕은 복사는 원본의 주소만 전달하는 것
//	장점 : 복사가 빠르다.
//	단점 : 원본까지 오염될 수 있다.
