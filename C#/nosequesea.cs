class Program
{
    static void Swap(int[]arreglo,int i,int j)
    {
         int temp = arreglo[i];  // 1. Guardamos el valor del primer elemento en una variable temporal.
        arreglo[i] = arreglo[j];  // 2. Reemplazamos el valor del primer elemento con el del segundo.
        arreglo[j] = temp; // 3. Asignamos el valor guardado (original del primer elemento) al segundo.
    }

    static void QuickShort(int[]arreglo,int inicio, int final)
    {
        if (inicio < final)
        {
            int pivote = Particion(arreglo, inicio, final);
            QuickShort(arreglo, inicio, pivote - 1);
            QuickShort(arreglo, pivote + 1, final);
        }
    }
    static int Particion(int[]arreglo,int inicio,int final)
    {
        int pivote = arreglo[final];
        int i = inicio - 1;

        for (int j = inicio; j < final; j++)
        {
            if (arreglo[j] <= pivote)
            {
                i++;
                Swap(arreglo, i, j);
            }
        }
        Swap(arreglo, i + 1, final);
        return i + 1;
    }
    static void Main()
    {
        Random x = new Random();
        int[] arr = new int[10];

        for (int i = 0; i < arr.Length; i++)
        {
            int numero = x.Next(1, 100);
            arr[i] = numero;
        }

        Console.WriteLine("El arreglo desordenado es: ");
        Array.ForEach(arr, x => Console.Write(x + " "));
        Console.WriteLine("\n");
        Console.WriteLine("El arreglo ordenado es: ");
        QuickShort(arr, 0, arr.Length - 1);
        Array.ForEach(arr, x => Console.Write(x + " "));
        Console.WriteLine("");

    }
}
