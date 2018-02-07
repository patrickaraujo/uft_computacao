/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package controletemas;

import java.io.*;
import java.util.Scanner;
import java.util.Date;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import com.google.gson.Gson;

/**
 *
 * @author arauj
 */
public class ControleTemas {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args)throws IOException{
        // TODO code application logic here
        Revista primeira = new Revista("RevistaVeja.txt");
        System.out.println("Nome da revista: "+primeira.getNome()+"\tEdição: "+primeira.getEdicao()+"\tPublicação: "+primeira.getPublicacao());
        
        ArrayList <Artigo> artigos = primeira.getArtigos();
        
        for(Artigo a: artigos){
            System.out.print("\nSecção: "+a.getSeccao()+"\tTítulo: "+a.getTitulo()+"\t");
            for (int i = 0; i < a.getTemas().length; i++) {
                System.out.print("Temas: "+a.getTemas()[i]+"\n");
            }
        }
        Gson gson = new Gson();
        BufferedWriter writer = new BufferedWriter(new FileWriter("saida.json"));
        writer.write(gson.toJson(primeira));
        writer.close();
    }
    
}