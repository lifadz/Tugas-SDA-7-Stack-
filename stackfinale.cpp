#include <iostream>
using namespace std;

int maximum = 7;
int stackData [7];
int currentData[7];
int top  = -1;
int currenttop = -1;

bool isFullStack(){
    if(top == maximum){
       return true; 
    }else{
        return false;
    }
}
bool isEmptyStack(){
    if(top == -1){
       return true; 
    }else{
        return false;
    }
}
bool tempisEmptyStack(){
   if(currenttop == -1){
       return true;
   } else{
       return false;
   }
}

int removeStack(){ //menghapus data stack
    if(isEmptyStack()){
        cout<< "Empty Data !!"<<endl;
    }else{
        int rem = stackData[top];
        top--;
        return rem;   
    }
}

int removeCurrent(){ // fungsi agar saat menambahkan data stack, data langsung di sorting
    if(tempisEmptyStack()){
        cout<<"Empty Data !!"<<endl;
    }
    else{
        int rem = currentData[currenttop];
        currenttop--;
        return rem;
    }
}

void addStack(int num){ //menambah data stack
    if (isFullStack()){
        top++;
        stackData[top] = num;

    }else{
        if (num > stackData[top]){
            top++;
            stackData[top] = num;
        }
        else{
            while (!isEmptyStack() && stackData[top] > num){
                currenttop++;
                currentData[currenttop] = removeStack();
            }
            top++;
            stackData[top] = num;

            while (!tempisEmptyStack()){
                top++;
                stackData[top] = removeCurrent();

            }    
        }
    }
}

void viewStack(){ //untuk mencetak output
    cout<< "Stack Data : "<<endl;
    int j = 0;
    for (int i = top; i != -1; i-- ){
           cout<< "" << stackData[j] <<endl;     
           j++;
    }    
    cout<<"\n"; 
}
    

int main (){
    addStack(8);
    viewStack();

    addStack(1);
    viewStack();

    addStack(10);
    viewStack();

    addStack(19);
    viewStack();   

    addStack(6);
    viewStack();

    removeStack();
    viewStack();

    removeStack();
    viewStack();
}