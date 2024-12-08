/*
다음은 정수를 입력받아 구구단을 출력하는 프로그램이다.
그런데 이 프로그램은 1~9가 아닌 정수가 입력되는 것을 걸러내지 못하고,
특히 문자가 입력되면 무한루프에 빠지게 된다

// 원본 프로그램
int main() {
    int n;
    while(true) {
        cout << "양수 입력 >> ";
        cin >> n;
        for(int i=1;i<=9; i++)
            cout << n << 'x' << i << '=' << n*i << ' ';
        cout << endl;
    }
}
*/
#include <iostream>
using namespace std;

int main()
{
    int n;
    while (true)
    {
        cout << "양수 입력 >> ";
        try
        {
            cin >> n;
            if (cin.fail()||n < 1 || n>9)
                throw n;
        }
        catch (int x)
        {
            cout << x <<"는 유효하지 않은 입력입니다. \n 입력 오류가 발생하여 더 이상 입력되지 않습니다. 프로그램을 종료합니다.";
            break;
        }
        for (int i = 1; i <= 9; i++)
            cout << n << 'x' << i << '=' << n * i << ' ';
        cout << endl;
    }
}
