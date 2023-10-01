package nFactorial;
import java.util.Random;
import java.util.concurrent.TimeUnit;

public class JAVATester {

    public static void main(String[] args) {
        int[] array = arrayBuild(11);

        long startTime = System.nanoTime();
        rearangeArr(array, 0);
        long endTime = System.nanoTime();

        long duration = endTime - startTime;
        System.out.println(TimeUnit.NANOSECONDS.toMillis(duration) + " ms");
    }

    public static int[] arrayBuild(int num) {
        int[] arr = new int[num];
        Random random = new Random();
        for (int i = 0; i < num; i++) {
            arr[i] = random.nextInt(1000);
        }
        return arr;
    }

    public static void rearangeArr(int[] array, int start) {
        for (int i = start; i < array.length; i++) {
            int temp = array[start];
            array[start] = array[i];
            array[i] = temp;

            rearangeArr(array, start + 1);

            temp = array[start];
            array[start] = array[i];
            array[i] = temp;
        }
    }
}
