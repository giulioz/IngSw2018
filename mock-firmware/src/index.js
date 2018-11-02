import express from "express";

const app = express();
app.get("*", (req, res) => {
  res.send("test");
});

app.listen(8080, "0.0.0.0", () => console.log("Up and running..."));
