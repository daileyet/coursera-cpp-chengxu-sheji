//#include <iostream>
//using namespace std;
//class A {
//public:
//    int val;
    A():val(0){}
    A(int i):val(i){}
    A& GetObj(){
    	return *this;
    }
//};
//
//int main()  {
//    A a;
//    cout << a.val << endl;
//    a.GetObj() = 5;
//    cout << a.val << endl;
//}
