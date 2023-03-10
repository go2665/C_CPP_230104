#pragma once
#include "Human.h"
#include "Warrior.h"
#include "Wizard.h"

void TestDay10();


// 상속
// 객체지향의 핵심 개념 중 하나
// 오브젝트를 추상화시켜서 공통적인 부분을 부모 클래스로 만들고
// 부모클래스를 상속 받은 클래스를 만들어 세세한 변화를 추가하는 기법

// 추상화 
// 비슷한 기능을 가지는 오브젝트(객체)들의 공통적인 부분을 묶어서 전체적인 카테고리를 표현하는 것

// 부모 클래스 : 상속 해주는 클래스(슈퍼 클래스라고도 함)
// 자식 클래스 : 상속 받은 클래스

// 상속을 받은 자식 클래스는 부모 클래스의 기능을 전부 사용할 수 있다.(단 접근제한자를 고려해야 한다.)

// 실습 : Wizard 클래스 만들기. Wizard 클래스는 Fireball을 사용할 수 있어야 한다.

// 접근 제한자(맴버에 대한 접근 권한을 설정하는 것)
// public : 모두가 접근할 수 있다.
// protected : 나랑 나를 상속받은 대상들만 접근할 수 있다.
// private : 나만 접근할 수 있다.