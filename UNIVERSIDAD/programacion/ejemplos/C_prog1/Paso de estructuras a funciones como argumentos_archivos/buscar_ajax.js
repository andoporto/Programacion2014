function buscar(){
	var ajax = false
	if (window.XMLHttpRequest) {// Si es Mozilla, Safari etc
		ajax = new XMLHttpRequest()
	} else if (window.ActiveXObject){ // pero si es IE
		try {
			ajax = new ActiveXObject("Msxml2.XMLHTTP")
		} 
		catch (e){ // en caso que sea una versión antigua
			try{
				ajax = new ActiveXObject("Microsoft.XMLHTTP")
			}
			catch (e){}
		}
	} else
		return false
	ajax.onreadystatechange=function(){ // función de respuesta
		if(ajax.readyState==1){
				c("<img src='images/loading1.gif'> Buscando <b>" + document.getElementById('q').value + "</b>...");
			}
		if(ajax.readyState==4){
				c(ajax.responseText);
			}
	}
	ajax.open('GET', "buscar_php.php?palabra=" + document.getElementById('q').value + "&tipo=" + document.getElementById('tipobusqueda').innerHTML, true) // asignamos los métodos open y send
	ajax.send(null)
}

function abrir(url){
	var ajax = false
	if (window.XMLHttpRequest) {// Si es Mozilla, Safari etc
		ajax = new XMLHttpRequest()
	} else if (window.ActiveXObject){ // pero si es IE
		try {
			ajax = new ActiveXObject("Msxml2.XMLHTTP")
		} 
		catch (e){ // en caso que sea una versión antigua
			try{
				ajax = new ActiveXObject("Microsoft.XMLHTTP")
			}
			catch (e){}
		}
	} else
		return false
	ajax.onreadystatechange=function(){ // función de respuesta
		c("<img src='images/loading3.gif'><br>");
		if(ajax.readyState==4){
				c(ajax.responseText);
			}
	}
	ajax.open('GET', "buscar_php.php?add=" + document.getElementById('q').value, true) // asignamos los métodos open y send
	ajax.send(null)
	location.href = url;
	}

function c(t){
		document.getElementById('busqueda').innerHTML=t;
	}
