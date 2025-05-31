class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        stack=[]
        for char in s:
            if stack and stack[-1][1]==char:
                count,c=stack.pop()
                count+=1
                if count==k:
                    continue
                else:
                    stack.append((count,char))
            else:
                stack.append((1,char))
        return "".join(count*char for count,char in stack)

        