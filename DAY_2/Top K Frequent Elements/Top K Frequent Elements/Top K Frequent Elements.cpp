# include<iostream>
#include<vector>
#include <algorithm>
#include<utility>
#include<map>
using namespace std;
class Map_Solution
{
    public:
    vector<int>topKFrequent ( vector<int>& nums , int k ) {
        int map_size;
        map<int , int> m;
        multimap<int , int> m2;
        std::map<int , int>::iterator it;
        std::multimap<int , int>::iterator it2;
        for ( int i = 0; i < nums.size ( ); i++ ) {
            it = m.find ( nums [ i ] );
            if ( it != m.end ( ) ) {
                int temp1 = ( *it ).second;
                temp1++;
                m [ nums [ i ] ] = temp1;
            } else {
                m [ nums [ i ] ] = 1;
            }
        }
        for ( it = m.begin(),it2=m2.begin(); it != m.end(); it++ ) {
            m2.insert ( pair<int , int> ( ( *it ). second , ( *it ).first ) );
        }
        it2 = m2.end ( );
        it2--;
        nums.clear ( );
        map_size = m.size ( );
        for ( int j = 0; k > 0 && map_size > 0; k-- , j++ , map_size-- ,it2--) {
            nums.insert ( nums.begin ( )+j , ( *it2 ).second );
        }
        return nums;
    }
};
class Pair_Solution
{
    public:
    vector<int> topKFrequent ( vector<int>& nums , int k ) {
        vector<pair<int , int>> a;
        vector<pair<int , int>> :: iterator it;
        sort ( nums.begin ( ) , nums.end ( ) );
        for ( int i = 0 ; i < nums.size ( ); ++i ) {
            int count = 1;
            while ( i + 1 < nums.size ( ) && nums [ i + 1 ] == nums [ i ] ) {
                ++count;
                ++i;
            }
            a.push_back ( pair<int , int> ( count , nums [ i ] ) );
        }
        sort ( a.begin ( ) , a.end ( ) );
        nums.clear ( );
        int size = a.size ( ) - 1 , j = 0;
        while ( k > j && size >= 0 ) {
            nums.push_back ( a [ size ].second );
            ++j;
            --size;
        }
        return nums;
    }
};
int main () {
    int k  =2;
    Pair_Solution s1;
    Map_Solution m1;
    int  a [ ] = { 2,2,2,2,2,2,2,4,1,1,1,2,2};
    vector<int> p(a,a+sizeof(a)/sizeof(int));
   std:: vector<int> :: iterator it;
  /* p= s1.topKFrequent(p,k );
    for (it = p.begin ( ); it != p.end ( ); it++ ) {
        cout<<*it<<" ";
    }
    cout << endl;*/
    m1.topKFrequent ( p , k );
    for ( it = p.begin ( ); it != p.end ( ); it++ ) {
        cout << *it << " ";
    }
    cout << endl;
    system("pause" );
    return 1;
}