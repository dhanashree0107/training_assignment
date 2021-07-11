function evalPostFix(exp) {
    // create an empty stack
    var stack = [];

    // traverse the given expression
    for (var i = 0; i < exp.length; i++) {
        var no = exp[i];
        if (no.match(/[0-9]/i)) { // if the current character is an operand, push it into the stack
            stack.push(no - '0');
        } else { // if the current character is an operator
            var x = stack[stack.length - 1];
            stack.pop(); // remove the top two elements from the stack

            var y = stack[stack.length - 1];
            stack.pop();

            // evaluate the expression x op y, and push the
            // result back to the stack
            if (no == '+') {
                stack.push(y + x);
            } else if (no == '-') {
                stack.push(y - x);
            } else if (no == '*') {
                stack.push(y * x);
            } else if (no == '/') {
                stack.push(y / x);
            }
        }

    }

    // At this point, the stack is left with only one element, i.e.,
    // expression result
    return stack[stack.length - 1];
}

console.log(evalPostFix('53+62/*35*+')); //ans = 39