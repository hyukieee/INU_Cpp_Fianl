/*

Circle 클래스는 다음과 같다.
Circle 클래스의 객체를 입출력하는 다음 코드와 실행 결과를 참조하여 <<, >> 연산자를 작성하고 Circle 클래스를 수정하는 등 프로그램을 완성하라.


*/

#include <iostream>
#include <string>
using namespace std; 


class Circle
{
    string name;
    int radius;

public:
    Circle(int radius = 1, string name = "")
    {
        this->radius = radius;
        this->name = name;
    }
// ==================== implementation ===================
    friend istream& operator>>(istream& in, Circle& a);
    friend ostream& operator<<(ostream& out, Circle& a);
//========================================================
};

// ==================== implementation ===================
istream& operator>>(istream &in, Circle &a){
    cout << "Radius >> ";
    in >> a.radius;
    cout << "Name >> ";
    in >> a.name;
    return in;
}

ostream& operator<< (ostream & out, Circle &a ){
    out << "( Radius = " << a.radius << ", Name is " << a.name << ")";
    return out ;
    
}

//========================================================


int main()
{
    Circle d, w;
    cin >> d >> w;          // 키보드 입력을 받아 객체 d와 w를 완성
    cout << d << w << endl; // 객체 d, w 출력
}
