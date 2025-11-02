public class Hash {
    public static void displayArr(int[] arr) {
        for (int k : arr)
            System.out.print(k + " ");
        System.out.println();
    }

    public void sort(int[] arr) {
        int n = arr.length;
        for (int gap = n / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < n; i++) {
                int temp = arr[i];
                int j = i;
                while (j >= gap && arr[j - gap] > temp) {
                    arr[j] = arr[j - gap];
                    j -= gap;
                }
                arr[j] = temp;
            }
        }
    }

    public static void main(String[] args) {
        int[] arr = {36, 34, 43, 11, 15, 20, 28, 45};

        System.out.println("Arreglo antes de ser ordenado:");
        displayArr(arr);

        Hash obj = new Hash();
        obj.sort(arr);

        System.out.println("Arreglo después de ser ordenado:");
        displayArr(arr);
    }
}