class complex {
    constructor(r = 0.0, i = 0.0) {
        this.real = r;
        this.img = i;
    }
}

class complex_number {

    display(r, i) {
        if (r === 0) return '' + i + 'i';
        if (i === 0) return '' + r;
        if (i < 0) return '' + r + i + 'i';
        return '' + r + '+' + i + 'i';
    }

    //Addition of Two complex numbers
    complex_add(first, second) {
        var real = first.real + second.real;
        var img = first.img + second.img;
        return this.display(real, img);
    }

    //Subtraction of Two complex numbers
    complex_sub(first, second) {
        var real = first.real - second.real;
        var img = first.img - second.img;
        return this.display(real, img);
    }

    //Multiplication of Two complex numbers
    complex_mul(first, second) {
        var real = first.real * second.real - first.img * second.img;
        var img = first.real * second.img + first.img * second.real;
        return this.display(real, img);
    }

    //Division of Two complex numbers
    complex_div(first, second) {
        var real = (first.real * second.real + first.img * second.img) / (second.real * second.real + second.img * second.img);
        var img = (first.img * second.real - first.real * second.img) / (second.real * second.real + second.img * second.img);
        return this.display(real, img);
    }

}

let a = new complex(0, 2);
let b = new complex(3, -4);

let complex_no = new complex_number();
console.log(complex_no.complex_add(a, b));
console.log(complex_no.complex_sub(a, b));
console.log(complex_no.complex_mul(a, b));
console.log(complex_no.complex_div(a, b));