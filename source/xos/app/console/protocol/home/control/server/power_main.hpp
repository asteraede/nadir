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
///   Date: 12/4/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_PROTOCOL_HOME_CONTROL_SERVER_POWER_MAIN_HPP
#define XOS_APP_CONSOLE_PROTOCOL_HOME_CONTROL_SERVER_POWER_MAIN_HPP

#include "xos/app/console/protocol/home/control/server/power_main_opt.hpp"

namespace xos {
namespace app {
namespace console {
namespace protocol {
namespace home {
namespace control {
namespace server {

/// class power_maint
template 
<class TExtends = xos::app::console::protocol::home::control::server::power_main_opt, 
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
    power_maint(): run_(0) {
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

    /// ...prepare_power_on_response_from_request
    virtual int prepare_power_on_response_from_request(string_t &response, const string_t &request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        string_t &power_on_response = this->power_on_response();
        response.assign(power_on_response);
        this->set_power_on();
        return err;
    }
    virtual int before_prepare_power_on_response_from_request(string_t &response, const string_t &request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_power_on_response_from_request(string_t &response, const string_t &request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_power_on_response_from_request(string_t &response, const string_t &request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_power_on_response_from_request(response, request, argc, argv, env))) {
            int err2 = 0;
            err = prepare_power_on_response_from_request(response, request, argc, argv, env);
            if ((err2 = after_prepare_power_on_response_from_request(response, request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...prepare_power_off_response_from_request
    virtual int prepare_power_off_response_from_request(string_t &response, const string_t &request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        string_t &power_off_response = this->power_off_response();
        response.assign(power_off_response);
        this->set_power_off();
        return err;
    }
    virtual int before_prepare_power_off_response_from_request(string_t &response, const string_t &request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_power_off_response_from_request(string_t &response, const string_t &request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_power_off_response_from_request(string_t &response, const string_t &request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_power_off_response_from_request(response, request, argc, argv, env))) {
            int err2 = 0;
            err = prepare_power_off_response_from_request(response, request, argc, argv, env);
            if ((err2 = after_prepare_power_off_response_from_request(response, request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...prepare_power_response_on_from_request
    virtual int prepare_power_response_on_from_request(string_t &response, const string_t &request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        string_t &power_response = this->power_on_response();
        response.assign(power_response);        
        return err;
    }
    virtual int before_prepare_power_response_on_from_request(string_t &response, const string_t &request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_power_response_on_from_request(string_t &response, const string_t &request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_power_response_on_from_request(string_t &response, const string_t &request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_power_response_on_from_request(response, request, argc, argv, env))) {
            int err2 = 0;
            err = prepare_power_response_on_from_request(response, request, argc, argv, env);
            if ((err2 = after_prepare_power_response_on_from_request(response, request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...prepare_power_response_off_from_request
    virtual int prepare_power_response_off_from_request(string_t &response, const string_t &request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        string_t &power_response = this->power_off_response();
        response.assign(power_response);        
        return err;
    }
    virtual int before_prepare_power_response_off_from_request(string_t &response, const string_t &request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_power_response_off_from_request(string_t &response, const string_t &request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_power_response_off_from_request(string_t &response, const string_t &request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_power_response_off_from_request(response, request, argc, argv, env))) {
            int err2 = 0;
            err = prepare_power_response_off_from_request(response, request, argc, argv, env);
            if ((err2 = after_prepare_power_response_off_from_request(response, request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...prepare_power_response_from_request
    virtual int prepare_power_response_from_request(string_t &response, const string_t &request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        bool power_on = this->power_on();

        if ((power_on)) {
            if (!(err = err = prepare_power_response_on_from_request(response, request, argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = err = prepare_power_response_off_from_request(response, request, argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int before_prepare_power_response_from_request(string_t &response, const string_t &request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_power_response_from_request(string_t &response, const string_t &request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_power_response_from_request(string_t &response, const string_t &request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_power_response_from_request(response, request, argc, argv, env))) {
            int err2 = 0;
            err = prepare_power_response_from_request(response, request, argc, argv, env);
            if ((err2 = after_prepare_power_response_from_request(response, request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...prepare_response_from_request
    virtual int prepare_response_from_request(string_t &response, const string_t &request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        int unequal = 0;
        string_t &power_on_request = this->power_on_request(), 
                 &power_off_request = this->power_off_request(), 
                 &power_request = this->power_request();

        LOGGER_IS_LOGGED_INFO("...request = \"" << request << "\"");
        LOGGER_IS_LOGGED_INFO("!(unequal = request.compare(\"" << power_request << "\"))...");
        if (!(unequal = request.compare(power_request))) {
            LOGGER_IS_LOGGED_INFO("!(err = all_prepare_power_response_from_request(response, request, argc, argv, env))...");
            if (!(err = all_prepare_power_response_from_request(response, request, argc, argv, env))) {
            } else {
            }
        } else {
            LOGGER_IS_LOGGED_INFO("!(unequal = request.compare(\"" << power_on_request << "\"))...");
            if (!(unequal = request.compare(power_on_request))) {
                LOGGER_IS_LOGGED_INFO("!(err = all_prepare_power_on_response_from_request(response, request, argc, argv, env))...");
                if (!(err = all_prepare_power_on_response_from_request(response, request, argc, argv, env))) {
                } else {
                }
            } else {
                LOGGER_IS_LOGGED_INFO("!(unequal = request.compare(\"" << power_off_request << "\"))...");
                if (!(unequal = request.compare(power_off_request))) {
                    LOGGER_IS_LOGGED_INFO("!(err = all_prepare_power_off_response_from_request(response, request, argc, argv, env))...");
                    if (!(err = all_prepare_power_off_response_from_request(response, request, argc, argv, env))) {
                    } else {
                    }
                } else {           
                    LOGGER_IS_LOGGED_INFO("!(err = all_prepare_power_response_from_request(response, request, argc, argv, env))...");
                    if (!(err = all_prepare_power_response_from_request(response, request, argc, argv, env))) {
                    } else {
                    }
                }
            }
        }
        return err;
    }
    virtual int before_prepare_response_from_request(string_t &response, const string_t &request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_response_from_request(string_t &response, const string_t &request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_response_from_request(string_t &response, const string_t &request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_response_from_request(response, request, argc, argv, env))) {
            int err2 = 0;
            err = prepare_response_from_request(response, request, argc, argv, env);
            if ((err2 = after_prepare_response_from_request(response, request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...request_option...
    virtual int on_request_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            string_t &response = this->response(),
                     &request = this->request();

            if (!(err = all_prepare_response_from_request(response, request, argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }

protected:
}; /// class power_maint
typedef power_maint<> power_main;

} /// namespace server
} /// namespace control
} /// namespace home
} /// namespace protocol
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_PROTOCOL_HOME_CONTROL_SERVER_POWER_MAIN_HPP
