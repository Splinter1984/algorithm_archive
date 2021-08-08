#Your function takes two arguments:
#current father's age (years)
#current age of his son (years)
#Сalculate how many years ago the father was twice as old as his son (or in how many years he will be twice as old).

#!/bin/sh

dad_years_old=$1
son_years_old=$2

#implement me
total=$((dad_years_old-2*son_years_old))
echo "${total#-}"

exit
