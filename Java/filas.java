public class filas {
    public static void main(String[] args) {
        int r = 3, c = 3;
        int[][] TwoArray = {
            {1,2,3},
            {4,5,6},
            {7,8,9}
        };

        int[] arr = new int[r*c];
        for(int x = 0; x < r; x++){
            for(int y = 0; y < c; y++){
                 int k = x * r + y;
                 arr[k] = TwoArray[x][y];
            }
        }

        System.out.println("Los elementos del array bidimensional son: ");
        for (int x = 0; x < r; x++){
            for (int y = 0; y < c; y++){
                System.out.print(TwoArray[x][y] + " ");
                
            }
            System.out.println();
        }

        System.out.println("Los elementos del array unidimensional son: ");
        for (int i =0; i < arr.length; i++ ){
            System.err.print(arr[i] + " ");
        }
        









        
    }
    
}
