/*
다음 원형과 조건을 가진 concat()함수를 작성하라.
int* concat(int a[], int sizea, int b[], int sizeb

concat 함수는 배열a와 배열b를 연결한 새로운 배열을 생성하여 리턴한다.
그러나 만일 메모리가 부족하거나, 배열a와 b가 NULL이거나,
sizea나 sizeb가 양수가 아닌 경우 int타입의 예외를 발생시킨다.
아래의 코드를 보고 프로그램을 완성하라

*/
#include <iostream>
using namespace std;


int* concat(int *a ,int x, int *b,int y){
    if(x<1 || y<1) throw 1; // x or y isn't positive -> ERROR_CODE 1
    if(a == nullptr || b == nullptr) throw 2; // a or b is null -> ERROR_CODE 2

    int* arr = new int[x+y];
    if(arr == nullptr) throw 3; // memory capacity isn't enough -> ERROR_CODE 3

    for(int i=0 ;i<x;i++){
        arr[i] = a[i];
    }
    for(int i=0 ;i<y;i++){
        arr[i+x] = b[i];
    }
    
    return arr;


}

int main()
{
    int x[] = {1, 2, 3, 4, 5};
    int y[] = {10, 20, 30, 40};
    try
    {
        int *p = concat(x, 0, y, 4); // 5 대신에 0을 입력하면 예외가 발생
        for (int n = 0; n < 9; n++)
            cout << p[n] << ' ';
        cout << endl;
        delete[] p;
    }
    catch (int failCode)
    {
        cout << "오류 코드 : " << failCode << endl;
    }
}
