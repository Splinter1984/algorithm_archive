--[[John has invited some friends. His list is:
s = "Fred:Corwill;Wilfred:Corwill;Barney:Tornbull;Betty:Tornbull;Bjon:Tornbull;Raphael:Corwill;Alfred:Corwill";
Could you make a program that

makes this string uppercase
gives it sorted in alphabetical order by last name.
When the last names are the same, sort them by first name. Last name and first name of a guest come in the result between parentheses separated by a comma.
So the result of function meeting(s) will be:

"(CORWILL, ALFRED)(CORWILL, FRED)(CORWILL, RAPHAEL)(CORWILL, WILFRED)(TORNBULL, BARNEY)(TORNBULL, BETTY)(TORNBULL, BJON)"
It can happen that in two distinct families with the same family name two people have the same first name too.]]--


#!/usr/bin/lua
local solution = {}

--- split function
-- @return table fill with data from splited string
function split(str, div)
        result = {}
        for sub in (str..div):gmatch("(.-)"..div) do
                table.insert(result, sub)
        end
        return result
end

--- meeting function
-- makes input string uppercase
-- sort by last name
-- @return string result join last/first names
function solution.meeting(s)
        local data = {}
        for _, val in pairs(split(s, ";")) do
                local person = split(val, ":")
                local per_dat = {}
                per_dat.first_name = person[1]:upper()
                per_dat.last_name = person[2]:upper()
                table.insert(data, per_dat)
        end
        table.sort(data, function(a, b)
                if (a.last_name == b.last_name) then
                        return a.first_name < b.first_name
                end
                return a.last_name < b.last_name
                end)
        local result = ""
        for _, val in pairs(data) do
                result = result.."("..val.last_name..", "..val.first_name..")"
        end
        return result
end
  
return solution
