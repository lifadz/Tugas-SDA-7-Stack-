// convert infix to prefix
#include <iostream>
#include <conio.h>
#include <string.h>
#define amount 10
using namespace std;

int add(char);
char del();

int theOperator(char);
int primary(char);

char *toPrefix(char *);
char prefix[amount];

struct stack
{
    int top;
    char stc[amount];
    
} st;

int main()
{
    char infix[amount];
    cout << "------Infix to Prefix------" << "\n" << endl;
    cout << "Input Infix Number Expression : ";//input infix, contoh: 2+(6*5)/9
    cin >> infix;

    printf("\nInfix Number Expression : %s", infix);
    printf("\nPrefix Number Expression : %s", toPrefix(strrev(infix)));

    return 0;
}

int add(char symbol)
{
    return st.stc[++st.top] = symbol;
}

char del()
{
    return st.stc[st.top--];
}

int primary(char symbol)
{
    switch (symbol)
    {
    case ')':
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

int theOperator(char symbol)
{
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

char *toPrefix(char infix[amount])
{
    st.top = -1;
    char symbol;
    int i = 0, j = 0;

    add('$');
    while (infix[i] != '\0')
    {
        if (!theOperator(infix[i]))
        {
            prefix[j++] = infix[i];
            i++;
        }
        else
        {
            if (infix[i] == '(')
            {
                do
                {
                    symbol = del();
                    if (symbol == ')')
                        break;
                    prefix[j++] = symbol;
                } while (symbol != ')');
                i++;
            }
            else if ((infix[i] == ')') || (primary(st.stc[st.top]) < primary(infix[i])))
            {
                add(infix[i]);
                i++;
            }
            else
                prefix[j++] = del();
        }
    }
    do
    {
        symbol = del();
        if (symbol == '$')
            break;
        prefix[j++] = symbol;
    } while (symbol != '$');
    prefix[j] = '\0';

    return strrev(prefix);
}
