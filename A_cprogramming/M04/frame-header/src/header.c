#include "header.h"
#include <stdio.h>
#define BITMASK_ACK (0x40)
#define SYNCCHECK (0x2a)
#define TYPETESTER (0x2959C8F00)
#define ADDRESSTESTER (0xFF)


/*
 * You are required to implement the parser functions below.
 *
 * int validateHeader(uint32_t header); function validates the header. A header is valid if all the conditions below evaluate true.
 *  - SYNC field is equal to 0x2a
 *  - if ACK bit is set V bit is also
 *  - if ACK bit is reset TYPE is non-zero.
 *  - SOURCE ADDRESS and DESTINATION ADDRESS are non-zero and different than each other.
 *
 *  If the header is valid, the function returns 1 otherwise it returns 0.
 *
 * int getFrameId(uint32_t header); function returns FRAME ID field if the header is valid, possibly checked using validateHeader function above.
 *  - If the header is not valid, it returns -1.
 *  - Otherwise, it returns non-negative integer corresponding to FRAME ID field.
 *
 * int getFrameType(uint32_t header); function returns TYPE field if the header is valid, possibly checked using validateHeader function above, and ACK bit is reset.
 *  - If the header is not valid, it returns -1.
 *  - If ACK bit is set, it returns 0.
 *  - Otherwise, it returns non-negative integer corresponding to TYPE field.
 *
 * int getSourceAddress(uint32_t header); function returns SOURCE ADDRESS field if the header is valid, possibly checked using validateHeader function above.
 *  - If the header is not valid, it returns -1.
 *  - Otherwise, it returns non-negative integer corresponding to SOURCE ADDRESS field.
 */



int validateHeader(uint32_t header)
{    
int Syncchecker = 63; //00111111
Syncchecker = Syncchecker & header; 
    if(Syncchecker == 42)
    {
        if(header & (1 << 6))
        {
            if(!(header & (1 << 7)))
            {   
                return 0; 
            }
        }
        else
        {
            for(int i=8; i<=10; i++)
            {
                if(header & (1 << i))
                {
                break;
                }
                else
                {
                    if(i == 10)
                    {
                        return 0;
                    }
                    else
                    {
                    }
                }
            }
        }
    }
    else
    {
        return 0;
    }
    if ((header & (ADDRESSTESTER << 16 )) != ((header >> 8) & (ADDRESSTESTER << 16)))
    {
        if ((header & (ADDRESSTESTER << 16)) == 0)
        {
            return 0;
        }
        if (((header >> 8) & (ADDRESSTESTER << 16)) == 0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }

}

int getFrameId(uint32_t header)
{
    int Frameretriever = 31;  //00011111
    int valid = validateHeader(header);
    if (valid == 1)
    { 
    Frameretriever = header & (Frameretriever << 11);
    Frameretriever = Frameretriever >> 11;
    return Frameretriever;
    }
    else
    {
    return -1;
    }
}

int getFrameType(uint32_t header)
{
    int ACKchecker = 1;
    int Typeretriever = 7;  //00000111
    int valid = validateHeader(header);
    if (valid == 1)
    { 
        if (header & (ACKchecker << 6))
        {
            return 0;
        }
        else
        {
            Typeretriever = header & (Typeretriever << 8);
            Typeretriever = Typeretriever >> 8;
        }
    }
    else
    {
        return -1;
    }
    return Typeretriever;   
}

int getSourceAddress(uint32_t header)
{
    int valid = validateHeader(header);
    int SAretriever = 255;
    if (valid == 1)
    { 
    SAretriever = header & (SAretriever << 16);
    SAretriever = SAretriever >> 16;
    return SAretriever;
    }
    else
    {
        return -1;
    }
}

uint32_t createAckHeader(int destAddress, int sourceAddress, uint8_t frameId, char valid)
{
    uint32_t Ackheader = 0;
    Ackheader = Ackheader | (destAddress << 24);
    Ackheader = Ackheader | (sourceAddress << 16);
    Ackheader = Ackheader | (frameId << 11);
    Ackheader = Ackheader | SYNCCHECK;
    if(valid == 0)
    {
        Ackheader = Ackheader | (1 << 6);
    }
    else
    {
        Ackheader = Ackheader | (1 << 7);
        Ackheader = Ackheader | (1 << 6);
    }
    return Ackheader;
}

uint32_t createHeader(int destAddress, int sourceAddress, uint8_t frameId, uint8_t type)
{    
    uint32_t Ackheader0 = 0;
    Ackheader0 = Ackheader0 | (destAddress << 24);
    Ackheader0 = Ackheader0 | (sourceAddress << 16);
    Ackheader0 = Ackheader0 | (frameId << 11);
    Ackheader0 = Ackheader0 | (type << 8);
    Ackheader0 = Ackheader0 | SYNCCHECK;
    return Ackheader0;
}
