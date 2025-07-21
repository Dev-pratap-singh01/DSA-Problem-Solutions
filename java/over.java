public class over {
    void show(int a) {
        System.out.println(a);
    }

    void show(String b) {
        System.out.println(b);
    }

    void show(int a, int b) {
        System.out.println("sum=" + (a + b));
    }

    public static void main(String[] args) {
        over obj1 = new over();

        obj1.show("hello");  
    }
}
