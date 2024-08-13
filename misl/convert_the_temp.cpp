#include<iostream>
using namespace std;
int main(){
    cout<<"enter the temp in celcius:";
    double celcius;
    cin>>celcius;
    double kelvin=celcius+273.15;//celcius to kelvin 
    double Fahrenheit=celcius*1.80+32.00;//celcius to  Fahrenheit

    cout<<kelvin<<endl<<Fahrenheit;

}