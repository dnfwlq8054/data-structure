#include <iostream>
#include <cstdio>
#include <string>
 
using namespace std;
 
const int ALPABATS = 26;
 
class Tri_Node {
private:
    Tri_Node* child[ALPABATS];
 
public:
    Tri_Node() {
        for (int i = 0; i < ALPABATS; i++)
            child[i] = NULL;
    }
 
    ~Tri_Node() {
        for (int i = 0; i < ALPABATS; i++)
            if (child[i] != NULL)
                delete child[i];
    }
 
    int tonum(char c) {        //문자를 숫자로 변환.
        return tolower(c) - 'a';    //대문자인 경우는 소문자로 변환.
    }
 
    void insert(const char* words) {
        if (*words == '\0')        //입력받은 words가 '\0'일 경우, 즉 문자열 끝인 경우.
            return;
 
        int next = tonum(*words);
 
        if (child[next] == NULL) {
            child[next] = new Tri_Node();
        }
        child[next]->insert(words + 1);
    }
 
    bool find(const char* words) {
        int next = tonum(*words);
 
        if (*words == '\0')
            return true;
 
        if (child[next] == NULL)
            return false;
 
        return child[next]->find(words + 1);
    }
};
 
int main(void) {
 
    Tri_Node tri;
 
    tri.insert("like");
 
    if (tri.find("like"))
        cout << true << endl;
    else
        cout << false << endl;
    
    if (tri.find("bike"))
        cout << true << endl;
    else
        cout << false << endl;
        
 
    return 0;
}
