
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
        Console.WriteLine("\n");

        for (int i = 0; i < arr.Length; i++)
        {
            int min = i;
            for (int j = i + 1; j < arr.Length; j++)
            {
                if (arr[min] > arr[j])
                {
                    min = j;
                }
            }
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
                  
        }
        Console.WriteLine("El arreglo ordenado es: ");
        Array.ForEach(arr, x => Console.Write(x + " "));
    }
}
