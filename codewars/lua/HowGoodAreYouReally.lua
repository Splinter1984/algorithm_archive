--[[There was a test in your class and you passed it. Congratulations!
But you're an ambitious person. You want to know if you're better than the average student in your class.

You receive an array with your peers' test scores. Now calculate the average and compare your score!

Return True if you're better, else False!]]--

return {
  better_than_average= function(class_points, your_points)
    local sum = 0
    
    if not next(class_points) then
      return true
    elseif #class_points == 1 then
      return next(class_points) < your_points
    end
    
    for _, val in pairs(class_points) do
      sum = sum + val
    end
    
    return sum / #class_points < your_points
  end
}
