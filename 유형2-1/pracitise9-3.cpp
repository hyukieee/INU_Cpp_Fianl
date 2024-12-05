/* --------------------------------------------------------------
[9-3]
다음 추상 클래스 LoopAdder가 있다.
LoopAdder 클래스를 상속받아 다음 main() 함수와 실행 결과처럼 되도록
ForLoopAdder 클래스를 작성하라. ForLoopAdder 클래스의 calculate() 함수는
for 문을 이용하여 합을 구한다.

## 실행 결과
For Loop:
처음 수에서 두번째 수까지 더합니다. 두 수를 입력하세요 ” 3 10
3에서 10까지의 합 = 52 입니다
----------------------------------------------------------------*/

#include <iostream>
using namespace std;

class LoopAdder
{                // 추상 클래스
    string name; // 루프의 이름
    int x, y, sum;
    void read();  // x, y 값을 읽어 들이는 함수
    void write(); // sum을 출력하는 함수
protected:
    LoopAdder(string name = "")
    { // 루프의 이름을 받는다. 초깃값은 ""
        this->name = name;
    }
    int getX() { return x; }
    int getY() { return y; }
    virtual int calculate() = 0; // 순수 가상 함수. 루프를 돌면서 합을 구하는 함수
public:
    void run(); // 연산을 진행하는 함수
};

class ForLoopAdder :public LoopAdder{
public:
    ForLoopAdder(string name= ""): LoopAdder(name) {name = name;}
    int calculate();
};

int ForLoopAdder::calculate() {
    int res =0;
    for(int i = getX(); i<= getY();i++ ){
        res += i;
    }
    return res;
}

void LoopAdder::read()
{ // x, y 입력을 구현하라
//======== 구현부 ===============
    cout << "x, y를 입력하시오";
    cin >> x >> y;

//==============================
}
void LoopAdder::write()
{ // 결과 sum 출력을 구현하라
//======== 구현부 ===============
    cout << x << "~" << y << "의 합 결과 = " << sum;
//==============================
}

void LoopAdder::run()
{
    read();            // x, y를 읽는다.
    sum = calculate(); // 루프 돌면서 계산한다.
    write();           // 결과 sum을 출력한다.
}

int main()
{
    ForLoopAdder forLoop("For Loop");
    forLoop.run();
}