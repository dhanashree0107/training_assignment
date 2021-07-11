function sumofDivisors(num, x) {
    if (x == 1)
        return 1;
    if (num % x == 0)
        return x + sumofDivisors(num, x - 1);
    else
        return sumofDivisors(num, x - 1);
}

function perfect_no(num) {
    console.log("pefect numbers between 1 to " + num)
    for (var i = 2; i <= num; i++) {
        if (sumofDivisors(i, parseInt(i / 2)) == i)
            console.log(i);
    }
}

perfect_no(1000);