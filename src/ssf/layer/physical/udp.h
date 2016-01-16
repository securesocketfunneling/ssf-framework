#ifndef SSF_LAYER_PHYSICAL_UDP_H_
#define SSF_LAYER_PHYSICAL_UDP_H_

#include <cstdint>

#include <memory>

#include <boost/asio/ip/udp.hpp>
#include <boost/asio/io_service.hpp>

#include "ssf/layer/basic_empty_datagram.h"
#include "ssf/layer/parameters.h"
#include "ssf/layer/physical/udp_helpers.h"
#include "ssf/layer/protocol_attributes.h"

namespace ssf {
namespace layer {
namespace physical {

class udp {
 public:
  enum {
    id = 11,
    overhead = 0,
    facilities = ssf::layer::facilities::datagram,
    mtu = 1500 - overhead
  };
  enum { endpoint_stack_size = 1 };

  typedef int socket_context;
  typedef int acceptor_context;
  typedef boost::asio::ip::udp::socket socket;
  typedef boost::asio::ip::udp::resolver resolver;
  typedef boost::asio::ip::udp::endpoint endpoint;

private:
 using query = ParameterStack;

 public:
  operator boost::asio::ip::udp() { return boost::asio::ip::udp::v4(); }

  static endpoint make_endpoint(boost::asio::io_service& io_service,
                                query::const_iterator parameters_it, uint32_t,
                                boost::system::error_code& ec) {
    return endpoint(ssf::layer::physical::detail::make_udp_endpoint(
        io_service, *parameters_it, ec));
  }

  static std::string get_address(const endpoint& endpoint) {
    return endpoint.address().to_string();  
  }
};

using UDPPhysicalLayer = VirtualEmptyDatagramProtocol<udp>;

}  // physical
}  // layer
}  // ssf

#endif  // SSF_LAYER_PHYSICAL_UDP_H_
