/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    var num = init;
    const n = init;
    const increment = (init) => {
        return ++num;
    }
    
    const decrement = (init) => {
        return --num;
    }
    
    const reset = ()=> {
        num = n;
        return n;
    }
    
    return {increment : increment , decrement : decrement , reset : reset};
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */