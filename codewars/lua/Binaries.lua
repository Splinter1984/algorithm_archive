--[[At last concatenate all the results got for the digits of n.
An example
So we code 0 as 10, 1 as 11, 2 as 0110, 3 as 0111 ... etc...
With the given process, the initial string "10111213" becomes: "11101111110110110111" resulting of concatenation of 11 10 11 11 11 0110 11 0111.
Task:
Given strng a string of digits representing a decimal number the function code(strng) should return the coding of strng as explained above.
Given a string strng resulting from the previous coding, decode it to get the corresponding decimal string.]]--

local solution = {}

--- convert number into bin
-- @return bin number as string
function toBin(number)
        local bin = {}

        if number == 0 then
                return '0'
        elseif number == 1 then
                return '1'
        end
        while number ~= 0 do
                bin[#bin+1]=number%2
                number=math.floor(number/2)
        end
        return table.concat(bin):reverse()
end

--- code string with numbers
--  @return coded string
function solution.code(str)
        local result = {}
        for i=1, #str do
                local num = tonumber(str:sub(i, i))
                local bits = math.ceil(math.log(num+1)/math.log(2))
                local num_code = ""
                for j=1, bits-1 do
                        num_code=num_code..'0'
                end
                num_code=num_code..'1'..toBin(num)
                result[i] = num_code
        end
        return table.concat(result)
end

--- decode string with bin nubmers
--  @return decoded string
function solution.decode(str)
        local result = {}
        local block = ""
        local i = 1
        while i < #str do
                local num = str:sub(i, i)
                block=block..num
                if tonumber(num) == 1 then
                        local bits = #block-1
                        i=i+1
                        local number = tonumber(str:sub(i, i+bits), 2)
                        result[#result+1] = number
                        print(block..' '..str:sub(i, i+bits)..": "..tostring(number))
                        i=i+bits+1
                        block=""
                else
                        i=i+1
                end
        end
        return table.concat(result)
end

return solution
