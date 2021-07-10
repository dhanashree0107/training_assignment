const fs = require('fs')

fs.readFile("word.txt", (err, data) => {
    if (err) throw err;
    var new_data = data.toString();
    console.log(new_data);
    let word = "first";
    let a = new_data.split(" ");
    let count = 0;
    for (let i = 0; i < a.length; i++) {
        if (word === (a[i])) {
            console.log(word);
            count++;
        }

    }
    console.log("Count of word " + word + ": " + count);
})