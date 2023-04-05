#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>

using namespace std;

int print_v(vector<string> v){
    cout << "{ ";
    for(int i=0;i<v.size();i++){
        cout << v[i] << "\t";
    }
    cout << " }";

    return 0;
}

int print_vv(vector<vector<string>> v){
    for(int i=0;i<v.size();i++){
        print_v(v[i]);
        cout << endl;
    }

    return 0;
}
bool compare_second(vector<string> a, vector<string> b) {
    return a[1] > b[1];
}

vector<string> split(string str, char Delimiter) {
    istringstream iss(str);             // istringstream에 str을 담는다.
    string buffer;                      // 구분자를 기준으로 절삭된 문자열이 담겨지는 버퍼
    vector<string> result;

    // istringstream은 istream을 상속받으므로 getline을 사용할 수 있다.
    while (getline(iss, buffer, Delimiter)) {
        result.push_back(buffer);               // 절삭된 문자열을 vector에 저장
    }
 
    return result;
}

int trans_m(string hm){
    vector<string> tmp = split(hm,':');
    int result = 60*stoi(tmp[0])+stoi(tmp[1]);

    return result;
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    vector<vector<string>> wait_work;
    int available_time = 0;
    //cout << "plans.size(): " << plans.size() << endl;
    while(!plans.empty()){
        //cout << "plans.size(): " << plans.size() << endl;
        if(plans.size()==1){
            wait_work.push_back(plans.back());
            plans.pop_back();
            break;
        }
        wait_work.push_back(plans.back());
        plans.pop_back();
        available_time = trans_m(plans.back()[1])-trans_m(wait_work.back()[1]);
        //cout << "available_time: " << available_time << "\t,plans.size(): " << plans.size() << endl;
        while(available_time!=0){
            //cout << "available_time털기 진행" << endl;
            if(!wait_work.empty()){
                //cout << "과제 필요시간: " <<stoi(wait_work.back()[2]) << endl;
                if(available_time - stoi(wait_work.back()[2]) >= 0){//wait_work에 있는 일 수행 가능
                    available_time -= stoi(wait_work.back()[2]);
                    answer.push_back(wait_work.back()[0]);  

                    //cout << wait_work.back()[0] << "클리어" <<endl; 

                    wait_work.pop_back();
                    //빼서 만약 0이 되면 while 탈출됨/ avtime 0인데 wait가 비어있지 않을때?
                }else{  //wait_work에 있는 일 수행 불가능
                    wait_work.back()[2] = to_string(stoi(wait_work.back()[2]) - available_time);
                    available_time = 0; //while 탈출
                    //cout << wait_work.back()[0] << "_못끝냄" <<endl; 
                }
            }else{
                available_time = 0; //while 탈출  
                //cout << "wait_work is empty!" << endl; 
            }
        }
    }
    //cout << "plans.size(): " << plans.size() << endl;

    //cout << "---clear wait_work---" << endl;
    while(!wait_work.empty()){
        //cout << wait_work.back()[0] << "클리어" <<endl;
        answer.push_back(wait_work.back()[0]);
        wait_work.pop_back();
    }
    /*
    for(int i=0;i<answer.size();i++){
        cout << answer[i] << endl;
    }
    */
    return answer;
}

int main(){
    vector<string> work;
    vector<vector<string>> plans;
    vector<string> time;
/*
    work.push_back("science");
    work.push_back("12:40");
    work.push_back("50");
    plans.push_back(work);
    work.clear();

    work.push_back("music");
    work.push_back("12:20");
    work.push_back("40");
    plans.push_back(work);
    work.clear();

    work.push_back("history");
    work.push_back("14:00");
    work.push_back("30");
    plans.push_back(work);
    work.clear();

    work.push_back("computer");
    work.push_back("12:30");
    work.push_back("100");
    plans.push_back(work);
    work.clear();
*/
    work.push_back("aaa");
    work.push_back("12:00");
    work.push_back("20");
    plans.push_back(work);
    work.clear();

    work.push_back("bbb");
    work.push_back("12:10");
    work.push_back("30");
    plans.push_back(work);
    work.clear();

    work.push_back("ccc");
    work.push_back("12:40");
    work.push_back("10");
    plans.push_back(work);
    work.clear();

    sort(plans.begin(), plans.end(), compare_second);
    //print_vv(plans);
    //cout << "-------------------------" << endl;

    //print_v(solution(plans));
    cout << solution(plans)[0] << endl;
    cout << solution(plans)[1] << endl;
    cout << solution(plans)[2] << endl;
    //cout << "끝" << endl;

    return 0;
}