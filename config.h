#ifndef __CONFIG_H__
#define __CONFIG_H__

struct config {
  char *fileName;
  int noffsets;
  unsigned long *offsets;
  char *chars;
  int slotSize;
  unsigned long base;
};

typedef struct config *config_t;

config_t readConfig(const char *cf);
void freeConfig(config_t conf);

int checkConfig(config_t conf);





#endif // __CONFIG_H__