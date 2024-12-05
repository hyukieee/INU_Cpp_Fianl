#include <iostream>
using namespace std;

class Color
{
    int red, green, blue;

public:
    Color(int r = 0, int g = 0, int b =0)
    {
        red = r;
        green = g;
        blue = b;
    }
    void show() {
        cout << "R ="<< red <<", G =" << green << ", B =" << blue << endl;
    }

    friend Color operator+ (Color op1, Color op2);
    friend bool operator ==(Color op1 ,Color op2);

};

Color operator +(Color op1, Color op2){
    return Color(op1.red +op2.red, op1.green+ op2.green , op1.blue + op2.blue);

}

bool operator ==(Color op1, Color op2){
    if(op1.red == op2.red && op1.green == op2.green && op1.blue == op2.blue) return true;
    else return false;

}

int main()
{
    Color red(255, 0, 0), blue(0, 0, 255), c;
    c = red + blue; // +(red, blue) 호출
    c.show();       // 색 값 출력

    Color fuchsia(255, 0, 255);
    if (c == fuchsia) // ==(c, fuchsia) 호출
        cout << "보라색 맞음";
    else
        cout << "보라색 아님";

    cout << endl;
}


