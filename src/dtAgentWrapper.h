
#ifndef DTAGENTWRAPPER_H
#define DTAGENTWRAPPER_H


#ifdef dtAgentWrapper_EXPORTS
#include <cstring>	// This is used for strlen()

/* ---- Initializiation ---- */
int __stdcall VB_dTInitialize(int argC, char **argV);
int __stdcall VB_dTSet(const char *key_value);
int __stdcall VB_dTUnInitialize();
int __stdcall VB_dTReInitialize();

/* ---- Util ---- */
int __stdcall VB_dTAgentLog(const char *message, int level);

/* ---- PurePath ---- */
int __stdcall VB_dTGetMethodID(char* method_name, char* sourcefile_name, int source_line_no, char* api, char is_artificial);
int __stdcall VB_dTGetMethodIDWithCharset(const char *method_name, int method_name_length, unsigned short method_name_ccsid, const char *source_file_name, int source_file_name_length, unsigned short source_file_name_ccsid, int source_line_no, const char *api, int api_length, unsigned short api_ccsid, unsigned char is_artificial);
int __stdcall VB_dTGetSerialNo(int __dynatrace_method_id__, int entry_point);
int __stdcall VB_dTEnter(int __dynatrace_method_id__, int __dynatrace_serial_no__);
int __stdcall VB_dTExit(int __dynatrace_method_id__, int __dynatrace_serial_no__);
int __stdcall VB_dTExitException(int method_id, int serial_no, const char *message);
//int __stdcall VB_dTExceptionThrow(int method_id, const char *message, const char *throwable_class);
int __stdcall VB_dTExceptionThrow(const char *message, const char *throwable_class);
int __stdcall VB_dTExceptionThrowWithCharset(int method_id, const char *message, int message_length, unsigned short message_ccsid, const char *throwable_class, int throwable_class_length, unsigned short throwable_class_ccsid);
int __stdcall VB_dTCustomLog(int __dynatrace_method_id__, char *message, int level, char *loggername);
int __stdcall VB_dTCustomLogWithCharset(int method_id, const char *message, int message_length, unsigned short message_ccsid, int level, const char *logger_name, int logger_name_length, unsigned short logger_name_ccsid);

/* ---- Capturing ---- */
int __stdcall VB_dTCaptureBool(int __dynatrace_serial_no__, dynatrace_int32_t argument);
int __stdcall VB_dTCaptureChar(int __dynatrace_serial_no__, char argument);
int __stdcall VB_dTCaptureInt16(int __dynatrace_serial_no__, dynatrace_int16_t argument); 
int __stdcall VB_dTCaptureInt32(int __dynatrace_serial_no__, dynatrace_int32_t argument);
int __stdcall VB_dTCaptureInt64(int __dynatrace_serial_no__, dynatrace_int64_t argument);
int __stdcall VB_dTCaptureFloat(int __dynatrace_serial_no__, float argument);
int __stdcall VB_dTCaptureDouble(int __dynatrace_serial_no__, double argument);
int __stdcall VB_dTCaptureString(int __dynatrace_serial_no__, const char *argument);
int __stdcall VB_dTCaptureStringWithCharset(int __dynatrace_serial_no__, const char * argument, int length, dynatrace_uint16_t ccsid);

/* ---- Tagging ---- */
int __stdcall VB_dTGetTagAsString(char *buf, size_t size);
int __stdcall VB_dTSetTagFromString(const char *tag);
int __stdcall VB_dTGetTag(unsigned char *buf, size_t size);
int __stdcall VB_dTSetTag(unsigned char *buf);
int __stdcall VB_dTSetCustomTag(const unsigned char *customTag, size_t tagSize);
int __stdcall VB_dTGetTagSize();
int __stdcall VB_dTLinkClientPurepath(int synchronous, const unsigned char *buf);
int __stdcall VB_dTLinkClientPurepathByString(int synchronous, const char* tag);
int __stdcall VB_dTLinkClientPurepathByCustomtag(int synchronous, const unsigned char *customTag, size_t tagSize, const unsigned char *prevCustomTag, size_t prevTagSize);
int __stdcall VB_dTStartServerPurepath();
int __stdcall VB_dTEndServerPurepath();
int __stdcall VB_dTTagToString(const unsigned char* tag, char* buf, size_t size);
int __stdcall VB_dTStringToTag(const char* tag, unsigned char* buf, size_t size);
int __stdcall VB_dTIsTagValid(const unsigned char *buf);


int __stdcall VB_simpleTest();

#endif
#endif


