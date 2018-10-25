#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include<stdio.h>
using namespace std;
class Solution {
    public:
    static bool cmp ( string &a , string &b ) {
        string ab = a + b;
        string ba = b + a;
        return ab > ba;
    }
    string largestNumber ( vector<int>& nums ) {
        vector<string> numbers;
        string result;
        int count = nums.size ( );
        int count_zero = 0;
        if ( count == 0 ) {
            return NULL;
        }
        for ( int i = 0; i < count; i++ ) {
            if ( nums [ i ] == 0 ) {
                count_zero++;
            }
            char temp [ 20 ];
            sprintf ( temp , "%d" , nums [ i ] );
            numbers.push_back ( temp );
        }
        if ( count_zero == count ) {
            return "0";
        }
        sort ( numbers.begin ( ) , numbers.end ( ) , cmp );
        for ( int i = 0; i < count; i++ ) {
            result += numbers [ i ];
        }
        return result;
    }
};
int main ( ) {
    Solution s1;
    int a [ ] = { 3,30,34,5,9 };
    string result;
    vector<int> given ( a , a + sizeof ( a ) / sizeof ( int ) );
    result = s1.largestNumber (given );
    cout << result << endl;
    system ( "pause" );
    return 1;
}