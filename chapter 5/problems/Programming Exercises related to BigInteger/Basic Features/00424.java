import java.util.Scanner;
import java.math.BigInteger;
public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		BigInteger sum = BigInteger.ZERO;
		BigInteger N;
		while(true){
		    N = sc.nextBigInteger();
		    sum = sum.add(N);
		    if(N.compareTo(BigInteger.ZERO) == 0)break;
		   
		}
		System.out.println(sum);
	}
}

