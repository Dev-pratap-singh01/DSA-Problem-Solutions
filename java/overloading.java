public class overloading {
    class cat extends overloading {
        void show(int a) {
            System.out.println("Integer: " + a);
        }

        void show(String b) {
            System.out.println("String: " + b);
        }

        void show(int a, int b) {
            System.out.println("Sum: " + (a + b));
        }
    
        
    }
    
}

            