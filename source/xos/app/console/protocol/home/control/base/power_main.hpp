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
///   File: power_main.hpp
///
/// Author: $author$
///   Date: 12/3/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_PROTOCOL_HOME_CONTROL_BASE_POWER_MAIN_HPP
#define XOS_APP_CONSOLE_PROTOCOL_HOME_CONTROL_BASE_POWER_MAIN_HPP

#include "xos/app/console/protocol/home/control/base/power_main_opt.hpp"

namespace xos {
namespace app {
namespace console {
namespace protocol {
namespace home {
namespace control {
namespace base {

/// class power_maint
template 
<class TExtends = xos::app::console::protocol::home::control::base::power_main_opt, 
 class TImplements = typename TExtends::implements>

class exported power_maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef power_maint derives;

    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };
    typedef typename extends::string_t string_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;

    /// constructor / destructor
    power_maint()
    : run_(0),

      power_on_(false),
      power_on_request_("{\"control\":{\"power\":{\"set_power_state\":{\"state\":\"on\"}}}}"), 
      power_off_request_("{\"control\":{\"power\":{\"set_power_state\":{\"state\":\"off\"}}}}"),
      power_request_("{\"control\":{\"power\":{\"get_power_state\":null}}}"),

      power_on_response_("{\"control\":{\"power\":{\"power_state\":{\"state\":\"on\"}}}}"), 
      power_off_response_("{\"control\":{\"power\":{\"power_state\":{\"state\":\"off\"}}}}"),
      power_unknown_response_("{\"control\":{\"power\":{\"power_state\":{\"state\":\"unknown\"}}}}") {
    }
    virtual ~power_maint() {
    }
private:
    power_maint(const power_maint& copy) {
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

protected:
    bool power_on_;
    string_t power_on_request_, power_off_request_, power_request_;
    string_t power_on_response_, power_off_response_, power_unknown_response_;
}; /// class power_maint
typedef power_maint<> power_main;

} /// namespace base
} /// namespace control
} /// namespace home
} /// namespace protocol
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_PROTOCOL_HOME_CONTROL_BASE_POWER_MAIN_HPP
