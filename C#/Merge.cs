using System;

class MergeSortExample
{
    static void Merge(int[] a, int l, int m, int r)
    {
        int a1 = m - l + 1;
        int a2 = r - m;

        int[] L = new int[a1];
        int[] R = new int[a2];

        for (int j = 0; j < a1; j++)
            L[j] = a[l + j];
        for (int k = 0; k < a2; k++)
            R[k] = a[m + 1 + k];

        int i = 0, j2 = 0, k = l;

        while (i < a1 && j2 < a2)
        {
            if (L[i] <= R[j2])
            {
                a[k] = L[i];
                i++;
            }
            else
            {
                a[k] = R[j2];
                j2++;
            }
            k++;
        }

        while (i < a1)
        {
            a[k] = L[i];
            i++;
            k++;
        }

        while (j2 < a2)
        {
            a[k] = R[j2];
            j2++;
            k++;
        }
    }

    static void MergeSort(int[] a, int l, int r)
    {
        if (l < r)
        {
            int m = l + (r - l) / 2;
            MergeSort(a, l, m);
            MergeSort(a, m + 1, r);
            Merge(a, l, m, r);
        }
    }

    static void Main()
    {
        int[] a = { 39, 28, 44, 11 };
        Console.WriteLine("Antes de ordenar: " + string.Join(" ", a));
        MergeSort(a, 0, a.Length - 1);
        Console.WriteLine("Después de ordenar: " + string.Join(" ", a));
    }
}