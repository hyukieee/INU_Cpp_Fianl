/* --------------------------------------------------------------
AbstracStack은 정수 클래스이다.
이를 추상 클래스로 만들고 이를 IntStack에서 상속받아 처리하는 프로그램을 만들어 보시오

memo
    - 추상 클래스 : 순수 가상함수를 1개 이상 갖는 클래스

----------------------------------------------------------------*/

#include <iostream>
using namespace std;

class Abstractstack
{
public:
    virtual bool push(int n) = 0; // 스택에 n을푸시한다. 스택이 full이면 false 리턴
    virtual bool pop(int &n) = 0; // 스택에서 팝한 정수를 n에 저장하고 스택이 empty이면 false 리턴
    virtual int size() = 0;       // 현재 스택에 저장된 정수의 개수 리턴
};

// ==================== 구현부 ===============================

class IntStack : public Abstractstack
{
    int tos;
    int capacity;
    int *stack;

public:
    IntStack(int n)
    {
        capacity = n;
        stack = new int[capacity];
        tos = 0;
    }
    bool push(int n)
    {
        if (tos >= capacity )return false;

        stack[tos] = n;
        tos++;
        return true;
    }
    bool pop(int &n)
    {
        if(tos <= 0) return false;
        tos--;
        n = stack[tos];
        return true;
    }
    int size()
    {
        return tos;
    }
};

// =========================================================

int main()
{
    IntStack a(5);
    for (int i = 0; i < 10; i++)
    { // 처음 5 개를 성공적으로 push되고 다음 5 개는 스택 full로 push 실패
        if (a.push(i))
            cout << "push 성공" << endl;
        else
            cout << "스택 full" << endl;
    }

    int n;
    for (int i = 0; i < 10; i++)
    { // 처음 5 개를 성공적으로 pop되고 다음 5 개는 스택 empty로 pop 실패
        if (a.pop(n))
            cout << "pop 성공 " << n << endl;
        else
            cout << "스택 empty" << endl;
    }
}
