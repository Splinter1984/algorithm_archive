--[[
In this Kata, you will be given two numbers, a and b, and your task is to determine if the first number a is divisible by all the prime factors of the second number b. 
For example: solve(15,12) = False because 15 is not divisible by all the prime factors of 12 (which include2).
See test cases for more examples.
Good luck!
]]--

simplediv = {}

function simplediv.solve(a, b)
        local simple = 2
        if a % simple ~= b % simple then return false end
        while b > 1 do
                while b % simple == 0 do
                        if a % simple ~= 0 then return false end
                        b = math.ceil(b/simple)
                end
                simple = simple + 1
        end
        return true
end

return simplediv
