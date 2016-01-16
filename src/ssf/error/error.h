#ifndef SSF_ERROR_ERROR_H_
#define SSF_ERROR_ERROR_H_

#include <string>

#include <boost/system/error_code.hpp>
#include <boost/asio/error.hpp>

namespace ssf {
namespace error {

enum errors {
  success = boost::system::errc::success,
  interrupted = boost::system::errc::interrupted,
  io_error = boost::system::errc::io_error,
  bad_file_descriptor = boost::system::errc::bad_file_descriptor,
  device_or_resource_busy = boost::system::errc::device_or_resource_busy,
  invalid_argument = boost::system::errc::invalid_argument,
  not_a_socket = boost::system::errc::not_a_socket,
  broken_pipe = boost::system::errc::broken_pipe,
  filename_too_long = boost::system::errc::filename_too_long,
  function_not_supported = boost::system::errc::function_not_supported,
  connection_aborted = boost::system::errc::connection_aborted,
  connection_refused = boost::system::errc::connection_refused,
  connection_reset = boost::system::errc::connection_reset,
  not_connected = boost::system::errc::not_connected,
  protocol_error = boost::system::errc::protocol_error,
  wrong_protocol_type = boost::system::errc::wrong_protocol_type,
  operation_canceled = boost::system::errc::operation_canceled,
  identifier_removed = boost::system::errc::identifier_removed,
  address_in_use = boost::system::errc::address_in_use,
  address_not_available = boost::system::errc::address_not_available,
  destination_address_required =
      boost::system::errc::destination_address_required,
  bad_address = boost::system::errc::bad_address,
  message_size = boost::system::errc::message_size,
  network_down = boost::system::errc::network_down,
  no_buffer_space = boost::system::errc::no_buffer_space,
  no_link = boost::system::errc::no_link,
  service_not_found = 10000,
  out_of_range = 10001,
  import_crt_error = 10002,
  set_crt_error = 10003,
  no_crt_error = 10004,
  import_key_error = 10005,
  set_key_error = 10006,
  no_key_error = 10007,
  no_dh_param_error = 10008,
  buffer_is_full_error = 11000,
  missing_config_parameters = 12000,
  cannot_resolve_endpoint = 12001
};

extern BOOST_ASIO_DECL const boost::system::error_category& get_ssf_category();

}  // error
}  // ssf

#include "ssf/error/error.ipp"

#endif  // SSF_ERROR_ERROR_H_
