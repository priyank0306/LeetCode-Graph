class Solution
{
    public:
        string countAndSay(int n)
        {
            vector<string> ans;

            ans.push_back("1");
            ans.push_back("11");

            for (int i = 1; i < 32; i++)
            {
                string flag = "";
                int count = 1;

                char temp = ans[i][0];
                for (int j = 1; j < ans[i].size(); j++)
                {
                    if (ans[i][j] == temp)
                    {
                        count++;
                    }
                    else
                    {
                        flag += to_string(count);
                        flag += temp;
                        count = 1;
                        temp = ans[i][j];
                    }
                }
                flag += to_string(count);
                flag += temp;
                ans.push_back(flag);
            }
            return ans[n-1];
        }
};