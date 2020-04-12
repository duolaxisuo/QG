//服务器地址
let serverUrl = 'http://recruit.qgailab.com/'

/*监听该标签的事件*/
document.getElementById('register').addEventListener('click', sentregister);
document.getElementById('Login').addEventListener('click', sentlogin);

function sentregister() {
	/*将数据存储起来 */
	let data = {
		username: document.getElementById('re_username').value,
		password: document.getElementById('re_password').value,
		phone: document.getElementById('re_phone').value,
		email: document.getElementById('re_email').value,
		name: document.getElementById('re_name').value,
	}

	/*建立请求对象*/
	let xhr = new XMLHttpRequest();
	/*用post方法发送数据，中间为地址，是否采取异步*/
	xhr.open("post", serverUrl + "ajax/register", true);
	/*post用法需要设置请求头 */
	xhr.setRequestHeader("Content-type", "application/json");
	/*发送数据,将js对象转化为字符串*/
	xhr.send(JSON.stringify(data));
	/*服务器响应式触发函数,存储函数（或函数名），每当 readyState 属性改变时，就会调用该函数。*/
	xhr.onreadystatechange = function () {
		/*readyState:4 说明请求已完成，且响应就绪 */
		/*status:200  说明'ok' */
		if (xhr.readyState == 4 & xhr.status == 200) {
			/*responseText为后台返回的数据（类型为字符串）,返回的数据需要用JSON.parse方法将其转化成JS对象*/
			let result = JSON.parse(xhr.responseText);
			/*从后台返回的信息 */
			if (result.code === 1) {
				alert(result.message);
			} else {
				alert(result.message);
			}
		}
	}
}

function sentlogin() {
	/*存储数据 */
	let data = {
		username: document.getElementById('re_username').value,
		password: document.getElementById('re_password').value,
	}

	let xhr_login = new XMLHttpRequest();
	xhr_login.open('post', serverUrl + 'ajax/login', true);
	xhr_login.setRequestHeader("content-type", "application/json");
	xhr_login.send(JSON.stringify(data));
	xhr_login.onreadystatechange = function () {
		if (xhr_login.readyState == 4 && xhr_login.status == 200) {
			let result = JSON.parse(xhr_login.responseText);
			if (result.code == 1) {
				alert(result.message);
			} else {
				alert(result.message);
			}
		}
	}
}