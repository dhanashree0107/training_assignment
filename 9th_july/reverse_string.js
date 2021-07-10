function reverse_string(str) {
    //return str.split('').reverse().join('');
    //return [...str].reverse().join('');

    if (!str || str.length < 2 || typeof str !== 'string') {
        return "string is not valid";
    }
    let rev_arr = [];
    const length = str.length - 1;

    for (let i = length; i >= 0; i--) {
        rev_arr.push(str[i]);
    }

    return rev_arr.join('');
}

console.log(reverse_string("Hello World"));