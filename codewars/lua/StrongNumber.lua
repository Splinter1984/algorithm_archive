--[[Strong number is the number that the sum of the factorial of its digits is equal to number itself.

For example: 145, since
1! + 4! + 5! = 1 + 24 + 120 = 145
So, 145 is a Strong number.

Task
Given a number, Find if it is Strong or not.
Input >> Output Examples
strong_num(1) ==> return "STRONG!!!!"
Explanation:
Since , the sum of its digits' factorial of (1) is equal to number itself (1) , Then its a Strong .

strong_num(123) ==> return "Not Strong !!"
Explanation:
Since the sum of its digits' factorial of 1! + 2! + 3! = 9 is not equal to number itself (123) , Then it's Not Strong .]]--


function fact(n)
  if n == 0 then
    return 1
  else
    return n*fact(n-1)
  end
end

return function(n)
  local sum = 0
  if not n then return "Not Strong !!" end
  local number = n
  while number%10 ~= 0 do
    sum=sum+fact(number%10)
    number=math.modf(number/10)
  end
  return n == sum and "STRONG!!!!" or "Not Strong !!"
end
