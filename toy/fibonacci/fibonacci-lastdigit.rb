#!/usr/bin/env ruby

def fibonacci (n, n_1=0, n_2=1)
    begin
       if n==0 then n_1
       elsif n==1 then n_2
       else fibonacci(n-1, n_2, n_1+n_2); end
    rescue SystemStackError => e
       puts "fib(#{n}) is too large to compute"
    end
end

def fibonacci_lastdigit (n, n_1=0, n_2=1)
    begin
       if n==0 then n_1
       elsif n==1 then n_2
       else fibonacci_lastdigit(n-1, n_2 % 10, (n_1+n_2) % 10); end
    rescue SystemStackError => e
       puts "last digit of fib(#{n}) is too large to compute recursively because Ruby doesn't support tail recursion"
    end

end

def fibonacci_loop (n, only_last_digit=false) # this will support even huge numbers
    if (n==0) then return 0
    elsif (n==1) then return 1
    end
    n_2 = 0
    n_1 = 1
    result = 0
    for i in 2..n do
        result = only_last_digit==true ? (n_2 + n_1) % 10 : n_2 + n_1
        n_2 = n_1
        n_1 = result
    end
    result
end

printf "Enter a non-negative number: "
n = gets.to_i 
puts "fib(#{n}) = #{fibonacci(n, 0, 1)} (recursive-optimized) / #{fibonacci_loop(n)} (loop)"
puts "last digit of fib(#{n}) = #{fibonacci_loop(n, true)}"
