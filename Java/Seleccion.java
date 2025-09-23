import java.util.Arrays;
import java.util.Random;

public class Seleccion {
    public static void main(String[] args) {
        
        Random r1 = new Random();
        int[] arr = new int[10];    

        for (int i = 0; i < 10;i++){
            int n2 = r1.nextInt(100);
            arr[i] = n2;
        }
        
        System.out.println("El arreglo desordenado es: ");
        System.out.println(Arrays.toString(arr));

        for (int i = 0; i < arr.length; i++){
            int min = i;
            for (int j = i+1; j < arr.length; j++){
                if (arr[min] > arr[j]){
                    min = j;
                }
            }
            
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;

        }

        System.out.println("El arreglo ordenado es: ");
        System.out.println(Arrays.toString(arr));
    }

}
