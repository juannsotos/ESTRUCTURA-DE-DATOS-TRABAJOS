import java.util.Random;
import java.util.Arrays;

public class Inserccion {
    public static void main(String[] args) {
        
        Random r1 = new Random();
        int[] arr = new int[10];    

        for (int i = 0; i < 10; i++){
            int n2 = r1.nextInt(100);
            arr[i] = n2;
        }

        System.out.println("El arreglo es :");
        System.out.println(Arrays.toString(arr));

        for (int i = 1; i < arr.length; i++){
            int actual = arr[i];
            int j = i-1; 
            while (j >= 0 && arr[j] > actual) {
                arr[j+1] = arr[j];
                j = j -1;
            }
            arr[j+1] = actual;

        }

        System.out.println("Ordenado es: ");
        System.out.println(Arrays.toString(arr));



    }

    
}
