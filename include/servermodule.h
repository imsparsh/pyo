#ifndef Py_SERVERMODULE_H
#define Py_SERVERMODULE_H
#ifdef __cplusplus
extern "C" {
#endif

#include "portaudio.h"
#include "portmidi.h"
#include "sndfile.h"    

typedef struct {
    PyObject_HEAD
    PyObject *streams;
    PaStream *stream;
    PmStream *in;
    PmEvent midibuf[1];
    float samplingRate;
    int nchnls;
    int bufferSize;
    int duplex;
    int withPortMidi;
    int server_started;
    int stream_count;
    int record;
    float *input_buffer;
    SNDFILE *recfile;
    SF_INFO recinfo;
} Server;

PyObject * PyServer_get_server();
extern PyObject * Server_removeStream(Server *self, int sid);
extern float * Server_getInputBuffer(Server *self);    
extern PmEvent * Server_getMidiEventBuffer(Server *self);    
extern PyTypeObject ServerType;    
    

#ifdef __cplusplus
}
#endif

#endif /* !defined(Py_SERVERMODULE_H) */

