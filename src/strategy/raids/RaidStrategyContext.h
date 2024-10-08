#ifndef _PLAYERBOT_RAIDSTRATEGYCONTEXT_H_
#define _PLAYERBOT_RAIDSTRATEGYCONTEXT_H_

#include "RaidUlduarStrategy.h"
#include "Strategy.h"
#include "RaidBwlStrategy.h"
#include "RaidNaxxStrategy.h"
#include "RaidMcStrategy.h"
#include "RaidAq20Strategy.h"

class RaidStrategyContext : public NamedObjectContext<Strategy>
{
public:
    RaidStrategyContext() : NamedObjectContext<Strategy>(false, true)
    {
        // TODO should we give these prefixes (eg: "naxx" -> "raid naxx")? because if we don't it's going to end up
        // very crowded (with possible conflicts) once we have strats for all raids and some dungeons
        // (mc already very similiar to nc)
        creators["naxx"] = &RaidStrategyContext::naxx;
        creators["bwl"] = &RaidStrategyContext::bwl;
        creators["uld"] = &RaidStrategyContext::uld;
        creators["mc"] = &RaidStrategyContext::mc;
        creators["aq20"] = &RaidStrategyContext::aq20;
    }

private:
    static Strategy* naxx(PlayerbotAI* botAI) { return new RaidNaxxStrategy(botAI); }
    static Strategy* bwl(PlayerbotAI* botAI) { return new RaidBwlStrategy(botAI); }
    static Strategy* uld(PlayerbotAI* botAI) { return new RaidUlduarStrategy(botAI); }
    static Strategy* mc(PlayerbotAI* botAI) { return new RaidMcStrategy(botAI); }
    static Strategy* aq20(PlayerbotAI* botAI) { return new RaidAq20Strategy(botAI); }
};

#endif
