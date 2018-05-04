package albumCopaMundo;

import java.io.*;

public class TestaLista {

    public static void main(String[] args) {
        Lista linkedList = new Lista();

        try{
            String nome;
            nome = "C:/Users/gabri/Documents/albumCopaMundo/db.txt";
            BufferedReader br = new BufferedReader(new FileReader(nome));

            int cont = 0;
            Nodo membro = null;
            ListaFigurinhas listaFigurinhas = null;

            while(br.ready()){
                String linha = br.readLine();

                if (linha.indexOf ("Membro_") >= 0) {
                    cont = 1;
                    if(membro != null) {
                        linkedList.insereNoFim(membro);
                    }

                    membro = new Nodo();
                    linkedList.insereNoFim(membro);

                    listaFigurinhas = new ListaFigurinhas();
                }else{
                    if (cont == 1) {
                        membro.setNome(linha);
                        cont++;
                    }else if(cont == 2){
                        membro.setTelefone(linha);
                        cont++;
                    }else if(cont == 3){
                        cont++;
                    }else if(cont > 3){
                        Figura figurinha = new Figura();
                        figurinha.setNumero(linha);

                        listaFigurinhas.insereNoFim(figurinha);
                    }
                }
            }
            br.close();
        }catch(IOException ioe){
            ioe.printStackTrace();
        }
    }

}