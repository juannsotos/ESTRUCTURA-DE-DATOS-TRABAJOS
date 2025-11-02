import java.util.ArrayList;

public class bucket {

    static void insertionSort(ArrayList<Double> bukt) {
        for (int j = 1; j < bukt.size(); j++) {
            double val = bukt.get(j);
            int k = j - 1;
            while (k >= 0 && bukt.get(k) > val) {
                bukt.set(k + 1, bukt.get(k));
                k--;
            }
            bukt.set(k + 1, val);
        }
    }

    static void bucketSort(double[] inputArr) {
        int s = inputArr.length;
        ArrayList<ArrayList<Double>> bucketArr = new ArrayList<>(s);

        for (int i = 0; i < s; i++)
            bucketArr.add(new ArrayList<>());

        for (double j : inputArr) {
            int bi = (int) (s * j);
            if (bi != s)
                bucketArr.get(bi).add(j);
            else
                bucketArr.get(s - 1).add(j);
        }

        for (ArrayList<Double> bukt : bucketArr)
            insertionSort(bukt);

        int idx = 0;
        for (ArrayList<Double> bukt : bucketArr)
            for (double j : bukt)
                inputArr[idx++] = j;
    }

    public static void main(String[] args) {
        double[] inputArr = {0.77, 0.16, 0.38, 0.25, 0.71, 0.93, 0.22, 0.11, 0.24, 0.67};

        System.out.println("Arreglo antes de ordenar:");
        for (double v : inputArr) System.out.print(v + " ");

        bucketSort(inputArr);

        System.out.println("\nArreglo después de ordenar:");
        for (double v : inputArr) System.out.print(v + " ");
    }
}