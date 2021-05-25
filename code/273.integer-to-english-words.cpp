class Solution {
public:
    vector<string> below_20{" One", " Two", " Three", " Four", " Five", " Six", " Seven", " Eight", " Nine", " Ten", " Eleven", " Twelve", " Thirteen", " Fourteen", " Fifteen", " Sixteen", " Seventeen", " Eighteen", " Nineteen"};
    vector<string> below_100{" Twenty", " Thirty", " Forty", " Fifty", " Sixty", " Seventy", " Eighty", " Ninety"};
    
    string numtoword(int n) {
        
        if (n >= 1000000000000){
            cout<<n<<endl;
            return numtoword(n/1000000000000) + " Trillion" + numtoword(n%1000000000000);
        }
        
        else if (n >= 1000000000){
            cout<<n<<endl;
            return numtoword(n/1000000000) + " Billion" + numtoword(n%1000000000);
        }
        
        else if (n >= 1000000) {
            cout<<n<<endl;
            return numtoword(n/1000000) + " Million" + numtoword(n%1000000);
        }
        
        else if (n >= 1000) 
        {
            cout<<n<<endl;
            return numtoword(n/1000) + " Thousand" + numtoword(n%1000);
        }
        
        else if (n >= 100)
        {
            cout<<n<<endl;
            return numtoword(n/100) + " Hundred" + numtoword(n%100);
        }
        
        else if (n >= 20) 
        {
            cout<<n<<endl;
            return below_100[(n-20)/10] + numtoword(n%10);
        }
        
        else if (n >= 1)
        {
            cout<<n<<endl;
            return below_20[n-1];
        }
            
        
        else 
        {
            cout<<n<<endl;
            return "";
        }
    }
    
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        string res = numtoword(num);
        return res.substr(1, res.length() - 1);
    }
};