#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct Account {
    unsigned int id = 0;
    string login = "None";
    string name = "None";
    string shell = "None";
    string home_directory = "None";

    bool operator<(const Account& src)const{ return (this->id < src.id); }

    void Show() const{
        cout << id << " " << login  << " " << name  << " " << shell  << " " << home_directory << endl;
    }

};


int main() {
    vector <Account> mas;
    Account person;

    map<Account, int> myMap;
    unordered_map<string , int> unMap;
    unordered_set<int> mySet;
    vector<unsigned int> v;

    string line;
    char delimiter = ',';
    ifstream work_file(R"(D:\Projects\CLion_Projects\Templates\data.csv)");
    getline(work_file, line); //Read headline

    int key = 0;
    int size = 0;
    while (getline(work_file, line))
    {
        string id, login, name, shell, home_directory;
        stringstream stream(line);

        getline(stream, id,delimiter);
        person.id = stoi(id);
        getline(stream, login, delimiter);
        person.login = login;
        getline(stream, name, delimiter);
        person.name = name;
        getline(stream, shell, delimiter);
        person.shell = shell;
        getline(stream, home_directory, delimiter);
        person.home_directory = home_directory;
        mas.push_back(person);

        myMap.insert(pair<Account,int>(person, key));
        unMap.insert(pair<string ,int>(shell, size));
        unMap[shell] += 1;
        if (!mySet.insert(stoi(id)).second){
            v.push_back(stoi(id));
        }
        key ++;
    }
    work_file.close();


    cout << "~ Task 1 ~" << endl;
    auto condition = [](const Account& person){ return  person.shell == "/bin/bash"; };
    auto result = find_if(begin(mas), end(mas), condition);
    (result != end(mas))
        ? cout << "The table contains required shell: " << result->shell << endl
        : cout << "The table does not contain required shell" << endl;
    cout << endl;

    cout << "~ Task 2 ~" << endl;
    map<Account, int>::iterator it;
    for (it = myMap.begin(); it != myMap.end(); ++it){
        if ((it->first).id < 1000) {
            (it->first).Show();
        }
    }
    cout << endl;

    cout << "~ Task 3 ~" << endl;
    unordered_map<string , int>::iterator ik;
    for (ik = unMap.begin(); ik != unMap.end(); ++ik){
        cout << ik->first << " " << ik->second << endl;
    }
    cout << endl;

    cout << "~ Task 4 ~" << endl;
    for (unsigned int i : v){
        cout << i <<endl;
    }
    return 0;
}