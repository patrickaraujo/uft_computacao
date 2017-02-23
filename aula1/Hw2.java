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
    
    public static int[] toArray(String x){
        String numeros[] = x.split(",");
        int z[] = new int[numeros.length];
        for (int i = 0; i < z.length; i++) {
            z[i] = Integer.parseInt(numeros[i]);
        }
        return z;
    }
    
    public static boolean odd(int x){
        /*        
            int l = 0;
                while(l < 2){
                    System.out.println("0-------j: "+j);
                    if(l==1)
                        j++;
                    if(j%2!=0){
                        System.out.println("\nj: "+j+"\n");
                        l++;
                    }
                    else{
                        System.out.println("----------------shit");
                        j++;
                    }
                    l++;
                }
        */
        return false;
    }
    
    public static void v(int s[]) {
        int x[][] = verify(s);
        boolean resultado = false;
        int var1 = 0;
        for (int i = 0; i < x[0].length; i++)
                if(s.length==(x[i][0]*x[i][1])){
                    resultado = true;
                    
                }
        if(resultado){
            System.out.println("Sequencia completa, definindo resutado...");
        }
        else{
            System.out.println("Sequencia incompleta");
        }
    }
    
    public static int[][] verify(int s[]){
        int j = 1, l = 0;
        int arrayTD [][] = new int [s.length*2][s.length*2];
        for (int i = 1; i <= s.length; i++) {
            int k = 0;    
            while(k < 2){
                k++;
                while(k != 1){
                    if(j%2==0)
                        j++;
                    else
                        j=j+2;
                    break;
                }
                arrayTD [l][0] = i;
                arrayTD [l][1] = j;
                //  if(s.length > arrayTD [l][0]*arrayTD [l][1]) return arrayTD;
                l++;
            }
        }
        return arrayTD;
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
