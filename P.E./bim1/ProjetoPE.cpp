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
    ifstream MyFile("Tabela3.txt");
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
    ofstream saida;
    saida.open ("saida.txt");
    float pDesvioM = 0;
    float pDesvioP = 0;
    for(int o = 0; o <sep.size(); o++){
        cout << "Elemento [" << o+1 << "]: " << a[o] << endl;
        saida << "Elemento [" << o+1 << "]: " << a[o] << "\n";
        float desvio = a[o]-media;
        cout << "Desvio: " << (desvio) << endl;
        saida << "Desvio: " << (desvio) << "\n";
        pDesvioP += pow(desvio, 2);
        pDesvioM += fabs(desvio);
        cout << "" << endl;
        saida << "\n";
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
    int maxN = 0;
    for(int i = 0; i < sep.size(); i++){
        cout << "z[" << i << "]: " << z[i] << endl;
        if(maxN < z[i]){
            maxN = z[i];
            max = i;
        }
    }
    for(int j = 0; j < sep.size(); j++){
        if(z[max] == z[j]){
            cout << "Moda: " << a[j] << endl;
            saida << "Moda: " << a[j] << "\n";
        }
    }

    float amplitude = (a[sep.size()-1]-a[0]);
    float k = 1+3.22*log10(sep.size());
    float w = amplitude/k;
    float pMedio = (a[0]+a[sep.size()-1])/2;
    cout << "Desvio Médio: " << pDesvioM/sep.size() << endl;
    saida << "\nDesvio Médio: " << pDesvioM/sep.size() << "\n";
    cout << "Ponto Medio: " << pMedio << endl;
    saida << "Ponto Médio: " << pMedio << "\n";
    cout << "Amplitude: " << amplitude << endl;
    saida << "Amplitude: " << amplitude << "\n";
    cout << "Mediana: " << mediana << endl;
    saida << "Mediana: " << mediana << "\n";
    cout << "Média: " << media << endl;
    saida << "Média: " << media << "\n\n";
    cout << "" << endl;

    cout << "" << endl;
    cout << "Esses dados são do tipo Amostra ou População?" << endl;
    cout << "1 - Amostra" << endl;
    int op;
    cout << "2 - População" << endl;
    cin >> op;
    if(op == 1){
        saida << "\nTipo de dado: Amostra" << "\n";
        cout << "Desvio Padrão: " << sqrt (pDesvioP/(sep.size()-1)) << endl;
        saida << "Desvio Padrão: " << sqrt (pDesvioP/(sep.size()-1)) << "\n";
        cout << "Variância: " << pDesvioP/(sep.size()-1) << endl;
        saida << "Variância: " << pDesvioP/(sep.size()-1) << "\n";
        cout << "Coeficiente de Variação: " << (sqrt (pDesvioP/(sep.size()-1)))/media <<endl;
        saida << "Coeficiente de Variação: " << (sqrt (pDesvioP/(sep.size()-1)))/media << "\n";
        cout << "Coeficiente de Variação em Porcento: " << ((sqrt (pDesvioP/(sep.size()-1)))/media)*100 << "%" << endl;
        saida << "Coeficiente de Variação em Porcento: " << ((sqrt (pDesvioP/(sep.size()-1)))/media)*100 << "%" << "\n";
    }
    else if(op == 2){
        saida << "\nTipo de dado: População" << "\n" ;
        cout << "Desvio Padrão: " << sqrt (pDesvioP/(sep.size())) << endl;
        saida << "Desvio Padrão: " << sqrt (pDesvioP/(sep.size())) << "\n";
        cout << "Variância: " << pDesvioP/(sep.size()) << endl;
        saida << "Variância: " << pDesvioP/(sep.size()) << "\n";
        cout << "Coeficiente de Variação: " << (sqrt (pDesvioP/sep.size()))/media << endl;
        saida << "Coeficiente de Variação: " << (sqrt (pDesvioP/sep.size()))/media << "\n";
        cout << "Coeficiente de Variação em Porcento: " << ((sqrt (pDesvioP/sep.size()))/media)*100 << "%" << endl;
        saida << "Coeficiente de Variação em Porcento: " << ((sqrt (pDesvioP/sep.size()))/media)*100 << "%" << "\n";
    }
    else{
        cout << "Opção inválida" << endl;
        saida << "\nnull" << "\n";
    }
    cout << " " << endl;

    int quant[(int)k];
    for(int i = 0; i < (int)k+1; i++){
        quant[i] = 0;
    }
    for(int i = 0; i < (int)k+1; i++){
        if(i == 0){
            for(int j = 0; j < sep.size(); j++)
                if(a[j] < (a[0])+pow(w, (i+1)))
                    quant[0]++;
        }
        else{
            for(int j = 0; j < sep.size(); j++)
                if((a[j] >= ((a[0])+pow(w, i))) && (a[j] < ((a[0])+pow(w, (i+1)))))
                    quant[i]++;
        }
    }
    cout << "Tabela de Frequência" << endl;
    saida << "\nTabela de Frequência";
    cout << "Classes\tIntervalo de Números\tQuantidade\tFrequência Percentual\tFrequência Acumulada" << endl;
    saida << "\nClasses\tIntervalo de Números\tQuantidade\tFrequência Percentual\tFrequência Acumulada";
    int fa = quant[0];
    for(int i = 0; i < (int)k+1; i++){
        float fp = (((float)quant[i]*100)/(float)sep.size());
        if(i == 0){
            cout << i+1 << "\t" << a[0] << " |----- " << a[0] + pow(w, (i+1)) << "\t" << quant[i] << "\t" << fp << "%\t" << fa << endl;
            saida << i+1 << "\t" << a[0] << " |----- " << a[0] + pow(w, (i+1)) << "\t" << quant[i] << "\t" << fp << "%\t" << fa << "\n";
        }
        else{
            fa += quant[i];
            cout << i+1 << "\t" << a[0] + pow(w, i) << " |----- " << a[0] + pow(w, (i+1)) << "\t" << quant[i] << "\t" << fp << "%\t" << fa << endl;
            saida << i+1 << "\t" << a[0] + pow(w, i) << " |----- " << a[0] + pow(w, (i+1)) << "\t" << quant[i] << "\t" << fp << "%\t" << fa << "\n";
        }
        cout << "" << endl;
    }
    cout << "\t\tTotal: " << fa << "\t" << ((float)fa*100)/(float)sep.size() <<"%" << endl;
    saida << "\t\tTotal: " << fa << "\t" << ((float)fa*100)/(float)sep.size() <<"%";
    saida << "\n\nFim da execução";
    saida.close();
    return 0;
}
