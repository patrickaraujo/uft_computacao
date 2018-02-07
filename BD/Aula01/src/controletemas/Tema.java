/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package controletemas;

/**
 *
 * @author arauj
 */
public class Tema {
    private String tema;
    private int qtd;

    public Tema(String tema, int qtd) {
        this.tema = tema;
        this.qtd = qtd;
    }

    public void setTema(String tema) {
        this.tema = tema;
    }

    public void setQtd(int qtd) {
        this.qtd = qtd;
    }

    public String getTema() {
        return tema;
    }

    public int getQtd() {
        return qtd;
    }
}
