--[[
Build Tower
Build Tower by the following given argument:
number of floors (integer and always greater than 0).

Tower block is represented as *]]--

#!/usr/bin/lua
function towerBuilder(nFloors)
  local floor = "*"
  if nFloors < 2 then 
    return {floor} 
  end
  
  local result = {}
  local space_num = nFloors - 1
  for i=1, nFloors do
    result[i] = string.rep(" ", space_num)..floor..string.rep(" ", space_num)
    floor=floor..string.rep("*", 2)
    space_num=space_num - 1
  end
  
  return result
end
