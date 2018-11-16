#include "UDP/ServerUDP.hpp"

//CAPIRE COSA VIENE RICEVUTO
//CREARE IL MESSAGGIO DI RISPOSTA PER ESITO POSITIVO


ServerUDP::ServerUDP(const char *address)
{

    mg_mgr_init(&mgr, this);
    this->nc = mg_bind(&mgr, address, wrapperHandler);
}

static void wrapperHandler(struct mg_connection *nc, int ev, void *p)
{
    ServerUDP *_this = static_cast<ServerUDP *>(nc->mgr->user_data);
    _this->handler(nc, ev, p);
}

void ServerUDP::start()
{
    for (;;)
    {
        mg_mgr_poll(&mgr, 1000);
    }
}

ServerUDP::~ServerUDP() { mg_mgr_free(&mgr); }

void ServerUDP::handler(struct mg_connection *c, int ev, void *p)
{
    struct mbuf *io = &c->recv_mbuf;
    if (ev == MG_EV_RECV)
    {
        if (nc->recv_mbuf == DOGE_SEARCH)
        {
            mg_send(c, DOGE_ANNOUNCE + IPaddress, msglen);
        }
        mbuf_remove(io, io->len); //Pulisce il buffer
    }
}