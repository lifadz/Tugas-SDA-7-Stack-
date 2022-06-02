#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;
stack<int> stc;

int main(){
string post;

cout << "------Postfix Evaluation------" << "\n" << endl;
cout<<"Enter Postfix Number To : "; //untuk input angka postfix agar dievaluasi, contoh: 45+3/6*3+ 
cin>>post;

//traversing operasi postfix dari kiri ke kanan
for(int i = 0; i<post.length();i++){

    //apabila digit/angka, maka akan ditambahkan ke dalam stack
    if (isdigit(post[i]))
            stc.push(post[i] - '0');

    //apabila simbol operator, maka mengambil 2 angka dari stack sebelumnya, nantinya akan melakukan operasi yang spesifik dan hasilnya akan disimpan ke dalam stack kembali
    else{

        int num2 = stc.top();
        stc.pop();
            
        int num1 = stc.top();
        stc.pop();

        if(post[i] == '+')
            stc.push(num1 + num2); 

        else if(post[i] == '-')
            stc.push(num1-num2);

        else if(post[i] == '*')
            stc.push(num1*num2);

        else if(post[i] == '/')
            stc.push(num1 / num2);
        }   
    }
    cout << "Result : " << stc.top(); //menampilkan hasil evaluasi
    return 0;
}