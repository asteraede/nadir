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
#ifndef XOS_APP_CONSOLE_PROTOCOL_HOME_CONTROL_SERVER_MAIN_HPP
#define XOS_APP_CONSOLE_PROTOCOL_HOME_CONTROL_SERVER_MAIN_HPP

#include "xos/app/console/protocol/home/control/server/main_opt.hpp"

namespace xos {
namespace app {
namespace console {
namespace protocol {
namespace home {
namespace control {
namespace server {

/// class maint
template 
<class TExtends = xos::app::console::protocol::home::control::server::main_opt, 
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
    maint(): run_(0) {
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

    /// ...prepare_system_restart_response_from_request
    virtual int prepare_system_restart_response_from_request(string_t &response, const string_t &request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        response.assign(request);
        this->set_system_restart();
        return err;
    }
    virtual int before_prepare_system_restart_response_from_request(string_t &response, const string_t &request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_system_restart_response_from_request(string_t &response, const string_t &request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_system_restart_response_from_request(string_t &response, const string_t &request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_system_restart_response_from_request(response, request, argc, argv, env))) {
            int err2 = 0;
            err = prepare_system_restart_response_from_request(response, request, argc, argv, env);
            if ((err2 = after_prepare_system_restart_response_from_request(response, request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...prepare_system_stop_response_from_request
    virtual int prepare_system_stop_response_from_request(string_t &response, const string_t &request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        response.assign(request);
        this->set_system_stop();
        return err;
    }
    virtual int before_prepare_system_stop_response_from_request(string_t &response, const string_t &request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_system_stop_response_from_request(string_t &response, const string_t &request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_system_stop_response_from_request(string_t &response, const string_t &request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_system_stop_response_from_request(response, request, argc, argv, env))) {
            int err2 = 0;
            err = prepare_system_stop_response_from_request(response, request, argc, argv, env);
            if ((err2 = after_prepare_system_stop_response_from_request(response, request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
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

    /// ...prepare_power_unknown_response_from_request
    virtual int prepare_power_unknown_response_from_request(string_t &response, const string_t &request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        string_t &power_unknown_response = this->power_unknown_response();
        response.assign(power_unknown_response);
        return err;
    }
    virtual int before_prepare_power_unknown_response_from_request(string_t &response, const string_t &request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_power_unknown_response_from_request(string_t &response, const string_t &request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_power_unknown_response_from_request(string_t &response, const string_t &request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_power_unknown_response_from_request(response, request, argc, argv, env))) {
            int err2 = 0;
            err = prepare_power_unknown_response_from_request(response, request, argc, argv, env);
            if ((err2 = after_prepare_power_unknown_response_from_request(response, request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...prepare_power_response_from_request
    virtual int prepare_power_response_from_request(string_t &response, const string_t &request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        bool power_on = this->power_on();
        string_t &power_on_response = this->power_on_response(),
                 &power_off_response = this->power_off_response();

        if ((power_on)) {
            response.assign(power_on_response);
        } else {
            response.assign(power_off_response);
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
                 &power_request = this->power_request(),
                 &system_restart_request = this->system_restart_request(),
                 &system_stop_request = this->system_stop_request();

        if (!(unequal = request.compare(power_request))) {
            if (!(err = all_prepare_power_response_from_request(response, request, argc, argv, env))) {
            } else {
            }
        } else {
            if (!(unequal = request.compare(power_on_request))) {
                if (!(err = all_prepare_power_on_response_from_request(response, request, argc, argv, env))) {
                } else {
                }
            } else {
                if (!(unequal = request.compare(power_off_request))) {
                    if (!(err = all_prepare_power_off_response_from_request(response, request, argc, argv, env))) {
                    } else {
                    }
                } else {
                    if (!(unequal = request.compare(system_restart_request))) {
                        if (!(err = all_prepare_system_restart_response_from_request(response, request, argc, argv, env))) {
                        } else {
                        }
                    } else {
                        if (!(unequal = request.compare(system_stop_request))) {
                            if (!(err = all_prepare_system_stop_response_from_request(response, request, argc, argv, env))) {
                            } else {
                            }
                        } else {
                            if (!(err = all_prepare_power_unknown_response_from_request(response, request, argc, argv, env))) {
                            } else {
                            }
                        }
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
    virtual int on_set_request_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            string_t& request = this->request();
            if (!(err = this->on_set_string_message_option(request, optarg, optind, argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
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
}; /// class maint
typedef maint<> main;

} /// namespace server
} /// namespace control
} /// namespace home
} /// namespace protocol
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_PROTOCOL_HOME_CONTROL_SERVER_MAIN_HPP
