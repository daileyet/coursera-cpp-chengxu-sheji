#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
class BigInteger;
ostream& operator<<(ostream& _cout,const BigInteger& big );
class BigInteger{
public:
    BigInteger():s_val("0"),base(10){}
    BigInteger(const string& val):s_val(val),base(10){}
    BigInteger operator+(const BigInteger& other){
        int len1 = static_cast<int>(s_val.length()), len2 = static_cast<int>(other.s_val.length()),len = max(len1,len2);
        int index1 = static_cast<int>(len1-1) , index2 = static_cast<int>(len2-1);
        string rst;
        bool hasCarry=false;
        for (int i=len;i>=0;i--) {
            char c1 = '0', c2 = '0';
            if(index1>=0){
                c1 = s_val[static_cast<size_t>(index1)];
                index1--;
            }
            if(index2>=0){
                c2 = other.s_val[static_cast<size_t>(index2)];
                index2--;
            }
            int temp = char2Int(c1)+char2Int(c2) + ((hasCarry)?1:0);
            if(temp>=base){
                hasCarry=true;
                temp = temp - base;
            }else{
                hasCarry=false;
            }
            if(i>0){
                rst.insert(rst.begin(),int2Char(temp));
            }
            else if(temp==0 && hasCarry){
                temp = 1;
                rst.insert(rst.begin(),int2Char(temp));
            }
        }
        return rst;
    }
    BigInteger operator-(const BigInteger& other){
        int len1 = static_cast<int>(s_val.length()), len2 = static_cast<int>(other.s_val.length()),len = max(len1,len2);
        int index1 = static_cast<int>(len1-1) , index2 = static_cast<int>(len2-1);
        string rst;
        return other;
    }
    BigInteger operator*(const BigInteger& other){

        return other;
    }
    BigInteger operator/(const BigInteger& other){

        return other;
    }
    friend ostream& operator<<(ostream& _cout,const BigInteger& big );
private:
    int char2Int(char num){
        return static_cast<int>(num - '0');
    }
    char int2Char(int num){
        return static_cast<char>(num+48);
    }
    string s_val;
    int base;
};

ostream& operator<<(ostream& _cout,const BigInteger& big ){
    _cout<<big.s_val;
    return _cout;
}

int main(){
    string s_num1,s_num2,s_oper;
    cin>>s_num1;
    cin>>s_oper;
    cin>>s_num2;
    BigInteger num1 = s_num1;
    BigInteger num2 = s_num2;
    BigInteger result;
    switch (s_oper.c_str()[0]) {
    case '+':
        result = num1+num2;
        break;
    case '-':
        result = num1-num2;
        break;
    case '*':
        result = num1*num2;
        break;
    case '/':
        result = num1/num2;
        break;
    }
    cout<<result<<endl;
    return 0;
}
