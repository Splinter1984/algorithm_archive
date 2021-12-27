--[[
You will have a list of rationals in the form
lst = [ [numer_1, denom_1] , ... , [numer_n, denom_n] ]
or
lst = [ (numer_1, denom_1) , ... , (numer_n, denom_n) ]
where all numbers are positive integers. You have to produce their sum N / D in an irreducible form: this means that N and D have only 1 as a common divisor.
]]--

local solution = {}

function gcd04(a, b)
        if (a == b) then return a end
        if (a > b) then
                local tmp = a        
                a = b
                b = tmp
        end

        return gcd04(a, b - a)       
end

function solution.sumFracts(lst)
        local num, dem = 0, 0
        if next(lst) == nil then return {0, 1} end
        for key, val in pairs(lst) do
                if num ~= 0 and dem ~= 0 then
                        local coef1, coef2, gen_dem = val[2], dem, dem*val[2]
                        if val[2] % dem == 0 then
                                coef1, coef2, gen_dem = val[2]/dem, 1, val[2]
                        elseif dem % val[2] == 0 then
                                coef1, coef2, gen_dem = 1, dem/val[2], dem
                        end
                        num = num*coef1 + val[1]*coef2
                        dem = gen_dem
                else
                        num = val[1]
                        dem = val[2]
                end
        end
        local gcd = gcd04(num, dem)
        return {math.ceil(num/gcd), math.ceil(dem/gcd)}
end

return solution
