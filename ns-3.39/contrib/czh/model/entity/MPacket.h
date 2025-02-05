#ifndef _MPACKET_H
#define _MPACKET_H
#include "BloomFilter.h"
#include "../tools/GLOBAL.h"
#include "MNode.h"
#include "Session.h"
#include "Topolopy.h"

namespace ns3
{
class Session;

class MPacket
{
  public:
    BloomFilter bfs[3];
    std::set<PairII> erroredge;
    MPacket(Session* session);
    void generateLabelFattree(Session* session);
    void generateLabelLeafspine();
    void init(Session* session);
    bool doForward(int nodeId, int interfaceId, Topolopy* topology, Session* session);
};
} // namespace ns3
#endif