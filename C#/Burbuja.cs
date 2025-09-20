
class Program
{
    static void Main()
    {
        Random rnd = new Random();
        int[] arr = new int[10];

        for (int i = 0; i < arr.Length; i++)
        {
            int numero = rnd.Next(1, 100);
            arr[i] = numero;
        }

        Console.WriteLine("El arreglo desordenado es: ");
        Array.ForEach(arr, x => Console.Write(x + " "));  

        for (int i = 0;i < arr.Length; i++)
        {
            for (int j = 0; j<arr.Length-i-1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;  
                }
            }
        }
        Console.WriteLine("");
        Console.WriteLine("El arreglo ordenado es: ");
        Array.ForEach(arr, x => Console.Write(x + " "));

    }



}
