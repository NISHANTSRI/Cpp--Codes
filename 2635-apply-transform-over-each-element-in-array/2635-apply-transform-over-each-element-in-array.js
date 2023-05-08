/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    retArr = arr;
    for(var i=0;i<arr.length;i++){
        var num = retArr[i];
        num = fn(num,i);
        retArr[i] = num;
    }
    
    return retArr;
};