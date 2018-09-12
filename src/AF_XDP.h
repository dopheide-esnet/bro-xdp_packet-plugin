#ifndef IOSOURCE_PKTSRC_AF_XDP_SOURCE_H
#define IOSOURCE_PKTSRC_AF_XDP_SOURCE_H

extern "C" {
}

#include "iosource/PktSrc.h"

namespace iosource {
namespace pktsrc {

class AF_XDPSource : public iosource::PktSrc {
public:
	AF_XDPSource(const std::string& path, bool is_live);

	virtual ~AF_XDPSource();

	static PktSrc* InstantiateAF_XDP(const std::string& path, bool is_live);

protected:
	virtual void Open();
	virtual void Close();
	virtual bool ExtractNextPacket(Packet* pkt);
	virtual void DoneWithPacket();
	virtual bool PrecompileFilter(int index, const std::string& filter);
	virtual bool SetFilter(int index);
	virtual void Statistics(Stats* stats);

private:
	Properties props;
};

}
}

#endif