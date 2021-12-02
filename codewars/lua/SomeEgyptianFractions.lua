--[[ Given a rational number n

n >= 0, with denominator strictly positive

as a string (example: "2/3" in Ruby, Python, Clojure, JS, CS, Go)
or as two strings (example: "2" "3" in Haskell, Java, CSharp, C++, Swift, Dart)
or as a rational or decimal number (example: 3/4, 0.67 in R)
or two integers (Fortran)
decompose this number as a sum of rationals with numerators equal to one and without repetitions 
(2/3 = 1/2 + 1/6 is correct but not 2/3 = 1/3 + 1/3, 1/3 is repeated).

The algorithm must be "greedy", so at each stage the new rational obtained in the decomposition must 
have a denominator as small as possible. In this manner the sum of a few fractions in the decomposition 
gives a rather good approximation of the rational to decompose.

2/3 = 1/3 + 1/3 doesn't fit because of the repetition but also because the first 1/3 has a denominator 
bigger than the one in 1/2 in the decomposition 2/3 = 1/2 + 1/6.]]--

local solution = {}

function division(lv, rv)
        if (lv/rv)%1 == 0 then
                return tostring(math.ceil(lv/rv))
        else
                return tostring(lv)..'/'..tostring(rv)
        end
end

function solution.decompose(nr, dr)
        local result = {}
        if nr == 0 or dr == 0 or nr == nil or dr == nil then
                return ""
        end
        while nr ~= 0 and dr ~= 0 do
                if nr >= dr then
                        local val = math.floor(nr/dr)
                        nr = nr-val*dr
                        table.insert(result, tostring(val))
                else
                        local tmp
                        if dr%nr == 0 then tmp = math.ceil(dr/nr)
                        else tmp = math.floor(dr/nr) + 1 end
                        table.insert(result, division(1, tmp))
                        nr = nr*tmp-dr
                        dr = dr*tmp
                end
        end
        return table.concat(result, ", ")
end
return solution
