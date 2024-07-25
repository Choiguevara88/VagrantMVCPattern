<?php
// 기본 시간대 설정
date_default_timezone_set("Asia/Seoul");
/********************
    경로 상수
********************/
define('CH_DOMAIN', '');
define('CH_HTTPS_DOMAIN', '');

if(isset($_SERVER['HTTPS']) && $_SERVER['HTTPS']=='on') define('CH_HTTP', "https://");
else													                          define('CH_HTTP', "http://");

// 디버깅 상수, 실제 서버운영시 false 로 설정해 주세요.
define('CH_DEBUG', false);
define('CH_DB_ENGINE', '');
define('CH_DB_CHARSET', 'utf8mb4');
define('CH_COOKIE_DOMAIN',  '');
define('CH_DBCONFIG_FILE',  '/libs/dbconfig.inc');
define('CH_UTILS_FILE',     '/libs/utils.inc');
define('CH_ADMIN_DIR',      'adm');
define('CH_BBS_DIR',        'bbs');
define('CH_CSS_DIR',        'css');
define('CH_DATA_DIR',       'data');
define('CH_EXTEND_DIR',     'extend');
define('CH_IMG_DIR',        'img');
define('CH_JS_DIR',         'js');
define('CH_LIB_DIR',        'lib');
define('CH_PLUGIN_DIR',     'plugin');
define('CH_SKIN_DIR',       'skin');
define('CH_EDITOR_DIR',     'editor');
define('CH_MOBILE_DIR',     'm');
define('CH_OKNAME_DIR',     'okname');
define('CH_KCPCERT_DIR',    'kcpcert');
define('CH_LGXPAY_DIR',     'lgxpay');
define('CH_SNS_DIR',        'sns');
define('CH_SYNDI_DIR',      'syndi');
define('CH_PHPMAILER_DIR',  'PHPMailer');
define('CH_SESSION_DIR',    'session');
define('CH_THEME_DIR',      'theme');
define('CH_GROUP_DIR',      'group');
define('CH_CONTENT_DIR',    'content');

// URL 은 브라우저상에서의 경로 (도메인으로 부터의)
if (CH_DOMAIN) {
  define('CH_URL', CH_DOMAIN);
} else {
  if (isset($path_info['url'])) define('CH_URL', $path_info['url']);
  else                          define('CH_URL', '');
}
if (isset($path_info['path']))    define('CH_PATH', $path_info['path']);
else                              define('CH_PATH', '');

define('CH_ADMIN_URL',      CH_URL.'/'.CH_ADMIN_DIR);
define('CH_BBS_URL',        CH_URL.'/'.CH_BBS_DIR);
define('CH_CSS_URL',        CH_URL.'/'.CH_CSS_DIR);
define('CH_DATA_URL',       CH_URL.'/'.CH_DATA_DIR);
define('CH_IMG_URL',        CH_URL.'/'.CH_IMG_DIR);
define('CH_JS_URL',         CH_URL.'/'.CH_JS_DIR);
define('CH_SKIN_URL',       CH_URL.'/'.CH_SKIN_DIR);
define('CH_PLUGIN_URL',     CH_URL.'/'.CH_PLUGIN_DIR);
define('CH_EDITOR_URL',     CH_PLUGIN_URL.'/'.CH_EDITOR_DIR);
define('CH_OKNAME_URL',     CH_PLUGIN_URL.'/'.CH_OKNAME_DIR);
define('CH_KCPCERT_URL',    CH_PLUGIN_URL.'/'.CH_KCPCERT_DIR);
define('CH_LGXPAY_URL',     CH_PLUGIN_URL.'/'.CH_LGXPAY_DIR);
define('CH_SNS_URL',        CH_PLUGIN_URL.'/'.CH_SNS_DIR);
define('CH_SYNDI_URL',      CH_PLUGIN_URL.'/'.CH_SYNDI_DIR);
define('CH_MOBILE_URL',     CH_URL.'/'.CH_MOBILE_DIR);

// PATH 는 서버상에서의 절대경로
define('CH_ADMIN_PATH',     CH_PATH.'/'.CH_ADMIN_DIR);
define('CH_BBS_PATH',       CH_PATH.'/'.CH_BBS_DIR);
define('CH_DATA_PATH',      CH_PATH.'/'.CH_DATA_DIR);
define('CH_EXTEND_PATH',    CH_PATH.'/'.CH_EXTEND_DIR);
define('CH_LIB_PATH',       CH_PATH.'/'.CH_LIB_DIR);
define('CH_PLUGIN_PATH',    CH_PATH.'/'.CH_PLUGIN_DIR);
define('CH_SKIN_PATH',      CH_PATH.'/'.CH_SKIN_DIR);
define('CH_MOBILE_PATH',    CH_PATH.'/'.CH_MOBILE_DIR);
define('CH_SESSION_PATH',   CH_DATA_PATH.'/'.CH_SESSION_DIR);
define('CH_EDITOR_PATH',    CH_PLUGIN_PATH.'/'.CH_EDITOR_DIR);
define('CH_OKNAME_PATH',    CH_PLUGIN_PATH.'/'.CH_OKNAME_DIR);

define('CH_KCPCERT_PATH',   CH_PLUGIN_PATH.'/'.CH_KCPCERT_DIR);
define('CH_LGXPAY_PATH',    CH_PLUGIN_PATH.'/'.CH_LGXPAY_DIR);
define('CH_SNS_PATH',       CH_PLUGIN_PATH.'/'.CH_SNS_DIR);
define('CH_SYNDI_PATH',     CH_PLUGIN_PATH.'/'.CH_SYNDI_DIR);
define('CH_PHPMAILER_PATH', CH_PLUGIN_PATH.'/'.CH_PHPMAILER_DIR);
//==============================================================================


//==============================================================================
/********************
    시간 상수
********************/
// 서버의 시간과 실제 사용하는 시간이 틀린 경우 수정하세요.
// 하루는 86400 초입니다. 1시간은 3600초
// 6시간이 빠른 경우 time() + (3600 * 6);
// 6시간이 느린 경우 time() - (3600 * 6);
define('CH_SERVER_TIME',    time());
define('CH_TIME_YMDHIS',    date('Y-m-d H:i:s', CH_SERVER_TIME));
define('CH_TIME_YMD',       substr(CH_TIME_YMDHIS, 0, 10));
define('CH_TIME_HIS',       substr(CH_TIME_YMDHIS, 11, 8));
// 입력값 검사 상수 (숫자를 변경하시면 안됩니다.)
define('CH_ALPHAUPPER',      1); // 영대문자
define('CH_ALPHALOWER',      2); // 영소문자
define('CH_ALPHABETIC',      4); // 영대,소문자
define('CH_NUMERIC',         8); // 숫자
define('CH_HANGUL',         16); // 한글
define('CH_SPACE',          32); // 공백
define('CH_SPECIAL',        64); // 특수문자
// 퍼미션
define('CH_DIR_PERMISSION',  0757); // 디렉토리 생성시 퍼미션
define('CH_FILE_PERMISSION', 0644); // 파일 생성시 퍼미션
// 모바일 인지 결정 $_SERVER['HTTP_USER_AGENT']
define('CH_MOBILE_AGENT',   'phone|samsung|lgtel|mobile|[^A]skt|nokia|blackberry|BB10|android|sony');
// SMTP
// lib/mailer.lib.php 에서 사용
define('CH_SMTP',      '127.0.0.1');
define('CH_SMTP_PORT', '25');

/********************
    기타 상수
********************/
// Kakao REST API 키값
define('CH_KAKAO_REST_API_KEY', 'bda56772a3cabf981287d7d8d56e0d6f');
// 암호화 해시키
define('CH_ENCRYPT_HASH_KEY', 'vd0qwdkgo2kr2');
// 업로드 금지 파일
define('CH_FILTER_EXTENSION', '/php|htm|html|inc|htm|shtm|ztx|dot|cgi|pl|phtm|ph|exe/');
// // SQL 에러를 표시할 것인지 지정
// // 에러를 표시하려면 TRUE 로 변경
// define('CH_DISPLAY_SQL_ERROR', FALSE);
// escape string 처리 함수 지정
// addslashes 로 변경 가능
define('CH_ESCAPE_FUNCTION', 'sql_escape_string');
// sql_escape_string 함수에서 사용될 패턴
// // define('CH_ESCAPE_PATTERN',  '/(and|or).*(union|select|insert|update|delete|from|where|limit|create|drop).*/i');
// // define('CH_ESCAPE_REPLACE',  '');
// 썸네일 jpg Quality 설정
// // define('CH_THUMB_JPG_QUALITY', 90);
// // 썸네일 png Compress 설정
// define('CH_THUMB_PNG_COMPRESS', 5);
// // 모바일 기기에서 DHTML 에디터 사용여부를 설정합니다.
// define('CH_IS_MOBILE_DHTML_USE', false);
// // MySQLi 사용여부를 설정합니다.
// define('CH_MYSQLI_USE', true);
// // Browscap 사용여부를 설정합니다.
// define('CH_BROWSCAP_USE', true);
// // 접속자 기록 때 Browscap 사용여부를 설정합니다.
// define('CH_VISIT_BROWSCAP_USE', false);

if(isset($_SERVER['HTTPS']) && $_SERVER['HTTPS']=='on') {   // https 통신일때 daum 주소 js
  define('CH_POSTCODE_JS', '<script src="https://spi.maps.daum.net/imap/map_js_init/postcode.v2.js"></script>');
} else {                                                    // http 통신일때 daum 주소 js
  define('CH_POSTCODE_JS', '<script src="http://dmaps.daum.net/map_js_init/postcode.v2.js"></script>');
}
