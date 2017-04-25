
import java.math.BigInteger;
import java.util.*;

public class Main{

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in=new Scanner(System.in);
		int t, tt = 1;
		t = in.nextInt();
		while(t > 0){
			BigInteger a,b, c, d;
			a = in.nextBigInteger();
			c = a.abs();
			b = in.nextBigInteger();
			d = b.abs();
			if(c.mod(d) == BigInteger.ZERO) System.out.println("Case " + tt + ": divisible");
			else System.out.println("Case " + tt + ": not divisible");
			t --;
			tt ++;
		}

	}

}
