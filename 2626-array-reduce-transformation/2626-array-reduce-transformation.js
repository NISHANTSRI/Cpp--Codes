/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    if(nums.length == 0) return init;
    var prev = init;
    var val;
    for(var i=0;i<nums.length;i++){
        val = fn(prev,nums[i]);
        prev = val;
    }
    
    return val;
};