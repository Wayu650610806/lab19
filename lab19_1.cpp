#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string file,vector<string> &n,vector<int> &s,vector<char> &g){
    ifstream f("name_score.txt");
    string input;
    int i=0;
    int a,b,c;
        char name[100];
    while (getline(f,input))
    {
        
        char format[]="%[^:]: %d %d %d";
        sscanf(input.c_str(),format,name,&a,&b,&c);
        n.push_back(name);
        int sum=a+b+c;
        s.push_back(sum);
        g.push_back(score2grade(s[i]));
        
        i++;
    }
    
}


void getCommand(string &c,string &key){
    string input;
    char comman[100];
    char k[100];
    cout<<"Please input your command: ";
    getline(cin,input);
    char format[] = "%s %[^\n]";
    sscanf(input.c_str(),format,comman,k);
    c=comman;
    key=k;
}

void searchName(vector<string> n,vector<int> s,vector<char> g,string k){
    int count=0;
    cout << "---------------------------------\n";
    for(unsigned int i=0;i<n.size();i++){
        string name=n[i];
        if(k==toUpperStr(name)){
            count++;
            cout<<n[i]<<"'s score = "<<s[i]<<"\n";
            cout<<n[i]<<"'s grade = "<<g[i]<<"\n";
            
        }
    }
    if(count==0) cout << "Cannot found.\n";
    cout << "---------------------------------\n";
    
    
}

void searchGrade(vector<string> n,vector<int> s,vector<char> g,string k){
    int count=0;
    const char * key = k.c_str();
    char keychar=key[0];
    cout << "---------------------------------\n";
    for(unsigned int i=0;i<n.size();i++){
        if(keychar==g[i]){
            
            count++;
            cout<<n[i]<<" ("<<s[i]<<")\n";
        }
    }
    if(count==0) cout << "Cannot found.\n";
    cout << "---------------------------------\n";
   
}


int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}
