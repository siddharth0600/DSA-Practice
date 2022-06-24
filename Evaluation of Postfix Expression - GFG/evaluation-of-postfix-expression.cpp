// { Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Your code here
        stack<int> s1;
        
        for(int i=0;i<S.size();i++){
            if(S[i]>='0' && S[i]<='9'){
                s1.push(S[i]-'0');
            } else {
                int num1=s1.top();
                s1.pop();
                int num2=s1.top();
                s1.pop();
                int res;
                  if(S[i]=='+')
               {
                   res = num2 + num1 ;
               }
               else if(S[i]=='-')
               {
                   res = num2 - num1 ;
               }
               else if(S[i]=='*')
               {
                   res = num2 * num1 ;
               }
               if(S[i]=='/')
               {
                   res = num2 / num1 ;
               }
               
               s1.push(res);
            }
        }
        return s1.top();
    }
};

// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends