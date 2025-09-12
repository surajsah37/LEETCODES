/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    let result = []; // step 1
    for (let i = 0; i < arr.length; i++) { // step 2
        result.push(fn(arr[i], i)); // step 3 & 4
    }
    return result; // step 5
};