import java.util.Scanner;
import java.math.BigInteger;
public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for(int i = 0; i < t; i++){
	       BigInteger p = sc.nextBigInteger();
	       String temp = sc.next();
	       BigInteger q = sc.nextBigInteger();
	       BigInteger gcd_pq = p.gcd(q);
	       System.out.println(p.divide(gcd_pq) + " / " + q.divide(gcd_pq) );
		} 
	
	}
}

