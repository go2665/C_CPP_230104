#pragma once			// 중복으로 추가되는 것들 방지(include 순서 맞출때 편리하다.)
#include <iostream>

using namespace std;

// 구구단 단수를 입력하면 해당 구구단을 출력하는 함수 만들기
// 함수는 특정 기능을 수행하는 코드 뭉치
// 함수의 이름 : GuGuDan
// GuGuDan의 기능 : 입력에 맞게 구구단을 화면에 출력

// 리턴 타입 : void. 그 이유는 결과를 받아올 이유가 없으니까.
// 이름 : Print_GuGuDan
// 파라메터 : 출력할 단
void Print_GuGuDan(int dan);



// 1 이상의 양수를 입력하면 입력된 수 만큼 *를 출력하는 함수.(단 *은 한 줄 내려갈 때마다 1개씩 증가한다.)
// ex) 3을 입력했다.
//	*
//	**
//	***

void Print_Star(int floorCount);