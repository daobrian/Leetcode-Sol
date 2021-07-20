# Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 
def generateParenthesis(n):
    res = []
    maxLen = 2*n
    def backtrack(currStr, numOpen, numClose):
        # base case: when current str reaches maxLen, append to res
        if len(currStr) == maxLen:
            res.append(currStr)
            return

        # Can only add a closing brace when the current str has more open braces than closing braces
        if numClose < numOpen:
            backtrack(currStr + ')', numOpen, numClose + 1)
        
        # As long as the current str has less than n opening braces, then adding an extra opening brace is always possible
        if numOpen < n:
            backtrack(currStr + '(', numOpen + 1, numClose)

    backtrack("", 0, 0)
    return res

print(generateParenthesis(3))