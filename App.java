import java.util.*;

public class App {
    public static void main(String[] args) {
        // FIX 1: Type Safety
        List<String> liste = new ArrayList<>(); 
        liste.add("Test");

        // FIX 2: Removed unnecessary casting
        String s = "Merhaba"; 

        // FIX 3: Try-with-resources to prevent Resource Leak
        try (Scanner sc = new Scanner(System.in)) {
            System.out.println("Input expected (Simulation)...");
        }

        System.out.println("Java side is completely clean now.");
    }
}
