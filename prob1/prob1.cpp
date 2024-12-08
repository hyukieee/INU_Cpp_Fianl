#include <iostream>
#include <string>
using namespace std;

/* -- 아래에 Rectangle 클래스를 작성하라 ----------------------------*/
/* 구현해야할 멤버함수  int getWidth(), int getHeight(), void setWidth(int width),
                        void setHeight(int height), double getArea()*/

/* -----------------------------------------------------------------*/

/*============== Implementation Section ============================*/

class Rectangle
{
    int width, height;

public:
    Rectangle(int width = 0, int height = 0)
    {
        this->width = width;
        this->height = height;
    }
    int getWidth() { return width; }
    int getHeight() { return height; }
    void setWidth(int width) { this->width = width; }
    void setHeight(int height) { this->height = height; }
    double getArea() { return width * height; }
};

/* -----------------------------------------------------------------*/

class NamedRectangle : public Rectangle
{
    string name;

public:
    NamedRectangle(int width = 0, int height = 0, string name = "NONAME") : Rectangle(width, height)
    {
        this->name = name;
    }

    /* -- 아래에 set(), getName(), show() 함수를 구현하라 -------------------------*/
    void set(int w, int h, string name){
        setHeight(h);
        setWidth(w);
        this->name = name;
    }
    string getName(){return name;}
    void show() {
        cout << "Rectangle "<< name << "'s Area is " << getArea()  << endl ;
    }
    /* -----------------------------------------------------------------*/
};

/* -- 아래에 smallest()함수를 구현하라 ----------------------------------------*/
string smallest(NamedRectangle *a, int n){
    int min = a[0].getArea();
    int idx = 0 ;

    for(int i=0; i<n ; i++){
        if(min > a[i].getArea()){
            min = a[i].getArea();
            idx = i;
        }
    }
    return a[idx].getName();
}

/* -------------------------------------------------------------*/
int main()
{
   // NamedRectangle rect[5];
    //cout << "3개의 가로 와 세로, 직사각형의 이름을 입력하세요" << endl;

    /* -- 아래 코딩을 수정하여 가로와 세로를 0보다 작게 입력할 때 예외처리하시오. -------------*/
    NamedRectangle r[5];
    cout << "5 개의 가로와 세로, 직사각형의 이름을 입력하세요" << endl;
    for (int i = 0; i < 5; i++)
    {
        try {
        int w, h;
        string name;
        cout << i + 1 << ">> ";
        cin >> w >> h;
        getline(cin, name);
        
        if (w <= 0 || h <= 0) { throw 1; }

        r[i].set(w, h, name);
        }
        catch(int x){
            cout << "다시 입력하세요" << endl;
            i --;
        }
        
    }
    cout << "가장 면적이 작은 직사각형은 " << smallest(r, 5) << "입니다" << endl<< endl;
}