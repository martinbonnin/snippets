console.log ("file is included");

toto = function toto()
{
    xhr = new XMLHttpRequest();
    console.log("xhr created " + xhr);
    xhr.open("GET", "http://test/channellist.xml", false);
    xhr.send();
    console.log("response" + xhr.responseXML);
}
