import java.math.*;
import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		BigInteger ans[] = new BigInteger[200+2];
		ans[1] = new BigInteger("2");
		for(int i = 2; i <= 200; i++) {
			Integer aa = i;
			ans[i] = new BigInteger(aa.toString());
		}
		for(int i = 2; i <= 200; i++) {
			ans[i] = ans[i].multiply(ans[i-1]);
		}
		int q;
		boolean flag = true;
		while(cin.hasNextInt()) {
			q = cin.nextInt();
			if(q == -1) {
				break;
			}
			else {
				System.out.println("N=" + q + ":\n" + ans[q - 1]);
			}
		}
	}

}
