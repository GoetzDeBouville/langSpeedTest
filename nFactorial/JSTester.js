const { performance } = require('perf_hooks');

function arrayBuild(num) {
    const arr = [];
    for (let i = 0; i < num; i++) {
        arr.push(Math.floor(Math.random() * 1000));
    }
    return arr;
}

function rearangeArr(array, start) {
    for (let i = start; i < array.length; i++) {
        [array[start], array[i]] = [array[i], array[start]];
        rearangeArr([...array], start + 1);
        [array[i], array[start]] = [array[start], array[i]];
    }
}

const array = arrayBuild(11);
const t0 = performance.now();
rearangeArr(array, 0);
const t1 = performance.now();

console.log(`${((t1 - t0) / 1000).toFixed(5)} sec`);
