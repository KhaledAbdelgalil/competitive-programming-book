import java.util.Scanner;
import java.math.BigInteger;
public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
		    int n = sc.nextInt();
		    BigInteger A = sc.nextBigInteger();
		    BigInteger sum = BigInteger.ZERO;
		    for(int i = 1; i <= n; i++){
		        sum = sum.add(BigInteger.valueOf(i).multiply(A.pow(i)));
		    }
            System.out.println(sum);
		}
	
	}
}

