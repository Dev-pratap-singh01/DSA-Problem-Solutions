import java.io.FileInputStream;
import java.io.FileNotFoundException;

public class file {
    public static void main(String[] args) { 
        try {
            FileInputStream vds = new FileInputStream("C:\\Users\\Dev Pratap Singh\\OneDrive\\Desktop\\java programming\\n" + //
                                "ew.txt");
            System.out.println("File found and opened");
        } catch (FileNotFoundException e) {
            System.out.println("file not found");
        }
    }
}