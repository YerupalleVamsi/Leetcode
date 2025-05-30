class Solution:
    def removeDuplicates(self, s: str) -> str:
        stack=[]
        for w in s:
            if stack and stack[-1]==w:
                stack.pop()
            else:
                stack.append(w)
        return "".join(stack)


        