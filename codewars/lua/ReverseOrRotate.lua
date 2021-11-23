--[[The input is a string str of digits. Cut the string into chunks (a chunk here is a substring of the initial string)
of size sz (ignore the last chunk if its size is less than sz).
If a chunk represents an integer such as the sum of the cubes of its digits is divisible by 2, reverse that chunk; otherwise 
rotate it to the left by one position. Put together these modified chunks and return the result as a string.
If
sz is <= 0 or if str is empty return ""
sz is greater (>) than the length of str it is impossible to take a chunk of size sz hence return "".]]--

local solution = {}

function solution.revRot(s, sz)
  local result = ""
  if sz <= 0 or #s <= 0 or sz > #s then
    return result
  end
  
  local rv=1 lv=sz
  for i=1, math.floor(#s/sz) do
    local tmp = 0
    local substr = s:sub(rv, lv)
    
    for j=1, #substr do
      local num = tonumber(substr:sub(j, j))
      tmp = tmp + num*num*num
    end
    
    if tmp % 2 ~= 0 then
      result = result .. substr:sub(2, sz) .. substr:sub(1, 1)
    else
      result = result .. string.reverse(substr)
    end
    
    rv = rv + sz
    lv = lv + sz
  end
  
  return result
end
  
return solution
