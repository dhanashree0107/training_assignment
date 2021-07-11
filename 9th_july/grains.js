function grains(n) {
    let squares = n * n;
    console.log(squares);
    var sum;
    var sum2 = BigInt(0);
    for (let number = 0; number < squares; number++) {
        sum = BigInt(Math.pow(2, number));
        sum2 += sum;
        console.log("No of grains till square no. " + (number + 1) + ": " + sum2);
    }
    console.log("No of grains in " + squares + " squares : " + sum2);
}

var n = 8;
console.log(grains(n));