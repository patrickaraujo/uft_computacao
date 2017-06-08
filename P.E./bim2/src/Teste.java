/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package teste;

import java.util.Scanner;

/**
 *
 * @author Patrick
 * http://soniavieira.blogspot.com.br/2015/09/teorema-de-bayes-exemplos.html
 */
public class Teste {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        System.out.println("Problema\n\nEm uma cidade em que os carros são testados para emissão de poluentes, 25% deles emitem quantidade considerada excessiva. \nO teste falha para 99% dos carros que emitem excesso de poluentes, mas resulta positivo para 17% dos carros que não emitem quantidade excessiva. \nQual é a probabilidade de um carro que falha no teste realmente emitir quantidade excessiva de poluentes?");
        //  Scanner all = new Scanner(System.in);
        //  float e = all.nextInt();
        float eC = 25;
        float eE = 99;
        float eN = 17;
        Categoria carro = new Categoria(eC);
        Categoria excesso = new Categoria(eE);
        Categoria normal = new Categoria(eN);
        
        float p = (carro.getY()*excesso.getY())/((carro.getY()*excesso.getY())+(carro.getX()*normal.getY()));
        System.out.println("Resposta: "+p);
        
    }
    
}
