import java.util.Random;
import java.util.Arrays;
public class QuickShort {

    public static void swap(int[] arreglo, int i, int j) {
        int temp = arreglo[i];  // 1. Guardamos el valor del primer elemento en una variable temporal.
        arreglo[i] = arreglo[j];  // 2. Reemplazamos el valor del primer elemento con el del segundo.
        arreglo[j] = temp; // 3. Asignamos el valor guardado (original del primer elemento) al segundo.
    }

    public static int particion(int [] arr,int inicio,int finall){
        int pivote = arr[finall];
        int i = inicio - 1;

        for (int j = inicio; j < finall; j++){
            if (arr[j] <= pivote){
                i++;
                swap(arr, i, j);
                
            }
        }
        swap(arr, i+1, finall);
        return i+1;
    }

    public static void quickshort(int [] arr,int inicio,int finall){
        if (inicio < finall){
            int pivote = particion(arr,inicio,finall);
            quickshort(arr,inicio,pivote-1);
            quickshort(arr,pivote+1,finall);
        }
    }
    public static void main(String[] args) {
        Random r1 = new Random();
        int[] arr = new int[10];    

        for (int i = 0; i < arr.length;i++){ // Esto genera una arreglo con numeros aleatorios
            int n2 = r1.nextInt(100);
            arr[i] = n2;
        }
        
        System.out.println("El arreglo desordenado es: ");
        System.out.println(Arrays.toString(arr));
        quickshort(arr, 0, arr.length - 1);
        System.out.println("El arreglo ordenado es: ");
        System.out.println(Arrays.toString(arr));
    }
}
