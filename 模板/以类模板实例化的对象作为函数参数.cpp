#include<iostream>
#include<typeinfo>

using namespace std;

//首先定义一个 名叫Person的模板类------------------------------------
template<class Nametype, class Agetype = int>
class Person {
public:
    Person(Nametype name, Agetype age) {
        this->mName = name;
        this->mAge = age;
    }

    void showPerson() {
        cout << "name: " << this->mName << " age:" << this->mAge << endl;
    }

    Nametype mName;
    Agetype mAge;
};
//------------------------------------------------------------------

//------------------------------------------------------------------
//第一种方法：
//在函数定义时指定传入的类型，***最常用***
//限制了在实例化一个class（Person）时，必须以Person<int,int> p(var1,var2)
void printPerson(Person<int, int> &p) {
    p.showPerson();
    p.mName = int('b');
    p.mAge = 25;
    p.showPerson();
}
//------------------------------------------------------------------

//第二种方法：
//将要调用类模板的函数，模板化
template <class t,class m>
void printPerson1(Person<t,m> &p)
{
    p.showPerson();
    cout << "T1的类型为： " << typeid(t).name() << endl;//查看数据类型
    cout << "T2的类型为： " << typeid(m).name() << endl;
}
//-----------------------------------------------------------------

//第三种方法：
//将调用类模板的函数，模板化，但是是将 类 这个类作为输入参数的类型
//???如果此时输入的是一个普通类 或者 结构体呢
template <class T>
void printPerson2(T &p)
{
    cout << "T的类型为： " << typeid(T).name() << endl;
//    p.showPerson();
    cout<<p.mName<<" "<<p.mAge<<endl;
}
//定义一个结构体
struct person
{
    string mName = "wang";
    int mAge = 20;
};


//定义一个普通类
class Person_normal
{
public :

    Person_normal(string name,int age)
    {
        mName = name;
        mAge = age;
    }
    string mName;
    int mAge;
};
int main() {
    Person<string, int> p1("10", 20);
    printPerson1(p1);

    struct person p2;
    printPerson2(p2);

    Person_normal p3("zahng",22);
    printPerson2(p3);
    return 0;
}
