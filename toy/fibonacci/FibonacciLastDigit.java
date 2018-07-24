import java.util.*;

class FibonacciLastDigit
{
    static long fibonacci(int n, long n_1, long n_2)
    { 
      if (n == 0) return n_1;
      if (n == 1) return n_2;
      return fibonacci(n-1, n_2, Math.addExact(n_1, n_2));
    }
    
    static long fibonacciLastDigit(int n, long n_1, long n_2)
    { 
      if (n == 0) return n_1;
      if (n == 1) return n_2;
      return fibonacciLastDigit(n-1, n_2 % 10, (n_1 + n_2) % 10); // Math.addExact requires Java 8!
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
			System.exit(1);
		}
		catch (ArithmeticException e) {
			System.out.println ("The number n is too large");
		}
		
		try {
			System.out.println ("The last digit of nth fibonacci number is " + fibonacciLastDigit(n, 0, 1));
		}
		catch (StackOverflowError e) {
			System.out.println ("Too large a number to compute last digit tail recursively - Java has no optimization for tail calls.");
		}
		
    }
}
