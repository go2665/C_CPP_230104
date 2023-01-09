#pragma once
#include <bitset>		// 비트를 표시하기 위한 해더
#include <stdlib.h>		// 표준 라이브러리를 사용하기 위한 해더
#include <time.h>		// 시간을 받아오기 위한 해더
#include <Windows.h>	// 윈도우에서만 사용되는 것들을 사용하기 위한 해더

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



void Day01();

void Day02();

void Day03();

void Day03_SlotMachine();
