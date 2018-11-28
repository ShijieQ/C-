import java.util.*;
import java.math.*;
public class sol{
    public static void main(String args[]){
        Scanner cin = new Scanner(System.in);
        BigInteger a, b, k;
        while (cin.hasNext()){
			k = new BigInteger("0");
            a = cin.nextBigInteger();
            b = cin.nextBigInteger();
		    if(a.compareTo(k) == 0 && b.compareTo(k) == 0)
				break;
            System.out.println(a.add(b)); 
		    /*
            System.out.println(a.subtract(b)); 
			System.out.println(a.multiply(b)); 
			System.out.println(a.divide(b)); 
			System.out.println(a.remainder(b)); 
			if( a.compareTo(b) == 0 ) System.out.println("a == b"); 
			else if( a.compareTo(b) > 0 ) System.out.println("a > b"); 
			else if( a.compareTo(b) < 0 ) System.out.println("a < b"); 
			System.out.println(a.abs()); 
			int exponent=10;
			System.out.println(a.pow(exponent)); 
			System.out.println(a.toString());
			int p=8;
			System.out.println(a.toString(p));
		   */
        }
    }
}