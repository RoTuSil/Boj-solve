#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    bool isExist[201]={};
    vector<int> answer;
    sort(numbers.begin(),numbers.end());
    for(int i = 0;i<numbers.size()-1;i++) {
        for(int j = i+1;j<numbers.size();j++) {
            int sum = numbers[i]+numbers[j];
            if(isExist[sum]) continue;
            isExist[sum]=true;
            answer.push_back(sum);
        }
    }
    sort(answer.begin(),answer.end());
    
    return answer;
}