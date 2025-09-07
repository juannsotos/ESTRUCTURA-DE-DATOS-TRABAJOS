
int r = 3, c = 3;
int[,] TwoArray =
{
    {1,2,3 },
    {4,5,6 },
    {7,8,9 }

};

int[] arr = new int[r * c];

for (int x = 0; x < r; x++)
{
    for (int y = 0; y < c; y++)
    {
        int k = x * c + y;
        arr[k] = TwoArray[x, y];
    }
}

Console.WriteLine("Los elementos del array bidimensional son:");
for (int x = 0; x<r; x++)
{
    for (int y = 0; y<c; y++)
    {
        Console.Write(TwoArray[x, y] + " ");
    }
    Console.WriteLine();
}

Console.WriteLine("Los elementos del arreglo unidimensional son: ");
for (int i =  0; i < arr.Length; i++)
{
    Console.Write(arr[i] + " ");
}
