#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define size 10 //agar variabel size selalu bernilai 10

char *stack; //inisialisasi
int top = -1;
void push(char);
char pop();
int palindrome(char st[]);


void push(char symbol){

    stack[++top] = symbol;
}

char pop(){

    return stack[top--];
}

int palindrome(char st[]){

    char character;
    int data = 1, i, j, mid, len;

    len = strlen(st);
    stack = (char *)malloc(len * sizeof(char));
    mid = len / 2;

    for (i = 0; i < mid; i++)
        push(st[i]); // push/menambahkan semua elemen termasuk mid, ke dalam stack

    if (len % 2 != 0)
        i++; // jika panjang data string itu ganjil, maka elemen tengah akan diabaikan


    while (st[i] != '\0'){ // hingga sampai akhir dari string, akan dilakukan pop elemen dari stack yang telah ada dan membandingkannya dengan character saat ini 
        
        character = pop();
        if (character != st[i]) // jika string tidak cocok, maka string bukan palindrome.
            return 0;
        i++;
    }
    
    return 1; // jika semua elemen  sesuai/cocok, maka string yang diinput adalah palindrome.
}

int main(){

    char str[size];
    cout << ("\nInput String Word to Check : "); // untuk input kata yang ingin dicheck, contoh nya akuka
    gets(str);

    if (palindrome(str))
        cout << ("\nString is Palindrome\n"); // kondisi bila true
    else
        cout << ("\nString is not Palindrome\n"); // kondisi bila false
    return 0;
}
