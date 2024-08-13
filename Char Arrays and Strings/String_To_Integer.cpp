#include<iostream>
using namespace std;
//atoi-function in std which  is used to covert char_string to int
// int ans=atoi(s.c_str());

//steps
//1.Ignore leading white spaces
//2.Determine sign-+ve or -ve
//3.if digit found after finding the sign take that as integer till the next non digit charcter  is found
//4.handle the case if num is out of range->(INT_MIN to INT_MAX)
int myAtoi(string s) {
    int num=0;
    int sign=1;//indicating postive initially
    int i=0;//iterate over string
    while(s[i]==' '){
        //1.skip over leading white spaces
        i++;
    }
    if(i<s.length() && s[i]=='+' || s[i]=='-'){
        // 2.check for sign in the string
        sign=s[i]=='+'? 1:-1; //sign =1 if s[i] is +ve else -1
        ++i;
    }

    while(i<s.length()&&isdigit(s[i])){
        // 3.take num till it is a digit 
        if(num>INT_MAX/10 || num==INT_MAX/10 && s[i]>'7'){
            //4.if the num is out of range handle them acc to sign
            return sign==-1 ? INT_MIN : INT_MAX;
        }
        num=num*10+(s[i]-'0');//s[i]-'0' converts the respective char(s[i]) to int
        i++;
    }

    return num*sign;//if it is negative then sign =-1 and we return num*sign
        
}
int main(){
    string s="  1234 with words as well";
    cout<<myAtoi(s);
}