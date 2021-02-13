import java.util.Scanner;
import java.math.BigInteger;
public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
	    for(int i = 0; i < t; i++){
		    BigInteger A = sc.nextBigInteger();
		    BigInteger B = sc.nextBigInteger();
		    A = A.subtract(B);
		   System.out.println(A);
		}
	}
}

