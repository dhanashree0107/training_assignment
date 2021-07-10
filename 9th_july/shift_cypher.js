function encrpt(str, key) {
    if (key < 0) {
        return encrpt(str, key + 26);
    }

    var encrpt_msg = "";
    for (var i = 0; i < str.length; i++) {

        var ch = str[i];

        if (ch.match(/[a-z]/i)) {
            var code = str.charCodeAt(i);

            if (code >= 65 && code <= 90) {
                ch = String.fromCharCode(((code - 65 + key) % 26) + 65);
            } else if (code >= 97 && code <= 122) {
                ch = String.fromCharCode(((code - 97 + key) % 26) + 97);
            }
        }
        encrpt_msg += ch;
    }
    return encrpt_msg;
}

function decrypt(str, key) {
    if (key < 0) {
        return decrypt(str, key + 26);
    }

    var decrypt_msg = "";
    for (var i = 0; i < str.length; i++) {

        var ch = str[i];

        if (ch.match(/[a-z]/i)) {
            var code = str.charCodeAt(i);

            if (code >= 65 && code <= 90) {
                ch = String.fromCharCode(((code - 65 - key) % 26) + 65);
            } else if (code >= 97 && code <= 122) {
                ch = String.fromCharCode(((code - 97 - key) % 26) + 97);
            }
        }
        decrypt_msg += ch;
    }
    return decrypt_msg;
}


console.log("Encrypted message : " + encrpt("HELLO", 4));
console.log("Decrypted message : " + decrypt("LIPPS", 4));