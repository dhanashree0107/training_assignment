const express = require("express");
var math = require('mathjs');
const bodyParser = require("body-parser");
var cors = require('cors')
const { response, request } = require("express");
const application = express()
    //var jsonParser = bodyParser.json()
application.listen(3003, () => console.log('listening at 3003'));
application.use(express.static("./"));
//application.use(bodyParser.urlencoded({ extended: false }));
var http = require('http').createServer(application);
application.use(
    express.urlencoded({
        extended: true
    })
)

application.use(cors())

application.use(express.json())

function complex_num_add(addCN1, addCN2) {
    var ans = math.add(addCN1, addCN2);
    if (ans.im === '0') return '' + ans.re;
    if (ans.re === 0) return '' + ans.im + 'i';
    if (ans.im < 0) return '' + ans.re + ans.im + 'i';
    return '' + ans.re + '+' + ans.im + 'i';
}

function complex_num_sub(subCN1, subCN2) {
    var ans = math.subtract(subCN1, subCN2);
    if (ans.im === '0') return '' + ans.re;
    if (ans.re === 0) return '' + ans.im + 'i';
    if (ans.im < 0) return '' + ans.re + ans.im + 'i';
    return '' + ans.re + '+' + ans.im + 'i';
}

function complex_num_multiply(mulCN1, mulCN2) {
    var ans = math.multiply(mulCN1, mulCN2);
    if (ans.im === '0') return '' + ans.re;
    if (ans.re === 0) return '' + ans.im + 'i';
    if (ans.im < 0) return '' + ans.re + ans.im + 'i';
    return '' + ans.re + '+' + ans.im + 'i';
}


function complex_num_divide(divCN1, divCN2) {
    var ans = math.divide(divCN1, divCN2);
    if (ans.im === '0') return '' + ans.re;
    if (ans.re === 0) return '' + ans.im + 'i';
    if (ans.im < 0) return '' + ans.re + ans.im + 'i';
    return '' + ans.re + '+' + ans.im + 'i';
}

application.post("/add", (request, response, next) => {

    console.log("I got request of addition");
    console.log(request.body);
    const addfunc1 = math.complex(request.body.real1, request.body.img1)
    const addfunc2 = math.complex(request.body.real2, request.body.img2)
    var addoutput = complex_num_add(addfunc1, addfunc2);
    response.send({ addoutput });
});

application.post("/sub", (request, response, next) => {

    console.log("I got request of sutraction");
    console.log(request.body);
    const CN1 = math.complex(request.body.real1, request.body.img1)
    const CN2 = math.complex(request.body.real2, request.body.img2)
    var suboutput = complex_num_sub(CN1, CN2);
    response.send({ suboutput });
});

application.post("/mul", (request, response, next) => {

    console.log("I got request of multiplication");
    console.log(request.body);
    const CN1 = math.complex(request.body.real1, request.body.img1)
    const CN2 = math.complex(request.body.real2, request.body.img2)
    var muloutput = complex_num_multiply(CN1, CN2);
    response.send({ muloutput });
});

application.post("/div", (request, response, next) => {

    console.log("I got request of division");
    console.log(request.body);
    const CN1 = math.complex(request.body.real1, request.body.img1)
    const CN2 = math.complex(request.body.real2, request.body.img2)
    var divoutput = complex_num_divide(CN1, CN2);
    response.send({ divoutput });
});