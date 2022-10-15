class Solution
{
    public:
        int compress(vector<char> &chars)
        {
            string ans = "";
            chars.push_back(NULL);
            int count = 1;
            for (int i = 1; i < chars.size(); i++)
            {
                if (chars[i] == chars[i - 1])
                {
                    count++;
                }
                else
                {
                    ans += chars[i - 1];
                    if (count > 1)
                    {
                        int temp = count;
                        string a = "";
                        while (temp > 0)
                        {
                            int rem = temp % 10;

                            a += (char)(rem + 48);
                            temp = temp / 10;
                        }
                      reverse(a.begin(),a.end());
                      ans+=a;
                    }
                  count=1;
                }
            }
          for(int i=0; i<ans.length(); i++)chars[i]=ans[i];
            return ans.length();
        }
};