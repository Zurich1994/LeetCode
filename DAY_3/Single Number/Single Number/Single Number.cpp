#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
    int singleNumber ( vector<int>& nums ) {
        int positive_hash [ 100000] = { 0 };
        int negative_hash [ 100000 ] = { 0 };
        std::vector<int >:: iterator it;
        for ( it=nums.begin(); it!=nums.end();it++ ) {
            if ( *it < 0 ) {
                negative_hash [ abs ( *it ) ]++;
            } else {
                positive_hash [ *it ]++;
            }
        }
        for ( int i = 0; i < 100000; i++ ) {
            if ( positive_hash [ i ] == 1 ) {
                return i;
            }
            if ( negative_hash [ i ] == 1 ) {
                return -i;
            }
        }
        return -1;
    }
};
int main ( ) {
    Solution s1;
    int a [ 13 ] = { 0,0,2,2,1,1,3,4,5,5,4,3,201};
    int result;
    vector<int> nums ( a , a + 13 );
    result = s1.singleNumber ( nums );
    cout << result << endl;
    system ( "pause" );
    return 1;
}