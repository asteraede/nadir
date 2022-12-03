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
///   Date: 12/3/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_PROTOCOL_HOME_CONTROL_KASA_BASE_MAIN_HPP
#define XOS_APP_CONSOLE_PROTOCOL_HOME_CONTROL_KASA_BASE_MAIN_HPP

#include "xos/app/console/protocol/home/control/kasa/base/main_opt.hpp"

namespace xos {
namespace app {
namespace console {
namespace protocol {
namespace home {
namespace control {
namespace kasa {
namespace base {

/// class maint
template 
<class TExtends = xos::app::console::protocol::home::control::kasa::base::main_opt, 
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
      power_on_request_("{\"system\":{\"set_relay_state\":{\"state\":1}}}"), 
      power_off_request_("{\"system\":{\"set_relay_state\":{\"state\":0}}}"),
      power_request_("{\"system\":{\"get_sysinfo\":null}}") {
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

    /// ...output_request
    int (derives::*output_request_run_)(int argc, char_t** argv, char_t** env);
    virtual int output_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (output_request_run_) {
            err = (this->*output_request_run_)(argc, argv, env);
        } else {
            err = extends::output_request_run(argc, argv, env);
        }
        return err;
    }
    virtual int encrupt_output_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        string_t& request = this->request();
        const char_t* chars = 0;
        size_t length = 0;

        if ((chars = request.has_chars(length))) {
            string_t& encrypted = encrypt_text(request);

            if ((chars = encrypted.has_chars(length))) {
                this->outxln(chars, length);
            }
        }
        return err;
    }
    virtual int set_encrupt_output_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_request_run_ = &derives::encrupt_output_request_run;
        return err;
    }
    virtual int unset_encrupt_output_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_request_run_ = 0;
        return err;
    }

    /// ...request_option...
    virtual int on_request_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = extends::on_request_option_set(optarg, optind, argc, argv, env))) {
            if (!(err = set_encrupt_output_request_run(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }

    /// ...on_set_string_message_option
    virtual int string_on_set_string_message_option(string_t& message, const char_t* optarg, int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        string_t& cipher_text = this->cipher_text();

        if (!(err = this->hex_string_on_set_string_message_option(cipher_text, optarg, optind, argc, argv, env))) {
            string_t& decrypted = decrypt_text(cipher_text);

            message.assign(decrypted);
        } else {
        }
        return err;
    }
    virtual int file_on_set_string_message_option(string_t& message, const char_t* optarg, int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        string_t& cipher_text = this->cipher_text();

        if (!(err = this->hex_file_on_set_string_message_option(cipher_text, optarg, optind, argc, argv, env))) {
            string_t& decrypted = decrypt_text(cipher_text);

            message.assign(decrypted);
        } else {
        }
        return err;
    }

    /// ...encrypt_text
    virtual string_t& encrypt_text(const string_t& plain) {
        string_t& encrypted = this->cipher_text();
        const char_t* chars = 0;
        size_t length = 0;

        encrypted.clear();
        if ((chars = plain.has_chars(length))) {
            char_t a = 0, i = 0, k = 0;
            size_t lsb = length, msb = 0, remain = 0;
            
            for (remain = 4; remain; --remain) {
                msb = (msb << 8) | (lsb & 255);
                lsb = (lsb >> 8);
            }
            for (remain = 4; remain; --remain) {
                i = (char_t)(msb & 255);
                msb = (msb >> 8);
                encrypted.append(&i, 1);
            }
            for (k = 171; length; --length, ++chars) {
                i = *chars;
                a = k ^ i;
                k = a;
                encrypted.append(&a, 1);
            }
        }
        return encrypted;
    }

    /// ...decrypt_text
    virtual string_t& decrypt_text(const string_t& cipher) {
        string_t& decrypted = this->plain_text();
        const char_t* chars = 0;
        size_t length = 0;

        decrypted.clear();
        if ((chars = cipher.has_chars(length)) && (4 < length)) {
            char_t a = 0, i = 0, k = 0;
            
            for (k = 171, chars += 4, length -= 4; length; --length, ++chars) {
                i = *chars;
                a = k ^ i;
                k = i;
                decrypted.append(&a, 1);
            }
        }
        return decrypted;
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

    /// ...text
    virtual string_t& cipher_text() const {
        return (string_t&)cipher_text_;
    }
    virtual string_t& plain_text() const {
        return (string_t&)plain_text_;
    }

protected:
    string_t power_on_request_, power_off_request_, power_request_, cipher_text_, plain_text_;
}; /// class maint
typedef maint<> main;

} /// namespace base
} /// namespace kasa
} /// namespace control
} /// namespace home
} /// namespace protocol
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_PROTOCOL_HOME_CONTROL_KASA_BASE_MAIN_HPP
