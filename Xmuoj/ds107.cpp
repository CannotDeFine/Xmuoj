/*
 * @Author: cdf
 * @Date: 2025-02-16 15:06:40
 * @LastEditors: cdf
 * @LastEditTime: 2025-02-16 15:33:20
 * @Description: 后缀表达式求值
 */

 #include<bits/stdc++.h>
 using namespace std;
 
 int main() {
 
    stack<int> nums;

    string temp;
    while (cin >> temp)
    {
        if (temp == "#") break;
        else if (temp == "+")
        {
            if (nums.size() < 2)
            {
                cout << "Expression Error: " << nums.top() << endl;
                return 0;
            }

            int num1 = nums.top();
            nums.pop();
            int num2 = nums.top();
            nums.pop();

            int ans = num1 + num2;
            nums.push(ans);
        }
        else if (temp == "*")
        {
            if (nums.size() < 2)
            {
                cout << "Expression Error: " << nums.top() << endl;
                return 0;
            }

            int num1 = nums.top();
            nums.pop();
            int num2 = nums.top();
            nums.pop();

            int ans = num1 * num2;
            nums.push(ans);
        }
        else if (temp == "-")
        {
            if (nums.size() < 2)
            {
                cout << "Expression Error: " << nums.top() << endl;
                return 0;
            }
            
            int num1 = nums.top();
            nums.pop();
            int num2 = nums.top();
            nums.pop();

            int ans = num2 - num1;
            nums.push(ans);
            
        }
        else if (temp == "/")
        {
            if (nums.size() < 2) 
            {
                cout << "Expression Error: " << nums.top() << endl;
                return 0;
            }

            int num1 = nums.top();
            nums.pop();
            int num2 = nums.top();
            nums.pop();

            if (num1 == 0) 
            {
                cout << "Error: " << num2 << "/" << num1 << endl;
                return 0;
            }

            int ans = num2 / num1;
            nums.push(ans);
        }
        else 
        {
            int tempnum = stoi(temp);
            nums.push(tempnum);
        }
    }

    if (nums.size() != 1)
    {
        cout << "Expression Error: " << nums.top() << endl;
    }
    else
    {
        cout << nums.top() << endl;
    }
 
    return 0;
 }