// Test.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>     // iostream의 기능을 쓰겠다.
#include "Test.h"
#include <Windows.h>
using namespace std;

int main() 
{    
    srand(time(nullptr));

    // Day01();
    // Day02();
    // Day03();
    // Day03_SlotMachine();   
    // Day04_RockPaperScissors();
    // Day04();
    // Day05_RandomSelect();
    // Day05();
    // Day06();
    // Day07();
    // Day08();
    // Day09();
    // TestDay10();
    // TestDay11();

    TestDay12();
}

void Day08()
{
    int numbers[] = { 5,27,12,54,4 };
    int min = INT32_MAX;
    min = Min1(numbers, sizeof(numbers) / sizeof(int));
    cout << "Min value is " << min << endl;

    min = Min2(numbers, sizeof(numbers) / sizeof(int));
    cout << "Min value is " << min << endl;

    int max = Max(numbers, sizeof(numbers) / sizeof(int));
    cout << "Max value is " << max << endl;

    int clamp = Clamp(12, 5, 15);   // 12
    cout << "Clamp result is " << clamp << endl;

    clamp = Clamp(2, 5, 15);    // 5
    cout << "Clamp result is " << clamp << endl;

    clamp = Clamp(22, 5, 15);   // 15
    cout << "Clamp result is " << clamp << endl;


    cout << "Clamp result is " << ClampTemplate(22, 5, 15) << endl;
    cout << "Clamp result is " << ClampTemplate(22.5f, 5.5f, 20.1f) << endl;

    PlayerInfo info;    // PlayerInfo 타입의 변수. 이 변수의 이름은 info
    strcpy(info.name, "Human");
    info.level = 3;
    info.exp = 100.0f;

    // "This player's name is Human"
    // "Human level is 3"
    // "Human exp is 100.0"
    cout << "This player's name is " << info.name << endl;
    cout << info.name << " level is " << info.level << endl;
    cout << info.name << " exp is " << info.exp << endl;

    Print_PlayerInfo_Deep(info);
    Print_PlayerInfo(&info);

    int i = 0;
}

void Day07()
{
    // 구구단 단수를 입력하면 해당 구구단을 출력하는 함수 만들기
    int inputNum;
    cin >> inputNum;
    //Print_GuGuDan(inputNum);
    //Print_Star(inputNum);
    Print_Pyramid(inputNum);
}

void Day06()
{
    // 문자열 활용하기

    const char* testString = "01_Hello";
    char resultString[32];

    // 실습 : testString이 가지는 내용에서 _ 이후부분만 잘라서 resultString에 넣기

    // 1. testString의 내용을 확인하기
    // 2. _ 부분을 찾을 수 있어야 한다.
    // 3. 문자열을 복사할 수 있어야 한다.

    // for( 변수만들기; 조건 설정하기 ; 변수 변경하기)
    int size = strlen(testString);  // testString의 길이 구하기
    for (int i = 0; i < size; i++)   // i가 0에서 (size - 1)만큼 될때까지 반복시키기(i는 1씩 계속 증가)
    {
        if (testString[i] == '_')   // testString에 '_'가 있는지 처음부터 하나씩 확인
        {
            strcpy(resultString, testString + i + 1);   // '_'가 있으면 그 이후의 위치를 복사
            break;
        }
    }

    cout << "resultString : " << resultString << endl;

    int index = 0;
    while (testString[index] != '*' && testString[index] != '\0')
    {
        index++;
    }

    if (testString[index] != '\0')
        strcpy(resultString, testString + index + 1);
    else
        resultString[0] = '\0';

    cout << "resultString : " << resultString << endl;

    strcpy(resultString, strstr(testString, "_") + 1);
    cout << "resultString : " << resultString << endl;

    // strlen : 문자열 길이 구하기
    // 실습 : test1의 길이를 구하는 코드 작성하기.(strlen 사용금지)

    // strcmp : 문자열이 같은지 다른지 구하기
    // 실습 : test1과 "Hello world!"가 같으면 result에 true 다르면 false를 넣는 코드 작성하기(strcmp 사용금지)

    const char* test1 = "Hello World!";
    bool result;

    int length = 0;
    while (test1[length] != '\0')
    {
        length++;
    }
    cout << "test1의 길이는 " << length << "이다.\n";
    cout << "test1의 길이는 " << strlen(test1) << "이다.\n";

    int cmpLength = strlen(test1);
    const char* test2 = "Hello world!";
    result = true;
    for (int i = 0; i < cmpLength; i++)
    {
        if (test1[i] != test2[i])
        {
            result = false;
            break;
        }
    }

    if (result)
        cout << "\"" << test1 << "\"과 " << "\"" << test2 << "\"는 서로 같다.";
    else
        cout << "\"" << test1 << "\"과 " << "\"" << test2 << "\"는 서로 다르다.";

    // 동적 할당
    int array[5] = { 1,2,3,4,5 };

    // 숫자를 1~5를 입력받아서 입력 크기만큼 배열을 만들어서 array에 있는 것을 복사하고 싶다.
    int input = 3;  // 입력받은 수라고 가정

    // C 언어 방식
    // malloc은 void*로 결과를 돌려주는데 우리가 사용하는것은 int* 이기 때문에 캐스팅을 해줘야 한다.
    int* pArray = (int*)malloc(input * sizeof(int));   // 메모리 할당
    for (int i = 0; i < input; i++)
    {
        pArray[i] = array[i];
    }
    free(pArray);   // 메모리 해제
    pArray = NULL;  // 사용이 끝난 주소임을 표시(필수는 아니지만 해주는 것을 매우 추천)

    // C++ 언어 방식
    int* pArray2 = new int[input];  // pArray2에 int input개 짜리 배열을 만들어서 줘라.
    delete[] pArray2;               // pArray2가 할당받은 배열 메모리를 해제해라.

    int* pInt = new int;    // pInt에 int를 하나 할당해서 줘라
    delete pInt;            // pInt가 할당받은 메모리를 해제해라.


    // memory leek(메모리 누수)
    // 메모리를 할당 받고 해제하지 않아 사용 가능한 메모리가 점점 줄어드는 현상

    // 함수(Function)
    // 특정 기능을 수행하기 위한 코드 뭉치

    // 함수 사용법 : 함수의 이름을 적고 ()사이에 요구되는 파라메터를 입력하면 된다.
    //int result = Sum(1, 2);
}

int Sum(int a, int b)
{
    int result = a + b;     // 지역변수 : 함수 내부에 존재하는 변수들
    return result;
}

void Day05()
{
    int array_1d[4];    // 크기 4짜리 1차원 배열    (데이터 갯수는 4개)
    int array_2d[4][4]; // 크기 4*4짜리 2차원 배열. (데이터 갯수는 16개)
    int array[3][4];    // 크기 4짜리 1차원 배열을 3개 겹친 것

    // 실습 : array에 1부터 12까지 순서대로 넣어보기(for문을 이용할 것)

    // F9 : 단축키를 통해 브레이크 포인트를 설정/해제할 수 있다.

    int num = 1;
    for (int y = 0; y < 3; y++)
    {
        for (int x = 0; x < 4; x++)
        {
            array[y][x] = num;
            num++;
        }
    }

    int size = 3 * 4;
    num = 0;
    for (int i = 0; i < size; i++)
    {
        int* pArray = &array[0][0] + i; // array[0][0]의 주소에 i만큼 더한다. (i*4만큼 주소가 변경됨)  
        *pArray = num;          // 위에서 계산한 주소가 가리키는 곳에 저장된 데이터를 num으로 변경
    }

    // array[2];
    // array + 2

    // array[3][2]  // 가로2 세로3
    // array[2][1] = 3; array + (2 * 2 + 1)

    char str[10] = "Hello";
    const char* str2 = "Hello";

    cout << str << endl;

    str[3] = '\0';
    cout << str << endl;

    cout << "str2의 길이는 " << strlen(str2) << "입니다." << endl; // 문자열 길이 구하기

    const char* str3 = " World";
    char strDest[128];
    strcpy(strDest, str2);  // 문자열 복사하기
    strcat(strDest, str3);  // 문자열 붙여넣기
    if (strcmp(strDest, "Hello World") == 0)    // 문자열 비교하기
    {
        cout << "strDest와 Hello World는 같다" << endl;
    }

    int num2 = atoi("123");     // 글자를 숫자로 바꾸는 함수
    char strDest2[64];
    _itoa(num2, strDest2, 10);  // 숫자를 글자로 바꾸는 함수

    //cout << strDest << endl;

    
}

void Day05_RandomSelect()
{
    srand(time(NULL));
    int cup[3] = { Fail, Fail, Fail };
    cout << "cup의 크기는 " << sizeof(cup) << endl; // sizeof(cup) / sizeof(int) 는 배열의 크기
    cout << "int의 크기는 " << sizeof(int) << endl;
    int size = sizeof(cup) / sizeof(int);           // 3

    int select = rand() % size;    // 0,1,2 중 하나
    cup[select] = Winning;

    int mySelect = -1;
    while (mySelect < 0 || mySelect >(size - 1))
    {
        cout << "어느것을 선택할까요?(0~2를 선택하세요) : ";
        cin >> mySelect;
        if (mySelect < 0 || mySelect >(size - 1))
        {
            cout << "숫자를 잘못 입력했습니다. 다시 입력하세요. \n";
        }
    }

    if (cup[mySelect] == Winning)
    {
        cout << "당신의 승리입니다.\n\n";
    }
    else
    {
        cout << "당신의 패배입니다.\n\n";
    }
}

void Day04()
{
    int str;
    int dex;
    int stm;
    int intelligence;
    int wisdom;

    // 배열(같은 종류의 데이터를 여러개 가질 수 있다.)
    int status[5];  // int 5개짜리 배열
    status[0] = 10;
    status[1] = 20;
    status[2] = 30;
    status[3] = 40;
    status[4] = 50;

    // &(status[0]) == status   // 배열에 저장된 값은 배열의 첫번째 데이터의 주소이다.

    int* pStatus = &(status[0]);

    for (int i = 0; i < 5; i++)
    {
        cout << "i = " << i << "\tstatus[i] = " << status[i] << endl;
        cout << "i = " << i << "\tpStatus + i = " << *(pStatus + i) << endl << endl;
    }

    // 실습 - int 9개짜리 배열을 만들고 숫자를 하나입력받아 그 숫자의 구구단을 배열에 저장하고 출력
    // ex) 5를 입력받았으면 배열에다가 5단을 기억 시키고 배열에 들어있는 내용을 순서대로 출력한다.

    int gugu[9];
    //int gugu2[9] = {1,2,3,4,5,6,7,8,9};
    int input = 0;
    cout << "\n\n\n구구단을 출력할 숫자를 입력하세요 : ";
    cin >> input;
    for (int i = 0; i < 9; i++)
    {
        gugu[i] = input * (i + 1);
        cout << input << " * " << (i + 1) << " = " << gugu[i] << endl;
    }
}

void Day04_RockPaperScissors()
{
    srand(time(NULL));

    cout << "가위 바위 보를 합시다.\n";

    int retry = 1;

    while (retry == 1)
    {
        // 나의 가위바위보 선택
        int select = 0;
        while (select < 1 || select > 3)
        {
            cout << "\n\n가위바위보를 선택하세요(1:가위, 2:바위, 3:보) : ";
            cin >> select;
            RockPaperScissors mSelect = (RockPaperScissors)select;
            switch (mSelect)
            {
            case Scissors:
                cout << "당신은 가위를 냈습니다.\n";
                break;
            case Rock:
                cout << "당신은 바위를 냈습니다.\n";
                break;
            case Paper:
                cout << "당신은 보를 냈습니다.\n";
                break;
            default:
                cout << "잘못된 입력입니다. 다시 입력하세요.\n";
                break;
            }
        }

        // 적의 선택
        int enemySelect = rand() % 3 + 1;
        // int를 enum인 RockPaperScissors 타입으로 캐스팅했다.
        RockPaperScissors eSelect = (RockPaperScissors)enemySelect;
        switch (eSelect)
        {
        case Scissors:
            cout << "상대는 가위를 냈습니다.\n";
            break;
        case Rock:
            cout << "상대는 바위를 냈습니다.\n";
            break;
        case Paper:
            cout << "상대는 보를 냈습니다.\n";
            break;
        default:
            break;
        }

        // 승패 결정 내리기
        RPS_Result result = Draw;
        if (select == Scissors)
        {
            if (enemySelect == Scissors)
            {
                result = Draw;
            }
            else if (enemySelect == Rock)
            {
                result = Lose;
            }
            else if (enemySelect == Paper)
            {
                result = Win;
            }
        }
        else if (select == Rock)
        {
            if (enemySelect == Scissors)
            {
                result = Win;
            }
            else if (enemySelect == Rock)
            {
                result = Draw;
            }
            else if (enemySelect == Paper)
            {
                result = Lose;
            }
        }
        else if (select == Paper)
        {
            if (enemySelect == Scissors)
            {
                result = Lose;
            }
            else if (enemySelect == Rock)
            {
                result = Win;
            }
            else if (enemySelect == Paper)
            {
                result = Draw;
            }
        }

        // 승패 결과 출력
        switch (result)
        {
        case Win:
            cout << "당신은 승리했습니다.\n";
            break;
        case Lose:
            cout << "당신은 패배했습니다.\n";
            break;
        case Draw:
            cout << "비겼습니다.\n";
            break;
        default:
            break;
        }

        cout << "다시 하시겠습니까? (1:예, 다른수:아니오) : ";
        cin >> retry;
    }
}

void Day03_SlotMachine()
{
    // 슬롯 머신
    srand(time(NULL));  // 시드값을 현재 시간으로 설정
    int money = 1000;

    while (true)
    {
        std::cout << "현재 " << money << "원을 가지고 있습니다.\n";
        std::cout << "슬롯을 돌립니다";

        for (int i = 0; i < 10; i++)
        {
            Sleep(100);         // 0.1초(100 마이크로 세컨드) 기다리기
            std::cout << ".";
        }

        int result = -100 + rand() % 201;
        if (result > 0)
        {
            std::cout << std::endl << result << "원을 얻었습니다.\n";
        }
        else if (result < 0)
        {
            std::cout << std::endl << abs(result) << "원을 잃었습니다.\n";
        }
        else
        {
            std::cout << std::endl << "따지도 잃지도 않았습니다.\n";
        }

        money += result;

        std::cout << "다시 하고 싶으면 1, 끝내고 싶으면 다른수를 입력하세요 : ";
        int input;
        std::cin >> input;

        if (input != 1)
        {
            break;
        }
    }
    std::cout << "종료합니다.\n\n";
}

void Day03()
{
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
    if (con)          // 만약에 괄호안이 true면 {}를 실행해라
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
        //result = -100 + rand() % 201;
        result = rand() % 201;  // 0 ~ 200
        result -= 100;          // -100 ~ 100

        // 나온 결과는 money에 더해진다.
        money += result;

        // "다시 하고 싶으면 1, 끝내고 싶으면 2를 입력하세요 : "
        std::cout << "다시 하고 싶으면 1, 끝내고 싶으면 2를 입력하세요 : ";
        int input;
        std::cin >> input;
    } while (true);  // input이 1이 아니거나 money가 다 떨어졌을 때 종료하도록 조건 변경하기

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
