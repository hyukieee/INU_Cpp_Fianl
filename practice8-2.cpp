/*
2. 다음과 같이 배열을 선언하여 다음 실행 결과가 나오도록 Circle을 상속받은 NamedCircle 클래스와 main() 함수 등 필요한 함수를 작성하라.

    NamedCircle pizza[5];
*/
#include <iostream>
using namespace std;

class Circle
{
    int radius;

public:
    Circle(int r = 0) { radius = r; }
    void setR(int r) { radius = r; }
    double getArea() { return 3.14 * radius * radius; }
};

class NamedCircle : public Circle
{
    string name;

public:
    NamedCircle(int radius = 0, string n = "") : Circle(radius) {
        name = n;
    }
    void set(int r, string n)
    {
        setR(r);
        name = n;
    }
    string getName() { return this->name; }
};

string biggest(NamedCircle c[], int idx)
{
    NamedCircle maxIdx = c[0];
    for (int i = 0; i < idx; i++)
    {
        if (maxIdx.getArea() < c[i].getArea())
        {
            maxIdx = c[i];
        }
    }

    return maxIdx.getName();
}

int main()
{
    NamedCircle c[5];
    cout << "5 개의 정수 반지름과 원의 이름을 입력하세요" << endl;
    for (int i = 0; i < 5; i++)
    {
        int r;
        string name;
        cout << i + 1 << ">> ";
        cin >> r;
        getline(cin, name);
        if (r <= 0)
        {
            cout << "다시 입력하세요" << endl;
            i--;
            continue;
        }

        c[i].set(r, name);
    }
    cout << "가장 면적이 큰 피자는 " << biggest(c, 5) << "입니다" << endl;
}
