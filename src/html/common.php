<?php
@header('P3P: CP="NOI CURa ADMa DEVa TAIa OUR DELa BUS IND PHY ONL UNI COM NAV INT DEM PRE"');
error_reporting( E_CORE_ERROR | E_CORE_WARNING | E_COMPILE_ERROR | E_ERROR | E_WARNING | E_PARSE | E_USER_ERROR | E_USER_WARNING );
ini_set( "display_errors", 1 );
// error_reporting(E_ERROR);
if(version_compare(PHP_VERSION, '5.2.17' , '<'))	die(sprintf('PHP 5.2.17 or higher required. Your PHP version is %s', PHP_VERSION));
//==========================================================================================================================
// extract($_GET); 명령으로 인해 page.php?_POST[var1]=data1&_POST[var2]=data2 와 같은 코드가 _POST 변수로 사용되는 것을 막음
//--------------------------------------------------------------------------------------------------------------------------
$ext_arr	= array ('PHP_SELF', '_ENV', '_GET', '_POST', '_FILES', '_SERVER', '_COOKIE', '_SESSION', '_REQUEST', 'HTTP_ENV_VARS', 'HTTP_GET_VARS', 'HTTP_POST_VARS', 'HTTP_POST_FILES', 'HTTP_SERVER_VARS', 'HTTP_COOKIE_VARS', 'HTTP_SESSION_VARS', 'GLOBALS');
$ext_cnt	= count($ext_arr);
for($i=0; $i < $ext_cnt; $i++) {
  if(isset($_GET[$ext_arr[$i]]))  unset($_GET[$ext_arr[$i]]);
  if(isset($_POST[$ext_arr[$i]])) unset($_POST[$ext_arr[$i]]);
}
function path_info() {
  $chroot					        = substr($_SERVER['SCRIPT_FILENAME'], 0, strpos($_SERVER['SCRIPT_FILENAME'], dirname(__FILE__)));
  $result['path']			    = str_replace('\\', '/', $chroot.dirname(__FILE__));
  $server_script_name     = preg_replace('/\/+/', '/', str_replace('\\', '/', $_SERVER['SCRIPT_NAME']));
  $server_script_filename	= preg_replace('/\/+/', '/', str_replace('\\', '/', $_SERVER['SCRIPT_FILENAME']));
  $tilde_remove			      = preg_replace('/^\/\~[^\/]+(.*)$/', '$1', $server_script_name);
  $document_root          = str_replace($tilde_remove, '', $server_script_filename);
  $pattern                = '/.*?' . preg_quote($document_root, '/') . '/i';
  $root                   = preg_replace($pattern, '', $result['path']);
  $port                   = ($_SERVER['SERVER_PORT'] == 80 || $_SERVER['SERVER_PORT'] == 443) ? '' : ':'.$_SERVER['SERVER_PORT'];
  $http                   = 'http' . ((isset($_SERVER['HTTPS']) && $_SERVER['HTTPS']=='on') ? 's' : '') . '://';
  $user                   = str_replace(preg_replace($pattern, '', $server_script_filename), '', $server_script_name);
  $host                   = isset($_SERVER['HTTP_HOST']) ? $_SERVER['HTTP_HOST'] : $_SERVER['SERVER_NAME'];
  if(isset($_SERVER['HTTP_HOST']) && preg_match('/:[0-9]+$/', $host))	$host = preg_replace('/:[0-9]+$/', '', $host);
  $host					          = preg_replace("/[\<\>\'\"\\\'\\\"\%\=\(\)\/\^\*]/", '', $host);
  $result['url']          = $http.$host.$port.$user.$root;
  return $result;
}
$path_info = path_info();
include_once($path_info['path'].'/libs/config.inc');   // 설정 파일
unset($path_info);

// IIS 에서 SERVER_ADDR 서버변수가 없다면
if(!isset($_SERVER['SERVER_ADDR']) )	$_SERVER['SERVER_ADDR'] = isset($_SERVER['LOCAL_ADDR']) ? $_SERVER['LOCAL_ADDR'] : '';
// HTTPS || HTTP 여부
$CH_HTTP = CH_HTTP;
// multi-dimensional array에 사용자지정 함수적용
function array_map_deep($fn, $array) {
  if(is_array($array)) {
    foreach($array as $key => $value) {
      if(is_array($value))	$array[$key] = array_map_deep($fn, $value);
      else					$array[$key] = call_user_func($fn, $value);
    }
  } else {
    $array = call_user_func($fn, $array);
  }
  return $array;
}
// SQL Injection 대응 문자열 필터링
function sql_escape_string($str) { $str = call_user_func('addslashes', $str); return $str; }
//==============================================================================
// SQL Injection 등으로 부터 보호를 위해 sql_escape_string() 적용
//------------------------------------------------------------------------------
// magic_quotes_gpc 에 의한 backslashes 제거
if (function_exists('get_magic_quotes_gpc') && get_magic_quotes_gpc()) {
  $_POST    = array_map_deep('stripslashes',  $_POST);
  $_GET     = array_map_deep('stripslashes',  $_GET);
  $_COOKIE  = array_map_deep('stripslashes',  $_COOKIE);
  $_REQUEST = array_map_deep('stripslashes',  $_REQUEST);
}
// sql_escape_string 적용
$_POST    = array_map_deep(CH_ESCAPE_FUNCTION,  $_POST);
$_GET     = array_map_deep(CH_ESCAPE_FUNCTION,  $_GET);
$_COOKIE  = array_map_deep(CH_ESCAPE_FUNCTION,  $_COOKIE);
$_REQUEST = array_map_deep(CH_ESCAPE_FUNCTION,  $_REQUEST);
//==============================================================================

//====================================================================================================================================================================================
@ini_set("session.use_trans_sid", 0); // PHPSESSID를 자동으로 넘기지 않음	=> session.auto_start = 0 으로 설정 / PHP 5 이상 버전부터 session.use_trans_sid 설정을 ini_set으로 바꿀 수 없음
@ini_set("url_rewriter.tags","");     // 링크에 PHPSESSID가 따라다니는것을 무력화함
// session_save_path("$_SERVER[DOCUMENT_ROOT]/adm/data/session"); // 세션쿠키 저장위치
if (isset($SESSION_CACHE_LIMITER))	@session_cache_limiter($SESSION_CACHE_LIMITER);
else								                @session_cache_limiter("no-cache, must-revalidate");

@ini_set("session.cache_expire", 1440);		// 세션 캐쉬 보관시간 (분)
@ini_set("session.gc_maxlifetime", 86400);	// session data의 garbage collection 존재 기간을 지정 (초)
@ini_set("session.gc_probability", 1);		  // session.gc_probability는 session.gc_divisor와 연계하여 gc(쓰레기 수거) 루틴의 시작 확률을 관리합니다. 기본값은 1입니다. 자세한 내용은 session.gc_divisor를 참고하십시오.
@ini_set("session.gc_divisor", 100);			  // session.gc_divisor는 session.gc_probability와 결합하여 각 세션 초기화 시에 gc(쓰레기 수거) 프로세스를 시작할 확률을 정의합니다. 확률은 gc_probability/gc_divisor를 사용하여 계산합니다. 즉, 1/100은 각 요청시에 GC 프로세스를 시작할 확률이 1%입니다. session.gc_divisor의 기본값은 100입니다.
@session_set_cookie_params(0, "/");
@ini_set("session.cookie_domain", "");

if(!function_exists('session_start_samesite')) {
	function session_start_samesite($options = array()) {
		$res = session_start($options);
		// IE 브라우저 또는 엣지브라우저 또는 IOS 모바일과 http환경에서는 secure; SameSite=None을 설정하지 않습니다.
		if( preg_match('/Edge/i', $_SERVER['HTTP_USER_AGENT']) || preg_match('/(iPhone|iPod|iPad).*AppleWebKit.*Safari/i', $_SERVER['HTTP_USER_AGENT']) || preg_match('~MSIE|Internet Explorer~i', $_SERVER['HTTP_USER_AGENT']) || preg_match('~Trident/7.0(; Touch)?; rv:11.0~',$_SERVER['HTTP_USER_AGENT']) || ! (isset($_SERVER['HTTPS']) && $_SERVER['HTTPS']=='on') ){
			return $res;
		}
		$headers = headers_list();
		krsort($headers);
		foreach ($headers as $header) {
			if (!preg_match('~^Set-Cookie: PHPSESSID=~', $header)) continue;
			$header = preg_replace('~; secure(; HttpOnly)?$~', '', $header) . '; secure; SameSite=None';
			header($header, false);
			break;
		}
		return $res;
	}
}

session_start_samesite();

@extract($_GET);
@extract($_POST);
@extract($_SERVER);
@extract($_ENV);
@extract($_SESSION);
@extract($_COOKIE);
@extract($_REQUEST);
@extract($_FILES);

/******************************************************************************
* DB, Util
******************************************************************************/
include CH_PATH.'/'.CH_DBCONFIG_FILE;
include CH_PATH.'/'.CH_UTILS_FILE;
$util = new Util();
/******************************************************************************/

?>
