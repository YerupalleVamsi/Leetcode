class Solution:
    def maximumValueSum(self, nums: List[int], k: int, edges: List[List[int]]) -> int:
        deltas = []
        base_sum = sum(nums)
        
        for num in nums:
            flipped = num ^ k
            deltas.append(flipped - num)

        gain_nodes = [d for d in deltas if d > 0]
        total_gain = sum(d for d in deltas if d > 0)
 
        if len(gain_nodes) % 2 == 0:
            return base_sum + total_gain
        else:
            min_abs_loss = min(abs(d) for d in deltas)
            return base_sum + total_gain - min_abs_loss
