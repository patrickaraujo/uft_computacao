#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> split(string str, char delimiter) {
  vector<string> internal;
  stringstream ss(str); // Turn the string into a stream.
  string tok;

  while(getline(ss, tok, delimiter)) {
    internal.push_back(tok);
  }

  return internal;
}

void fillActors(vector <string>&numbers){
     for(int i = 0; i < (sizeof(numbers)/sizeof(*numbers)); i++){

     }
     return;
}
    ifstream MyFile("Tabela1.txt");
    string line;
    vector<string> sep;
    if (MyFile.is_open()){
        while ( getline (MyFile,line) ){
            sep = split(line, '\t');
        }
    }
    MyFile.close();
    for(int i = 0; i < sep.size(); ++i)
        cout << sep[i] << endl;
    return 0;

}
