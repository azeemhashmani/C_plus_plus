#include<bits/stdc++.h>
using namespace std;
#include <stdio.h>

/* Function Proto-type
 */
bool isParanthesisBalanced(string str);

int main()
{
    string str = "";

    cout << "Enter paranthesis string "<< endl;
    cout << ":";
    getline(cin, str); 

    if (isParanthesisBalanced(str))
        cout << "Paranthesis is balanced" << endl;
    else
        cout << "Paranthesis is not balanced" << endl;

   return 0;
}

/* To check if Paranthesis is Balanced
 */
bool isParanthesisBalanced(string str)
{
    stack<char> stackData;
    char c;
 
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i]=='('|| str[i]=='['|| str[i]=='{')
        {
            // Push the element in the stack
            stackData.push(str[i]);
        }
        else
        {
            // IF current current character is not opening
            // bracket, then it must be closing. So stack
            // cannot be empty at this point.
            if (stackData.empty())
                return false;
 
            switch (str[i])
            {
            case ')':
 
                // Store the top element in a
                c = stackData.top();
                stackData.pop();
                if (c != '(')
                return false;
                break;
 
            case '}':
                // Store the top element in b
		c = stackData.top();
		stackData.pop();
		if (c != '{' )
		return false;
		break;
	 
		case ']':
	 
	        // Store the top element in c
	        c = stackData.top();
	        stackData.pop();
	        if (c != '[')
	        return false;
	        break;
            }
        }  
    }
 
    // Check Empty Stack
    return (stackData.empty());
}
 
