/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package controletemas;

import java.util.ArrayList;

/**
 *
 * @author arauj
 */
public class Artigo {
    private String titulo, seccao;
    private ArrayList <Autor> autores;
    private ArrayList <String> temas;

    public Artigo(String seccao, String titulo, String themes, String autor, String curriculos, String ocupacoes) {
        autores = new ArrayList<Autor>();
        this.titulo = titulo;
        this.seccao = seccao;
        String nome[] = autor.split(", ");
        String curriculo[] = curriculos.split(", ");
        String ocupacao[] = ocupacoes.split(", ");
        for (int i = 0; i < nome.length; i++) {
            autores.add(new Autor(nome[i], curriculo[i], ocupacao[i]));
        }
        String tema[] = themes.split(", ");
        temas = new ArrayList<String>();
        for (int i = 0; i < tema.length; i++) {
            temas.add(tema[i]);
        }
        
    }

    public void setSeccao(String seccao) {
        this.seccao = seccao;
    }

    public String getSeccao() {
        return seccao;
    }
    
    public String[] getTemas() {
        String retorno [] = new String[temas.size()];
        for (int i = 0; i < retorno.length; i++) {
            retorno[i] = temas.get(i);
        }
        return retorno;
    }

    public String getTitulo() {
        return titulo;
    }
    
    public void setTemas(String tema) {
        this.temas = temas;
    }

    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }
    
}
