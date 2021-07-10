function canQueenAttack(q1r, q1c, q2r, q2c) {
    if (q1r == q2r)
        return true;

    if (q2c == q1c)
        return true;

    if (Math.abs(q1r - q2r) == Math.abs(q1c - q2c))
        return true;

    return false;
}

var queen1_row = 0,
    queen1_col = 2;
var queen2_row = 2,
    queen2_col = 4;


if (canQueenAttack(queen1_row, queen1_col, queen2_row, queen2_col))
    console.log("Can attack");
else
    console.log("Cannot Attack");