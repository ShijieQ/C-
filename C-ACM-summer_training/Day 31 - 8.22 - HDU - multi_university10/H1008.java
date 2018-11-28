import java.util.*;
import java.math.*;
public class H1008{
    public static void main(String args[]){
        Scanner cin = new Scanner(System.in);
        BigInteger a;
        int b;
        int T;
        T = cin.nextInt();
        while (T != 0){
            a = BigInteger.valueOf(2);
            b = cin.nextInt();
            System.out.println(a.pow(b));
            T--;
        }
    }
}