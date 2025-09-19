import java.util.Random;
import java.util.Arrays;
public class Burbuja {

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
            for (int j = 0; j < arr.length-i-1; j++){
                if (arr[j] > arr[j+1]){
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }

            }
        }

        System.out.println("El arreglo ordenado es: ");
        System.out.println(Arrays.toString(arr));

    }


    
}
