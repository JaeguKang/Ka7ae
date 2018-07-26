const http = require("http");

const server = http.createServer((req, res) => {

	res.statusCode = 200;
	res.setHeader("Content-Type", "text/plain");
	res.end("I'm Kang JG \n");

});

server.listen(8080, "222.105.177.200", () => {
	console.log("server is running...")
})


//node httpsrv.js <<cmd창에서 경로에 맞게 들어가 실행