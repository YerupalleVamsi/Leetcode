class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        res=[-1]*len(nums1)
        stack=[]
        map=defaultdict(int)
        for i in range(len(nums2)):
            while stack and stack[-1]<nums2[i]:
                map[stack.pop()]=nums2[i]
                
            stack.append(nums2[i])
        for i in range(len(nums1)):
            if nums1[i] in map:
                res[i]=map[nums1[i]]
        return res

            


        