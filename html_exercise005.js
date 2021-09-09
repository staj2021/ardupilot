//alert("take the place!");

// js exercise..


function clickFunction1(){
    alert("Welcome the Hell!");
}

function clickFunction2(){
    // change the parag1 text
    document.getElementById("parag1").innerHTML = "Don't escape coward!";
    //innerHTML = "Don't escape!";
}

function clickFunction3(){
    document.getElementById("parag1").innerHTML = "Well, come and join!";
}

function clickFunction4(){
    document.getElementById("parag1").innerHTML = "Pick a Hero!";
}

function clickFunction5(){
    document.getElementById("parag1").innerHTML = "See in there!";
}

var numberData = 0;
var nameData = "Star";
var counter = 0;
function clickFunction6(){
    var changeVar = document.getElementById("input1").value;
    document.getElementById("parag2").innerHTML = numberData;
    document.getElementById("parag3").innerHTML = changeVar + "  " + "4";

}
function clickFunction7(){
    funCeption();
    funCeption2();
}
function funCeption(){
    var changeVar = document.getElementById("input2").value;
    document.getElementById("parag4").innerHTML = changeVar;
    document.getElementById("parag4").style.color = "orange";
}

var num1 = 0;
function funCeption2(){
    if (num1 == 0){
        
    }
    else if(num1 == 1){

    }
    else{
        alert("awda");
    }
}