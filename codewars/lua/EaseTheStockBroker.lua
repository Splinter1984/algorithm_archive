--[[
Clients place orders to a stockbroker as strings. The order can be simple or multiple or empty.
Type of a simple order: Quote/white-space/Quantity/white-space/Price/white-space/Status
where Quote is formed of non-whitespace character, Quantity is an int, Price a double (with mandatory decimal point "." ), 
Status is represented by the letter B (buy) or the letter S (sell).
Example:
"GOOG 300 542.0 B"
A multiple order is the concatenation of simple orders with a comma between each.
Example:
"ZNGA 1300 2.66 B, CLH15.NYM 50 56.32 B, OWW 1000 11.623 B, OGG 20 580.1 B"
or
"ZNGA 1300 2.66 B,CLH15.NYM 50 56.32 B,OWW 1000 11.623 B,OGG 20 580.1 B"
To ease the stockbroker your task is to produce a string of type
"Buy: b Sell: s" where b and s are 'double' formatted with no decimal, b representing the total price of bought stocks and s the total price of sold stocks.
Example:
"Buy: 294990 Sell: 0"
Unfortunately sometimes clients make mistakes. When you find mistakes in orders, you must pinpoint these badly formed orders and produce a string of type:
"Buy: b Sell: s; Badly formed nb: badly-formed 1st simple order ;badly-formed nth simple order ;"
where nb is the number of badly formed simple orders, b representing the total price of bought stocks with correct simple order and s the total price of sold stocks with correct simple order.
Examples:
"Buy: 263 Sell: 11802; Badly formed 2: CLH16.NYM 50 56 S ;OWW 1000 11 S ;"
"Buy: 100 Sell: 56041; Badly formed 1: ZNGA 1300 2.66 ;"
Notes:
If the order is empty, Buy is 0 and Sell is 0 hence the return is: "Buy: 0 Sell: 0".
Due to Codewars whitespace differences will not always show up in test results.
With Golang (and maybe others) you can use a format with "%.0f" for "Buy" and "Sell".]]--

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

--- count operations BUY & SELL in specific format
-- @return string with bad and completed count results
function solution.balanceStatement(lst)
        local result = ""
        local bad_format = {}
        local buy, sell = 0, 0
        for _, order in pairs(split(lst, ", ")) do
                if order ~= "" then
                        local block = split(order, " ")
                        local bad = false
                        if block[2]:find('.', 1, true) then
                                bad = true
                        elseif not block[3]:find('.', 1, true) then
                                bad = true
                        elseif block[4] ~= "B" and block[4] ~= "S" then
                                bad = true
                        end
                        if not bad then
                                local count = tonumber(block[2])*tonumber(block[3])
                                if block[4] == "B" then
                                        buy=buy+count
                                else
                                        sell=sell+count
                                end
                        else
                                bad_format[#bad_format+1]=order
                        end
                end
        end
        local str_buy = tostring(string.format("%.f", buy))
        local str_sell = tostring(string.format("%.f", sell))

        result = "Buy: "..str_buy.." Sell: "..str_sell
        if #bad_format > 0 then
                result=result.."; Badly formed "..tostring(#bad_format)..": "..table.concat(bad_format, " ;").." ;"
        end

        return result
end
  
return solution
