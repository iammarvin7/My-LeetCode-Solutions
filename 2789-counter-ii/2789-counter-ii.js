/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    current = init;
    var increment = function(){
        return current +=1;
    }
    var decrement = function(){
        return current-=1;
    }
    var reset = function(){
        current = init;
        return init;
    }

    return {increment, decrement, reset}
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */