#include <string>
#include <vector>

using namespace std;

string Atoa(string str) {
    for(int i = 0;i<str.length();i++) {
        if(str[i]>='A'&&str[i]<='Z')
            str[i] -= ('A'-'a');
    }
    return str;
}

string removeNotAllowedChar(string str) {
    const string allowedChar = "abcdefghijklmnopqrstuvwxyz0123456789_-.";
    string answer = "";
    for(int i = 0;i<str.length();i++) {
        if(allowedChar.find(str[i])<=allowedChar.length()) {
            answer.push_back(str[i]);
        }
    }
    return answer;
}

string removeDoubleDots(string str) {
    string answer = "";
    for(int i = 0;i<str.length();i++) {
        if(answer.back() == '.' && str[i] == '.') 
            continue;    
        answer.push_back(str[i]);
    }
    return answer;
}

string removeSideDots(string str) {
    string answer = "";
    int i = (str.front()=='.' ? 1 : 0);
    
    for(;i<str.length();i++) {
        answer.push_back(str[i]);
    }
    if(answer.back() == '.') 
        answer.pop_back();
    return answer;
}

string shorterId(string str) {
    while(str.length()>15) {
        str.pop_back();
    }
    str = removeSideDots(str);
    return str;
}

string makeLonger(string str) {
    while(str.length()<3) {
        str.push_back(str.back());
    }
    return str;
}

string solution(string new_id) {
    string answer = "";
    answer = Atoa(new_id);
    answer = removeNotAllowedChar(answer);
    answer = removeDoubleDots(answer);
    answer = removeSideDots(answer);
    if(answer.empty()) answer = "a";
    answer = shorterId(answer);
    answer = makeLonger(answer);
    return answer;
}