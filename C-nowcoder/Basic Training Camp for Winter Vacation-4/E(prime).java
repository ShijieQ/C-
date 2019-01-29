import java.util.*;
import java.math.*;
public class Main{
    static long phi(long n){
        long ans = n,temp = n;  
        for(int i = 2;i*i <= temp;i++){     
            if(temp % i == 0){  
                ans-=ans/i;  
                while(temp%i== 0) temp/=i;  
            }  
        }  
        if(temp > 1) ans -= ans/temp;  
        return ans;
    }  
    
    static long mod_pow(long x,long n,long mod){     
        long ans = 1;  
        while(n != 0){  
            if(n % 2 == 1) 
                ans = ans*x%mod;  
            x = x*x%mod;  
            n/=2;  
        }  
        return ans;  
    } 
    public static void main(String args[]){
        Scanner cin = new Scanner(System.in);
        BigInteger a, b;
		BigInteger c = BigInteger.valueOf(1);
        long phic = phi(1000000007);
        a = cin.nextBigInteger();
        b = cin.nextBigInteger();
        // a = a.add(c).divide(BigInteger.valueOf(2));
        // b = b.add(c).divide(BigInteger.valueOf(2));
        // long ans1;
        // if(b.compareTo(BigInteger.valueOf(phic)) == -1){
        //     ans1 = mod_pow(2, b.longValue(), 1000000007);
        // }
        // else {
        //     ans1 = mod_pow(2, b.remainder(BigInteger.valueOf(1000000007)).longValue() + phic, 1000000007);
        // }
        long ans2;
        if(a.compareTo(BigInteger.valueOf(phic)) == -1){
            ans2 = mod_pow(2, a.longValue(), 1000000007);
        }
        else {
            ans2 = mod_pow(2, a.remainder(BigInteger.valueOf(1000000007)).longValue() + phic, 1000000007);
        }
        // long ans = (ans1%1000000007*ans2%1000000007)%1000000007;
        System.out.println(ans2);
    }
}