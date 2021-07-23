var API_KEY = "AIzaSyC2zQ1sU2eoX-Ih87DnsHxnygV3xUx6Llc";


function search() {
    const serach_text = document.getElementById("textbox").value;
    console.log(serach_text);
    const base_url = `https://www.googleapis.com/youtube/v3/search?part=snippet&maxResults=10&q=${serach_text}&key=${API_KEY}`;
    var detail = '';

    fetch(base_url).then(response => response.json()).then(data => {
        // console.log(data);
        //  document.querySelector(".video").src = `${data.items[1].snippet.thumbnails.medium.url}`;

        video_render(data);
    }).catch(console.error());



}

function video_render(data) {
    var detail = '';
    data.items.forEach(item => {
        detail += `
     <div id="row2">
    <iframe src = "https://www.youtube.com/embed/${item.id.videoId}"></iframe>
    <div id="details">
    ${item.snippet.title}<br>
    ${item.snippet.channelTitle}<br>
    <p style="font-size:10ox">${item.snippet.description}</p>
    </div>
    </div>
 

    `;
        // console.log(detail);

    });
    document.getElementById('card').innerHTML = detail;

}