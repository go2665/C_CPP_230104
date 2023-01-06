// Test.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>     // iostream의 기능을 쓰겠다.
#include "Test.h"
//using namespace std;

int main() 
{
    // Day01();
    // Day02();

    // 포인터(Pointer) : 메모리의 주소를 저장하는 변수
    int* pi;        // int의 포인터 타입
    float* pf;      // float의 포인터 타입

    int i = 10;

    pi = &i;        // i의 주소를 pi에 넣아라.

    std::cout << "i : " << i << ", i의 주소 : " << &i << std::endl;

    (*pi) = 100;    // pi에 기록된 주소를 찾아가서 그곳의 데이터를 100으로 바꾼다.
    std::cout << "i : " << i << ", i의 주소 : " << &i << std::endl;

    int j = i;

    // k에 i의 값을 복사해주고 싶은데 나는 pi밖에 모를 때.
    // 코드를 어떻게 작성해야 하나?
    int k = (*pi);  // pi가 가지고 있는 주소에 있는 데이터를 k에 복사해라.

    std::cout << "pi : " << pi << std::endl;
    pi = pi + 1;    // pi가 12일 때 pi + 1은?  => 16
    std::cout << "pi : " << pi << std::endl;
    //(*pi) = 200;

    // 제어문 ( Control Statement )

    // 조건문
    bool con = 1 < 10;  // true
    if ( con )          // 만약에 괄호안이 true면 {}를 실행해라
    {
        std::cout << "1은 10보다 작습니다.\n";
    }

    bool isRight = false;
    if (isRight)
    {
        std::cout << "오른쪽으로 가시오\n";
    }

    if (!isRight)
    {
        std::cout << "왼쪽으로 가시오\n";
    }

    if (isRight)       //만약에 () 사이가 true면 A부분을 실행하고 false면 B부분을 실행해라.
    {
        // A부분
        std::cout << "오른쪽으로 가시오\n";
    }
    else
    {
        // B부분
        std::cout << "왼쪽으로 가시오\n";
    }

    // 실습
    // 입력을 받아서 input에 값을 저장하기
    // input의 값이 홀수면 "홀수입니다."를 출력한다.
    // input의 값이 짝수면 "짝수입니다."를 출력한다.
    //int input;
    //std::cout << "숫자를 입력하세요 : ";
    //std::cin >> input;
    //if (input % 2 == 0)
    //{
    //    std::cout << "짝수입니다.\n";
    //}
    //else
    //{
    //    std::cout << "홀수입니다.\n";
    //}

    //std::cout << "숫자를 입력하세요 : ";
    //std::cin >> input;
    //if ( input < 10 )
    //{
    //    // 0 ~ 9
    //    std::cout << "input은 0~9 사이입니다.\n ";
    //}
    //else if ( input < 100 )
    //{
    //    // 10 ~ 99
    //    std::cout << "input은 10~99 사이입니다.\n ";
    //}
    //else
    //{
    //    // 100 ~
    //    std::cout << "input은 100 이상입니다.\n";
    //}

    int switchNum = 1;
    switch (switchNum)  // switch : 조건이 정확하게 지정되어있을 때 유용하다.
    {
    case 0:
    case 1:
        std::cout << "0이 나왔습니다.\n";
        std::cout << "1이 나왔습니다.\n";
        break;
    case 2:
        std::cout << "2가 나왔습니다.\n";
        break;
    default:
        std::cout << "0,1,2가 아니다.\n";
        break;
    }

    // 반복문
    // while : ()안이 참이면 {}를 반복한다.
    
    /*while (true)
    {
        std::cout << "안녕하세요.\n";
    }*/ 

    // 실습 : 안녕하세요를 3번 출력하기
    int count = 0;
    while (count < 3)
    {
        std::cout << "안녕하세요.\n";
        count++;
    }

    count = 0;
    do
    {
        std::cout << "안녕하세요2.\n";
        count++;
    } while (count<3); // do-while은 일단 {}내용을 실행하고 조건을 확인. 최소 한번은 실행해야 할 때 유용

    // i가 0부터 시작해서 ; i가 3보다 작을 때까지 ; 매번 i를 1씩 증가시키면서 반복해라
    for (int i = 0; i < 3; i++)     
    {
        std::cout << "안녕하세요3.\n";
    }

    count = 0;
    // 무한 루프
    while (true)
    {
        std::cout << "안녕하세요4.\n";
        count++;
        if (count > 2)
        {
            break;      // while 같은 것도 캔슬 할 수 있다.
        }
    }

    for (int i = 0; i < 10; i++)
    {
        std::cout << "출력 : ";
        if (i % 2 == 0)
            continue;       // 루프 안에서 이후 부분은 스킵하고 루프의 첫부분으로 이동

        std::cout << i << " 안녕하세요.\n";
    }

    //RAND_MAX = 32767
    srand(time(NULL));      // 랜덤 함수에 현재 시간을 시드값으로 설정한다.
    for (int i = 0; i < 10; i++)
    {
        int random = rand();    // random이라는 변수에 랜덤한 숫자를 준다. 0~RAND_MAX
        std::cout << random << std::endl;
    }

    int money = 1000;
    do
    {
        // 한번 실행할 때마다 랜덤으로 -100~100사이의 결과를 얻고 싶다.
        int result; // 랜덤으로 나온 결과를 저장할 변수
        result = -100 + rand() % 201;
        
        // 나온 결과는 money에 더해진다.
        money += result;

        // "다시 하고 싶으면 1, 끝내고 싶으면 2를 입력하세요 : "
        std::cout << "다시 하고 싶으면 1, 끝내고 싶으면 2를 입력하세요 : ";
        int input;
        std::cin >> input;
    }while (true);  // input이 1이 아니거나 money가 다 떨어졌을 때 종료하도록 조건 변경하기

    // 주말 과제 : 가위 바위 보 만들기
}

void Day02()
{
    // Day02
    // 산술연산자 : + - * /
    int a = 10;         // a라는 이름을 가진, int 타입의 변수를 만들고, 10이라는 값을 넣어라
    int b = 3;          // b라는 이름을 가진, int 타입의 변수를 만들고, 3이라는 값을 넣어라

    int c = a + b;      // c라는 이름을 가진, int 타입의 변수를 만들고, a와 b를 더한 값을 넣아라.

    std::cout << "a는 " << a << ", b는 " << b << ", c는 " << c << std::endl;

    //int d;
    //std::cout << "d는 " << d;    // 초기화 하지 않고 사용할 경우 쓰레기 값이 들어간다. 그래서 초기화해서 사용해야 한다.

    c = a - b;
    std::cout << "a는 " << a << ", b는 " << b << ", c는 " << c << std::endl;

    c = a * b;
    std::cout << "a는 " << a << ", b는 " << b << ", c는 " << c << std::endl;

    c = a / b;
    std::cout << "a는 " << a << ", b는 " << b << ", c는 " << c << std::endl;

    // 실습 : + - * /를 이용해서 a를 b로 나누었을 때의 나머지를 계산해보기.
    c = a - (a / b) * b;
    std::cout << "a는 " << a << ", b는 " << b << ", c는 " << c << std::endl;

    c = a % b;  // 나머지(modulo) 연산자
    std::cout << "a는 " << a << ", b는 " << b << ", c는 " << c << std::endl;

    a = 10;
    std::cout << "a = " << a << " (a=10이 나와야 한다.)" << std::endl;
    a = a + 1;
    std::cout << "a = " << a << " (a=11이 나와야 한다.)" << std::endl;
    a += 3; // a = a + 3;와 같음
    std::cout << "a = " << a << " (a=14이 나와야 한다.)" << std::endl;
    a++;
    std::cout << "a = " << a << " (a=15이 나와야 한다.)" << std::endl;
    ++a;
    std::cout << "a = " << a << " (a=16이 나와야 한다.)" << std::endl;
    std::cout << "a = " << a++ << " (a=16이 나와야 한다.)" << std::endl;  // 값을 먼저 확인하고 증가
    std::cout << "a = " << ++a << " (a=18이 나와야 한다.)" << std::endl;  // 값이 증가되고 확인
    std::cout << "a = " << a << " (a=18이 나와야 한다.)" << std::endl;

    int b2 = 10;
    b2 -= 3;

    float c2 = 10.0f;
    c2++;
    std::cout << c2 << std::endl;

    // 비교 연산자 
    // == : 같다
    // != : 다르다.
    // > : 크다
    // < : 작다
    // >= : 크거나 같다.
    // <= : 작거나 같다.

    a = b;  // = 는 대입 연산자. 연산자의 오른쪽에 있는 값을 왼쪽 변수에 넣어라
    a == b; // == 는 비교 연산자. 연산자의 오른쪽과 왼쪽이 같으면 true, 아니면 false

    a = 10;
    b = 20;
    bool d = (a == b);
    std::cout << "a = " << a << ", b = " << b << ", a == b는 " << d << "(결과는 false다.)" << std::endl;

    a = 10;
    b = 10;
    d = (a == b);
    std::cout << "a = " << a << ", b = " << b << ", a == b는 " << d << "(결과는 true다.)" << std::endl;

    d = (a != b);
    std::cout << "a = " << a << ", b = " << b << ", a == b는 " << d << "(결과는 false다.)" << std::endl;

    a = 15;
    b = 5;
    d = (a > b);
    std::cout << "a = " << a << ", b = " << b << ", a == b는 " << d << "(결과는 true다.)" << std::endl;

    // 논리 연산자 : 결과는 true아니면 false
    // && : and. 그리고. ~이고 ~다. 논리곱. && 양쪽에 있는 것이 모두 true일때만 true.
    // || : or. 또는. ~이거나 ~다. 논리합. || 양쪽에 있는 것이 하나라도 true면 true.
    // ! : not. 반대. true는 false로, false는 true로
    bool aaa = true;
    bool bbb = false;
    bool ccc;

    ccc = aaa && bbb;   // false
    ccc = aaa || bbb;   // true

    ccc = !aaa && bbb;  // false && false, false
    ccc = !aaa && !bbb; // false && true, false
    ccc = aaa || !bbb;  // true || true, true

    // 비트 연산자
    // &    : and. 둘 다 1일때만 1이다.
    // |    : or. 둘 중 하나가 1이면 1이다.
    // ^    : xor. 두개가 다르면 1.
    // ~    : not. 0은 1로, 1은 0으로
    // <<   : left shift. 왼쪽에 있는 비트를 오른쪽 수만큼 밀기
    // >>   : right shift.

    a = 1;  // 0001
    b = 3;  // 0011
    std::cout << std::bitset<4>(a) << std::endl;
    std::cout << std::bitset<4>(b) << std::endl;
    std::cout << std::bitset<4>(a & b) << " (0001가 나와야 한다.)" << std::endl;
    std::cout << std::bitset<4>(a | b) << " (0011가 나와야 한다.)" << std::endl;
    std::cout << std::bitset<4>(a ^ b) << " (0010가 나와야 한다.)" << std::endl;
    std::cout << std::bitset<4>(~b) << " (1100가 나와야 한다.)" << std::endl;
    c = a << 2;
    std::cout << std::bitset<4>(c) << " (0100가 나와야 한다.)" << std::endl;
    c = b >> 1;
    std::cout << std::bitset<4>(c) << " (0001가 나와야 한다.)" << std::endl;

    // 실습
    // int a; 에 세번째 비트가 1인지 확인해서 bool d;에 1이면 true 아니면 false를 넣는 코드 작성하기
    a = 6; // 6 = 0110, d = true;
    a = 8; // 8 = 1000, d = false;

    // <<, &, !=

    // 1 = 0001 오른쪽이 끝이다.
    int flag = 1 << 2;  // 0100
    d = (a & flag) != 0;   // a & flag가 0이 아니면 true, 0이면 false
    int flag2 = 1 << 1; // 0010
    flag |= flag2;      // flag = 0110
}

void Day01()
{
    std::cout << "Hello World!\nHello World!\n";
    std::cout << "내 이름은 고병조입니다.\n" << "나는 사람입니다.\n";

    //int i = 0;
    //std::cout << "i는 " << i << " 입니다.\n";
    //std::cin >> i;
    //std::cout << "i는 " << i << " 입니다.\n";

    //// 실습 - 생일을 입력받고 출력해보기
    //std::cout << "생일을 입력해 주세요. : ";
    //int month = 0;  
    //int day = 0;
    //std::cin >> month >> day;
    //std::cout << "당신의 생일은 " << month << "월 " << day << "일 입니다.\n";

    // 변수 : 데이터를 저장하기 위한 것들. 변하는 숫자
    // 변수는 정해진 종류의 데이터만 저장할 수 있다.
    // 데이터 타입 : 저장할 수 있는 데이터 종류별로 설정되어있다.
    // int : 정수형. 인티저. 소수점 없는 숫자만 저장 가능. 크기 : 32bit => 2^32만큼 표현이 가능하다.
    // float : 실수형. 플로트. 소수점 있는 숫자만 저장 가능. 크기 : 32bit. 태생적으로 오차가 존재한다.
    // bool : 불형. true 아니면 false 만 저장 가능.
    // char : 글자 하나를 저장하는 데이터 타입. (8bit 크기의 int와 같음)

    int a = 10;
    float b = 3.141592f;
    bool c = true;
    char d = 'a';

    std::cout << "a는 인티저이다. " << "a의 크기는 " << sizeof(a) << "Byte 이다.\n";
    std::cout << "b는 플로트이다. " << "b의 크기는 " << sizeof(b) << "Byte 이다.\n";
    std::cout << "c는 불이다. " << "c의 크기는 " << sizeof(c) << "Byte 이다.\n";
    std::cout << "d는 캐릭터이다. " << "d의 크기는 " << sizeof(d) << "Byte 이다.\n";

    //auto e = c;
    a = 20;

    // 상수 : 데이터 값이 변하지 않는 변수.
    const int ca = 10;
    //ca = 20;

    // 실습 - 변수들을 이용해서 + - * / 사용해보기
    // 자세히 볼것들
    // int 나누기
    // int와 float끼리 계산해보기
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
