class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        ans=0
        min_diff=float('inf')
        for i in range(len(nums)-2):
            j=i+1
            k=len(nums)-1
            while j<k :
                sum=nums[i]+nums[j]+nums[k]
                curr_diff=abs(target-sum)
                if min_diff>curr_diff:
                    min_diff=curr_diff
                    ans=sum
                if sum > target:
                    k-=1
                elif sum<target:
                    j+=1
                else:
                    return sum
                
        return ans