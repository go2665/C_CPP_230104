// Test.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//
#include <iostream>     // iostream�� ����� ���ڴ�.
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

    PlayerInfo info;    // PlayerInfo Ÿ���� ����. �� ������ �̸��� info
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
    // ������ �ܼ��� �Է��ϸ� �ش� �������� ����ϴ� �Լ� �����
    int inputNum;
    cin >> inputNum;
    //Print_GuGuDan(inputNum);
    //Print_Star(inputNum);
    Print_Pyramid(inputNum);
}

void Day06()
{
    // ���ڿ� Ȱ���ϱ�

    const char* testString = "01_Hello";
    char resultString[32];

    // �ǽ� : testString�� ������ ���뿡�� _ ���ĺκи� �߶� resultString�� �ֱ�

    // 1. testString�� ������ Ȯ���ϱ�
    // 2. _ �κ��� ã�� �� �־�� �Ѵ�.
    // 3. ���ڿ��� ������ �� �־�� �Ѵ�.

    // for( ���������; ���� �����ϱ� ; ���� �����ϱ�)
    int size = strlen(testString);  // testString�� ���� ���ϱ�
    for (int i = 0; i < size; i++)   // i�� 0���� (size - 1)��ŭ �ɶ����� �ݺ���Ű��(i�� 1�� ��� ����)
    {
        if (testString[i] == '_')   // testString�� '_'�� �ִ��� ó������ �ϳ��� Ȯ��
        {
            strcpy(resultString, testString + i + 1);   // '_'�� ������ �� ������ ��ġ�� ����
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

    // strlen : ���ڿ� ���� ���ϱ�
    // �ǽ� : test1�� ���̸� ���ϴ� �ڵ� �ۼ��ϱ�.(strlen ������)

    // strcmp : ���ڿ��� ������ �ٸ��� ���ϱ�
    // �ǽ� : test1�� "Hello world!"�� ������ result�� true �ٸ��� false�� �ִ� �ڵ� �ۼ��ϱ�(strcmp ������)

    const char* test1 = "Hello World!";
    bool result;

    int length = 0;
    while (test1[length] != '\0')
    {
        length++;
    }
    cout << "test1�� ���̴� " << length << "�̴�.\n";
    cout << "test1�� ���̴� " << strlen(test1) << "�̴�.\n";

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
        cout << "\"" << test1 << "\"�� " << "\"" << test2 << "\"�� ���� ����.";
    else
        cout << "\"" << test1 << "\"�� " << "\"" << test2 << "\"�� ���� �ٸ���.";

    // ���� �Ҵ�
    int array[5] = { 1,2,3,4,5 };

    // ���ڸ� 1~5�� �Է¹޾Ƽ� �Է� ũ�⸸ŭ �迭�� ���� array�� �ִ� ���� �����ϰ� �ʹ�.
    int input = 3;  // �Է¹��� ����� ����

    // C ��� ���
    // malloc�� void*�� ����� �����ִµ� �츮�� ����ϴ°��� int* �̱� ������ ĳ������ ����� �Ѵ�.
    int* pArray = (int*)malloc(input * sizeof(int));   // �޸� �Ҵ�
    for (int i = 0; i < input; i++)
    {
        pArray[i] = array[i];
    }
    free(pArray);   // �޸� ����
    pArray = NULL;  // ����� ���� �ּ����� ǥ��(�ʼ��� �ƴ����� ���ִ� ���� �ſ� ��õ)

    // C++ ��� ���
    int* pArray2 = new int[input];  // pArray2�� int input�� ¥�� �迭�� ���� ���.
    delete[] pArray2;               // pArray2�� �Ҵ���� �迭 �޸𸮸� �����ض�.

    int* pInt = new int;    // pInt�� int�� �ϳ� �Ҵ��ؼ� ���
    delete pInt;            // pInt�� �Ҵ���� �޸𸮸� �����ض�.


    // memory leek(�޸� ����)
    // �޸𸮸� �Ҵ� �ް� �������� �ʾ� ��� ������ �޸𸮰� ���� �پ��� ����

    // �Լ�(Function)
    // Ư�� ����� �����ϱ� ���� �ڵ� ��ġ

    // �Լ� ���� : �Լ��� �̸��� ���� ()���̿� �䱸�Ǵ� �Ķ���͸� �Է��ϸ� �ȴ�.
    //int result = Sum(1, 2);
}

int Sum(int a, int b)
{
    int result = a + b;     // �������� : �Լ� ���ο� �����ϴ� ������
    return result;
}

void Day05()
{
    int array_1d[4];    // ũ�� 4¥�� 1���� �迭    (������ ������ 4��)
    int array_2d[4][4]; // ũ�� 4*4¥�� 2���� �迭. (������ ������ 16��)
    int array[3][4];    // ũ�� 4¥�� 1���� �迭�� 3�� ��ģ ��

    // �ǽ� : array�� 1���� 12���� ������� �־��(for���� �̿��� ��)

    // F9 : ����Ű�� ���� �극��ũ ����Ʈ�� ����/������ �� �ִ�.

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
        int* pArray = &array[0][0] + i; // array[0][0]�� �ּҿ� i��ŭ ���Ѵ�. (i*4��ŭ �ּҰ� �����)  
        *pArray = num;          // ������ ����� �ּҰ� ����Ű�� ���� ����� �����͸� num���� ����
    }

    // array[2];
    // array + 2

    // array[3][2]  // ����2 ����3
    // array[2][1] = 3; array + (2 * 2 + 1)

    char str[10] = "Hello";
    const char* str2 = "Hello";

    cout << str << endl;

    str[3] = '\0';
    cout << str << endl;

    cout << "str2�� ���̴� " << strlen(str2) << "�Դϴ�." << endl; // ���ڿ� ���� ���ϱ�

    const char* str3 = " World";
    char strDest[128];
    strcpy(strDest, str2);  // ���ڿ� �����ϱ�
    strcat(strDest, str3);  // ���ڿ� �ٿ��ֱ�
    if (strcmp(strDest, "Hello World") == 0)    // ���ڿ� ���ϱ�
    {
        cout << "strDest�� Hello World�� ����" << endl;
    }

    int num2 = atoi("123");     // ���ڸ� ���ڷ� �ٲٴ� �Լ�
    char strDest2[64];
    _itoa(num2, strDest2, 10);  // ���ڸ� ���ڷ� �ٲٴ� �Լ�

    //cout << strDest << endl;

    
}

void Day05_RandomSelect()
{
    srand(time(NULL));
    int cup[3] = { Fail, Fail, Fail };
    cout << "cup�� ũ��� " << sizeof(cup) << endl; // sizeof(cup) / sizeof(int) �� �迭�� ũ��
    cout << "int�� ũ��� " << sizeof(int) << endl;
    int size = sizeof(cup) / sizeof(int);           // 3

    int select = rand() % size;    // 0,1,2 �� �ϳ�
    cup[select] = Winning;

    int mySelect = -1;
    while (mySelect < 0 || mySelect >(size - 1))
    {
        cout << "������� �����ұ��?(0~2�� �����ϼ���) : ";
        cin >> mySelect;
        if (mySelect < 0 || mySelect >(size - 1))
        {
            cout << "���ڸ� �߸� �Է��߽��ϴ�. �ٽ� �Է��ϼ���. \n";
        }
    }

    if (cup[mySelect] == Winning)
    {
        cout << "����� �¸��Դϴ�.\n\n";
    }
    else
    {
        cout << "����� �й��Դϴ�.\n\n";
    }
}

void Day04()
{
    int str;
    int dex;
    int stm;
    int intelligence;
    int wisdom;

    // �迭(���� ������ �����͸� ������ ���� �� �ִ�.)
    int status[5];  // int 5��¥�� �迭
    status[0] = 10;
    status[1] = 20;
    status[2] = 30;
    status[3] = 40;
    status[4] = 50;

    // &(status[0]) == status   // �迭�� ����� ���� �迭�� ù��° �������� �ּ��̴�.

    int* pStatus = &(status[0]);

    for (int i = 0; i < 5; i++)
    {
        cout << "i = " << i << "\tstatus[i] = " << status[i] << endl;
        cout << "i = " << i << "\tpStatus + i = " << *(pStatus + i) << endl << endl;
    }

    // �ǽ� - int 9��¥�� �迭�� ����� ���ڸ� �ϳ��Է¹޾� �� ������ �������� �迭�� �����ϰ� ���
    // ex) 5�� �Է¹޾����� �迭���ٰ� 5���� ��� ��Ű�� �迭�� ����ִ� ������ ������� ����Ѵ�.

    int gugu[9];
    //int gugu2[9] = {1,2,3,4,5,6,7,8,9};
    int input = 0;
    cout << "\n\n\n�������� ����� ���ڸ� �Է��ϼ��� : ";
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

    cout << "���� ���� ���� �սô�.\n";

    int retry = 1;

    while (retry == 1)
    {
        // ���� ���������� ����
        int select = 0;
        while (select < 1 || select > 3)
        {
            cout << "\n\n������������ �����ϼ���(1:����, 2:����, 3:��) : ";
            cin >> select;
            RockPaperScissors mSelect = (RockPaperScissors)select;
            switch (mSelect)
            {
            case Scissors:
                cout << "����� ������ �½��ϴ�.\n";
                break;
            case Rock:
                cout << "����� ������ �½��ϴ�.\n";
                break;
            case Paper:
                cout << "����� ���� �½��ϴ�.\n";
                break;
            default:
                cout << "�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���.\n";
                break;
            }
        }

        // ���� ����
        int enemySelect = rand() % 3 + 1;
        // int�� enum�� RockPaperScissors Ÿ������ ĳ�����ߴ�.
        RockPaperScissors eSelect = (RockPaperScissors)enemySelect;
        switch (eSelect)
        {
        case Scissors:
            cout << "���� ������ �½��ϴ�.\n";
            break;
        case Rock:
            cout << "���� ������ �½��ϴ�.\n";
            break;
        case Paper:
            cout << "���� ���� �½��ϴ�.\n";
            break;
        default:
            break;
        }

        // ���� ���� ������
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

        // ���� ��� ���
        switch (result)
        {
        case Win:
            cout << "����� �¸��߽��ϴ�.\n";
            break;
        case Lose:
            cout << "����� �й��߽��ϴ�.\n";
            break;
        case Draw:
            cout << "�����ϴ�.\n";
            break;
        default:
            break;
        }

        cout << "�ٽ� �Ͻðڽ��ϱ�? (1:��, �ٸ���:�ƴϿ�) : ";
        cin >> retry;
    }
}

void Day03_SlotMachine()
{
    // ���� �ӽ�
    srand(time(NULL));  // �õ尪�� ���� �ð����� ����
    int money = 1000;

    while (true)
    {
        std::cout << "���� " << money << "���� ������ �ֽ��ϴ�.\n";
        std::cout << "������ �����ϴ�";

        for (int i = 0; i < 10; i++)
        {
            Sleep(100);         // 0.1��(100 ����ũ�� ������) ��ٸ���
            std::cout << ".";
        }

        int result = -100 + rand() % 201;
        if (result > 0)
        {
            std::cout << std::endl << result << "���� ������ϴ�.\n";
        }
        else if (result < 0)
        {
            std::cout << std::endl << abs(result) << "���� �Ҿ����ϴ�.\n";
        }
        else
        {
            std::cout << std::endl << "������ ������ �ʾҽ��ϴ�.\n";
        }

        money += result;

        std::cout << "�ٽ� �ϰ� ������ 1, ������ ������ �ٸ����� �Է��ϼ��� : ";
        int input;
        std::cin >> input;

        if (input != 1)
        {
            break;
        }
    }
    std::cout << "�����մϴ�.\n\n";
}

void Day03()
{
    // ������(Pointer) : �޸��� �ּҸ� �����ϴ� ����
    int* pi;        // int�� ������ Ÿ��
    float* pf;      // float�� ������ Ÿ��

    int i = 10;

    pi = &i;        // i�� �ּҸ� pi�� �־ƶ�.

    std::cout << "i : " << i << ", i�� �ּ� : " << &i << std::endl;

    (*pi) = 100;    // pi�� ��ϵ� �ּҸ� ã�ư��� �װ��� �����͸� 100���� �ٲ۴�.
    std::cout << "i : " << i << ", i�� �ּ� : " << &i << std::endl;

    int j = i;

    // k�� i�� ���� �������ְ� ������ ���� pi�ۿ� �� ��.
    // �ڵ带 ��� �ۼ��ؾ� �ϳ�?
    int k = (*pi);  // pi�� ������ �ִ� �ּҿ� �ִ� �����͸� k�� �����ض�.

    std::cout << "pi : " << pi << std::endl;
    pi = pi + 1;    // pi�� 12�� �� pi + 1��?  => 16
    std::cout << "pi : " << pi << std::endl;
    //(*pi) = 200;

    // ��� ( Control Statement )

    // ���ǹ�
    bool con = 1 < 10;  // true
    if (con)          // ���࿡ ��ȣ���� true�� {}�� �����ض�
    {
        std::cout << "1�� 10���� �۽��ϴ�.\n";
    }

    bool isRight = false;
    if (isRight)
    {
        std::cout << "���������� ���ÿ�\n";
    }

    if (!isRight)
    {
        std::cout << "�������� ���ÿ�\n";
    }

    if (isRight)       //���࿡ () ���̰� true�� A�κ��� �����ϰ� false�� B�κ��� �����ض�.
    {
        // A�κ�
        std::cout << "���������� ���ÿ�\n";
    }
    else
    {
        // B�κ�
        std::cout << "�������� ���ÿ�\n";
    }

    // �ǽ�
    // �Է��� �޾Ƽ� input�� ���� �����ϱ�
    // input�� ���� Ȧ���� "Ȧ���Դϴ�."�� ����Ѵ�.
    // input�� ���� ¦���� "¦���Դϴ�."�� ����Ѵ�.
    //int input;
    //std::cout << "���ڸ� �Է��ϼ��� : ";
    //std::cin >> input;
    //if (input % 2 == 0)
    //{
    //    std::cout << "¦���Դϴ�.\n";
    //}
    //else
    //{
    //    std::cout << "Ȧ���Դϴ�.\n";
    //}

    //std::cout << "���ڸ� �Է��ϼ��� : ";
    //std::cin >> input;
    //if ( input < 10 )
    //{
    //    // 0 ~ 9
    //    std::cout << "input�� 0~9 �����Դϴ�.\n ";
    //}
    //else if ( input < 100 )
    //{
    //    // 10 ~ 99
    //    std::cout << "input�� 10~99 �����Դϴ�.\n ";
    //}
    //else
    //{
    //    // 100 ~
    //    std::cout << "input�� 100 �̻��Դϴ�.\n";
    //}

    int switchNum = 1;
    switch (switchNum)  // switch : ������ ��Ȯ�ϰ� �����Ǿ����� �� �����ϴ�.
    {
    case 0:
    case 1:
        std::cout << "0�� ���Խ��ϴ�.\n";
        std::cout << "1�� ���Խ��ϴ�.\n";
        break;
    case 2:
        std::cout << "2�� ���Խ��ϴ�.\n";
        break;
    default:
        std::cout << "0,1,2�� �ƴϴ�.\n";
        break;
    }

    // �ݺ���
    // while : ()���� ���̸� {}�� �ݺ��Ѵ�.

    /*while (true)
    {
    std::cout << "�ȳ��ϼ���.\n";
    }*/

    // �ǽ� : �ȳ��ϼ��並 3�� ����ϱ�
    int count = 0;
    while (count < 3)
    {
        std::cout << "�ȳ��ϼ���.\n";
        count++;
    }

    count = 0;
    do
    {
        std::cout << "�ȳ��ϼ���2.\n";
        count++;
    } while (count<3); // do-while�� �ϴ� {}������ �����ϰ� ������ Ȯ��. �ּ� �ѹ��� �����ؾ� �� �� ����

    // i�� 0���� �����ؼ� ; i�� 3���� ���� ������ ; �Ź� i�� 1�� ������Ű�鼭 �ݺ��ض�
    for (int i = 0; i < 3; i++)
    {
        std::cout << "�ȳ��ϼ���3.\n";
    }

    count = 0;
    // ���� ����
    while (true)
    {
        std::cout << "�ȳ��ϼ���4.\n";
        count++;
        if (count > 2)
        {
            break;      // while ���� �͵� ĵ�� �� �� �ִ�.
        }
    }

    for (int i = 0; i < 10; i++)
    {
        std::cout << "��� : ";
        if (i % 2 == 0)
            continue;       // ���� �ȿ��� ���� �κ��� ��ŵ�ϰ� ������ ù�κ����� �̵�

        std::cout << i << " �ȳ��ϼ���.\n";
    }

    //RAND_MAX = 32767
    srand(time(NULL));      // ���� �Լ��� ���� �ð��� �õ尪���� �����Ѵ�.
    for (int i = 0; i < 10; i++)
    {
        int random = rand();    // random�̶�� ������ ������ ���ڸ� �ش�. 0~RAND_MAX
        std::cout << random << std::endl;
    }

    int money = 1000;
    do
    {
        // �ѹ� ������ ������ �������� -100~100������ ����� ��� �ʹ�.
        int result; // �������� ���� ����� ������ ����
        //result = -100 + rand() % 201;
        result = rand() % 201;  // 0 ~ 200
        result -= 100;          // -100 ~ 100

        // ���� ����� money�� ��������.
        money += result;

        // "�ٽ� �ϰ� ������ 1, ������ ������ 2�� �Է��ϼ��� : "
        std::cout << "�ٽ� �ϰ� ������ 1, ������ ������ 2�� �Է��ϼ��� : ";
        int input;
        std::cin >> input;
    } while (true);  // input�� 1�� �ƴϰų� money�� �� �������� �� �����ϵ��� ���� �����ϱ�

    // �ָ� ���� : ���� ���� �� �����
}

void Day02()
{
    // Day02
    // ��������� : + - * /
    int a = 10;         // a��� �̸��� ����, int Ÿ���� ������ �����, 10�̶�� ���� �־��
    int b = 3;          // b��� �̸��� ����, int Ÿ���� ������ �����, 3�̶�� ���� �־��

    int c = a + b;      // c��� �̸��� ����, int Ÿ���� ������ �����, a�� b�� ���� ���� �־ƶ�.

    std::cout << "a�� " << a << ", b�� " << b << ", c�� " << c << std::endl;

    //int d;
    //std::cout << "d�� " << d;    // �ʱ�ȭ ���� �ʰ� ����� ��� ������ ���� ����. �׷��� �ʱ�ȭ�ؼ� ����ؾ� �Ѵ�.

    c = a - b;
    std::cout << "a�� " << a << ", b�� " << b << ", c�� " << c << std::endl;

    c = a * b;
    std::cout << "a�� " << a << ", b�� " << b << ", c�� " << c << std::endl;

    c = a / b;
    std::cout << "a�� " << a << ", b�� " << b << ", c�� " << c << std::endl;

    // �ǽ� : + - * /�� �̿��ؼ� a�� b�� �������� ���� �������� ����غ���.
    c = a - (a / b) * b;
    std::cout << "a�� " << a << ", b�� " << b << ", c�� " << c << std::endl;

    c = a % b;  // ������(modulo) ������
    std::cout << "a�� " << a << ", b�� " << b << ", c�� " << c << std::endl;

    a = 10;
    std::cout << "a = " << a << " (a=10�� ���;� �Ѵ�.)" << std::endl;
    a = a + 1;
    std::cout << "a = " << a << " (a=11�� ���;� �Ѵ�.)" << std::endl;
    a += 3; // a = a + 3;�� ����
    std::cout << "a = " << a << " (a=14�� ���;� �Ѵ�.)" << std::endl;
    a++;
    std::cout << "a = " << a << " (a=15�� ���;� �Ѵ�.)" << std::endl;
    ++a;
    std::cout << "a = " << a << " (a=16�� ���;� �Ѵ�.)" << std::endl;
    std::cout << "a = " << a++ << " (a=16�� ���;� �Ѵ�.)" << std::endl;  // ���� ���� Ȯ���ϰ� ����
    std::cout << "a = " << ++a << " (a=18�� ���;� �Ѵ�.)" << std::endl;  // ���� �����ǰ� Ȯ��
    std::cout << "a = " << a << " (a=18�� ���;� �Ѵ�.)" << std::endl;

    int b2 = 10;
    b2 -= 3;

    float c2 = 10.0f;
    c2++;
    std::cout << c2 << std::endl;

    // �� ������ 
    // == : ����
    // != : �ٸ���.
    // > : ũ��
    // < : �۴�
    // >= : ũ�ų� ����.
    // <= : �۰ų� ����.

    a = b;  // = �� ���� ������. �������� �����ʿ� �ִ� ���� ���� ������ �־��
    a == b; // == �� �� ������. �������� �����ʰ� ������ ������ true, �ƴϸ� false

    a = 10;
    b = 20;
    bool d = (a == b);
    std::cout << "a = " << a << ", b = " << b << ", a == b�� " << d << "(����� false��.)" << std::endl;

    a = 10;
    b = 10;
    d = (a == b);
    std::cout << "a = " << a << ", b = " << b << ", a == b�� " << d << "(����� true��.)" << std::endl;

    d = (a != b);
    std::cout << "a = " << a << ", b = " << b << ", a == b�� " << d << "(����� false��.)" << std::endl;

    a = 15;
    b = 5;
    d = (a > b);
    std::cout << "a = " << a << ", b = " << b << ", a == b�� " << d << "(����� true��.)" << std::endl;

    // �� ������ : ����� true�ƴϸ� false
    // && : and. �׸���. ~�̰� ~��. ����. && ���ʿ� �ִ� ���� ��� true�϶��� true.
    // || : or. �Ǵ�. ~�̰ų� ~��. ����. || ���ʿ� �ִ� ���� �ϳ��� true�� true.
    // ! : not. �ݴ�. true�� false��, false�� true��
    bool aaa = true;
    bool bbb = false;
    bool ccc;

    ccc = aaa && bbb;   // false
    ccc = aaa || bbb;   // true

    ccc = !aaa && bbb;  // false && false, false
    ccc = !aaa && !bbb; // false && true, false
    ccc = aaa || !bbb;  // true || true, true

    // ��Ʈ ������
    // &    : and. �� �� 1�϶��� 1�̴�.
    // |    : or. �� �� �ϳ��� 1�̸� 1�̴�.
    // ^    : xor. �ΰ��� �ٸ��� 1.
    // ~    : not. 0�� 1��, 1�� 0����
    // <<   : left shift. ���ʿ� �ִ� ��Ʈ�� ������ ����ŭ �б�
    // >>   : right shift.

    a = 1;  // 0001
    b = 3;  // 0011
    std::cout << std::bitset<4>(a) << std::endl;
    std::cout << std::bitset<4>(b) << std::endl;
    std::cout << std::bitset<4>(a & b) << " (0001�� ���;� �Ѵ�.)" << std::endl;
    std::cout << std::bitset<4>(a | b) << " (0011�� ���;� �Ѵ�.)" << std::endl;
    std::cout << std::bitset<4>(a ^ b) << " (0010�� ���;� �Ѵ�.)" << std::endl;
    std::cout << std::bitset<4>(~b) << " (1100�� ���;� �Ѵ�.)" << std::endl;
    c = a << 2;
    std::cout << std::bitset<4>(c) << " (0100�� ���;� �Ѵ�.)" << std::endl;
    c = b >> 1;
    std::cout << std::bitset<4>(c) << " (0001�� ���;� �Ѵ�.)" << std::endl;

    // �ǽ�
    // int a; �� ����° ��Ʈ�� 1���� Ȯ���ؼ� bool d;�� 1�̸� true �ƴϸ� false�� �ִ� �ڵ� �ۼ��ϱ�
    a = 6; // 6 = 0110, d = true;
    a = 8; // 8 = 1000, d = false;

    // <<, &, !=

    // 1 = 0001 �������� ���̴�.
    int flag = 1 << 2;  // 0100
    d = (a & flag) != 0;   // a & flag�� 0�� �ƴϸ� true, 0�̸� false
    int flag2 = 1 << 1; // 0010
    flag |= flag2;      // flag = 0110
}

void Day01()
{
    std::cout << "Hello World!\nHello World!\n";
    std::cout << "�� �̸��� �����Դϴ�.\n" << "���� ����Դϴ�.\n";

    //int i = 0;
    //std::cout << "i�� " << i << " �Դϴ�.\n";
    //std::cin >> i;
    //std::cout << "i�� " << i << " �Դϴ�.\n";

    //// �ǽ� - ������ �Է¹ް� ����غ���
    //std::cout << "������ �Է��� �ּ���. : ";
    //int month = 0;  
    //int day = 0;
    //std::cin >> month >> day;
    //std::cout << "����� ������ " << month << "�� " << day << "�� �Դϴ�.\n";

    // ���� : �����͸� �����ϱ� ���� �͵�. ���ϴ� ����
    // ������ ������ ������ �����͸� ������ �� �ִ�.
    // ������ Ÿ�� : ������ �� �ִ� ������ �������� �����Ǿ��ִ�.
    // int : ������. ��Ƽ��. �Ҽ��� ���� ���ڸ� ���� ����. ũ�� : 32bit => 2^32��ŭ ǥ���� �����ϴ�.
    // float : �Ǽ���. �÷�Ʈ. �Ҽ��� �ִ� ���ڸ� ���� ����. ũ�� : 32bit. �»������� ������ �����Ѵ�.
    // bool : ����. true �ƴϸ� false �� ���� ����.
    // char : ���� �ϳ��� �����ϴ� ������ Ÿ��. (8bit ũ���� int�� ����)

    int a = 10;
    float b = 3.141592f;
    bool c = true;
    char d = 'a';

    std::cout << "a�� ��Ƽ���̴�. " << "a�� ũ��� " << sizeof(a) << "Byte �̴�.\n";
    std::cout << "b�� �÷�Ʈ�̴�. " << "b�� ũ��� " << sizeof(b) << "Byte �̴�.\n";
    std::cout << "c�� ���̴�. " << "c�� ũ��� " << sizeof(c) << "Byte �̴�.\n";
    std::cout << "d�� ĳ�����̴�. " << "d�� ũ��� " << sizeof(d) << "Byte �̴�.\n";

    //auto e = c;
    a = 20;

    // ��� : ������ ���� ������ �ʴ� ����.
    const int ca = 10;
    //ca = 20;

    // �ǽ� - �������� �̿��ؼ� + - * / ����غ���
    // �ڼ��� ���͵�
    // int ������
    // int�� float���� ����غ���
}

// ���α׷� ����: <Ctrl+F5> �Ǵ� [�����] > [��������� �ʰ� ����] �޴�
// ���α׷� �����: <F5> Ű �Ǵ� [�����] > [����� ����] �޴�

// ������ ���� ��: 
//   1. [�ַ�� Ž����] â�� ����Ͽ� ������ �߰�/�����մϴ�.
//   2. [�� Ž����] â�� ����Ͽ� �ҽ� ��� �����մϴ�.
//   3. [���] â�� ����Ͽ� ���� ��� �� ��Ÿ �޽����� Ȯ���մϴ�.
//   4. [���� ���] â�� ����Ͽ� ������ ���ϴ�.
//   5. [������Ʈ] > [�� �׸� �߰�]�� �̵��Ͽ� �� �ڵ� ������ ����ų�, [������Ʈ] > [���� �׸� �߰�]�� �̵��Ͽ� ���� �ڵ� ������ ������Ʈ�� �߰��մϴ�.
//   6. ���߿� �� ������Ʈ�� �ٽ� ������ [����] > [����] > [������Ʈ]�� �̵��ϰ� .sln ������ �����մϴ�.
