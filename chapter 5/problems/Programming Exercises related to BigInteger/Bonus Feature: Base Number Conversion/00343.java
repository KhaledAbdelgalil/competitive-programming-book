import java.util.Scanner;
import java.math.BigInteger;
public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
	    while(sc.hasNext()){
	        boolean found = false;
	        String A = sc.next();
	        String B = sc.next();
	        BigInteger biga, bigb;
	        for(int i = 2; i <= 36; i++){
	             try {
                      biga = new BigInteger(A, i);
                     } catch (Exception e) {
                     continue;
                    }
	            for(int j = 2; j <= 36; j++){
	               try {
                     bigb = new BigInteger(B, j);
                    } catch (Exception e) {
                     continue;
                    }
	                if(biga.compareTo(bigb) == 0){
	                    found = true;
	                    System.out.println(A + " (base " + i + ") = " + B + " (base " + j + ")");
	                    break;
	                }
	            }
	            if(found)break;
	        }
	       
         if(found == false)
    	       System.out.println(A + " is not equal to " + B + " in any base 2..36");
	    }
	
	}
}

