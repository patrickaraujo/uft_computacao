/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package matriz;

import java.util.Scanner;

/**
 *
 * @author aluno
 */
public class Matriz {

  /**
  * @param args the command line arguments
  */

  public static void alocar(int x[][]){
  for (int i = 0; i < x.length; i++) {
  for (int j = 0; j < x[0].length; j++) {
  x[i][j] = (int) (Math.random() * 100);
  }
  }
  }

  public static void printMatrix(int m[ ][ ]){
  //andando na linha
  for (int n = 0; n < m.length; n++){
  for(int i = 0; i < m[0].length; i++){
  System.out.println(m[n][i]);
  }
  }
  }


  public static void main(String[] args) {
  // TODO code application logic here,
  System.out.println("Entre com a quantidade de linhas...");
  Scanner entrada = new Scanner(System.in);
  int linha = entrada.nextInt();

  System.out.println("Entre com a quantidade de colunas...");
  int coluna = entrada.nextInt();

  int m[][] = new int[linha][coluna];

  alocar(m);
  printMatrix(m);
  }

}
