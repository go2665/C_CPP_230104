#pragma once
#include <bitset>		// ��Ʈ�� ǥ���ϱ� ���� �ش�
#include <stdlib.h>		// ǥ�� ���̺귯���� ����ϱ� ���� �ش�
#include <time.h>		// �ð��� �޾ƿ��� ���� �ش�
#include <Windows.h>	// �����쿡���� ���Ǵ� �͵��� ����ϱ� ���� �ش�

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
