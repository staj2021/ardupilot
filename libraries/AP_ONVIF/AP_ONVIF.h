/*
 * This file is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This file is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Code by Michael Oborne and Siddharth Bharat Purohit, Cubepilot Pty.
 */
#pragma once

#include <AP_HAL/AP_HAL.h>

#if ENABLE_ONVIF
#include <AP_ONVIF/onvifDeviceBindingProxy.h>
#include <AP_ONVIF/onvifMediaBindingProxy.h>
#include <AP_ONVIF/onvifPTZBindingProxy.h>
#include <plugin/wsseapi-lite.h>
#include <AP_Math/AP_Math.h>

class AP_ONVIF {
public:
    AP_ONVIF();

    /* Do not allow copies */
    AP_ONVIF(const AP_ONVIF &other) = delete;
    AP_ONVIF &operator=(const AP_ONVIF&) = delete;
    
    // Start ONVIF client with username, password and service host url
    bool start(const char *user, const char *pass, const char *httphostname);

    // Turn ONVIF camera to mentioned pan, tilt and zoom, normalised 
    // between limits
    bool set_absolutemove(float pan, float tilt, float zoom);

    // returns pan/tilt command max limit
    Vector2f get_pan_tilt_limit_max() const { return pan_tilt_limit_max; }

    // returns pan/tilt command min limit
    Vector2f get_pan_tilt_limit_min() const { return pan_tilt_limit_min; }

    // get singleton instance
    static AP_ONVIF *get_singleton() { return _singleton; }

private:

    // prepares security header of SOAP message going to be sent immmediately after
    void set_credentials();

    // convert error message from gSOAP lib into human readable string and print
    void report_error();

    // detect onvif server present on the network
    bool probe_onvif_server();

    // Generate Random Nonce value
    void rand_nonce(char *nonce, size_t noncelen);

    Vector2f pan_tilt_limit_min;
    Vector2f pan_tilt_limit_max;
    float pan_norm, tilt_norm, zoom_norm;
    float last_pan_cmd, last_tilt_cmd;

    float zoom_min, zoom_max;
    std::string profile_token;
    struct soap *soap;
    DeviceBindingProxy *proxy_device;
    MediaBindingProxy  *proxy_media;
    PTZBindingProxy    *proxy_ptz;
    static AP_ONVIF *_singleton;
    char* media_endpoint;
    
    std::string username;
    std::string password;
    std::string hostname;
    
    std::string DEVICE_ENDPOINT;
    std::string MEDIA_ENDPOINT;
    std::string PTZ_ENDPOINT;
    bool initialised;
};


 namespace AP {
     AP_ONVIF &onvif();
 };
#endif // #if ENABLE_ONVIF