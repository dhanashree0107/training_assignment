function palindrome(str) {
    var flag = 0;
    var length = str.length;
    for (var i = 0, j = length - 1; i < length, j >= 0; i++, j--) {
        if (i < j || i != j) { //i<j - condition for odd string , i!=j - condition for even string
            if (str[i] == str[j])
                flag = 1;
            else return 0;
        }
    }
    if (flag == 1)
        return 1;
    else return 0;

}

var str = "malayalama";
if (palindrome(str)) {
    console.log("palindrome");
} else {
    console.log("not a palindrome");
}