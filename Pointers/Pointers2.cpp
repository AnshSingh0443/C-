#include<iostream>
using namespace std;
void solve(int arr[]) {
   //9. here an pointer arr is created which stores the base address of array arr
   cout <<"Size inside solve function " << sizeof(arr) << endl;
   cout <<"arr: " << arr << endl;
   cout << "&arr: " << & arr << endl;

   arr[0] = 50;// means*(arr+0)=50
}

void update(int *p) {
   //11. a new pointer p is created which will point to the same location ptr is pointing to
   // i.e p will store the same address as ptr->pointer copying
   cout << "Address stored inside p is: " << p << endl;
   cout << "Address of p  is:" << &p << endl;
   *p = *p + 10;
}
int main(){
   int arr[4] = {12,44,66,18};
   //1.in case of array arr,&arr and &arr[0] all give BASE ADDRESS of the array
   //note->arr is a pointer to the first location of the array 
   cout << arr << endl;
   cout << arr[0] << endl;
   cout << &arr << endl;
   cout << &arr[0] << endl;


   //2.arr[i] works  as *(arr+i) since arr->base address 
   cout << *arr << endl;//value at 0th index
   cout << arr[0] << endl;
   cout << *arr + 1 << endl;
   cout << *(arr) + 1 << endl;
   cout << *(arr + 1) << endl;//value at 1st Index
   cout << arr[1] << endl;
   cout << *(arr + 2) << endl;//value at 2nd index
   cout << arr[2] << endl;
   cout << *(arr + 3) << endl;//value at 3rd index
   cout << arr[3] << endl;
   //3.we can also write i[arr] instead of arr[i] which works as *(i+arr)
    


   //4. we can cannot change/update the value of arr ie(arr=arr+2) ->BASE ADDRESS of array cannot be changed
   // arr=arr+2->gives error

   //5. Since arr is a pointer in case of array the size of arr is the size of the whole array but in case of noraml pointer it gave 4
   cout << sizeof(arr) << endl;//since total elemnts->4 and type int->4byte ,total size=16

   int* p = arr;//a pointer p is created which pointes to the first location of the array
   cout << sizeof(p) << endl;
   //6. now we can do p=p+1 as we could not do arr=arr+1(base address cannot be changed)
   //if base address of arr=104
   // then p=p+1 will be 108 which points to the 1st index of the array


   //7.implementation of cout is such that ki ch does not give base address so we Have to do &ch for address(in case of array of char)
   char ch[10]="ansh";
   char *c=ch;//since ch does not give base address we cannot assign a pointer to &ch but we can do &ch[0] instead so char*c=&ch[0] is valid
   cout<<ch<<endl;//ansh is printed
   cout<<&ch<<endl;//now we can get the address of the array
   cout<<c<<endl;//ansh is printed instead of base address of array ch
   cout<<*c<<endl;//print char at base address(0th index)
   cout<<*(c+1)<<endl;//char at 1st index
   cout<<c+2<<endl;//2nd index se le kar jab tak null char na mile tab tak print hoga

   //8.When array is passed in a fxn
   int arr1[10] = {1,2,3,4};
   cout << "Size inside main function. " << sizeof(arr) << endl;
   cout << arr1 << endl;
   cout << &arr1 << endl;

   //printing array inside main
   for(int i=0; i<10; i++) {
      cout << arr1[i] << " ";
   }cout << endl;
   cout << endl << endl << "Now calling solve function" << endl;

   solve(arr1);

   cout << "Wapas main function me aagye h " << endl;

   for(int i=0; i<10; i++) {
    cout << arr1[i] << " ";
   }cout << endl;


   //10. passing pointer in a function
   int a = 5;
   cout << "Address of a is: " << &a << endl;
   int* ptr = &a;
   cout << "address stored in ptr is: " << ptr << endl;
   cout << "Address of ptr is: " << &ptr << endl;
   //function call
   update(ptr);
   //updated value of a
   cout<<"value of a is: " << a << endl;



}