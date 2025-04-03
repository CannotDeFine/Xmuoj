/*
 * @Author: cdf
 * @Date: 2025-03-06 16:05:34
 * @LastEditors: cdf
 * @LastEditTime: 2025-03-06 16:22:30
 * @Description: QQ账户的申请与登录
 */

 #include <bits/stdc++.h>
 using namespace std;

 struct node
 {
    string account;
    string password;
 };

 int main()
 {
    int n;
    cin >> n;

    unordered_map<string, string> hash;
    while (n--)
    {
        string tmp_account, tmp_password, option;
        cin >> option >> tmp_account >> tmp_password;
        
        if (option == "N")
        {
            if (hash.count(tmp_account)) // if the account has existed
            {
                cout << "ERROR: Exist" << endl;
            }
            else                        // if the account has not existed, sign in successfully
            {
                hash[tmp_account] = tmp_password;
                cout << "New: OK" << endl;
            }
        }
        else if (option == "L")         // if the option is login
        {
            if (hash.count(tmp_account))
            {
                if (hash[tmp_account] == tmp_password)
                {
                    cout << "Login: OK" << endl;
                }
                else
                {
                    cout << "ERROR: Wrong PW" << endl;
                }
            }
            else
            {
                cout << "ERROR: Not Exist" << endl;
            }
        }

        else cout << "Wrong option !!" << endl;
    }

    return 0;
 }
