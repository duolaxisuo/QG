/***************登录和注册的切换**************************/
function reverse() {
	var obj = document.getElementById('dl');
	obj.style.transform = "rotateY(90deg)";
	var anotherobj = document.getElementById('zc');
	anotherobj.style.transform = "rotateY(0deg)";
}

function back() {
	var obj = document.getElementById('dl');
	obj.style.transform = "rotateY(0deg)";
	var anotherobj = document.getElementById('zc');
	anotherobj.style.transform = "rotateY(90deg)";
}
/******************登录***********************************/
var a = 0,
	b = 0;

function checkUsername1(temp1) {
	var reg = /^[\w\u3E00-\u9FA5]{8,16}$/;
	var obj = document.getElementById('001');
	if (reg.test(temp1.value)) {
		obj.style.display = "inline-block";
	} else {
		obj.style.display = "none";
	}
}

function checkPassword1(temp2) {
	var reg = /^\w{8,16}$/;
	var obj = document.getElementById('002');
	if (reg.test(temp2.value)) {
		obj.style.display = "inline-block";
	} else {
		obj.style.display = "none";
	}
}
/*********************注册*********************************/
var c = 0,
	d = 0,
	e = 0,
	f = 0;
g = 0;

function checkUsername(temp1) {
	var reg = /^[\w\u3E00-\u9FA5]{8,16}$/; /*文字、字母、数字、下划线*/
	var obj = document.getElementById('01');
	if (reg.test(temp1.value)) {
		obj.style.display = "inline-block";
		c = 1;
	} else {
		obj.style.display = "none";
	}
}

function checkPassword(temp2) {
	var reg = /^\w{8,16}$/;
	var obj = document.getElementById('02');
	if (reg.test(temp2.value)) {
		obj.style.display = "inline-block";
		d = 1;
	} else {
		obj.style.display = "none";
	}
}

function checknumber(temp3) {
	var reg = /^[1][3,4,5,7,8][0-9]{9}$/; /*正常手机号码*/
	var numbers = temp3.value;
	var obj = document.getElementById('03');
	if (reg.test(numbers)) {
		obj.style.display = "inline-block";
		e = 1;
	} else {
		obj.style.display = "none";
	}
}

function checkEmail(temp4) {
	var reg = /[\w!#$%&'*+/=?^_`{|}~-]+(?:\.[\w!#$%&'*+/=?^_`{|}~-]+)*@(?:[\w](?:[\w-]*[\w])?\.)+[\w](?:[\w-]*[\w])?/;
	var obj = document.getElementById('04');
	if (reg.test(temp4.value)) {
		obj.style.display = "inline-block";
		f = 1;
	} else {
		obj.style.display = "none";
	}
}

function checkName(temp5) {
	var reg = /^[\w\u3E00-\u9FA5]{2,16}$/; /*文字、字母、数字、下划线*/
	var obj = document.getElementById('05');
	if (reg.test(temp5.value)) {
		obj.style.display = "inline-block";
		g = 1;
	} else {
		obj.style.display = "none";
	}
}
/************************************************/
function register_check() {
	if (c == 0) {
		alert("请输入8~16位的合法ID");
		return false;
	}
	if (d == 0) {
		alert("密码内容应为字母、数字、下划线");
		return false;
	}
	if (e == 0) {
		alert("手机号码错误");
		return false;
	}
	if (f == 0) {
		alert("邮箱格式错误");
		return false
	}
	if (g == 0) {
		alert("名字格式错误");
		return false
	}
	return true;
}