const name_DOB = [

    ['dhanashree kere', '1st july 2000'],
    ['priya kere', '25th may 1997'],
    ['sakshi jagtap', '20th march 2002']
];

function list(arr) {
    let single_array = [];
    for (let i = 0; i < arr.length; i++) {
        if (Array.isArray(arr[i])) {
            single_array = single_array.concat(list(arr[i]))
        } else
            single_array.push(arr[i]);
    }
    return single_array;
}

console.log(list(name_DOB));