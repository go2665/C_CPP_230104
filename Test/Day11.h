#pragma once

#include "Human.h"
#include "Wizard.h"
#include "Warrior.h"

void TestDay11();


// 가상 함수(virtual function)
// 상속받은 클래스 -> 자식클래스
// 상속해주는 클래스 -> 부모클래스
// 
// 자식 클래스에 가상함수가 있으면 자식 클래스를 부모 클래스 타입으로 저장했을 때 
// 가상함수를 호출하면 자기 자신(가상함수를 호출한 클래스)의 함수가 호출된다.


// 실습 : Defence 수정하기
// Warrior는 데미지를 받을 때 무조건 50%가 감소되어서 받는다.
// Wizzard는 데미지를 받을 때 50%의 확률로 회피한다.