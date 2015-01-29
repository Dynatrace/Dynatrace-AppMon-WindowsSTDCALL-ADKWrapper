// dtAgentWrapper2.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

#include <dynatrace_adk.h>

#define dtAgentWrapper_EXPORTS
#include "dtAgentWrapper.h"




int __stdcall VB_dTSet(const char *key_value) 
{
	dynatrace_set(key_value);
	return 0;
}

int __stdcall VB_dTInitialize(int argC, char **argV) 
{
	int returnValue = 0;
	returnValue = dynatrace_initialize(&argC, &argV);
	return returnValue;
}

int __stdcall VB_dTUnInitialize() 
{
	dynatrace_uninitialize();
	return 0;
}

int __stdcall VB_dTReInitialize() 
{
	dynatrace_reinitialize();
	return 0;
}

int __stdcall VB_dTAgentLog(const char *message, int level)
{
	dynatrace_agent_log(message, level);
	return 0;
}

int __stdcall VB_dTCaptureBool(int __dynatrace_serial_no__, bool argument) 
{
	dynatrace_capture_bool(__dynatrace_serial_no__, !!(argument));
	return 0;
}

int __stdcall VB_dTCaptureChar(int __dynatrace_serial_no__, char argument) 
{
	dynatrace_capture_char(__dynatrace_serial_no__, (char)(argument));
	return 0;
}

int __stdcall VB_dTCaptureInt16(int __dynatrace_serial_no__, dynatrace_int16_t argument) 
{
	dynatrace_capture_int16(__dynatrace_serial_no__, (dynatrace_int16_t)(argument));
	return 0;
}

int __stdcall VB_dTCaptureInt32(int __dynatrace_serial_no__, dynatrace_int32_t argument) 
{
	dynatrace_capture_int32(__dynatrace_serial_no__, (dynatrace_int32_t)(argument));
	return 0;
}

int __stdcall VB_dTCaptureInt64(int __dynatrace_serial_no__, dynatrace_int64_t argument) 
{
	dynatrace_capture_int64(__dynatrace_serial_no__, (dynatrace_int64_t)(argument));
	return 0;
}

int __stdcall VB_dTCaptureFloat(int __dynatrace_serial_no__, float argument) 
{
	dynatrace_capture_float(__dynatrace_serial_no__, (float)(argument));
	return 0;
}

int __stdcall VB_dTCaptureDouble(int __dynatrace_serial_no__, double argument) 
{
	dynatrace_capture_double(__dynatrace_serial_no__, (double)(argument));
	return 0;
}

int __stdcall VB_dTCaptureString(int __dynatrace_serial_no__, char* argument) 
{
	dynatrace_capture_string(__dynatrace_serial_no__, argument);
	return 0;
}

int __stdcall VB_dTCaptureStringWithCharset(int __dynatrace_serial_no__, const char* argument, int length, dynatrace_uint16_t ccsid) 
{
	dynatrace_capture_string_with_charset(__dynatrace_serial_no__, (const char *)(argument), length, ccsid);
	return 0;
}

int __stdcall VB_dTGetTagAsString(char* buf, int length, size_t size) 
{
	int returnValue = 0;
	returnValue = dynatrace_get_tag_as_string(buf, size);
	return returnValue;
}

int __stdcall VB_dTSetTagFromString(char* tag) 
{
	int returnValue = 0;
	returnValue = dynatrace_set_tag_from_string(tag);
	return returnValue;
}

int __stdcall VB_dTGetTag(unsigned char* buf, int size) 
{
	int returnValue = 0;
	returnValue = dynatrace_get_tag(buf, size);
	return returnValue;
}

int __stdcall VB_dTSetTag(unsigned char* tag) 
{
	int returnValue = 0;
	returnValue = dynatrace_set_tag(tag);
	return returnValue;
}

int __stdcall VB_dTSetCustomTag(const unsigned char* tag, size_t tagSize) 
{
	int returnValue = 0;
	returnValue = dynatrace_set_customtag(tag, tagSize);
	return returnValue;
}

int __stdcall VB_dTGetTagSize() 
{
	int returnValue = 0;
	returnValue = dynatrace_get_tag_size();
	return returnValue;
}

int __stdcall VB_dTLinkClientPurepath(int synchronous, const unsigned char* buffer) 
{
	dynatrace_link_client_purepath(synchronous, buffer);
	return 0;
}

int __stdcall VB_dTLinkClientPurepathByString(int synchronous, const char* buffer) 
{
	dynatrace_link_client_purepath_by_string(synchronous, buffer);
	return 0;
}

int __stdcall VB_dTLinkClientPurepathByCustomTag(int synchronous, const unsigned char *customTag, size_t tagSize, const unsigned char *prevCustomTag, size_t prevTagSize) 
{
	dynatrace_link_client_purepath_by_customtag(synchronous, customTag, tagSize, prevCustomTag, prevTagSize);
	return 0;
}

int __stdcall VB_dTTagToString(const unsigned char* tag, char* buf, size_t size)
{
	int returnValue = 0;
	returnValue = dynatrace_tag_to_string(tag, buf, size);
	return returnValue;
}

int __stdcall VB_dTStringToTag(const char* tag, unsigned char* buf, size_t size)
{
	int returnValue = 0;
	returnValue = dynatrace_string_to_tag(tag, buf, size);
	return returnValue;
}

int __stdcall VB_dTIsTagValid(const unsigned char *buf)
{
	int returnValue = 0;
	returnValue = dynatrace_is_tag_valid(buf);
	return returnValue;
}


int __stdcall VB_dTEnter(int __dynatrace_method_id__, int __dynatrace_serial_no__) 
{
	int returnValue = 0;
	returnValue = dynatrace_enter(__dynatrace_method_id__, __dynatrace_serial_no__);
	return returnValue;
}


int __stdcall VB_dTExit(int __dynatrace_method_id__, int __dynatrace_serial_no__) 
{
	dynatrace_exit(__dynatrace_method_id__, __dynatrace_serial_no__);
	return 0;
}

int __stdcall VB_dTExitException(int method_id, int serial_no, const char *message) 
{
	dynatrace_exit_exception(method_id, serial_no, message);
	return 0;
}

/*int __stdcall VB_dTExceptionThrow(int method_id, const char *message, const char *throwable_class) 
{
	dynatrace_exception_throw(method_id, message, throwable_class);
	return 0;
}*/

int __stdcall VB_dTExceptionThrow(const char *message, const char *throwable_class) 
{
 int method_id = dynatrace_get_method_id(throwable_class, NULL, 0, "Exception", 0);
 dynatrace_exception_throw(method_id, message, throwable_class);
 return 0;
}


int __stdcall VB_dTExceptionThrowWithCharset(int method_id, const char *message, int message_length, unsigned short message_ccsid, const char *throwable_class, int throwable_class_length, unsigned short throwable_class_ccsid) 
{
	dynatrace_exception_throw_with_charset(method_id, message, message_length, message_ccsid, throwable_class, throwable_class_length, throwable_class_ccsid);
	return 0;
}

int __stdcall VB_dTGetMethodID(char* method_name, char* sourcefile_name, int source_line_no, char* api, char is_artificial) 
{
	int returnValue = 0;
	returnValue = dynatrace_get_method_id(method_name, sourcefile_name, source_line_no, api, is_artificial);
	return returnValue;
}

int __stdcall VB_dTGetMethodIDWithCharset(const char *method_name, int method_name_length, unsigned short method_name_ccsid, const char *source_file_name, int source_file_name_length, unsigned short source_file_name_ccsid, int source_line_no, const char *api, int api_length, unsigned short api_ccsid, unsigned char is_artificial)
{
	int returnValue = 0;
	returnValue = dynatrace_get_method_id_with_charset(method_name, method_name_length, method_name_ccsid, source_file_name, source_file_name_length, source_file_name_ccsid, source_line_no, api, api_length, api_ccsid, is_artificial);
	return returnValue;
}


int __stdcall VB_dTGetSerialNo(int __dynatrace_method_id__, int entry_point) 
{
	int returnValue = 0;
	returnValue = dynatrace_get_serial_no(__dynatrace_method_id__, entry_point);
	return returnValue;
}

int __stdcall VB_dTLinkClientPurepathByCustomtag(int synchronous, const unsigned char *customTag, size_t tagSize, const unsigned char *prevCustomTag, size_t prevTagSize)
{
	dynatrace_link_client_purepath_by_customtag(synchronous, customTag, tagSize, prevCustomTag, prevTagSize);
	return 0;
}


int __stdcall VB_dTStartServerPurepath() 
{
	int returnValue = 0;
	dynatrace_start_server_purepath();
	return returnValue;
}

int __stdcall VB_dTEndServerPurepath() 
{
	int returnValue = 0;
	dynatrace_end_server_purepath();
	return returnValue;
}


/*int __stdcall VB_dTCustomLog(int __dynatrace_method_id__, char* message, int level, char* loggername) 
{
	dynatrace_custom_log(__dynatrace_method_id__, message, level, loggername);
	return 0;
}*/

int __stdcall VB_dTCustomLog(int __dynatrace_method_id__, char* message, int level, char* loggername) 
{
	int method_id = dynatrace_get_method_id(loggername, NULL, 0, "Log", 0);
	dynatrace_custom_log(__dynatrace_method_id__, message, level, loggername);
	return 0;
}


int __stdcall VB_dTCustomLogWithCharset(int __dynatrace_method_id__, char* message, int message_length, unsigned short message_ccsid, int level, const char *logger_name, int logger_name_length, unsigned short logger_name_ccsid) 
{
	dynatrace_custom_log_with_charset(__dynatrace_method_id__, message, message_length, message_ccsid, level, logger_name, logger_name_length, logger_name_ccsid);
	return 0;
}

int __stdcall VB_simpleTest() 
{
	int returnValue = 0;
	returnValue = 28;
	return static_cast<int> (returnValue);
}


/** Platform specific defines */
#ifdef _WIN32
  #define dt_proc_t void
  #define dt_thread HANDLE
  #define dt_thread_create(thread, proc, data) \
	thread = (HANDLE)_beginthread(proc, 0, (void*)data)
  #define dt_thread_exit(rc) _endthread()
  #define dt_thread_join(thread) \
	WaitForSingleObject(thread, INFINITE); \
	CloseHandle(thread)
#else
  #define dt_proc_t void*
  #define dt_thread pthread_t
  #define dt_thread_create(thread, proc, data) \
	pthread_create(&thread, NULL, proc, (void*)data)
  #define dt_thread_exit(rc) pthread_exit(rc); return 0
  #define dt_thread_join(thread) pthread_join(thread, NULL);
#endif








