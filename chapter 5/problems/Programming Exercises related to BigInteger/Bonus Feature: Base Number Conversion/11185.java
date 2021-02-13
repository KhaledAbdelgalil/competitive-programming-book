import java.util.Scanner;
import java.math.BigInteger;
public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
	    while(true){
	        int d = sc.nextInt();
	        if(d < 0)break;
	        BigInteger ans = BigInteger.valueOf(d);
	        System.out.println(ans.toString(3));
	    }
	
	}
}

