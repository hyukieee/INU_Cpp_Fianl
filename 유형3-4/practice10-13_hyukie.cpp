/*
map컨테이너를 이용하여 (이름, 성적) 을 저장하고
이름으로 성적을 조회하는 점수관리 프로그램을 만들어라.
이름은 빈칸 없이 입력하는 것을 원칙으로 한다.
*/

#include <map>
#include <iostream>
using namespace std;
void checkGrade(map <string,int> &m){
    cout << "Enter the name of the person whose grades you want to check.";
    string _name;
    cin >> _name ;
    int _grade = m.at(_name);
    cout << _name << "'s grade is " << _grade << endl;


}

int main()
{
    map<string, int> grade;

    while (1)
    {
        cout << "Enter the your name and grade (if you want to exit , Enter the exit)>> ";
        string name;
        int score =0 ;
        cin >> name >> score;
        if (name == "exit")
        {
            checkGrade(grade);
            return 0;
        }

        grade[name] = score;

    }
}