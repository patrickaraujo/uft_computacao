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
public class Autor {
    private String nome, curriculo, ocupacao;

    public Autor(String nome, String curriculo, String ocupacao) {
        this.nome = nome;
        this.curriculo = curriculo;
        this.ocupacao = ocupacao;
    }

    public String getNome() {
        return nome;
    }

    public String getCurriculo() {
        return curriculo;
    }

    public String getOcupacao() {
        return ocupacao;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setCurriculo(String curriculo) {
        this.curriculo = curriculo;
    }

    public void setOcupacao(String ocupacao) {
        this.ocupacao = ocupacao;
    }
    
}
