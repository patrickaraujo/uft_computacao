/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hw2;

import java.util.Scanner;

/**
 *
 * @author Patrick
 */
public class Hw2 {

    /**
     * @param args the command line arguments
     */
    
    // fucking triangular numbers
    
    public static int[] toArray(String x){
        String numeros[] = x.split(",");
        int z[] = new int[numeros.length];
        for (int i = 0; i < z.length; i++) {
            z[i] = Integer.parseInt(numeros[i]);
        }
        return z;
    }
    
    public static int[] generateNext(int x){
        int v[] = new int[(((x+1) * ((x + 1) + 1) / 2) - (x * (x + 1) / 2))];
        System.out.println("x: "+x);
        for (int i = (x * (x + 1) / 2); i < ((x+1) * ((x + 1) + 1) / 2); i++) {
            int num;
            if((x + 1) % 2 == 0){
                do{
                    num = (int) (Math.random() * 100);
                    System.out.println("shit");
                    v[(i-(x * (x + 1) / 2))] = num;
                }while(num % 2 != 0);
            }
            else{
                do{
                    num = (int) (Math.random() * 100);
                    v[(i-(x * (x + 1) / 2))] = num;
                }while(num % 2 == 0);
            }
        }
        return v;
    }
    
    public static void v(int s[]) {
        int n = (int) Math.sqrt(2 * s.length);
        boolean triangular = n * (n + 1) / 2 == s.length;
        if(triangular){
            boolean allOK = verify(s, n);
            if(allOK){
                System.out.println("Sequencia completa e correta, definindo resutado...");
                int x[] = generateNext(n);
            }
            else
                System.out.println("Sequencia completa mas incorreta, sem resultados a mostrar");
                
        }
        else
            System.out.println("Sequencia incompleta");
    }
    
    public static boolean verify(int s[], int x){
        for (int i = 1; i <= x; i++) {
            int k = 0;
            if (i - 1 != 0)
                k = ((i - 1) * ((i - 1) + 1) / 2);
            for (int j = k; j < (i * (i + 1) / 2); j++) {
                if((i % 2 == 0)){
                    if(s[j] % 2 != 0){
                        return false;
                    }
                }
                else{
                    if(s[j] % 2 == 0){
                        return false;
                    }
                }
            }
        }
        return true;
    }
    
    public static void printArray(int v[]) {
        // Mostra o vetor v na tela
        for (int i = 0; i < v.length; i++) {
            if (i == (v.length) - 2) {
                System.out.print("Posição " + i + ": (" + v[i] + ") e ");
            } else if (!(i == (v.length) - 1)) {
                System.out.print("Posição " + i + ": (" + v[i] + "), ");
            } else {
                System.out.print("Posição " + i + ": (" + v[i] + ")");
            }
        }
        System.out.println();
    }
    
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner input = new Scanner(System.in);
        System.out.println("Entre com a sequência");
        String string = input.next();
        int x[] = toArray(string);
        printArray(x);
        v(x);
    }
}
