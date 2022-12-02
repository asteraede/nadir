///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: main.hpp
///
/// Author: $author$
///   Date: 11/29/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_PROTOCOL_HOME_CONTROL_BASE_MAIN_HPP
#define XOS_APP_CONSOLE_PROTOCOL_HOME_CONTROL_BASE_MAIN_HPP

#include "xos/app/console/protocol/home/control/base/main_opt.hpp"

namespace xos {
namespace app {
namespace console {
namespace protocol {
namespace home {
namespace control {
namespace base {

/// class maint
template 
<class TExtends = xos::app::console::protocol::home::control::base::main_opt, 
 class TImplements = typename TExtends::implements>

class exported maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef maint derives;

    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };
    typedef typename extends::string_t string_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;

    /// constructor / destructor
    maint()
    : run_(0),

      power_on_(false),
      power_on_request_("{\"control\":{\"power\":{\"set_power_state\":{\"state\":\"on\"}}}}"), 
      power_off_request_("{\"control\":{\"power\":{\"set_power_state\":{\"state\":\"off\"}}}}"),
      power_request_("{\"control\":{\"power\":{\"get_power_state\":null}}}"),

      power_on_response_("{\"control\":{\"power\":{\"power_state\":{\"state\":\"on\"}}}}"), 
      power_off_response_("{\"control\":{\"power\":{\"power_state\":{\"state\":\"off\"}}}}"),
      power_unknown_response_("{\"control\":{\"power\":{\"power_state\":{\"state\":\"unknown\"}}}}"),
    
      system_restart_request_("{\"control\":{\"system\":{\"system_action\":{\"action\":\"restart\"}}}}"),
      system_stop_request_("{\"control\":{\"system\":{\"system_action\":{\"action\":\"stop\"}}}}"),
      system_request_("{\"control\":{\"system\":{\"get_system_info\":null}}}"),
      system_response_
      ("{\"control\":{\"system\":{\"system_info\":"
       "{\"software_version\":\"control-0.0.0-11/29/2022\"},"
       "{\"hardware_type\":\"home.control.outlet.plug.switch\"},"
       "{\"hardware_model\":\"hcops1000us\"},"
       "{\"hardware_version\":\"0.0.0-11/29/2022\"},"
       "{\"device_id\":\"51904BC0-7265-11ED-9012-B1ED9D1D6E6A\"},"
       "{\"hardware_id\":\"06A5FE38-7266-11ED-8662-D91BD5DF16AF\"},"
       "{\"firmware_id\":\"4D579B3E-7266-11ED-895C-375E42C9F6CE\"},"
       "{\"oem_id\":\"83F2BD72-7266-11ED-8160-73564D545C1A\"},"
       "{\"ethernet_address\":\"00:00:00:00:00:00\"}},"
       "{\"device_name\":\"home-control-outlet-plug-switch\"},"
       "{\"device_alias\":\"home-control-outlet-plug-switch\"}}}}") {
    }
    virtual ~maint() {
    }
private:
    maint(const maint& copy) {
        throw exception(exception_unexpected);
    }

protected:
    typedef typename extends::in_reader_t in_reader_t;
    typedef typename extends::out_writer_t out_writer_t;
    typedef typename extends::err_writer_t err_writer_t;

    /// ...run
    int (derives::*run_)(int argc, char_t** argv, char_t** env);
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((run_)) {
            err = (this->*run_)(argc, argv, env);
        } else {
            err = extends::run(argc, argv, env);
        }
        return err;
    }

    /// ...power...request
    virtual string_t& power_on_request() const {
        return (string_t&)power_on_request_;
    }
    virtual string_t& power_off_request() const {
        return (string_t&)power_off_request_;
    }
    virtual string_t& power_request() const {
        return (string_t&)power_request_;
    }

    /// ...power...response
    virtual string_t& power_on_response() const {
        return (string_t&)power_on_response_;
    }
    virtual string_t& power_off_response() const {
        return (string_t&)power_off_response_;
    }
    virtual string_t& power_unknown_response() const {
        return (string_t&)power_unknown_response_;
    }

    /// ...system...
    virtual string_t& system_restart_request() const {
        return (string_t&)system_restart_request_;
    }
    virtual string_t& system_stop_request() const {
        return (string_t&)system_stop_request_;
    }
    virtual string_t& system_request() const {
        return (string_t&)system_request_;
    }
    virtual string_t& system_response() const {
        return (string_t&)system_response_;
    }

    /// ...power...
    virtual bool& set_power_off(const bool to = true) {
        bool& power_on = this->power_on();
        power_on = !to;
        return power_on;
    }
    virtual bool& set_power_on(const bool to = true) {
        bool& power_on = this->power_on();
        power_on = to;
        return power_on;
    }
    virtual bool& power_on() const {
        return (bool&)power_on_;
    }

    /// ...system_restart...
    virtual bool& set_system_restart(const bool to = true) {
        bool& system_restart = this->system_restart();
        system_restart = to;
        return system_restart;
    }
    virtual bool& system_restart() const {
        return (bool&)system_restart_;
    }

    /// ...system_stop...
    virtual bool& set_system_stop(const bool to = true) {
        bool& system_stop = this->system_stop();
        system_stop = to;
        return system_stop;
    }
    virtual bool& system_stop() const {
        return (bool&)system_stop_;
    }

protected:
    bool power_on_, system_restart_, system_stop_;
    string_t power_on_request_, power_off_request_, power_request_;
    string_t power_on_response_, power_off_response_, power_unknown_response_;
    string_t system_restart_request_, system_stop_request_, system_request_, system_response_;
}; /// class maint
typedef maint<> main;

} /// namespace base
} /// namespace control
} /// namespace home
} /// namespace protocol
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_PROTOCOL_HOME_CONTROL_BASE_MAIN_HPP
