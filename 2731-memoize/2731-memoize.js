/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    const cache = new Map();
    let callCount = 0;

    const mem = function(...args) {
        const key = JSON.stringify(args);
        if(!cache.has(key)){
            callCount++;
            cache.set(key, fn(...args));
        }    
        return cache.get(key);

    }

    mem.getCallCount = function (){
        return callCount;
    }
    return mem
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */