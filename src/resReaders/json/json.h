#ifndef JSON_READER
#define JSON_READER

// i'd like this to be more of a c thing tbh so time to see how 
// c headers work
typedef enum status{
    OK,
    ERROR,
} status; 

// likely could be moved to a include for everything
status OpenFile();
status CloseFile();

#endif
