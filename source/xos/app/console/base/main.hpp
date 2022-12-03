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
#ifndef XOS_APP_CONSOLE_BASE_MAIN_HPP
#define XOS_APP_CONSOLE_BASE_MAIN_HPP

#include "xos/app/console/base/main_opt.hpp"
#include "xos/io/string/reader.hpp"
#include "xos/io/crt/file/reader.hpp"
#include "xos/io/hex/read_to_string.hpp"

namespace xos {
namespace app {
namespace console {
namespace base {

/// class maint
template 
<class TExtends = xos::app::console::base::main_opt, 
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
      output_request_run_(0),
      output_response_run_(0),
      verbose_output_(false),
      request_("hello"),
      response_(request_) {
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

    typedef xos::io::string::readert<xos::base::string, xos::io::reader> string_reader_t;
    typedef typename string_reader_t::string_t reader_string_t;
    typedef typename reader_string_t::char_t reader_char_t;
    typedef xos::io::hex::read_to_stringt<string_t> hex_read_to_string_t;
    typedef xos::io::hex::reader_to hex_reader_t;

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

    /// ...output_request_run
    int (derives::*output_request_run_)(int argc, char_t** argv, char_t** env);
    virtual int output_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (output_request_run_) {
            err = (this->*output_request_run_)(argc, argv, env);
        } else {
            err = default_output_request_run(argc, argv, env);
        }
        return err;
    }
    virtual int default_output_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const string_t& request = this->request();
        this->outln(request);
        return err;
    }
    virtual int before_output_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_request_run(argc, argv, env))) {
            int err2 = 0;
            err = output_request_run(argc, argv, env);
            if ((err2 = after_output_request_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_output_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_output_request_run;
        return err;
    }
    virtual int output_request_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_output_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int output_request_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    /// ...output_response_run
    int (derives::*output_response_run_)(int argc, char_t** argv, char_t** env);
    virtual int output_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (output_response_run_) {
            err = (this->*output_response_run_)(argc, argv, env);
        } else {
            err = default_output_response_run(argc, argv, env);
        }
        return err;
    }
    virtual int default_output_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const string_t& response = this->response();
        this->outln(response);
        return err;
    }
    virtual int before_output_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_response_run(argc, argv, env))) {
            int err2 = 0;
            err = output_response_run(argc, argv, env);
            if ((err2 = after_output_response_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_output_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_output_response_run;
        return err;
    }
    virtual int output_response_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_output_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int output_response_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    /// ...on_set_string_message_option
    int (derives::*on_set_string_message_option_)(string_t& message, const char_t* optarg, int optind, int argc, char_t** argv, char_t** env);
    virtual int on_set_string_message_option(string_t& message, const char_t* optarg, int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (on_set_string_message_option_) {
            err = (this->*on_set_string_message_option_)(message, optarg, optind, argc, argv, env);
        } else {
            err = string_on_set_string_message_option(message, optarg, optind, argc, argv, env);
        }
        return err;
    }
    virtual int string_on_set_string_message_option(string_t& message, const char_t* optarg, int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            message.assign(optarg);
        }
        return err;
    }
    virtual int hex_string_on_set_string_message_option(string_t& message, const char_t* optarg, int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            reader_string_t string(optarg);
            const reader_char_t *chars = 0;
            size_t length = 0;
            
            if ((chars = string.has_chars(length))) {
                string_reader_t reader(string);

                if (!(err = hex_decode_source_to_string(message, reader))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual int file_on_set_string_message_option(string_t& message, const char_t* optarg, int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if ((optarg) && (optarg[0])) {
                xos::io::crt::file::char_reader file;
    
                LOGGER_IS_LOGGED_INFO("file.open(\""<< optarg <<"\")...");
                if ((file.open(optarg))) {
                    xos::io::crt::file::char_reader::char_t c = 0;
                    ssize_t amount = 0, count = 0;
                    if (0 < (amount = file.read(&c, 1))) {
                        string_t old_message(message);
                        message.clear();
                        do {
                            char_t message_c = ((char_t)c);
                            if ((err = on_string_message_char(message, message_c, argc, argv, env))) {
                                LOGGER_IS_LOGGED_ERROR("...failed on (" << signed_to_string(err) << " = on_string_message_char(message, message_c, argc, argv, env))");
                                message.assign(old_message);
                                break;
                            }
                            count += amount;
                        } while (0 < (amount = file.read(&c, 1)));
                    }
                    LOGGER_IS_LOGGED_INFO("...file.close(\""<< optarg <<"\")...");
                    file.close();
                }
            }
        }
        return err;
    }
    virtual int hex_file_on_set_string_message_option(string_t& message, const char_t* optarg, int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if ((optarg) && (optarg[0])) {
                xos::io::crt::file::reader file;
    
                LOGGER_IS_LOGGED_INFO("file.open(\""<< optarg <<"\")...");
                if ((file.open(optarg))) {
                    
                    if (!(err = hex_decode_source_to_string(message, file))) {
                    } else {
                    }
                    LOGGER_IS_LOGGED_INFO("...file.close(\""<< optarg <<"\")...");
                    file.close();
                }
            }
        }
        return err;
    }
    virtual int set_string_on_set_string_message_option(int argc, char_t** argv, char_t** env) {
        int err = 0;
        on_set_string_message_option_ = &derives::string_on_set_string_message_option;
        return err;
    }
    virtual int string_on_set_string_message_option_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int set_file_on_set_string_message_option(int argc, char_t** argv, char_t** env) {
        int err = 0;
        on_set_string_message_option_ = &derives::file_on_set_string_message_option;
        return err;
    }
    virtual int file_on_set_string_message_option_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    /// ...on_string_message_char
    int (derives::*on_string_message_char_)(string_t& message, const char_t& message_c, int argc, char_t** argv, char_t** env);
    virtual int on_string_message_char(string_t& message, const char_t& message_c, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (on_string_message_char_) {
            err = (this->*on_string_message_char_)(message, message_c, argc, argv, env);
        } else {
            err = default_on_string_message_char(message, message_c, argc, argv, env);
        }
        return err;
    }
    virtual int default_on_string_message_char(string_t& message, const char_t& message_c, int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t lf_c = ((char_t)'\n');
        
        if ((message_c != lf_c)) {
            message.append(&message_c, 1);
        } else {
            err = set_endof_on_string_message_char(argc, argv, env);
        }
        return err;
    }
    virtual int endof_on_string_message_char(string_t& message, const char_t& message_c, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int set_endof_on_string_message_char(int argc, char_t** argv, char_t** env) {
        int err = 0;
        on_string_message_char_ = &derives::endof_on_string_message_char;
        return err;
    }
    virtual int unset_endof_on_string_message_char(int argc, char_t** argv, char_t** env) {
        int err = 0;
        on_string_message_char_ = 0;
        return err;
    }

    /// ...input_option...
    virtual int on_set_file_input_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_file_on_set_string_message_option(argc, argv, env))) {
            if (!(err = file_on_set_string_message_option_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_string_input_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_string_on_set_string_message_option(argc, argv, env))) {
            if (!(err = string_on_set_string_message_option_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }

    /// ...output_option...
    virtual int on_set_verbose_output_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        set_verbose_output();
        return err;
    }
    virtual int on_set_quiet_output_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        set_quiet_output();
        return err;
    }

    /// ...hex_decode_source_to_string
    virtual int hex_decode_source_to_string(string_t& string, io::reader& source) {
        int err = 0;
        ssize_t count = 0, amount = 0;
        byte_t byte = 0;

        if (0 < (amount = source.read(&byte, 1))) {
            hex_read_to_string_t to_string_reader(string);
            hex_reader_t reader(to_string_reader, source);
            
            reader.on_begin(&byte, 1);
            do {
                if ((0 > (reader.on_read(&byte, 1)))) {
                    break;
                }
                count += amount;
                amount = source.read(&byte, 1);
            } while (0 < amount);
            reader.on_end(&byte, 1);
        }
        return err;
    }

    /// ...request
    virtual string_t& set_request(const string_t& to) {
        string_t& request = this->request();
        request.assign(to);
        return request;
    }
    virtual string_t& set_request(const char_t* to) {
        string_t& request = this->request();
        request.assign(to);
        return request;
    }
    virtual string_t& set_request(const char_t* to, size_t length) {
        string_t& request = this->request();
        request.assign(to, length);
        return request;
    }
    virtual string_t& request() const {
        return (string_t&)request_;
    }

    /// ...response
    virtual string_t& set_response(const string_t& to) {
        string_t& response = this->response();
        response.assign(to);
        return response;
    }
    virtual string_t& set_response(const char_t* to, size_t length) {
        string_t& response = this->response();
        response.assign(to, length);
        return response;
    }
    virtual string_t& set_response(const char_t* to) {
        string_t& response = this->response();
        response.assign(to);
        return response;
    }
    virtual string_t& response() const {
        return (string_t&)response_;
    }
    
    /// ...verbose_output
    virtual bool& set_quiet_output(bool to = true) {
        bool& verbose_output = this->verbose_output();
        verbose_output = !to;
        return verbose_output;
    }
    virtual bool& set_verbose_output(bool to = true) {
        bool& verbose_output = this->verbose_output();
        verbose_output = to;
        return verbose_output;
    }
    virtual bool& verbose_output() const {
        return (bool&)verbose_output_;
    }

protected:
    bool verbose_output_;
    string_t request_, response_;
}; /// class maint
typedef maint<> main;

} /// namespace base
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_BASE_MAIN_HPP
