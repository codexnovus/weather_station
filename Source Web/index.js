const express = require ('express'),
      app     = express(),
      server  = require ('http').createServer(app);

app.use("/", express.static(__dirname+"/data/http"));


server.listen(8086, () => {
    console.log('Weather Station simulator listening on port 8086');
})