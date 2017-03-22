#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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
    if(sep.size() % 2 == 0){
        mediana = (a[meio-1]+a[meio])/2;
    }
    else{
        mediana = a[meio];
    }

    float pDesvioM = 0;
    float pDesvioP = 0;
    for(int o = 0; o <sep.size(); o++){
        cout << "a[" << o << "]: " << a[o] << endl;
        float desvio = a[o]-media;
        cout << "Desvio: " << (desvio) << endl;
        pDesvioP += pow(desvio, 2);
        pDesvioM += fabs(desvio);
    }


    int z[sep.size()];
    for(int l = 0; l < sep.size(); l++){
        z[l] = 0;
    }
    for(int m = 0; m < sep.size(); m++){
        for(int n = m; n < sep.size(); n++)
            if(a[m] == a[n]){
                z[m]++;
            }
    }
    int max = 0;
    for(int i = 0; i < sep.size(); i++){
        if(max < z[i]){
            max = i;
        }
    }

    float pMedio = (a[0]+a[sep.size()-1])/2;
    cout << "Desvio Médio: " << pDesvioM/sep.size() << endl;
    cout << "Ponto Medio: " << pMedio << endl;
    cout << "Amplitude: " << (a[sep.size()-1]-a[0]) << endl;
    cout << "Mediana: " << mediana << endl;
    cout << "Média: " << media << endl;
    for(int j = 0; j < sep.size(); j++){
        if(z[max] == z[j]){
            cout << "Moda: " << a[j] << endl;
        }
    }
    cout << "Esses dados são do tipo Amostra ou População?" << endl;
    cout << "1 - Amostra" << endl;
    int op;
    cout << "2 - População" << endl;
    cin >> op;
    if(op == 1){
        cout << "Desvio Padrão: " << sqrt (pDesvioP/(sep.size()-1)) << endl;
        cout << "Variância: " << pDesvioP/(sep.size()-1) << endl;
        cout << "Coeficiente de Variação: " << (sqrt (pDesvioP/(sep.size()-1)))/media <<endl;
        cout << "Coeficiente de Variação em Porcento: " << ((sqrt (pDesvioP/(sep.size()-1)))/media)*100 << "%" << endl;
    }
    else if(op == 2){
        cout << "Desvio Padrão: " << sqrt (pDesvioP/(sep.size())) << endl;
        cout << "Variância: " << pDesvioP/(sep.size()) << endl;
        cout << "Coeficiente de Variação em Porcento: " << (sqrt (pDesvioP/sep.size()))/media << endl;
        cout << "Coeficiente de Variação em Porcento: " << ((sqrt (pDesvioP/sep.size()))/media)*100 << "%" << endl;
    }
    else{
        cout << "Opção inválida" << endl;
    }

}
