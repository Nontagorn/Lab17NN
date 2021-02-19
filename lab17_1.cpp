#include <iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cctype>
using namespace std;

int main(){
    vector<string> name;
    vector<int> score;
    vector<char> grade;
    int score1;
    int score2;
    int score3;
    string line;
    char name1[100];
    string command;
    string comname;
    string strname;
    vector<string> uppername;
    char comgrade;
    char format[] = "%[^:] %[^ ] %d %d %d";
    int j = 0;
    int sum;
    ifstream file("name_score.txt");
    char temp[100];

    while(getline(file,line)){
        sscanf(line.c_str(),format,name1,temp,&score1,&score2,&score3);
        strname = name1;
        while(strname[j]){
            strname[j] = toupper(strname[j]);
            j++;
        }
        j = 0;
        uppername.push_back(strname);
        name.push_back(name1);
        sum = score1+score2+score3;
        score.push_back(sum);
        if(score.back() >= 80)grade.push_back('A');
        else if(score.back() >= 70)grade.push_back('B');
        else if(score.back() >= 60)grade.push_back('C');
        else if(score.back() >= 50)grade.push_back('D');
        else grade.push_back('F');
    }

    while(command != "exit"){
        j=0;
        cout << "Please input your command : ";
        cin >> command;
        if(command == "name"){
            cin >> comname;
            while(comname[j]){
                comname[j] = toupper(comname[j]);
                j++;
            }
            for(int i = 0;i < name.size();i++){
                if(uppername[i] == comname){
                    cout << "------------------------------------\n";
                    cout << name[i] << "'s grade = " << grade[i] << '\n';
                    cout << "------------------------------------\n";
                    break;
                }
                if(i == name.size() - 1)cout << "Cannot found.\n";
            }
        }

        else if(command == "grade"){
            cin >> comgrade;
            comgrade = toupper(comgrade);
            cout << "------------------------------------\n";
            for(int i = 0;i < name.size();i++){
                if(comgrade == grade[i])cout << name[i] << '\n';
            }
            cout << "------------------------------------\n";
        }
        else if(command != "exit")cout << "Invalid command\n";
    }

    return 0;
}