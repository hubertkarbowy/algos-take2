import java.util.*;

class Fibonacci
{
    static long fibonacci(int n, long n_1, long n_2)
    { 
      if (n == 0) return n_1;
      if (n == 1) return n_2;
      return fibonacci(n-1, n_2, n_1 + n_2);
    }
     
    public static void main (String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        int n=0;
        System.out.print ("Enter a non-negative number: ");
        try {
			n = sc.nextInt();
			System.out.println("fib(" + n +") = " + fibonacci(n,0,1) );
		}
		catch (InputMismatchException e) {
			System.out.println ("Incorrect number.");
		}
    }
}
