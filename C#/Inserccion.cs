class Program
{

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
        Console.WriteLine(" ");

        for (int i = 1; i < arr.Length; i ++)
        {
            int actual = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > actual)
            {
                arr[j+1] = arr[j];
                j = j - 1;
                
            }
            arr[j+1] = actual;

        }
        Console.WriteLine("El arreglo ordenado es: ");
        Array.ForEach(arr, x => Console.Write(x + " "));
    }


}


