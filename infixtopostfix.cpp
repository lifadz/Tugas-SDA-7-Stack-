//convert infix to postfix
#include <iostream>
#include <conio.h>
using namespace std;
#define amount 10 //agar variabel amount selalu bernilai 10

int add(char);
char del();

int theOperator(char);
int primary(char);

char postfix[amount];
char *toPostfix(char *);

struct stack{

    int top;
    char stc[amount];

} st;

int primary(char symbol){

    switch (symbol){

        case '(':
        return 0;
        break;

        case '+':

        case '-':
        return 1;
        break;

        case '*':

        case '/':

        case '%':
        return 2;
        break;

        case '^':
        return 3;
        break;

        case '$':
        return -1;
        break;

        default:
        return 0;
        break;
    }
}

int theOperator(char symbol){

    switch (symbol){
        
    case '+':

    case '-':

    case '*':

    case '/':

    case '^':

    case '%':

    case '(':

    case ')':
        return 1;
        break;

    default:
        return 0;
        break;
    }
}

int add(char symbol){

    return st.stc[++st.top] = symbol;
}

char del(){

    return st.stc[st.top--];
}

char *toPostfix(char infix[amount]){
    st.top = -1;
    int i = 0, j = 0;
    char symbol;

    add('$');
    while (infix[i] != '\0'){
        if (!theOperator(infix[i])){

            postfix[j++] = infix[i];
            i++;

        } else{

            if (infix[i] == ')'){
                do{

                    symbol = del();
                    if (symbol == '(')
                        break;
                    postfix[j++] = symbol;

                } while (symbol != '(');
                i++;

            }
            else if ((infix[i] == '(') || (primary(st.stc[st.top]) < primary(infix[i]))){

                add(infix[i]);
                i++;

            }
            else
                postfix[j++] = del();
        }
    }
    do{

        symbol = del();
        if (symbol == '$')
            break;
            postfix[j++] = symbol;

    } while (symbol != '$');

        return postfix;
}

int main(){

    char infix[amount];
    cout << "------Infix to Postfix------" << "\n" << endl;
    cout << "Input Infix Number Expression : "; //input infix, contoh: 2+(6*5)/9
    cin >> infix;

    cout << "\nInfix Number : " << infix << endl;
    cout << "Postfix Number : " << toPostfix(infix);
    return 0;
}
