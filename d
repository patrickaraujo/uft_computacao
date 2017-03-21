#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

vector <string> split(string str, char delimiter) {
    vector<string> internal;
    stringstream ss(str); // Turn the string into a stream.
    string tok;

    while(getline(ss, tok, delimiter)) {
        internal.push_back(tok);
    }
    return internal;
}

/*
void fillActors(vector <string>&numbers){
    cout << size(numbers) << endl;
    return;
}
*/

int main(){
    ifstream MyFile("Tabela1.txt");
    string line;
    vector<string> sep;
    if (MyFile.is_open()){
        while ( getline (MyFile,line) ){
            sep = split(line, '\t');
        }
    }
    MyFile.close();
    float a[sep.size()];
    float toMedia = 0;
	for(int i = 0; i < sep.size(); ++i){
        string x = sep[i];
        a[i] = ::atof(x.c_str());
        toMedia += a[i];
    }
    for(int j = 0; j < sep.size(); j++){
        for(int k = 0; k < (sep.size()-1); k++){
            if(a[k] > a[k+1]){
                int aux = a[k];
                a[k] = a[k+1];
                a[k+1] = aux;
            }
        }
    }

    float media = toMedia/sep.size();
    float mediana;
    int meio = sep.size()/2;
    cout << "Meio: " << meio << endl;
    if(sep.size() % 2 == 0){
        mediana = (a[meio-1]+a[meio])/2;
    }
    else{
        mediana = a[meio];
    }
    float pMedio = (a[0]+a[sep.size()])/2;
    cout << "Ponto Medio: " << pMedio << endl;
    cout << "Mediana: " << mediana << endl;


    for(int i = 0; i <sep.size();i++){
        cout << a[i] << endl;
    }
    cout << "Média: " << media << endl;
    return 0;
}
// falta a moda
