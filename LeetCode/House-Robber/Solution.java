    }
    if(memo[i]>=0){
        return memo[i];
    }
    int res= Math.max(rob(nums, i - 2) + nums[i], rob(nums, i - 1));
    memo[i]=res;
    return res;
};
}