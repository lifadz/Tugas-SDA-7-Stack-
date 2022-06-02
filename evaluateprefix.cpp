#include<iostream>
#include<bits/stdc++.h>
using namespace std;
stack<int> stc;

int main(){
string pre;

cout << "------Prefix Evaluation------" << "\n" << endl;
cout << "Enter Prefix Number : "; //untuk input angka prefix agar dievaluasi, contoh: -+9*35+15
cin >> pre;

//traversing operasi prefix dari kiri ke kanan
for(int i = pre.length() - 1; i>= 0; i--){

    //apabila digit/angka, maka akan ditambahkan ke dalam stack
    if (isdigit(pre[i]))
        stc.push(pre[i] - '0');

    //apabila simbol operator, maka mengambil 2 angka dari stack sebelumnya, nantinya akan melakukan operasi yang spesifik dan hasilnya akan disimpan ke dalam stack kembali
    else{
        
        int num1 = stc.top();
        stc.pop();

        int num2 = stc.top();
        stc.pop();

        if(pre[i] == '+')
            stc.push(num1 + num2);

        else if(pre[i] == '-')
            stc.push(num1 - num2);

        else if(pre[i] == '*')
            stc.push(num1 * num2);

        else if(pre[i] =='/')
            stc.push(num1 / num2);
        }   
    }
    cout << "Result : " << stc.top();// menampilkan hasil evaluasi
    return 0;
}
