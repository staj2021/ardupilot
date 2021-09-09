var canvas2 = document.getElementById("canvas2");

var context = canvas2.getContext("2d");
/*context.fillStyle="red";
context.fillRect(10,10,100,100);*/

var /*canvas3 = context.createRadialGradient(10,10,3,50,50,70);*/
canvas3 = context.createLinearGradient(10,11,100,0);
canvas3.addColorStop(0,"orange");
canvas3.addColorStop(1,"yellow");

context.shadowBlur=10;
context.shadowColor="black";

context.fillStyle=canvas3;
context.fillRect=(0,0,150,150);


var canvas4 = document.getElementById("canvas4");
var context = canvas4.getContext("2d");

context.beginPath();
context.arc(100,100,20,0,2*Math.PI);
context.stroke();
/* daire çizdirmek için kullanılır*/




