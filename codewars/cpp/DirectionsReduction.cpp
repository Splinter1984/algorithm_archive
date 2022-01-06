/*
Once upon a time, on a way through the old wild mountainous west,…
… a man was given directions to go from one point to another. 
The directions were "NORTH", "SOUTH", "WEST", "EAST". Clearly "NORTH" and "SOUTH" are opposite, "WEST" and "EAST" too.

Going to one direction and coming back the opposite direction right away is a needless effort. 
Since this is the wild west, with dreadfull weather and not much water, it's important to save yourself some energy, otherwise you might die of thirst!
How I crossed a mountainous desert the smart way.
The directions given to the man are, for example, the following (depending on the language):
["NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST"].
or
{ "NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST" };
or
[North, South, South, East, West, North, West]

You can immediatly see that going "NORTH" and immediately "SOUTH" is not reasonable, better stay to the same place! 
So the task is to give to the man a simplified version of the plan. A better plan in this case is simply:
["WEST"]
or
{ "WEST" }
or
[West]

Other examples:
In ["NORTH", "SOUTH", "EAST", "WEST"], the direction "NORTH" + "SOUTH" is going north and coming back right away.
The path becomes ["EAST", "WEST"], now "EAST" and "WEST" annihilate each other, therefore, the final result is [] (nil in Clojure).
In ["NORTH", "EAST", "WEST", "SOUTH", "WEST", "WEST"], "NORTH" and "SOUTH" are not directly opposite but they become directly 
opposite after the reduction of "EAST" and "WEST" so the whole path is reducible to ["WEST", "WEST"].
Task
Write a function dirReduc which will take an array of strings and returns an array of strings with the needless directions removed (W<->E or S<->N side by side).

    The Haskell version takes a list of directions with data Direction = North | East | West | South.
    The Clojure version returns nil when the path is reduced to nothing.
    The Rust version takes a slice of enum Direction {North, East, West, South}.

*/

#include <vector>
#include <string>
#include <tuple>
#include <map>

typedef std::pair<int, int> Pos;

class DirReduction
{
public:
    static std::vector<std::string> dirReduc(const std::vector<std::string> &arr)
    {
      if (arr.empty())
        return arr;
      std::vector<std::string> res = arr;
      std::map<std::string, Pos> coords
      {
        { "NORTH", {  0,  1 } },
        { "SOUTH", {  0, -1 } },
        { "WEST" , { -1,  0 } },
        { "EAST" , {  1,  0 } }
      };

      for (unsigned int i = 1; i < res.size(); ++i)
      {
        std::string pos1 = res.at(i-1), pos2 = res.at(i);
        bool north_south = coords[pos1].first == coords[pos2].first
          && coords[pos1].second != coords[pos2].second;
        bool west_east = coords[pos1].second == coords[pos2].second
          && coords[pos1].first != coords[pos2].first;
        bool is_opposite = north_south || west_east;

        if (is_opposite)
        {
          res.erase(res.begin() + (i - 1), res.begin() + (i + 1));
          i = 0;
        }
      }

      return res;
    }
};
