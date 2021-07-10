function grains(n) {
    let squares = n * n;
    console.log(squares);
    var sum;
    var sum2 = 0;
    for (let number = 0; number < squares; number++) {
        sum = Math.pow(2, number);
        sum2 += sum;
        console.log("square of " + number + ": " + sum2);
    }
    console.log(sum2);
}

var n = 8;
console.log(grains(n));