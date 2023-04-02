#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;

    int temp = 0;
    for(int i=0;i<photo.size();i++){
        for(int j=0;j<photo[i].size();i++){
            for(int k=0;k<name.size();k++){
                if(!photo[i][j].compare(name[k])){
                    answer.push_back(yearning[k]);
                    break;
                }
            }
        }
    }

    return answer;
}

int main(){
    vector<string> name;
    vector<int> yearning;
    vector<string> temp;
    vector<vector<string>> photo;
    vector<int> answer;
    
    name.push_back("may");
    name.push_back("kein");
    name.push_back("kain");
    name.push_back("radi");

    yearning.push_back(5);
    yearning.push_back(10);
    yearning.push_back(1);
    yearning.push_back(3);

    temp.push_back("may");
    temp.push_back("kein");
    temp.push_back("kain");
    temp.push_back("radi");
    photo.push_back(temp);
    temp.clear();
    

    temp.push_back("may");
    temp.push_back("kein");
    temp.push_back("brin");
    temp.push_back("deny");
    photo.push_back(temp);
    temp.clear();

    temp.push_back("may");
    temp.push_back("kein");
    temp.push_back("brin");
    temp.push_back("deny");
    photo.push_back(temp);
    temp.clear();

    cout << yearning.size() << endl;
    cout << "dasd" << endl;
    
    for(int i=0;i<solution(name,yearning,photo).size();i++){
        cout << solution(name,yearning,photo)[i] << endl;
    }
    
    
    return 0;
}