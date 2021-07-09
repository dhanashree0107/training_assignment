let array = [2, 3, 6, 1, 7];
array.sort(function(first, second) {
    return first - second;
});


console.log("Ascending order of numbers: " + array);

array.sort(function(first, second) {
    return second - first;
});

console.log("Descending order of numbers: " + array);

let fruit_array = ["banana", "Apple", "kiwi", "pineapple", "Gauva"];

var sorted = fruit_array.sort();

console.log(sorted);

var sorted = fruit_array.reverse();
console.log(sorted);

console.log("hello");
var array2 = [1, 2, 3, 4];
let accumulator = [1, 8];
console.log(array2.reduce((accumulator, current, index, original) => {
    if (current % 2 == 0) {
        accumulator.push(current);
    }
    return accumulator;
}, []));

console.log("sorting by perticular attribute of object:");
let employees = [
    { name: 'John', salary: 90000, hireDate: "July 1, 2010" },
    { name: 'David', salary: 75000, hireDate: "August 15, 2009" },
    { name: 'Ana', salary: 80000, hireDate: "December 12, 2011" }
];

employees.sort(function(first, second) {
    return first.salary - second.salary;
});


console.log("By salary");
console.table(employees);

employees.sort((first, second) => (first.name > second.name) ? 1 : ((first.name < second.name) ? -1 : 0));
console.log("By name");
console.table(employees);