/*
지수 승 계산을 예외처리 코드로 재작성
*/
#include <iostream>
using namespace std;

double getExp(int base, int exp)
{
    double value = 1;

    if (exp < 0) {
        for (int n = 0; n < -exp; n++) {
            value *= base; // 양수 지수 계산
        }
        throw 1 / value; // 음수 지수의 경우 역수를 던짐
    }

    for (int n = 0; n < exp; n++) {
        value *= base; // 양수 지수 계산
    }

    return value; // 결과 반환
}

int main()
{
    int v = 0; // 반환 타입을 double로 수정
    try
    {
        v = getExp(2, 3);
        cout << "2^3 = " << v << endl;
        v = getExp(2, -3);
        cout << "2^-3 = " << v << endl; // 이 줄은 실행되지 않음
    }
    catch (double x) { // double 타입으로 수정
        cout << "exp is negative, so result is " << x << endl; // 소수점 값을 출력
    }
}

