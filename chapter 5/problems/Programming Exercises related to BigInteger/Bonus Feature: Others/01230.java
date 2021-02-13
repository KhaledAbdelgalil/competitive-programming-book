import java.util.Scanner;
import java.math.BigInteger;
public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for(int i = 0; i < t; i++){
	       BigInteger x = sc.nextBigInteger();
	       BigInteger y = sc.nextBigInteger();
	       BigInteger n = sc.nextBigInteger();
	       System.out.println( x.modPow(y,n) );
		} 
	    sc.nextInt();
	}
}

