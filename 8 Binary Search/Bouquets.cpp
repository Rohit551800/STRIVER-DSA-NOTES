//         FIND MIN. NUMBER OF DAYS TO MAKE BOUQUETS

#include<bits/stdc++.h>
using namespace std;

bool possible(vector<int> &bloomDay, int mid, int m, int k)
{
    int count = 0;
    int noOfDay = 0;
    int n = bloomDay.size();
    for (int i = 0; i < n; i++)
    {
        if (bloomDay[i] <= mid)
        {
            count++;
        }
        else
        {
            noOfDay = noOfDay + count / k;
            count = 0;
        }
    }
    noOfDay = noOfDay + count / k;

    if (noOfDay >= m)
        return true;
    else
        return false;
}

int minDays(vector<int> &bloomDay, int m, int k)
{
    int n = bloomDay.size();
    long long maxi = LLONG_MIN;
    long long mini = LLONG_MAX;
    long long total = 1LL * m * k;
    if (n < total)
        return -1;

    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, (long long)bloomDay[i]);
        mini = min(mini, (long long)bloomDay[i]);
    }

    long long low = mini;
    long long high = maxi;
    long long ans = -1;

    while (low <= high)
    {
        long long mid = (low + high) / 2;

        bool days = possible(bloomDay, mid, m, k);

        if (days == true)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}
int main(){
    int m , k;
    vector <int> bloomDay = { 7 , 7 , 7 , 7 , 13 , 12 , 11 , 7};
    cout<<"Enter the number of bouquets you want:";
    cin>>m;;
    cout<<"Enter the number of adjacent flowers:";
    cin>>k;
    cout<<"Min days require to bloom 2 bouquets:"<<minDays(bloomDay , m , k);
}