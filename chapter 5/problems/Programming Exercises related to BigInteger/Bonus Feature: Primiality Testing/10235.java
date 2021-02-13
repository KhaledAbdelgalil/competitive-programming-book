import java.util.Scanner;
import java.math.BigInteger;
public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
	    while(sc.hasNext()){
	       int N = sc.nextInt();
	       BigInteger BN = BigInteger.valueOf(N);
	       String R = new StringBuffer(BN.toString()).reverse().toString();
	       int RN = Integer.parseInt(R);
	       BigInteger RBN = BigInteger.valueOf(RN);
	       if(RN != N && BN.isProbablePrime(10) && RBN.isProbablePrime(10))
	            System.out.println(N + " is emirp.");
	       else if(BN.isProbablePrime(10))
	             System.out.println(N + " is prime.");
	       else System.out.println(N + " is not prime.");
	    }
	
	}
}

