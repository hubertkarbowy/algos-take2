#!/usr/bin/env ruby

def fibonacci (n, n_1=0, n_2=1)
    if n==0 then n_1
    elsif n==1 then n_2
    else fibonacci(n-1, n_2, n_1+n_2); end
end

printf "Enter a non-negative number: "
n = gets.to_i 
puts "fib(#{n}) = #{fibonacci(n, 0, 1)}"
