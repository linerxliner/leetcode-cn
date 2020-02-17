class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        local_min_product = nums[0]
        local_max_product = nums[0]
        global_max_product = local_max_product
        
        for n in nums[1:]:
            n_min_product = n * local_min_product
            n_max_product = n * local_max_product
            local_min_product = min(n, min(n_min_product, n_max_product))
            local_max_product = max(n, max(n_min_product, n_max_product))
            global_max_product = max(global_max_product, local_max_product)
        
        return global_max_product
