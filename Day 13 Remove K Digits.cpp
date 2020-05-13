class Solution {
public:
    string removeKdigits(string num, int k) {
        stack <char> s;
        if(num.length()==k)
            return "0";
        for(int i=0;i<num.size();i++)
        {         
             while(!s.empty() && num[i]< s.top() && k>0)
            {
                s.pop();
                k--;
            }
            
            s.push(num[i]);
        } 
      
        while(k>0)
        {
            cout<<s.top()<<endl;
            s.pop();
            k--;
        }
        string str="";
        while(!(s.empty()))
        {
            str=str+s.top();
            s.pop();
        }
        reverse(str.begin(),str.end());
        while(str[0]=='0' && str.length()!=1)
        {
                str.erase(0,1);
        }
        return str;
    }
};
