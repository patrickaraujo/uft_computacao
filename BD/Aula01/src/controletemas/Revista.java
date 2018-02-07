/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package controletemas;

import java.io.*;
import java.sql.Timestamp;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Date;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/**
 *
 * @author arauj
 */
public class Revista {

    public Timestamp getPublicacao() {
        return publicacao;
    }
    private String nome, categoria, editora;
    private int edicao, numArtigos;
    private Timestamp publicacao;
    private ArrayList <Artigo> artigos;
    private ArrayList <Tema> temas;

    public Revista(String file)throws IOException{
        BufferedReader entrada = new BufferedReader(new FileReader(file));
        String linha = entrada.readLine();
        artigos = new ArrayList<Artigo>();
        int i = 0;
        while (linha != null) {
            linha = entrada.readLine();
            i++;
        }
        passaDados(file, i);
        entrada.close();
        numArtigos = i-1;
        temas();
    }
    
    public void passaDados(String file, int i) throws IOException {
        BufferedReader entrada = new BufferedReader(new FileReader(file));
        String linha;
        for (int j = 0; j < i; j++) {
            linha = entrada.readLine();
            String vetorStr[] = linha.split("\t");
            if(j == 0){
                this.nome = vetorStr[0];
                this.edicao = Integer.parseInt(vetorStr[1]);
                this.publicacao = Timestamp.valueOf(vetorStr[2]);
                this.categoria = vetorStr[3];
            }
            else{
                artigos.add(new Artigo(vetorStr[0], vetorStr[1], vetorStr[2], vetorStr[3], vetorStr[4], vetorStr[5]));
            }
        }
        entrada.close();
    }
    
    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setCategoria(String categoria) {
        this.categoria = categoria;
    }

    public void setEditora(String editora) {
        this.editora = editora;
    }

    public void setEdicao(int edicao) {
        this.edicao = edicao;
    }
    
    public String getNome() {
        return nome;
    }

    public String getCategoria() {
        return categoria;
    }

    public String getEditora() {
        return editora;
    }

    public int getEdicao() {
        return edicao;
    }
    
    public ArrayList<Artigo> getArtigos() {
        return artigos;
    }
    
    public String[] ttas(){
        ArrayList <String> temas = new ArrayList<String>();
        for (Artigo a: artigos) {
            for (int i = 0; i < a.getTemas().length; i++)
                temas.add(a.getTemas()[i]);
        }
        String retorno [] = new String[temas.size()];
        for (int i = 0; i < retorno.length; i++)
            retorno[i] = temas.get(i);
        return retorno;
    }
    
    
    public void temas(){
        temas = new ArrayList<Tema>();
        String tTemas [] = ttas();
        List asList = Arrays.asList(tTemas);
        Set<String> mySet = new HashSet<String>(asList);
        for(String s: mySet){
            temas.add(new Tema(s, Collections.frequency(asList,s)));
        }
    }
}