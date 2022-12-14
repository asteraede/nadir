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
///   File: power_main_opt.hpp
///
/// Author: $author$
///   Date: 12/3/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_PROTOCOL_HOME_CONTROL_CLIENT_POWER_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_PROTOCOL_HOME_CONTROL_CLIENT_POWER_MAIN_OPT_HPP

#include "xos/app/console/protocol/home/control/client/main_opt.hpp"
#include "xos/app/console/protocol/home/control/base/power_main.hpp"

namespace xos {
namespace app {
namespace console {
namespace protocol {
namespace home {
namespace control {
namespace client {

/// class power_main_optt
template 
<class TExtends = xos::app::console::protocol::home::control::base::power_maint<>, 
 class TImplements = typename TExtends::implements>

class exported power_main_optt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef power_main_optt derives;

    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };
    typedef typename extends::string_t string_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;

    /// constructor / destructor
    power_main_optt(): run_(0) {
    }
    virtual ~power_main_optt() {
    }
private:
    power_main_optt(const power_main_optt& copy) {
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

    /// ...request_option...
    virtual int on_request_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }

    /// ...power_on_option...
    virtual int on_set_power_on_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        this->set_request(this->power_on_request());
        return err;
    }
    virtual int on_power_on_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = on_request_option_set(optarg, optind, argc, argv, env))) {
        } else {
        }
        return err;
    }
    virtual int on_power_on_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = on_set_power_on_option(optarg, optind, argc, argv, env))) {
            if (!(err = on_power_on_option_set(optarg, optind, argc, argv, env))) {
                if (!(err = this->set_output_request_run(argc, argv, env))) {
                    if (!(err = this->output_request_run_set(argc, argv, env))) {
                    } else {
                    }
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }
    virtual const char_t* power_on_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_PROTOCOL_HOME_CONTROL_CLIENT_MAIN_POWER_ON_OPTUSE;
        optarg = XOS_APP_CONSOLE_PROTOCOL_HOME_CONTROL_CLIENT_MAIN_POWER_ON_OPTARG;
        return chars;
    }

    /// ...power_off_option...
    virtual int on_set_power_off_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        this->set_request(this->power_off_request());
        return err;
    }
    virtual int on_power_off_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = on_request_option_set(optarg, optind, argc, argv, env))) {
        } else {
        }
        return err;
    }
    virtual int on_power_off_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = on_set_power_off_option(optarg, optind, argc, argv, env))) {
            if (!(err = on_power_off_option_set(optarg, optind, argc, argv, env))) {
                if (!(err = this->set_output_request_run(argc, argv, env))) {
                    if (!(err = this->output_request_run_set(argc, argv, env))) {
                    } else {
                    }
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }
    virtual const char_t* power_off_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_PROTOCOL_HOME_CONTROL_CLIENT_MAIN_POWER_OFF_OPTUSE;
        optarg = XOS_APP_CONSOLE_PROTOCOL_HOME_CONTROL_CLIENT_MAIN_POWER_OFF_OPTARG;
        return chars;
    }

    /// ...power_option...
    virtual int on_get_power_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        this->set_request(this->power_request());
        return err;
    }
    virtual int on_power_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = on_request_option_set(optarg, optind, argc, argv, env))) {
        } else {
        }
        return err;
    }
    virtual int on_set_power_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            string_t opt(optarg);
            int unequal = 0;
            if (!(unequal = opt.uncased_compare
                  (XOS_APP_CONSOLE_PROTOCOL_HOME_CONTROL_CLIENT_MAIN_POWER_OPTARG_ON))) {
                if (!(err = on_set_power_on_option(optarg, optind, argc, argv, env))) {
                    if (!(err = on_power_on_option_set(optarg, optind, argc, argv, env))) {
                    } else {
                    }
                } else {
                }
            } else {
                if (!(unequal = opt.uncased_compare
                      (XOS_APP_CONSOLE_PROTOCOL_HOME_CONTROL_CLIENT_MAIN_POWER_OPTARG_OFF))) {
                    if (!(err = on_set_power_off_option(optarg, optind, argc, argv, env))) {
                        if (!(err = on_power_off_option_set(optarg, optind, argc, argv, env))) {
                        } else {
                        }
                    } else {
                    }
                } else {
                    if (!(unequal = opt.uncased_compare
                          (XOS_APP_CONSOLE_PROTOCOL_HOME_CONTROL_CLIENT_MAIN_POWER_OPTARG_STATE))) {
                        if (!(err = on_get_power_option(optarg, optind, argc, argv, env))) {
                            if (!(err = on_power_option_get(optarg, optind, argc, argv, env))) {
                            } else {
                            }
                        } else {
                        }
                    } else {
                        if (!(err = on_get_power_option(optarg, optind, argc, argv, env))) {
                            if (!(err = on_power_option_get(optarg, optind, argc, argv, env))) {
                            } else {
                            }
                        } else {
                        }
                    }
                }
            }
        } else {
            if (!(err = on_get_power_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_power_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual int on_power_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_power_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_power_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_power_option_set(optarg, optind, argc, argv, env))) {
                    if (!(err = this->set_output_request_run(argc, argv, env))) {
                        if (!(err = this->output_request_run_set(argc, argv, env))) {
                        } else {
                        }
                    } else {
                    }
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_power_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_power_option_get(optarg, optind, argc, argv, env))) {
                    if (!(err = this->set_output_request_run(argc, argv, env))) {
                        if (!(err = this->output_request_run_set(argc, argv, env))) {
                        } else {
                        }
                    } else {
                    }
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* power_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_PROTOCOL_HOME_CONTROL_CLIENT_MAIN_POWER_OPTUSE;
        optarg = XOS_APP_CONSOLE_PROTOCOL_HOME_CONTROL_CLIENT_MAIN_POWER_OPTARG;
        return chars;
    }

    /// ...option...
    virtual int on_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {

        case XOS_APP_CONSOLE_PROTOCOL_HOME_CONTROL_CLIENT_MAIN_POWER_ON_OPTVAL_C:
            err = this->on_power_on_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_PROTOCOL_HOME_CONTROL_CLIENT_MAIN_POWER_OFF_OPTVAL_C:
            err = this->on_power_off_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_PROTOCOL_HOME_CONTROL_CLIENT_MAIN_POWER_OPTVAL_C:
            err = this->on_power_option(optval, optarg, optname, optind, argc, argv, env);
            break;

        default:
            err = extends::on_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual const char_t* option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {

        case XOS_APP_CONSOLE_PROTOCOL_HOME_CONTROL_CLIENT_MAIN_POWER_ON_OPTVAL_C:
            chars = this->power_on_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_PROTOCOL_HOME_CONTROL_CLIENT_MAIN_POWER_OFF_OPTVAL_C:
            chars = this->power_off_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_PROTOCOL_HOME_CONTROL_CLIENT_MAIN_POWER_OPTVAL_C:
            chars = this->power_option_usage(optarg, longopt);
            break;

        default:
            chars = extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = XOS_APP_CONSOLE_PROTOCOL_HOME_CONTROL_CLIENT_MAIN_POWER_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_PROTOCOL_HOME_CONTROL_CLIENT_MAIN_POWER_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    /// ...argument...
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_APP_CONSOLE_PROTOCOL_HOME_CONTROL_CLIENT_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_CONSOLE_PROTOCOL_HOME_CONTROL_CLIENT_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }

protected:
}; /// class power_main_optt
typedef power_main_optt<> power_main_opt;

} /// namespace client
} /// namespace control
} /// namespace home
} /// namespace protocol
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_PROTOCOL_HOME_CONTROL_CLIENT_POWER_MAIN_OPT_HPP
