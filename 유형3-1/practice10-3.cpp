/*
배열의 원소를 반대 순서로 뒤집는 reverseArray() 함수를 탬플릿으로 작성하라
reverseArray()의 첫 번째 매개변수는 배열에 대한 포인터이다. 두 번째 매개변수는 배열의 개수이다.
reverseArray()의 호출사례는 다음과 같다.
*/
#include<iostream>  
using namespace std;

template <class T> 
void reverseArray(T *a , T b)
{
    for(int i=0;i<b/2; i++){
        T tmp = a[i];
        a[i] = a[b-1-i];
        a[b-1-i] = tmp;
        
    }

}


int main()
{
    int x[] = {1, 10, 100, 5, 4};
    reverseArray(x, 5);
    for (int i = 0; i < 5; i++)
        cout << x[i] << ' ';
    cout << endl;

    int y[] = {-1, -10, -100, -1000};
    reverseArray(y, 4);
    for (int i = 0; i < 4; i++)
        cout << y[i] << ' ';
    cout << endl;
}
