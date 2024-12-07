/*
map컨테이너를 이용하여 (이름, 성적) 을 저장하고
이름으로 성적을 조회하는 점수관리 프로그램을 만들어라.
이름은 빈칸 없이 입력하는 것을 원칙으로 한다.
*/

#include <map>
#include <iostream>
using namespace std;

//========================= 구현부 =========================
class GradeManager
{
    int score;
    string name;
    string program;
    map<string, int> m;

public:
    GradeManager(string program = "")
    {
        this->program = program;
    };
    void run();
    void search()
    {
        cout << "Enter the name to seach someone's grade >> ";
        cin >> name;
        cout << name << "'score = " << m.at(name) << endl;
    };
    void insert()
    {
        cout << "Enter name and score >> ";
        cin >> name >> score;
        m[name] = score;
    };
    bool checkInputError()
    {
        if (cin.fail())
        {
            cin.clear();                                         // 오류 상태를 지움
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 입력 버퍼 삭제
            cout << "잘못된 입력입니다. 숫자를 입력하세요." << endl;
            return true;
        }
        return false;
    }
};
//========================================================

void GradeManager::run()
{

    int menu;
    cout << "***** 점수관리 프로그램 " << program << "을 시작합니다 *****" << endl;
    while (true)
    {
        cout << "입력:1, 조회:2, 종료:3 >> ";
        cin >> menu;

        // 단순하게 작성하려는 경우 다음 2 라인은 호출하지 않아도 됨
        if (checkInputError()) // 메뉴(menu)를 사용자가 숫자를 입력하지 않는 경우, 오류 발생
            continue;
        switch (menu)
        {
        case 1:
            insert();
            break;
        case 2:
            search();
            break;
        case 3:
            cout << "프로그램을 종료합니다...";
            return;
        }
    }
}

int main()
{
    GradeManager gm("HIGH SCORE");
    gm.run();

    cout << endl
         << endl;
}