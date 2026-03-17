#include <bits/stdc++.h>
using namespace std;
int printElem(int row, int col)
{
    int result = 1;
    row = row - 1;
    col = col - 1;
    for (int i = 0; i < col; i++)
    {
        result = result * (row - i);
        result = result / (i + 1);
    }
    return result;
}
void printRow(int row)
{
    vector<int> ans;
    int ans1 = 1;
    ans.push_back(ans1);
    for (int i = 1; i < row; i++)
    {
        ans1 = ans1 * (row - i);
        ans1 = ans1 / i;
        ans.push_back(ans1);
    }
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
}
vector<int> generateRow(int row)
{
    vector<int> ans1;
    int ans = 1;
    ans1.push_back(ans);
    for (int i = 1; i < row; i++)
    {
        ans = ans * (row - i);
        ans = ans / i;
        ans1.push_back(ans);
    }
    return ans1;
}
vector<vector<int>> printPascalTriangle(int row)
{
    vector<vector<int>> ans;
    for (int i = 1; i <= row; i++)
    {
        ans.push_back(generateRow(i));
    }
    for (auto row : ans)
    {
        for (auto r : row)
        {
            cout << r << " ";
        }
        cout << endl;
    }
}
int main()
{
    while (true)
    {
        cout << "****Menu****" << endl
             << endl;
        cout << "1>>> Print element of pascal Triangle" << endl;
        cout << "2>>> Print Row of pascal Triangle " << endl;
        cout << "3>>> Print Pascal Triangle" << endl;
        cout << "4>>> Exit" << endl;
        int choice;
        cout << "Enter your choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int row, col;
            cout << "Enter the row :";
            cin >> row;
            cout << "Enter the column:";
            cin >> col;
            cout << "The element at row " << row << "and column" << col << "is:" << printElem(row, col) << endl;
            break;
        case 2:
            int row1;
            cout << "Enter the row number:";
            cin >> row1;
            printRow(row1);
            break;
        case 3:
            int row2;
            cout << "Enter the number of rows:";
            cin >> row2;
            printPascalTriangle(row2);
            break;
        case 4:
            return 0;
        default:
            cout << "Entered a wrong choice.Please Try Again" << endl;
        }
    }
    return 0;
}