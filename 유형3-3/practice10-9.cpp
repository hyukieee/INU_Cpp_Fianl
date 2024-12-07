/*
STL의 vector 클래스를 이용하는 간단한 프로그램을 작성해 보자.
vector 객체를 생성하고, 키보드로부터 정수를 입력받을 때마다 정수를 벡터에 삽입하고
지금까지 입력된 수와 평균을 출력하는 프로그램을 작성하라. 0을 입력하면 프로그램이 종료된다.

*/

#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec.at(i) << " ";
    }
    cout << endl;
    
}

double vectorAvg(vector<int> &vec)
{
    int sum = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        sum += vec.at(i);
    }

    return (double)sum/vec.size();
}

int main()
{
    vector<int> a;

    while (1)
    {
        cout << "Enter the number(integer)>>";
        int num;
        cin >> num;
        if (num == 0)
            return 0;
            
        a.push_back(num);

        printVector(a);

        cout << "Vector Average = " << vectorAvg(a) << endl;
    }
}
