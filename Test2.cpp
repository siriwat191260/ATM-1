#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>
#include<cstring>
#include<iomanip>

using namespace std;

int x,m;
string sname;

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string fn,vector<string> &names,vector<float> &moneys){
	fstream source("fn");
    string text;
    char name[100];
    char format[] = "%[^,],%.2f";
    while(getline(source,text)){
    	float money;
        char ctext[100];
        strcpy(ctext,text.c_str());
        sscanf(ctext,format,name,&money);
        names.push_back(name);
        moneys.push_back(money);
    }
    source.close();
}

void searchName(vector<string> &names,vector<float> &moneys,string key){
    int N = names.size();
    int status = 0;
    cout << "---------------------------------\n";
    for(int i = 0 ; i < N ; i++){
        if(key == toUpperStr(names[i])){
            cout << names[i] << "'s moneys = " << fixed << setprecision(2) << moneys[i] << endl;
            status = 1;
        }
    }
    if(status != 1) cout << "Cannot found." << endl;
    cout << "---------------------------------\n";
}

void Deposit(vector<string> &names,vector<float> &moneys,string key){
    int N = names.size();
    int status = 0,deposit;
    cout << "---------------------------------\n";
    for(int i = 0 ; i < N ; i++){
        if(key == toUpperStr(names[i])){
        	sname=names[i];
        	m=i;
        }
    }
	cout << sname << "'s Money in the account now = " << fixed << setprecision(2) << moneys[m] << endl;
    cout <<"How much will you deposit?";
        	cin>>deposit;
        	moneys[m]+=deposit;
            cout << sname << "'s balance = " << fixed << setprecision(2) << moneys[m] << endl;
            status = 1;
    if(status != 1) cout << "Cannot found." << endl;
    cout << "---------------------------------\n";
}

int main(){
    string filename = "Bank.txt";
    vector<string> names;
    vector<float> moneys;
    string key;
    importDataFromFile(filename, names, moneys);

    cout<<"Please input your name : ";
	getline(cin,key);
	key = toUpperStr(key);
	cout<<"Please select your order"<<endl;
	cout<<"1 : Deposit"<<"     "<<"2 : Withdraw"<<"     "<<"3 : Transfer"<<endl;
	cout<<"4 : View transaction history"<<"     "<<"5 : EXIT"<<endl;
	while(true){
		cout<<"Please select number(1-5) : ";
		cin>>x;
		if(x>0&&x<6) break;
		else cout<<"Please select again"<<endl;
	}
        if(x == 1) Deposit(names, moneys, key);
        if(x == 4) searchName(names, moneys, key);
    
    return 0;
}
