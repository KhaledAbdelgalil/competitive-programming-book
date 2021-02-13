import java.util.Scanner;
import java.math.BigInteger;
public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int caseno = 1;
		while(true){
		    int N = sc.nextInt(), F = sc.nextInt();
		    if(N == 0 && F == 0)break;
		    BigInteger sum = BigInteger.ZERO;
		    for(int i = 0; i < N; i++){
		        BigInteger v = sc.nextBigInteger();
		        sum = sum.add(v);
		    }
		    System.out.println("Bill #" + (caseno++) + " costs " + sum + ": each friend should pay " 
		    + sum.divide(BigInteger.valueOf(F)));
		    System.out.println();
		}
	}
}

