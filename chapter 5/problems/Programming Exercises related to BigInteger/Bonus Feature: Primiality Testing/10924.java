import java.util.Scanner;
import java.math.BigInteger;
public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
	    while(sc.hasNext()){
	        String s = sc.next();
	        BigInteger sum  = BigInteger.ZERO;
	        for(int i = 0; i < s.length(); i++){
	           
	            if( Character.isUpperCase( s.charAt(i) ) ){
	                int x = (int)(s.charAt(i) - 'A') + 27;
	                BigInteger added = BigInteger.valueOf(x);
	                sum = sum.add(added);
	            }else{
	                int x = (int)(s.charAt(i) - 'a') + 1;
	                BigInteger added = BigInteger.valueOf(x);
	                sum = sum.add(added);
	            }
	        }
	        if(sum.isProbablePrime(10) || sum.compareTo(BigInteger.valueOf(1)) == 0){
	            System.out.println("It is a prime word.");
	        }else {
	            System.out.println("It is not a prime word.");
	        }
	    }
	
	}
}

