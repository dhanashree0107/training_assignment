function occ_of_digit(number, digit) {
    var occ = 0,
        rem;
    while (number) {
        rem = number % 10;
        if (rem == digit)
            occ++;
        number = parseInt(number / 10);
    }
    console.log("occ of " + digit + " in the number: " + occ);
}

function occurrence(number) {
    for (var i = 0; i <= 9; i++) {
        occ_of_digit(number, i);
    }
}

occurrence(123456784534);