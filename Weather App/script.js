var d = new Date();

function images(data, todaysDate) {
    var image;
    if (data.list[todaysDate].weather[0].main == "Clouds") {
        image = "images/cloudy.png";
    } else if (data.list[todaysDate].weather[0].main == "Rain" && data.list[todaysDate].weather[0].description == "light rain") {
        image = "images/rain_light.png";
    } else if (data.list[todaysDate].weather[0].main == "Extreme") {
        image = "images/sunny.png";
    } else if (data.list[todaysDate].weather[0].main == "Snow") {
        image = "";
    } else if (data.list[todaysDate].weather[0].main == "Clear") {
        image = "images/clear_sky.png";
    }
    return image;
}

function Headers(data) {
    var temperature = parseInt(data.list[0].main.temp - 273.15);
    var image = images(data, 0);
    document.getElementById('logo').src = image;
    document.getElementById('temp').innerHTML = temperature + `<sup>0</sup>C|<sup>0</sup>F`;
    document.getElementById('other').innerHTML = `<li>${data.list[0].weather[0].description}</li><li>Humidity: ${data.list[0].main.humidity}%</li><li>Wind Speed: ${data.list[0].wind.speed}m/s</li>`;
    document.getElementById('city').innerHTML = data.city.name + `<br>${d.toDateString()}<br>${data.list[0].weather[0].description}`;
}



function todaysReportByTimeSlots(data) {
    date = d.toISOString().substring(0, 10);
    var combinedDate = '';
    for (var todaysDate = 0; todaysDate < 8; todaysDate++) {
        apiDate = (data.list[todaysDate].dt_txt).substring(0, 10);
        apiTime = (data.list[todaysDate].dt_txt).substring(11, 16);
        temperature = parseInt(data.list[todaysDate].main.temp - 273.15);
        var image = images(data, todaysDate);
        combinedDate += `<div><p>${apiDate}</p><p>${apiTime}</p><p>${temperature}<sup>0</sup>C</p><img src="${image}"></div>`;



        document.getElementById("todaysReport").innerHTML = `<div style="display:flex;justify-content:space-between">${combinedDate}</div>`;
    }
}


function getweatherbycityname() {
    let citynametofetchdata = document.getElementById("cityname_").value;
    fetch(`http://api.openweathermap.org/data/2.5/forecast?q=${citynametofetchdata}&appid=2005810d196d4812bfb1d5603c372cbc`, {
        method: "GET"
    }).then(function(response) {
        return response.json();
    }).then(function(json) {
        //console.log(json);
        //var date = '';
        /*
        for (var i = 0; i < json.list.length; i++) {
            console.log(json.list[i].dt_txt);
            date += `<p>${json.list[i].dt_txt}</p>`;
            document.getElementById("date").innerHTML = date;
        }
        */

        Headers(json);
        todaysReportByTimeSlots(json);

    });
}