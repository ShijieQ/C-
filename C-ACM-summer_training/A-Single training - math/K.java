import java.util.*;
import java.math.*;
public class K{
    public static void main(String args[]){
        Scanner cin = new Scanner(System.in);
        BigInteger a, b, d;
		BigInteger c = BigInteger.valueOf(0);
        int T, i;
        T = cin.nextInt();
        for(i = 1; i <= T; i++){
            int k = 0;
            a = cin.nextBigInteger();
            b = cin.nextBigInteger();
            a = a.abs();
			b = b.abs();
			d = a.remainder(b);
			if(d.compareTo(c) == 0)
                k = 1;
            System.out.printf("Case %d: ", i);
            if(k == 1)
                System.out.println("divisible");
            else
                System.out.println("not divisible");
        }
    }
}