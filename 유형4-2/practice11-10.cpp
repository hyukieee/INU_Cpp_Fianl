/*
다음의 실행 결과가 나오도록 prompt 조작자를 작성하여 프로그램을 완성하라


return :
    암호?java
    login fail. try again!!
    암호?C++
    login success!!
*/
#include <iostream>
#include <string>
using namespace std;

istream& prompt(istream& in){
    cout << "PASSWORD?";
    return in;
}

int main()
{
    string password;
    while (true)
    {
        cin >> prompt >> password;
        for (char &c : password)
        {
            c = tolower(c);
        }
        if (password == "C++")
        {
            cout << "login success!!" << endl;
            break;
        }
        else
            cout << "login fail. try again!!" << endl;
    }
}
