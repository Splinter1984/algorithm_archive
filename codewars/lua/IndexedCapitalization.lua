--[[
Given a string and an array of integers representing indices, capitalize all letters at the given indices.
For example:

capitalize("abcdef",[1,2,5]) = "aBCdeF"
capitalize("abcdef",[1,2,5,100]) = "aBCdeF". There is no index 100.
The input will be a lowercase string with no spaces and an array of digits.

Good luck!
]]--

#!/usr/bin/lua
indexcap = {}
function indexcap.capitalize(s,arr) 
  local result = ""
  local lv_it = 1
  for _, val in pairs(arr) do
    result=result..s:sub(lv_it, val)..string.upper(s:sub(val+1, val+1))
    lv_it = val+2
  end
  result=result..s:sub(lv_it, #s)
  return result
end 
return indexcap
