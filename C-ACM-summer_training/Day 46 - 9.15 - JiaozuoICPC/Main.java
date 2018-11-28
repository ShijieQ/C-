import java.util.*;
import java.math.*;
public class Main{
    static long MAXN = 100005;
    static long mod = 1000000007;
	
    public long qpow(long n, long k) {
        long ans = 1;
        while(k != 0){
			if(k%2 != 0){
                ans = ans*n%mod;
            }
            n = n*n%mod;
            k >>= 1;
		}
        return ans;
    }

    public long inv(long num) {
        return qpow(num, mod - 2);
    }
    
    public long get(char s[]) {
        long len = s.length;
        long ans = 0;
        for(long i = 0; i < len; i++){
            ans = ans*10 + s[i]-'0';
        }
        return ans;
    }
    
    public boolean Comper(char s[], long num) {
        char[] bit = new char[MAXN];
        long len2 = 0,len1;
        while(num) {
            bit[len2++] = num%10;
            num = num/10;
        }
        bit[len2] = '\0';
    
        len1 = s.length;
        if(len1 > len2)
            return true;
        else if(len1 < len2)
            return false;
        else
        {
            for(long i = 0; i < len1; i++)
            {
                if(s[i] < bit[len1-i-1])
                    return false;
            }
            return true;
        }
    }
    
    public long Mod(char s[], long mod) {
        long len = s.length;
        long ans = 0;
        for(long i = 0; i < len; i++) {
            ans = (ans*10 + s[i]-'0')%mod;
        }
        return ans;
    }
	
	public static void main(String args[]){
       Scanner cin = new Scanner(System.in);
       long T;
       Main k = new Main();
       String arr;
       char[] s = new char[MAXN];
       T = cin.nextInt();
       while (T-- >0){
           arr = cin.nextLine();
           s = arr.toCharArray();
           long a = 2, g;
           long ans = 0;
           if(k.Comper(s, mod-1) == true){
                long tem = k.Mod(s, mod-1);
                a = tem-1+mod-1;
            // cout<<a<<endl;
                ans = k.qpow(2, a);
            }
            else{
                a = k.get(s);
                ans = k.qpow(2, a-1);
            }
        // ans = ans*inv(2)%mod;
        if(ans < 0){
            ans += mod;
        }
        System.out.println(ans);
       }
    }
}