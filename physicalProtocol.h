#ifndef PHYSICALPROTOCOL_H
#define PHYSICALPROTOCOL_H

#include "dataProtocol.h"

struct PHYSICAL_OPTIONS
{
    int OPTION_NO_ALARMS;
    int OPTION_FER;
    int OPTION_FER_HEAD;
    int OPTION_FER_DATA;
};

struct PHYSICAL_OPTIONS CREATE_PHYSICAL_OPTIONS();

void PHYSICAL_PROTOCOL_OPTIONS(struct PHYSICAL_OPTIONS cmd_options);

void OPTIONS_GENERATE_FER(struct linkLayer *link);

typedef enum
{
    START,
    FLAG_RCV,
    A_RCV,
    C_RCV,
    BCC_OK,
    STOP
} commandState;

typedef enum
{
    WI_START,
    WI_FLAG_RCV,
    WI_A_RCV,
    WI_REJ_RCV,
    WI_RR_RCV,
    WI_BCC_REJ_OK,
    WI_BCC_RR_OK,
    WI_STOP_REJ,
    WI_STOP_RR
} writeInformationState;

typedef enum
{
    RI_START,
    RI_FLAG_RCV,
    RI_A_RCV,
    RI_INF,
    RI_DISC,
    RI_UA,
    RI_BCC_DISC_OK,
    RI_BCC_UA_OK,
    RI_INFORMATION_READ,
    RI_INFORMATION_STOP,
    RI_READ_STOP,
    RI_READ_STOP_UA,
    RI_RESET
} readInformationState;

void atende();

void writeLinkResponse(struct linkLayer *link);

int writeLinkCommand(struct linkLayer *link, u_int8_t A, u_int8_t C);

int writeLinkInformation(struct linkLayer *link, u_int8_t A);

int readLinkCommand(struct linkLayer *link, u_int8_t A, u_int8_t C);

int readLinkInformation(struct linkLayer *link, u_int8_t *buffer, u_int8_t A, int *Nr);

int commandStateMachine(commandState state, u_int8_t A, u_int8_t C, u_int8_t byte);

int writeInformationStateMachine(writeInformationState state, u_int8_t A, u_int8_t byte, int *Nr);

int readInformationStateMachine(readInformationState state, u_int8_t A, u_int8_t byte, int *Nr);
#endif
