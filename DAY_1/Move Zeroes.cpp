#include <iostream>
#include <vector>
using namespace std;
vector<int> in;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        std::vector<int>:: iterator it;
        int length = nums.size();
        for(it = nums.begin(); length>0;){
            if (*it == 0) {
                nums.push_back(0);
				it = nums.erase(it);
            } else {
                it++;
            }
            length--;
        }
    }
};
int main(){
    int num;
    while(cin>>num){
        in.push_back(num);
    }
    cout<<in.size()<<endl;
    Solution s1;
    s1.moveZeroes(in);
    std::vector<int>:: iterator it;
    for(it = in.begin(); it<in.end();it++){
        cout<<*it<<" ";
    }
    return 1;
}

/*#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> move_zeroes(int *b) {
	vector<int> a(b,b+8);
	vector<int>:: iterator it;
	//sort(a.begin(),a.end());
    for(it = a.begin() ; it<a.end() ; it++){
        if(*it == 0){
            it = a.erase(it);
        }
    }
    return a;
};
int main(int argc, char const *argv[]){
    int b[8] = {0,0,1,0,1,0,1,0};
    vector<int> result = move_zeroes(b);
    vector<int>:: iterator it;
    //cout<<sizeof(b)/sizeof(int);
    for(it = result.begin() ; it!= result.end() ; it++){
        cout<<*it;
    }
    return 1;
}
*/
