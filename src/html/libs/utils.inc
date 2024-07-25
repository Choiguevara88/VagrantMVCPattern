<?
  class Util {
    // 문자열 끊기 (이상의 길이일때는 ... 로 표시)
    function cut_str($msg, $cut_size=30, $suffix='...'){
    	$pointtmp = $this->php_fn_utf8_substr($msg,0,$cut_size);
    	$msg_size = $this->php_fn_utf8_strlen($msg);
    	if($msg_size > $cut_size)  $pointtmp .= $suffix;
    	return $pointtmp;
    }
    // 문자열 아스타로 치환하기
    function cut_str_ast($msg, $cut_size=0) {
    	$strlen	= $this->php_fn_utf8_strlen($msg);
    	$ast	= "";
    	for($i=0; $i<($strlen-$cut_size); $i++)  { $ast .= "*"; }
    	return $this->php_fn_utf8_substr($msg, 0, $cut_size).$ast;
    }
    //utf8 문자열의 길이를 구한다.
    function php_fn_utf8_strlen($str){
    	return count($this->php_fn_utf8_to_array($str));
    }
    //utf 8문자열을 잘라낸다.
    function php_fn_utf8_substr($str,$start,$length=NULL){
    	return implode('',array_slice($this->php_fn_utf8_to_array($str),$start,$length));
    }
    // UTF-8 문자열 자르기
    function php_fn_utf8_to_array($str){
    	$re_arr = array(); $re_icount = 0;
    	for($i=0,$m=strlen($str);$i<$m;$i++){
    		$ch = sprintf('%08b',ord($str{$i}));
    		if(strpos($ch,'11110')===0)     {$re_arr[$re_icount++]=substr($str,$i,4);$i+=3;}
    		else if(strpos($ch,'1110')===0) {$re_arr[$re_icount++]=substr($str,$i,3);$i+=2;}
    		else if(strpos($ch,'110')===0)  {$re_arr[$re_icount++]=substr($str,$i,2);$i+=1;}
    		else if(strpos($ch,'0')===0)    {$re_arr[$re_icount++]=substr($str,$i,1);}
    	}
      return $re_arr;
    }
    // 문자열 Encoding 변환
    function iconv_utf8($str)	  { return iconv('euc-kr', 'utf-8', $str); }
    function iconv_euckr($str)	{ return iconv('utf-8', 'euc-kr', $str); }
    // 모바일 접속체크
    function mobile_check() {
      return preg_match(CH_MOBILE_AGENT, $_SERVER['HTTP_USER_AGENT']);
    }
    // 랜덤한 10자리 정수를 리턴
    function get_rand_number($len=10) {
      $len = abs((int)$len);
      if      ($len < 1) $len = 1;
      else if ($len > 10) $len = 10;
      return rand(pow(10, $len - 1), (pow(10, $len) - 1));
    }
    // 랜덤한 10자리 영대문자를 리턴
    function get_rand_char($loops=10) {
      $loops        = abs((int)$loops);
      $return_code  = "";
      $code_char    = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    	while ($loops--) {
    		$return_code .= $code_char{rand()%strlen($code_char)};
    	}
    	return $return_code;
    }
    // 랜덤한 10자리 숫자+영대문자를 리턴
    function get_rand_string($loops=10) {
      $loops        = abs((int)$loops);
      $characters  = "0123456789";
      $characters .= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
      $string_generated = "";
      while ($loops--) { $string_generated .= $characters[mt_rand(0, strlen($characters) - 1)]; }
      return $string_generated;
    }
    // 경고창 출력
    function alert($msg, $go_url=""){
      echo "<meta http-equiv='Content-Type' c&#111;&#110;tent='text/html; charset=utf-8'>";
      if($go_url == "") echo "<script>alert(\"$msg\");history.go(-1);</script>";
      else              echo "<script>alert(\"$msg\");document.location=\"$go_url\";</script>";
    }
    // 경고창 출력
    function alertClose($msg, $oppener=false){
      echo "<meta http-equiv='Content-Type' c&#111;&#110;tent='text/html; charset=utf-8'>";
      if($oppener)  echo "<script>alert(\"$msg\");opener.location.reload();self.close();</script>";
      else          echo "<script>alert(\"$msg\");self.close();</script>";
    }
    // 완료 페이지 출력
    function complete($com_msg="완료되었습니다.", $go_url="") {
    	include __DIR__."/../application/views/inc/complete.inc";
    }
    // 변수 또는 배열의 이름과 값을 얻어냄. print_r() 함수의 변형
    function print_r($var) {
      ob_start();
      print_r($var);
      $str = ob_get_contents();
      ob_end_clean();
      $str = str_replace(" ", "&nbsp;", $str);
      echo nl2br("<span style='font-family:Tahoma, 굴림; font-size:9pt;'>$str</span>");
    }
    // 파일 확장자 체크
    function file_check($filename) {
    	$fext		= pathinfo($de_img['name'], PATHINFO_EXTENSION);
    	$fext		= strtolower($fext);
    	//업로드 금지 확장자 체크
    	if(preg_match(CH_FILTER_EXTENSION, $fext)) return false;
      else                                       return true;
    }
    // 파일의 용량을 구한다.
    function get_filesize($size) {
      if ($size >= 1048576)   $size = number_format($size/1048576, 1) . "M";
      else if ($size >= 1024) $size = number_format($size/1024, 1) . "K";
      else                    $size = number_format($size, 0) . "byte";
      return $size;
    }
    // 특수문자 제거
    function clean_special_char($stx) {
      $stx_pattern = array();
      $stx_pattern[] = '#\.*/+#';
      $stx_pattern[] = '#\\\*#';
      $stx_pattern[] = '#\.{2,}#';
      $stx_pattern[] = '#[/\'\"%=*\#\(\)\|\+\&\!\$~\{\}\[\]`;:\?\^\,]+#';
      $stx_replace = array();
      $stx_replace[] = '';
      $stx_replace[] = '';
      $stx_replace[] = '.';
      $stx_replace[] = '';
      $stx = preg_replace($stx_pattern, $stx_replace, $stx);
      return $stx;
    }
    // XSS 관련 태그 제거
    function clean_xss_tags($str, $check_entities=0, $is_remove_tags=0, $cur_str_len=0){
      if($is_remove_tags) $str = strip_tags($str);
      if($cur_str_len)    $str = cut_str($str, $cur_str_len, '');

      $str_len = strlen($str);
      $i = 0;
      while($i <= $str_len){
        $result = preg_replace('#</*(?:applet|b(?:ase|gsound|link)|embed|frame(?:set)?|i(?:frame|layer)|l(?:ayer|ink)|meta|object|s(?:cript|tyle)|title|xml)[^>]*+>#i', '', $str);
        if($check_entities) $result = str_replace(array('&colon;', '&lpar;', '&rpar;', '&NewLine;', '&Tab;'), '', $result);
        $result = preg_replace('#([^\p{L}]|^)(?:javascript|jar|applescript|vbscript|vbs|wscript|jscript|behavior|mocha|livescript|view-source)\s*:(?:.*?([/\\\;()\'">]|$))#ius', '$1$2', $result);
        if((string)$result === (string)$str) break;
        $str = $result;
        $i++;
      }
      return $str;
    }
    // XSS 어트리뷰트 태그 제거
    function clean_xss_attributes($str) {
      $xss_attributes_string = 'onAbort|onActivate|onAttribute|onAfterPrint|onAfterScriptExecute|onAfterUpdate|onAnimationCancel|onAnimationEnd|onAnimationIteration|onAnimationStart|onAriaRequest|onAutoComplete|onAutoCompleteError|onAuxClick|onBeforeActivate|onBeforeCopy|onBeforeCut|onBeforeDeactivate|onBeforeEditFocus|onBeforePaste|onBeforePrint|onBeforeScriptExecute|onBeforeUnload|onBeforeUpdate|onBegin|onBlur|onBounce|onCancel|onCanPlay|onCanPlayThrough|onCellChange|onChange|onClick|onClose|onCommand|onCompassNeedsCalibration|onContextMenu|onControlSelect|onCopy|onCueChange|onCut|onDataAvailable|onDataSetChanged|onDataSetComplete|onDblClick|onDeactivate|onDeviceLight|onDeviceMotion|onDeviceOrientation|onDeviceProximity|onDrag|onDragDrop|onDragEnd|onDragEnter|onDragLeave|onDragOver|onDragStart|onDrop|onDurationChange|onEmptied|onEnd|onEnded|onError|onErrorUpdate|onExit|onFilterChange|onFinish|onFocus|onFocusIn|onFocusOut|onFormChange|onFormInput|onFullScreenChange|onFullScreenError|onGotPointerCapture|onHashChange|onHelp|onInput|onInvalid|onKeyDown|onKeyPress|onKeyUp|onLanguageChange|onLayoutComplete|onLoad|onLoadedData|onLoadedMetaData|onLoadStart|onLoseCapture|onLostPointerCapture|onMediaComplete|onMediaError|onMessage|onMouseDown|onMouseEnter|onMouseLeave|onMouseMove|onMouseOut|onMouseOver|onMouseUp|onMouseWheel|onMove|onMoveEnd|onMoveStart|onMozFullScreenChange|onMozFullScreenError|onMozPointerLockChange|onMozPointerLockError|onMsContentZoom|onMsFullScreenChange|onMsFullScreenError|onMsGestureChange|onMsGestureDoubleTap|onMsGestureEnd|onMsGestureHold|onMsGestureStart|onMsGestureTap|onMsGotPointerCapture|onMsInertiaStart|onMsLostPointerCapture|onMsManipulationStateChanged|onMsPointerCancel|onMsPointerDown|onMsPointerEnter|onMsPointerLeave|onMsPointerMove|onMsPointerOut|onMsPointerOver|onMsPointerUp|onMsSiteModeJumpListItemRemoved|onMsThumbnailClick|onOffline|onOnline|onOutOfSync|onPage|onPageHide|onPageShow|onPaste|onPause|onPlay|onPlaying|onPointerCancel|onPointerDown|onPointerEnter|onPointerLeave|onPointerLockChange|onPointerLockError|onPointerMove|onPointerOut|onPointerOver|onPointerUp|onPopState|onProgress|onPropertyChange|onqt_error|onRateChange|onReadyStateChange|onReceived|onRepeat|onReset|onResize|onResizeEnd|onResizeStart|onResume|onReverse|onRowDelete|onRowEnter|onRowExit|onRowInserted|onRowsDelete|onRowsEnter|onRowsExit|onRowsInserted|onScroll|onSearch|onSeek|onSeeked|onSeeking|onSelect|onSelectionChange|onSelectStart|onStalled|onStorage|onStorageCommit|onStart|onStop|onShow|onSyncRestored|onSubmit|onSuspend|onSynchRestored|onTimeError|onTimeUpdate|onTimer|onTrackChange|onTransitionEnd|onToggle|onTouchCancel|onTouchEnd|onTouchLeave|onTouchMove|onTouchStart|onTransitionCancel|onTransitionEnd|onUnload|onURLFlip|onUserProximity|onVolumeChange|onWaiting|onWebKitAnimationEnd|onWebKitAnimationIteration|onWebKitAnimationStart|onWebKitFullScreenChange|onWebKitFullScreenError|onWebKitTransitionEnd|onWheel';

      do {
        $count = $temp_count = 0;
        $str = preg_replace('/(.*)(?:' . $xss_attributes_string . ')(?:\s*=\s*)(?:\'(?:.*?)\'|"(?:.*?)")(.*)/ius', '$1-$2-$3-$4', $str, -1, $temp_count);
        $count += $temp_count;
        $str = preg_replace('/(.*)(?:' . $xss_attributes_string . ')\s*=\s*(?:[^\s>]*)(.*)/ius','$1$2',$str,-1,$temp_count);
        $count += $temp_count;
      } while ($count);

      return $str;
    }
    // 이메일 주소 추출
    function get_email_address($email) {
      preg_match("/[0-9a-z._-]+@[a-z0-9._-]{4,}/i", $email, $matches);
      return isset($matches[0]) ? $matches[0] : '';
    }
    // 파일명에서 특수문자 제거
    function get_safe_filename($name) {
      $pattern = '/["\'<>=#&!%\\\\(\)\*\+\?]/';
      $name = preg_replace($pattern, '', $name);
      return $name;
    }
    // 로그를 파일에 쓴다
    function write_log($file, $log) {
      $fp = fopen($file, "a+");
      ob_start();
      print_r($log);
      $msg = ob_get_contents();
      ob_end_clean();
      fwrite($fp, $msg);
      fclose($fp);
    }
    // 유니크 쿠키생성
    function make_uniq_cookie(){
    	//쿠키가 생성되어있지 않으면 고유값 생성해서 만들기
    	if(empty($_COOKIE["uniq_id"])) {
    		$basketid = md5($REMOTE_ADDR.time());
    		setcookie("uniq_id",$basketid,time()+3600*30*24,"/"); //쿠키시간 지정
    		return $basketid;
    	}
    }

    function xml_to_array($content, $get_attributes = 1, $priority = 'tag') {
        $contents = "";
        if (!function_exists('xml_parser_create')) { return array (); }
        $parser   = xml_parser_create('');
        $url      = $content;
        $url_list = parse_url($url);
        // URL
        if($url_list['host'] != "") {
    			if(!($socket = fsockopen($url_list['host'], 80, $errno, $errstr, 5))) { // URL에 소켓 연결
    				echo " $errno : $errstr "; exit;
    			}
    			$header = "GET {$url} HTTP/1.0\n\n";
    			fwrite($socket, $header);
    			$data = '';
    			while(!feof($socket)) { $data .= fgets($socket); }
    			fclose($socket);
    			$data = explode("\r\n\r\n", $data, 2);
    			$contents = $data[1];
    		// XML Data
    		} else {
    			$contents=$content;
    		}
        //xml_parser_set_option($parser, XML_OPTION_TARGET_ENCODING, "UTF-8"); //xml  파서에서 옵션설정 인코딩
        xml_parser_set_option($parser, XML_OPTION_CASE_FOLDING, 0); ///대문자로변경
        xml_parser_set_option($parser, XML_OPTION_SKIP_WHITE, 1); //공백값무시
        xml_parse_into_struct($parser, trim($contents), $xml_values); //읽어들인 xml를 이용해 배열에 xml 구조를 담는다
        xml_parser_free($parser); //파서해제

        if (!$xml_values) return; //Hmm...
        $xml_array = array ();
        $parents = array ();
        $opened_tags = array ();
        $arr = array ();
        $current = & $xml_array;
        $repeated_tag_index = array ();

        foreach ($xml_values as $data) {
            unset ($attributes, $value);
            extract($data);
            $result = array ();
            $attributes_data = array ();
            if (isset ($value))
            {
                if ($priority == 'tag')
                    $result = $value;
                else
                    $result['value'] = $value;
            }
            if (isset ($attributes) and $get_attributes)
            {
                foreach ($attributes as $attr => $val)
                {
                    if ($priority == 'tag')
                        $attributes_data[$attr] = $val;
                    else
                        $result['attr'][$attr] = $val; //Set all the attributes in a array called 'attr'
                }
            }
            if ($type == "open")
            {
                $parent[$level -1] = & $current;
                if (!is_array($current) or (!in_array($tag, array_keys($current))))
                {
                    $current[$tag] = $result;
                    if ($attributes_data)
                        $current[$tag . '_attr'] = $attributes_data;
                    $repeated_tag_index[$tag . '_' . $level] = 1;
                    $current = & $current[$tag];
                }
                else
                {
                    if (isset ($current[$tag][0]))
                    {
                        $current[$tag][$repeated_tag_index[$tag . '_' . $level]] = $result;
                        $repeated_tag_index[$tag . '_' . $level]++;
                    }
                    else
                    {
                        $current[$tag] = array (
                            $current[$tag],
                            $result
                        );
                        $repeated_tag_index[$tag . '_' . $level] = 2;
                        if (isset ($current[$tag . '_attr']))
                        {
                            $current[$tag]['0_attr'] = $current[$tag . '_attr'];
                            unset ($current[$tag . '_attr']);
                        }
                    }
                    $last_item_index = $repeated_tag_index[$tag . '_' . $level] - 1;
                    $current = & $current[$tag][$last_item_index];
                }
            }
            elseif ($type == "complete")
            {
                if (!isset ($current[$tag]))
                {
                    $current[$tag] = $result;
                    $repeated_tag_index[$tag . '_' . $level] = 1;
                    if ($priority == 'tag' and $attributes_data)
                        $current[$tag . '_attr'] = $attributes_data;
                }
                else
                {
                    if (isset ($current[$tag][0]) and is_array($current[$tag]))
                    {
                        $current[$tag][$repeated_tag_index[$tag . '_' . $level]] = $result;
                        if ($priority == 'tag' and $get_attributes and $attributes_data)
                        {
                            $current[$tag][$repeated_tag_index[$tag . '_' . $level] . '_attr'] = $attributes_data;
                        }
                        $repeated_tag_index[$tag . '_' . $level]++;
                    }
                    else
                    {
                        $current[$tag] = array (
                            $current[$tag],
                            $result
                        );
                        $repeated_tag_index[$tag . '_' . $level] = 1;
                        if ($priority == 'tag' and $get_attributes)
                        {
                            if (isset ($current[$tag . '_attr']))
                            {
                                $current[$tag]['0_attr'] = $current[$tag . '_attr'];
                                unset ($current[$tag . '_attr']);
                            }
                            if ($attributes_data)
                            {
                                $current[$tag][$repeated_tag_index[$tag . '_' . $level] . '_attr'] = $attributes_data;
                            }
                        }
                        $repeated_tag_index[$tag . '_' . $level]++; //0 and 1 index is already taken
                    }
                }
            }
            elseif ($type == 'close')
            {
                $current = & $parent[$level -1];
            }
        }
      return ($xml_array);
    }
    // 메타태그를 이용한 URL 이동 header("location:URL") 을 대체
    function location_replace($url) {
      $url = str_replace("&amp;", "&", $url);
      //echo "<script> location.replace('$url'); </script>";
      if (!headers_sent())
        header('Location: '.$url);
      else {
        echo '<script>';
        echo 'location.replace("'.$url.'");';
        echo '</script>';
        echo '<noscript>';
        echo '<meta http-equiv="refresh" content="0;url='.$url.'" />';
        echo '</noscript>';
      }
      exit;
    }
    // 페이지 리스트 출력
    function print_pagelist_span($page, $list_amount, $page_count, $param, $page_type = ""){

      global $ptype;

      if($param != "")			$param = "&".$param;

      if(($page%$list_amount) == 0)	$tmp = $page-1;
      else							$tmp = $page;

      $spage	= floor($tmp/$list_amount)*$list_amount+1;

      if($spage <= 1)	$ppage = 1;
      else			$ppage = $spage - $list_amount;

      $epage = $spage+$list_amount-1;

      if($epage >= $page_count) {
      	$epage = $page_count;
      	$npage = $page_count;
      } else {
      	$npage = $epage + 1;
      }

      if(!empty($page_type))  $page_name = strtolower($page_type)."page";
      else					          $page_name = "page";

      if($epage > 0) {
      	echo "<div class=\"pagination\">";
      	echo "	<span class=\"page_btn prev_group\">";
      	echo "		<a href=\"".$PHP_SELF."?ptype=".$ptype."&".$page_name."=1".$param."\" class=\"prev\" title=\"처음 페이지로\"><i class='bx bx-chevrons-left' ></i></a>";
      	echo "		<a href=\"".$PHP_SELF."?ptype=".$ptype."&".$page_name."=".$ppage.$param."\" class=\"prev_one\" rel=\"prev\"><i class='bx bx-chevron-left' ></i></a>";
      	echo "	</span>";
      	echo "	<span class=\"page_wrap\">";
         for($spage; $spage <= $epage; $spage++) {
            if($page == $spage)	echo "<strong>".$spage."</strong>";
            else					echo "<a href=\"".$PHP_SELF."?ptype=".$ptype."&".$page_name."=".$spage.$param."\">".$spage."</a>";
         }
      	echo "	</span>";
      	echo "	<span class=\"page_btn next_group\">";
      	echo "		<a href=\"".$PHP_SELF."?ptype=".$ptype."&".$page_name."=".$npage.$param."\" class=\"next\" rel=\"next\"><i class='bx bx-chevron-right' ></i></a>";
      	echo "		<a href=\"".$PHP_SELF."?ptype=".$ptype."&".$page_name."=".$page_count.$param."\" class=\"next_one\" title=\"끝 페이지로\"><i class='bx bx-chevrons-right' ></i></a>";
      	echo "	</span>";
      	echo "</div>";
      }
    }

    // 객체를 배열로
    function object_to_array($d) {
    	if (is_object($d))	$d = get_object_vars($d);
    	if (is_array($d))  return array_map(__FUNCTION__, $d);
    	else				       return $d;
    }
    // 배열을 객체로
    function array_to_object($d) {
    	if(is_array($d))	return (object) array_map(__FUNCTION__, $d);
    	else				return $d;
    }
    // 휴대폰번호의 숫자만 취한 후 중간에 하이픈(-)을 넣는다.
    function hyphen_hp_number($hp) {
      $hp = preg_replace("/[^0-9]/", "", $hp);
      return preg_replace("/([0-9]{3})([0-9]{3,4})([0-9]{4})$/", "\\1-\\2-\\3", $hp);
    }
    // 휴대폰번호 중간자리 번호를 아스타로 치환
    function hp_astar($phone) {
      $phone   = $this->hyphen_hp_number($phone);
      $list    = explode("-", $phone);
      $ast     = "";
      for($i=0; $i<strlen($list[1]); $i++) {
      	$ast .="*";
      }
      return $list[0]."-".$ast."-".$list[2];
    }
    // 값이 비었을 때 - 표시
    function null_dash($val,$suffix="") {
      return ($val == "" || $val == "0") ? "-" : $val.$suffix;
    }
    // 주소 좌표값 받아오는 카카오맵API
    function kakao_location_API($address) {

      $headers	= array('Authorization: KakaoAK '.CH_KAKAO_REST_API_KEY);
      $post_query	= 'query='.urlencode($address);
      $host		= 'https://dapi.kakao.com/v2/local/search/address.json?'.$post_query;
      $ch			= curl_init();
      curl_setopt($ch, CURLOPT_HTTPHEADER, $headers);
      curl_setopt($ch, CURLOPT_URL, $host);
      curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, true);
      curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);

      $json		= curl_exec($ch);
      $json		= json_decode($json);

      curl_close ($ch);

      $latitude   = $json->documents[0]->address->y; // latitude  위도
      $longitude  = $json->documents[0]->address->x; // longitude 경도

      return array($latitude, $longitude);
    }
    // 지금으로부터 얼마 전인지 (현재는 일주일까지)
    function calc_datetime($_date, $_type = 0) {
    	$today = date('Y-m-d');
    	// 당일
    	if(strpos($_date, $today) !== false) {
    		$diff   = strtotime(date('Y-m-d H:i:s')) - strtotime($_date);
    		$hours  = floor($diff / 3600);
    		$diff	  = $diff-($hours * 3600);
    		$min		= floor($diff / 60);
    		if($hours == 0) {
    			$show_date = $min == 0 ? "방금 전" : $min."분 전";
    		} else {
    			$show_date = $hours."시간 전";
    		}
    	// 당일이 아닌 경우
    	} else {
    		$start_date	= new DateTime(substr($_date,0,10));
    		$end_date		= new DateTime(date('Y-m-d'));
    		$date_diff	= $start_date->diff($end_date);
    		$diff_days	= $date_diff->days;
    		if($diff_days < 14) {
    				switch($diff_days) {
    					case 1 : $show_date = "어제";		break;
    					case 2 : $show_date = "그저께";	break;
    					case 3 : $show_date = "3일 전";	break;
    					case 4 : $show_date = "4일 전"; break;
    					case 5 : $show_date = "5일 전"; break;
    					case 6 : $show_date = "6일 전"; break;
    					default : $show_date = "지난 주"; break;
    				}
    		} else {
    			if($_type)	$show_date = str_replace("-",".",substr($_date,2,14));
    			else 				$show_date = str_replace("-",".",substr($_date,2,8));
    		}
    	}
    	return $show_date;
    }
    // 무슨 요일인지
    function day_of_week($date) {
    	$week_num	= date("w", strtotime($date));
    	switch($week_num) {
    		case "0"	: $week_str = "일"; break;
    		case "1"	: $week_str = "월"; break;
    		case "2"	: $week_str = "화"; break;
    		case "3"	: $week_str = "수"; break;
    		case "4"	: $week_str = "목"; break;
    		case "5"	: $week_str = "금"; break;
    		case "6"	: $week_str = "토"; break;
    	}
    	return $week_str;
    }
    // 며칠 차이가 나는지
    function calc_date($sdate, $edate="") {

    	if($edate == "")	$edate = date('Y-m-d');

    	$start_date	= new DateTime(substr($sdate,0,10));
    	$end_date		= new DateTime(substr($edate,0,10));
    	$date_diff	= $start_date->diff($end_date);
    	$diff_days	= $date_diff->days;

    	return $diff_days;
    }
    // 해당하는 날짜가 그달의 몇주차인지 계산
    function week_num_of_month($timestamp) {
      $w = date('w', mktime(0,0,0, date('n',$timestamp), 1, date('Y',$timestamp)));
      return ceil(($w + date('j',$timestamp) -1) / 7);
    }
    // 나이 계산
    function calc_age($birth) {
      $now    = date('Ymd');
      $birthD = date("Ymd", strtotime($birth));
      $age    = floor(($now - $birthD) / 10000);
    	return $age;
    }
    // 시간구하기
    function time_format($date_str) {
  		$result = "";
  		$hour   = date("H", strtotime($date_str));
  		$min    = date("i", strtotime($date_str));
  		if ($hour > 12) {
				$hour = $hour - 12;
				$result = "오후 " . $hour. ":". $min;
  		} else {
				$result = "오전 " . $hour. ":". $min;
  		}
  		return $result;
    }
    //JSON 타입 리턴
    //$result 성공: true, 실패: false  $msg 전달 문구  $data 배열 데이터
    function result_data($result, $msg = '', $data = array()) {
    	$arr = array();
    	$arr['result']	= $result;
    	$arr['msg'] 		= $msg;
    	$arr['data']		= $data;
    	$obj = json_encode($arr, JSON_UNESCAPED_UNICODE);
    	return $obj;
    }
    // 알리고 SMS 발송모듈
    function aligo_sms($phone, $send_msg) {
    	/****************** 인증정보 시작 ******************/
    	$sms_url = "https://apis.aligo.in/send/"; 							// 전송요청 URL
    	$sms['user_id'] = "";																		// SMS 아이디
    	$sms['key'] 		= "";																		// 인증키
    	/****************** 인증정보 끝 ********************/
    	/****************** 전송정보 설정시작 ****************/
    	$sms['msg'] 				= stripslashes($send_msg); 				// 메세지 내용 : euc-kr로 치환이 가능한 문자열만 사용하실 수 있습니다. (이모지 사용불가능)
    	$sms['receiver'] 		= str_replace("-", "", $phone); 	// 수신번호
    	$sms['destination'] = "";
    	$sms['sender'] 			= ""; // "01086866114"; 발송표시 번호
    	$sms['testmode_yn'] = 'N';
    	$sms['msg_type'] 		= "SMS";
    	/****************** 전송정보 설정끝 ***************/
    	$host_info	= explode("/", $sms_url);
    	$port				= $host_info[0] == 'https:' ? 443 : 80;
    	$oCurl	= curl_init();
    	curl_setopt($oCurl, CURLOPT_PORT, $port);
    	curl_setopt($oCurl, CURLOPT_URL, $sms_url);
    	curl_setopt($oCurl, CURLOPT_POST, 1);
    	curl_setopt($oCurl, CURLOPT_RETURNTRANSFER, 1);
    	curl_setopt($oCurl, CURLOPT_POSTFIELDS, $sms);
    	curl_setopt($oCurl, CURLOPT_SSL_VERIFYPEER, FALSE);
    	$ret	= curl_exec($oCurl);
    	curl_close($oCurl);
    	$retArr	= json_decode($ret);	// 결과배열
    	return $retArr;
    	/**** Response 항목 안내 ****
    	// result_code 	: 전송성공유무 (성공:1 / 실패: -100 부터 -999)
    	// message 			: success (성공시) / reserved (예약성공시) / 그외 (실패상세사유가 포함됩니다)
    	// msg_id 			: 메세지 고유ID = 고유값을 반드시 기록해 놓으셔야 sms_list API를 통해 전화번호별 성공/실패 유무를 확인하실 수 있습니다
    	// error_cnt 		: 에러갯수 = receiver 에 포함된 전화번호중 문자전송이 실패한 갯수
    	// success_cnt 	: 성공갯수 = 이동통신사에 전송요청된 갯수
    	// msg_type 		: 전송된 메세지 타입 = SMS / LMS / MMS (보내신 타입과 다른경우 로그로 기록하여 확인하셔야 합니다)
    	/**** Response 예문 끝 ****/
    }
    // 보내고 SMS
    function bonago_sms($mtype, $name, $phone, $msg, $callback="01021657321", $contents="", $reserve="",$reserve_time="",$etc1="",$etc2="") {

    	$msg	= urlencode($msg);

    	$host	= "www.sendgo.co.kr";

    	$id		= "khict0107";	// 보내고 아이디 입력
    	$pass	= "sp1417@!";		// 보내고 비밀번호 입력;

    	$phone	= str_replace("-","",$phone);

    	$param	 = "remote_id={$id}";
    	$param	.= "&remote_pass={$pass}";
    	$param	.= "&remote_reserve={$reserve}";
    	$param	.= "&remote_reservetime={$reserve_time}";
    	$param	.= "&remote_name={$name}";
    	$param	.= "&remote_phone={$phone}";
    	$param	.= "&remote_callback={$callback}";
    	$param	.= "&remote_msg={$msg}";
    	$param	.= "&remote_content={$contents}";
    	$param	.= "&remote_etc1={$etc1}";
    	$param	.= "&remote_etc2={$etc2}";

    	if($mtype == "lms")	$path	= "/Remote/RemoteMms.html";
    	else 								$path	= "/Remote/RemoteSms.html";

    	$fp		= @fsockopen($host,80,$errno,$errstr,30);
    	$return	= "";

    	if(!$fp) {
    		return "{$errstr}({$errno})";
    	} else {
    		fputs($fp, "POST {$path} HTTP/1.1\r\n");
    		fputs($fp, "Host: {$host}\r\n");
    		fputs($fp, "Content-type: application/x-www-form-urlencoded\r\n");
    		fputs($fp, "Content-length: ".strlen($param)."\r\n");
    		fputs($fp, "Connection: close\r\n\r\n");
    		fputs($fp, $param."\r\n\r\n");

    		while(!feof($fp)) {
    			$return .= fgets($fp,4096);
    		};
    	}

    	fclose($fp);

    	$_temp_array	= explode("\r\n\r\n", $return);
    	$_temp_array2	= explode("\r\n", $_temp_array[1]);

    	if (sizeof($_temp_array2) > 1)	$return_string	= $_temp_array2[1];
    	else 														$return_string	= $_temp_array2[0];

    	return $return_string;

    }

    // 앱에서 재렌더링 될때마다 호출해서 조회수 뻥튀기 되는 현상 발생 방지용
    function reduplicate_check($token, $idx) {
    	// $date = date('Y-m-d');
    	// $sql	= "SELECT idx FROM ch_api_conn_log WHERE wdate >= '$date 00:00:00' AND wdate <= '$date 23:59:59'";
    	// $res	= sql_query($sql);
    	// $num	= sql_num_rows($res);
      //
    	// if($num == 0) @sql_query("DELETE FROM ch_api_conn_log");
      //
    	// $chk_sql	= "SELECT idx FROM ch_api_conn_log WHERE appToken = '$token' AND bidx = '$idx'";
    	// $chk_res	= sql_query($chk_sql);
    	// $chk_num	= sql_num_rows($chk_res);
      //
    	// if($chk_num > 0) {
    	// 	return false;
    	// } else {
    	// 	$i_sql	= "INSERT INTO ch_api_conn_log SET wdate = NOW(), appToken = '$token', bidx = '$idx'";
    	// 	@sql_query($i_sql);
    	// 	return true;
    	// }
    }

    //FCM 발송 함수
    function fcm_push($token_list, $title, $message, $image="", $clickScreen="", $clickParams="", $ssd_badge ='-1') {

    // $FCM_KEY = 'AAAA9F4eJXg:APA91bFZcEgSziQwMwANtWVDIFxMgESR4tzPTWFx81lSXUP7s2w5dIUjSNACile6V_4iHOBdHdTDkXlQv5nxgvORQcbcrjnw1lVBuzLuvc5z3O_lCA8VlLDjKo7FNA4A4ORRP6TprCk6';
    	$FCM_KEY = 'AAAA22oOL1s:APA91bGbcP63eiyLOXCsRa_doWbwkwBst_5gHAc7tvjUvJbfPfbwaOkIJkZERNMBoqrKaEm6vlJkuQjcWl7gxbCMO72PEyMnj3CUdJtf_QYeeykdd3MFW9kfz7w--PudxoVN9egwBkVD';
    	$FCM_URL = 'https://fcm.googleapis.com/fcm/send';

    	$fields = array (
    		'data' => array (
    			'title'		=> $title,
    			'message'	=> $message,
    			'intent'	=> $clickScreen,
    			'badge'		=> $ssd_badge
    		),
    		'notification' => array (
    			'title'	=> $title,
    			'body'	=> $message,
    			'sound' => 'default',
    			'badge' => 20,
    			'image' => $image
    		),
    		'badge'	=> 30
    	);

    	if(is_array($token_list))	$fields['registration_ids'] = $token_list;
    	else 											$fields['to'] 							= $token_list;

    	if(is_array($clickParams)) {
    		foreach($clickParams AS $key => $val) {
    			$fields['data'][$key] = $val;
    		}
    	}

    	$headers = array( 'Authorization:key='. $FCM_KEY, 'Content-Type:application/json' );
    	$ch = curl_init();

    	curl_setopt($ch, CURLOPT_URL, $FCM_URL);
    	curl_setopt($ch, CURLOPT_POST, true);
    	curl_setopt($ch, CURLOPT_HTTPHEADER, $headers);
    	curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
    	curl_setopt($ch, CURLOPT_SSL_VERIFYHOST, 0);
    	curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, true);
    	curl_setopt($ch, CURLOPT_POSTFIELDS, json_encode($fields));

    	$result = curl_exec($ch);
    	if($result === false)	die('Curl failed: ' . curl_error($ch));

    	curl_close($ch);
    	$obj = json_decode($result);

    	return $obj;
    }

    function file_upload($key, $path, $suffix="") {
      if($suffix == "") $suffix = date('YmdHis')."_".$this->get_rand_string();
      else              $suffix .= "_".date('YmdHis');

      if(!is_dir($path)) mkdir($path, CH_DIR_PERMISSION);
      if(fileperms($path) >= 16839) {
        $file_name = "{$suffix}.".pathinfo($_FILES[$key]['name'],PATHINFO_EXTENSION);
        copy($_FILES[$key]['tmp_name'], $path."/".$file_name);
    	 	// $srcimg = $photo_name;
    	 	// $dstimg = $photo_name;
    	 	// $photo_width = "120";
    	 	// img_resize($srcimg, $dstimg, $upfile_path, $photo_width, $photo_height);
    		return $file_name;
  		} else {
        return "";
      }
    }

    function area_info($zone="") {
    		$area_1 = array("서울","부산","대구","인천","광주","대전","울산","세종특별자치시","경기","강원","충북","충남","전북","전남","경북","경남","제주특별자치도");
    		$area_2 = array();
        $area_2["서울"]		= array("강남구","강동구","강북구","강서구","관악구","광진구","구로구","금천구","노원구","도봉구","동대문구","동작구","마포구","서대문구","서초구","성동구","성북구","송파구","양천구","영등포구","용산구","은평구","종로구","중구","중랑구");
    		$area_2["부산"]		= array("강서구","금정구","남구","동구","동래구","부산진구","북구","사상구","사하구","서구","수영구","연제구","영도구","중구","해운대구");
    		$area_2["대구"]		= array("남구","달서구","달성군","동구","북구","서구","수성구","중구");
    		$area_2["인천"]		= array("강화군","계양구","남동구","동구","미추홀구","부평구","서구","연수구","옹진군","중구");
    		$area_2["광주"]		= array("광산구","남구","동구","북구","서구");
    		$area_2["대전"]		= array("대덕구","동구","서구","유성구","중구");
    		$area_2["울산"]		= array("남구","동구","북구","울주군","중구");
    		$area_2["세종특별자치시"]	  = array();
    		$area_2["경기"]		= array("가평군","고양시","과천시","광명시","광주시","구리시","군포시","김포시","남양주시","동두천시","부천시","수원시","시흥시","안산시","안성시","안양시","양주시","양평군","여주시","연천군","오산시","용인시","의왕시","의정부시","이천시","파주시","평택시","포천시","하남시","화성시");
    		$area_2["강원"]		= array("강릉시","고성군","동해시","삼척시","속초시","양구군","양양군","영월군","원주시","인제군","정선군","철원군","춘천시","태백시","평창군","홍천군","화천군","횡성군");
        $area_2["충북"]   = array("괴산군","단양군","보은군","영동군","옥천군","음성군","제천시","증평군","진천군","청주시","충주시");
        $area_2["충남"]   = array("계룡시","공주시","금산군","논산시","당진시","보령시","부여군","서산시","서천군","아산시","예산군","천안시","청양군","태안군","홍성군");
        $area_2["전북"]   = array("고창군","군산시","김제시","남원시","무주군","부안군","순창군","완주군","익산시","임실군","장수군","전주시","정읍시","진안군");
        $area_2["전남"]   = array("강진군","고흥군","곡성군","광양시","구례군","나주시","담양군","목포시","무안군","보성군","순천시","신안군","여수시","영광군","영암군","완도군","장성군","장흥군","진도군","함평군","해남군","화순군");
        $area_2["경북"]   = array("경산시","경주시","고령군","구미시","군위군","김천시","문경시","봉화군","상주시","성주군","안동시","영덕군","영양군","영주시","영천시","예천군","울릉군","울진군","의성군","청도군","청송군","칠곡군","포항시");
        $area_2["경남"]   = array("거제시","거창군","고성군","김해시","남해군","밀양시","사천시","산청군","양산시","의령군","진주시","창녕군","창원시","통영시","하동군","함안군","함양군","합천군");
        $area_2["제주특별자치도"]	  = array("서귀포시","제주시");

    		if($zone == "") return $area_1;
    		else			      return $area_2[$zone];
    }
  }
?>
