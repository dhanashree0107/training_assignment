var API_KEY = "AIzaSyC2zQ1sU2eoX-Ih87DnsHxnygV3xUx6Llc";

/*
fetch('https://www.googleapis.com/youtube/v3/', {
    method: 'GET',
    part: 'snippet',
    maxResults: 10,
    key: API_KEY
}).then(res => res.json()).then(data => console.log(data)).catch(error => console.log(error))
*/




function search() {
    const serach_text = document.getElementById("textbox").value;
    console.log(serach_text);
    const base_url = `https://www.googleapis.com/youtube/v3/search?part=snippet&maxResults=10&q=${serach_text}&key=${API_KEY}`;
    var detail = '';

    fetch(base_url).then(response => response.json()).then(data => {
        console.log(data);
        //  document.querySelector(".video").src = `${data.items[1].snippet.thumbnails.medium.url}`;

        video_render(data);
    }).catch(console.error());



}

function video_render(data) {
    var detail = '';
    data.items.forEach(item => {
        detail += `
     <div class="row" style={width:100%}>
    <iframe src = "https://www.youtube.com/embed/${item.id.videoId}"></iframe>
    <div>
    <h3>${item.snippet.title}</h3>
    </div>
    </div>
 

    `;
        console.log(detail);

    });
    document.getElementById('card').innerHTML = detail;






}

var details = [
    { "title": "html", "views": 255, "channel_Name": "coder", "description": "weerthjghj dftyj" },
    { "title": "html", "views": 255, "channel_Name": "coder", "description": "weerthjghj dftyj" },
    { "title": "html", "views": 255, "channel_Name": "coder", "description": "weerthjghj dftyj" }
];

// document.getElementById('demo').innerHTML = "Hello world";

/*
console.log(details);

document.getElementById("card") = details.map(user => {
    `<div>
            <h3>Title</h3>
            <h6>${user.views}</h6>
            <h5>${user.channel_Name}</h5>
            <h5>${user.description}</h5>
        </div>`
}).join('')



/*
document.querySelector('card').innerHTML = details.map(user => {
    `<div>
        <h3>Title</h3>
        <h6>${user.views}</h6>
        <h5>${user.channel_Name}</h5>
        <h5>${user.description}</h5>
    </div>`
}).join('')
*/