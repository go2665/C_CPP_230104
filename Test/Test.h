#pragma once
#include <bitset>		// 비트를 표시하기 위한 해더
#include <stdlib.h>		// 표준 라이브러리를 사용하기 위한 해더
#include <time.h>		// 시간을 받아오기 위한 해더
#include <Windows.h>	// 윈도우에서만 사용되는 것들을 사용하기 위한 해더
#include <string.h>		// 문자열 처리 함수들을 사용하기 위한 해더
#include <string>

#include "Day07.h"
#include "Day08.h"
#include "Day09.h"
#include "Day10.h"

enum RockPaperScissors
{
	Scissors = 1,
	Rock,	// = 2
	Paper	// = 3
};

enum RPS_Result
{
	Win,	// = 0
	Lose,	// = 1
	Draw	// = 2
};

enum Trickery
{
	Fail,
	Winning
};


void Day01();

void Day02();

void Day03();

void Day03_SlotMachine();

void Day04_RockPaperScissors();

void Day04();

void Day05_RandomSelect();

void Day05();

// 선언부
// 변수, 함수, 클래스, 구조체가 있다는 것을 알리는 부분

// 함수는 선언부에서 함수 프로토타입을 작성한다.
// 프로토타입 : 다른 함수와 구분할 수 있게 해주는 최소 요소만 기록해 놓은 것
// 함수 프로토타입의 구성요소
//	1) 리턴 타입 : 함수가 실행이 끝났을 때 돌려주는 값의 타입. 
//				함수 프로토타입의 제일 앞에 써있는 데이터 타입.
//				리턴이 없을 경우 리턴 타입을 void로 설정하면 된다.
//	2) 함수의 이름 : 다른 함수와 가장 크게 구분할 수 있게 해주는 것.
//					리턴 타입 뒤에 나오는 문장이 함수의 이름.
//					대체로 알파벳과 _만 가능. 
//					숫자로 시작하면 안된다. 숫자가 시작이후에 들어가는 것은 가능.
//					예약어나 키워드는 불가능
//	3) 파라메터(매개변수) : 함수 내부로 전달하는 데이터.
//							함수 이름 뒤에 있는 () 사이에 있는 것.
//							0개 이상 가능. 추가 할 때마다 콤마(,)로 구분하면 된다.

// 함수의 구성요소 : 함수의 프로토타입 구성요소에 함수 바디가 추가된다. 
//					함수 파라메터 뒤에 있는 {} 영역.

int Sum(int a, int b);

void Day06();

void Day07();

void Day08();
