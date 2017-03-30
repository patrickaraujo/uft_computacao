/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hw1;

import java.util.Scanner;

/**
 *
 * @author Patrick
 */
public class Hw1 {

    /**
     * @param args the command line arguments
     */
    
    public static int[] convertToArray(int x){
        String y = Integer.toString(x);
        int[] newX = new int[y.length()];
        for (int i = 0; i < y.length(); i++)
            newX[i] = y.charAt(i) - '0';
        return newX;
    }
    
    public static void quantoFind(int x, int y){
        int z[] = convertToArray(y);
        int i = 0;
        for(int j = 0; j < z.length; j++)
            if(x == z[j])
                i++;
        System.out.println("Quantidade: "+i);
    }
    
    public static void permutacao(int x1, int y1){
        int x[] = convertToArray(x1);
        int y[] = convertToArray(y1);
        int a = 0, b = 0, c = 0, d = 0;
        for(int i = 0; i < x.length; i++){
            a+=x[i];
            b+=y[i];
            c*=x[i];
            d*=y[i];
        }
        if((a == b) && (c == d))
            System.out.println("É permutação");
        else
            System.out.println("Não é permutação");
    }
    
    public static void exercicioC(int x1, int y1){
        int x[] = convertToArray(x1);
        int y[] = convertToArray(y1);
        int findIndex = 0;
        boolean ok[] = new boolean[y.length];
        int count = 0;
        for (int i = 0; i < x.length; i++){
            if(x[i] == y[0]){
                findIndex = i;
                ok[0] = true;
            }
        }
        if((findIndex + (y.length - 1)) < x.length){
            for (int i = findIndex; i < (findIndex + y.length - 1); i++){
                if(x[i+1] == y[1+i-findIndex]){
                    ok[1+i-findIndex] = true;
                }
            }
            for (int i = 0; i < ok.length; i++){
                if(ok[i]){
                    count++;
                }
            }
            if(count == y.length)
                System.out.println("É parte");
            else
                System.out.println("Não é parte");
        }
        else{
            System.out.println("Não é parte");
        }
    }
    
    public static void main(String[] args) {
        // TODO code application logic here
        System.out.println("Entre com o número");
        Scanner entrada = new Scanner(System.in);
        int num = entrada.nextInt();
        System.out.println("Escolha a operação: \n");
        System.out.println("1. Achar quantidade de dígitos");
        System.out.println("2. Verificar se o número é permutação de outro número");
        System.out.println("3. Procurar por ocorrencia");
        int operacao = entrada.nextInt();
        int d;
        switch(operacao){
            case 1:
                System.out.println("Entre com o elemento");
                d = entrada.nextInt();
                quantoFind(d, num);
                break;
            case 2:
                System.out.println("Entre com o elemento");
                d = entrada.nextInt();
                permutacao(num, d);
                break;
            case 3:
                System.out.println("Entre com o elemento");
                d = entrada.nextInt();
                exercicioC(num, d);
                break;
            default:
                System.out.println("Fim da execução");
        }
    }
    
}
