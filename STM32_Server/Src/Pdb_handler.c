#include "Pdb_handler.h"
#include "udp_client.h"
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>

#define NUM_Flotes 12
#define NUM_SOCKET 4
#define BUFFER_SIZE (NUM_Flotes * sizeof(float))


int PDB_Data(int UDP_client_fd)
{
  
  while (1)
  {
    uint8_t buffer[BUFFER_SIZE];
    float values[NUM_Flotes]; 
    
    nRet = recvfrom(UDP_client_fd, buffer, BUFFER_SIZE, 0,NULL, NULL);
    if (nRet == 0)
    {
      printf("Connection closed by client\n");
      return -1;
    }
    memcpy(values, buffer, BUFFER_SIZE);

    const char *labels[NUM_Flotes] = {

        "PDB-1 Temp", "PDB-2 Temp", "PDB-1 Current", "PDB-2 Current",
        "Thermistor 1", "Thermistor 2", "Thermistor 3", "Thermistor 4",
        "PDB-1 Out", "PDB-2 Out", "PDB-1 Fault", "PDB-2 Fault"};
    printf("\nReceived float values:\n");

    for (int i = 0; i < NUM_Flotes; i++)
    {
      printf("%s: %.2f\n", labels[i], values[i]);
    }
  }
  return UDP_client_fd;
}