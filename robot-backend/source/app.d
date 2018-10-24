import vibe.vibe;

extern (C++) void interopTest();

void main() {
	interopTest();

	listenHTTP(":8080", &handleRequest);
	runApplication();
}

void handleRequest(HTTPServerRequest req, HTTPServerResponse res) {
	if (req.path == "/")
		res.writeBody("Hello, World!");
}
