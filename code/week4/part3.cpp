//#include <iostream>
//#include <cstring>
//using namespace std;
// 在此处补充你的代码
class Array2{
public:
    explicit Array2():len1(0),len2(0),vals(0){}
    explicit Array2(int i,int j):len1(i),len2(j),vals(0){
        vals =  new int*[len1];
        for (int _i=0;_i<len1;_i++) {
            vals[_i] = new int[len2];
        }
    }
    explicit Array2(const Array2& other){
        if(other.vals==this->vals){
            return;
        }
        if(other.len1==other.len2==0 && !vals){
            delete []vals;
            return;
        }
        if(!vals){
            delete []vals;
        }
        vals =  new int*[other.len1];
        for (int _i=0;_i<other.len1;_i++) {
            vals[_i] = new int[other.len2];
            for (int _j=0;_j<other.len2;_j++) {
                vals[_i][_j] = other.vals[_i][_j];
            }
        }
    }
    int* & operator[](int index){
        return this->vals[index];
    }
    int operator()(int i,int j){
        return this->vals[i][j] ;
    }
private:
        int len1,len2;
        int **vals;
};

//int main() {
//    Array2 a(3,4);
//    int i,j;
//    for(  i = 0;i < 3; ++i )
//        for(  j = 0; j < 4; j ++ )
//            a[i][j] = i * 4 + j;
//    for(  i = 0;i < 3; ++i ) {
//        for(  j = 0; j < 4; j ++ ) {
//            cout << a(i,j) << ",";
//        }
//        cout << endl;
//    }
//    cout << "next" << endl;
//    Array2 b; b = a;
//    for(  i = 0;i < 3; ++i ) {
//        for(  j = 0; j < 4; j ++ ) {
//            cout << b[i][j] << ",";
//        }
//        cout << endl;
//    }
//    return 0;
//}

