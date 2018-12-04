# WatchDoge
# Documento di Progettazione

## Introduzione (Samuele)

...

### Scopo del Documento (Samuele)

...

### Struttura del Documento (Samuele)

...

## Glossario (Tutti)

## Struttura del Sistema (Giulio)

Il sistema sarà composto da due elementi:

- Il device del Doge
- L'applicazione Android

Le due parti comunicheranno tra loro seguendo un modello **client-server**, dove il device fungerà da server e l'applicazione da client. Il protocollo scelto per la comunicazione sarà quello di rete, dal momento che il device sarà dotato di scheda di rete Wi-Fi.

In particolare:

- Il device sarà continuamente in ascolto sulla porta 8001 in UDP per permettere il **Discovery**;
- Il device fornirà una API di tipo **REST** in HTTP sulla porta 8000, per fornire i dati relativi alle intrusioni;
- Il device sarà in grado di fornire uno stream video dalla videocamera e notifiche push per le intrusioni via **WebSocket**.

### Device

Il device sarà a tutti gli effetti un tradizionale server con sistema operativo Linux, in particolare con la distribuzione Debian fornita da EV3DEV. Il software che andremo a realizzare per il server sarà una grossa applicazione monolitica scritta in C++.

L'applicazione sarà composta da varie parti (ad oggetti), le quali collaboreranno tra loro usando uno scheduler cooperativo per fornire dei servizi ai client. Usando uno scheduler custom cooperativo saremo in grado di programmare in maniera event-driven e controllare al meglio le (limitate) risorse hardware dell'EV3.

[schema struttura]

Le parti principali che comporranno il backend saranno:

- Un *Web Server* che fornirà delle **REST API** e le connessioni *WebSocket*;
- Un *Server UDP* che fornirà il **Discovery**;
- Un *Engine* di **allarme** che andrà ad usare i sensori per riconoscere le intrusioni e notificare le altre parti di conseguenza;
- Una **Persistenza** utilizzando un DB interno ad oggetti.

### Applicazione Android

L'Applicazione Android sarà un semplice client per i servizi del device, e non necessita di nessuna persistenza. Di conseguenza sarà formata da due parti:

- **Interfaccia utente**, che farà uso dei servizi web del device per mostrare all'utente le intrusioni e il feed video;
- **Servizio Notifiche**, che riceverà eventuali notifiche di intrusioni dal device e le notificherà all'utente.

[schema struttura]

## Modello di Controllo (Samuele)

Modello event-driven broadcast [...]

## Diagramma delle Classi (Dario, Sandro, Giulio)

## Diagramma delle Attività (Scodella)

## Diagramma di Sequenza (Scodella)

## Interfaccia Utente (Dario, Sandro)

- On boarding
- Dashboard
- Live view
- Auto-mode schedule
- Intrusion history
- Settings

## REST API

Di seguito verranno elencati gli endpoint che consentono di interagire con il device, in ascolto sulla porta *HTTP 8000*.
Tutte le richieste vogliono il token di autenticazione come Bearer Token, altrimenti ritornano 403.

### Allarm

#### GET /allarm/state

Ritorna lo stato attuale dell'allarme.

**Response:** JSON
```json
{
  "active": true,
  "auto": false
}
```

#### GET /allarm/program

Ritorna la programmazione impostata dell'allarme.

**Response:** JSON
```json
{
  "mon": [
    {
      "from": { "hour": 0, "minute": 0 },
      "to": { "hour": 0, "minute": 0 }
    }
  ],
  "tue": [
    {
      "from": { "hour": 0, "minute": 0 },
      "to": { "hour": 0, "minute": 0 }
    }
  ],
  "wed": [
    {
      "from": { "hour": 0, "minute": 0 },
      "to": { "hour": 0, "minute": 0 }
    }
  ],
  "thu": [
    {
      "from": { "hour": 0, "minute": 0 },
      "to": { "hour": 0, "minute": 0 }
    }
  ],
  "fri": [
    {
      "from": { "hour": 0, "minute": 0 },
      "to": { "hour": 0, "minute": 0 }
    }
  ],
  "sat": [
    {
      "from": { "hour": 0, "minute": 0 },
      "to": { "hour": 0, "minute": 0 }
    }
  ],
  "sun": [
    {
      "from": { "hour": 0, "minute": 0 },
      "to": { "hour": 0, "minute": 0 }
    }
  ]
}
```

#### POST /allarm/on

Attiva l'allarme (override modalità automatica).

**Body:** nessuno

**Response:** nessuno

#### POST /allarm/off

Disattiva l'allarme (override modalità automatica).

**Body:** nessuno

**Response:** nessuno

#### POST /allarm/auto

Attiva la modalità automatica per l'allarme.

**Body:** nessuno

**Response:** nessuno

#### POST /allarm/program

Imposta la programmazione per la modalità automatica.

**Body:** JSON (vedi sopra)

**Response:** nessuno

### Data

#### GET /intrusions

Ritorna lo storico di tutte le intrusioni. Imposta quelle restitute come lette.

**Response:** JSON
```json
[
  {
    "id": 0,
    "date": 1542913758,
    "notified": false
  }
]
```

#### GET /intrusions/unread

Ritorna le intrusioni non ancora lette. Imposta quelle restitute come lette.

**Response:** JSON (vedi sopra)

#### GET /intrusions/time/:start/:end

Ritorna lo storico delle intrusioni in un certo rango di tempo (specificato come secondi timestamp). Imposta quelle restitute come lette.

**Response:** JSON (vedi sopra)

#### GET /intrusions/:id/shoot

Ritorna la foto relativa ad una certa intrusione.

**Response:** JPEG binary

### Hardware

#### GET /shoot

Ritorna un frame preso dalla videocamera.

**Response:** JPEG binary

#### POST /move/left

Gira il robot a sinistra.

**Body:** nessuno

**Response:** nessuno

#### POST /move/right

Gira il robot a destra.

**Body:** nessuno

**Response:** nessuno

### Authentication

#### POST /pair

Richiede un nuovo token per l'autenticazione.

**Body:** JSON

```json
{
  "clientKey": "ABCD",
  "pairKey": "1234"
}
```

**Response:** stringa JSON in caso positivo, HTTP 403 in caso di codice errato

### Misc

#### GET /info

Ritorna informazioni sul robot.

**Response:** stringa JSON
