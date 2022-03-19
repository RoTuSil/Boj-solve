#include <string>
#include <vector>

using namespace std;

int getRank(int corrects) {
    switch(corrects) {
        case 6:
            return 1;
        case 5:
            return 2;
        case 4:
            return 3;
        case 3:
            return 4;
        case 2:
            return 5;
        default:
            return 6;
    }
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int unreadable = 0;
    int correctCount = 0;
    for(int i = 0;i<6;i++) {
        if(lottos[i]==0) {
            unreadable++;
            continue;
        }
        for(int j = 0;j<6;j++) {
            if(lottos[i]==win_nums[j]) correctCount++;
        }
    }
    answer.push_back(getRank(correctCount+unreadable));
    answer.push_back(getRank(correctCount));
    return answer;
}

