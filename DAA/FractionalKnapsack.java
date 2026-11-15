
import java.util.*;

class FractionalKnapsack {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of items: ");
        int n = sc.nextInt();

        int[] weight = new int[n];
        int[] profit = new int[n];
        double[] ratio = new double[n];

        System.out.print("Enter knapsack capacity: ");
        int capacity = sc.nextInt();

        for (int i = 0; i < n; i++) {
            System.out.print("Enter weight of item " + (i + 1) + ": ");
            weight[i] = sc.nextInt();

            System.out.print("Enter profit of item " + (i + 1) + ": ");
            profit[i] = sc.nextInt();

            if (weight[i] <= 0 || profit[i] < 0) {
                System.out.println("Invalid weight or profit!");
                sc.close();
                return;
            }

            ratio[i] = (double) profit[i] / weight[i];
        }

        // Sort according to profit/weight ratio
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {

                if (ratio[i] < ratio[j]) {

                    double temp = ratio[i];
                    ratio[i] = ratio[j];
                    ratio[j] = temp;

                    int t = weight[i];
                    weight[i] = weight[j];
                    weight[j] = t;

                    t = profit[i];
                    profit[i] = profit[j];
                    profit[j] = t;
                }
            }
        }

        double maxProfit = 0;
        int remaining = capacity;

        for (int i = 0; i < n; i++) {

            if (remaining == 0)
                break;

            if (weight[i] <= remaining) {
                maxProfit += profit[i];
                remaining -= weight[i];
            } else {
                maxProfit += ratio[i] * remaining;
                remaining = 0;
            }
        }

        System.out.println("\nMaximum Profit = " + maxProfit);

        sc.close();
    }
}

// Enter number of items: 3
// Enter knapsack capacity: 50
// Enter weight of item 1: 10
// Enter profit of item 1: 60
// Enter weight of item 2: 20
// Enter profit of item 2: 100
// Enter weight of item 3: 30
// Enter profit of item 3: 120