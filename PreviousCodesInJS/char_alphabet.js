function char_alphabet(ch) {
    if (ch.match(/[a-z]/) || ch.match(/[A-Z]/)) {
        return ch + " is an alphabet";
    }
    return ch + " is not an alphabet"
}

console.log(char_alphabet("N"));
console.log(char_alphabet("A"));
console.log(char_alphabet("q"));
console.log(char_alphabet("_"));