/*import java.util.Scanner;
import java.util.function.Function;

public class SquareCalculator {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a number: ");
        int number = sc.nextInt();

        // Using Java 8 Function<T, R>
        Function<Integer, Integer> square = x -> x * x;

        System.out.println("Square of " + number + " is: " + square.apply(number));

        sc.close();
    }
}




import java.util.function.Function;

public class SquareCalculator {
    public static void main(String[] args) {
        int num = 4;

        Function<Integer, Integer> square = x -> x * x;

        System.out.println("Square of " + num + " is: " + square.apply(num));
    }
}











import java.util.Scanner;

public class SquareOfTwoNumbers {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the first number: ");
        int num1 = scanner.nextInt();

        System.out.print("Enter the second number: ");
        int num2 = scanner.nextInt();

        int square1 = num1 * num1;
        int square2 = num2 * num2;

      
        System.out.println("Square of " + num1 + " is: " + square1);
        System.out.println("Square of " + num2 + " is: " + square2);

        scanner.close();
    }
}
*/




import java.util.Scanner;
import java.util.function.Function;

public class square {  
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the first number: ");
        int num1 = scanner.nextInt();

        System.out.print("Enter the second number: ");
        int num2 = scanner.nextInt();

        Function<Integer, Integer> square = x -> x * x;

        System.out.println("Square of " + num1 + " is: " + square.apply(num1));
        System.out.println("Square of " + num2 + " is: " + square.apply(num2));

        scanner.close();
    }
}

