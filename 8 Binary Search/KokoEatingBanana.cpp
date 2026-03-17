        //KOKO EATING BANANA

#include<bits/stdc++.h>
using namespace std;

long long totalHour(vector<int> &piles, int mid)
{
    int n = piles.size();
    long long total_hour = 0;
    for (int i = 0; i < n; i++)
    {
        total_hour += ceil((double)piles[i] / mid);
    }
    return total_hour;
}
int minEatingSpeed(vector<int> &piles, int h)
{
    int low = 1;
    int maxi = INT_MIN;
    int n = piles.size();
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, piles[i]);
    }
    long long high = maxi;
    while (low <= high)
    {
        long long mid = (low + high) / 2;
        long long totalhour = totalHour(piles, mid);
        if (totalhour <= h)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}
int main(){
    vector<int> piles = {3 , 6 , 7 , 11};
    int hour;
    cout<<"Enter the hour:";
    cin>>hour;
    cout<<minEatingSpeed(piles , hour);
}