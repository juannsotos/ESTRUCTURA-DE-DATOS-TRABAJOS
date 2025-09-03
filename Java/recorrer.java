import java.util.Arrays;
import java.util.Scanner;
public class recorrer {
    public static void main(String[] args) {
        int[] a = {10,20,30,400,5};

    for (int i = 0; i < a.length; i++){
        System.err.println("Posicion " + i + " Valor " + a[i]);
    }

  
    
        Scanner sc = new Scanner(System.in);
        int[] b = {30,50,80,100,30,22};
      
          System.out.print("Ingresa el número a buscar: ");
        int numero = sc.nextInt();

        
        int resultado = BusquedaArray(b, numero);

         if (resultado != -1) {
            System.out.println("El numero esta en la posicion: " + resultado);
        } else {
            System.out.println(" El numero no esta en el arreglo");
        }




        int[] c = {1,2,3,4,5,6};
        System.out.print("Ingresa el valor del numero: ");
        int valor = sc.nextInt();
        System.out.print("Ingresa el indice: ");
        int indice = sc.nextInt();

        c = Inserccion(c, indice, valor);

        System.out.println(Arrays.toString(c));

        sc.close();

    }


    //Busqueda de dato en Array
    public static int BusquedaArray(int[] b,int numero) {

    for (int i = 0; i< b.length; i++){
        if (b[i] == numero) {
            return i;
        }
    }
    return -1;
    }
    
    
    //Hacer la inserccion con dezplazamiento
    public static int[] Inserccion(int[] c, int indice, int valor) {
        for (int i = c.length - 1; i > indice; i--){
            c[i] = c[i-1];}

        c[indice] = valor;
        System.out.println(c);
        return c;

        }

    } 


