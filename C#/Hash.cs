using System;

class ShellSort {
    public static void DisplayArr(int[] arr) {
        foreach (int k in arr)
            Console.Write(k + " ");
        Console.WriteLine();
    }

    public void Sort(int[] arr) {
        int n = arr.Length;
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

    static void Main() {
        int[] arr = {36, 34, 43, 11, 15, 20, 28, 45};

        Console.WriteLine("Arreglo antes de ser ordenado:");
        DisplayArr(arr);

        ShellSort obj = new ShellSort();
        obj.Sort(arr);

        Console.WriteLine("Arreglo después de ser ordenado:");
        DisplayArr(arr);
    }
}
