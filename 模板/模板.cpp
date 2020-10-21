#include<iostream>
#include<typeinfo>

using namespace std;

//--------------------------------------------------------------
template<class T>
void myswap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template<class T, class M>
void func()
{
    cout<<"func 1"<<endl;
}

template<class T, class M>
void myswap1(T &a, M &b) {
    T temp_a = a;
    M temp_b = b;

    a = (M) a;
    a = temp_b;
    b = (T) b;
    b = temp_a;

}

//-------------------------------------------------------------
void test() {
    int a = 10, b = 20;
    myswap(a, b);
}

void test1() {
    int a = 10;
    float b = 20.1;
    myswap1(a, b);
    cout << a << " " << b << " " << typeid(b).name() << endl;
}

void test02()
{
    func<int,int>();
}
//-------------------------------------------------------------
int main() {
    test1();
    test02();
    return 0;
}
