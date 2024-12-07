/*
다음 함수는 매개변수로 주어진 int 배열 src에서 배열 minus에 들어있는
같은 정수를 모두 삭제한 새로운 int 배열을 동적으로 할당받아 리턴한다.
retSize는 remove() 함수의 실행 결과를 리턴하는 배열의 크기를 전달받는다. 
템플릿을 이용하여 remove를 일반화 하라
*/

#include <iostream>
using namespace std;

template <class T>
T* remove(T a[],int x, T b[], int y, int& RETSIZE) {
    int idx =0;

    int flag =0;


    T *arr  = new T [x];
    for(int i=0; i<x; i++){
        for(int k=0; k<y;k++){
            if(a[i]==b[k]){
                flag =1;
                break;
            }

        }
        if(flag == 0 ){
            arr[idx] = a[i];
            idx++;
            
        }
        flag =0;

    }

    RETSIZE = idx;
    return arr;
}



// =========================== DON'T MODIFY IT =============================
int main()
{
    cout << "정수 배열 {1,2,3,4}에서 정수 배열 {-3,5,10,1,2,3}을 뺍니다" << endl;

    int x[] = {1, 2, 3, 4};
    int y[] = {-3, 5, 10, 1, 2, 3};
    int retSize;

    int *p = remove(x, 4, y, 6, retSize);
    if (retSize == 0)
    {
        cout << "모두 제거되어 리턴하는 배열이 없습니다." << endl;
        return 0;
    }
    else
    {
        for (int i = 0; i < retSize; i++)
            cout << p[i] << ' ';
        cout << endl;

        delete[] p; // 할당받은 배열 반환
    }
    cout << endl;
}
// =============================================================================
