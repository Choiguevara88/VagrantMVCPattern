<?php

namespace application\models;

class HomeModel extends Model {

  public function siteInfo() {

    $sql  = "SELECT * FROM ch_site_info";
    $res  = $this->pdo->query($sql);
    $row  = $res->fetch();

    $bbs_grp  = explode("\n", $row['bbs_grp']);
    $tmp_bool = true;

    for($ii = 0; $ii < count($bbs_grp); $ii++) {
      if(!empty($bbs_grp[$ii])) {
        $tmp_grp  = explode("^", $bbs_grp[$ii]);
        if($tmp_bool) { $tmp_first = $tmp_grp[1]; $tmp_bool = false; }
        $bbs_grp_list[$tmp_grp[0]]	= $tmp_grp[1];
      }
    }
    $row['bbs_grp_list']  = $bbs_grp_list;

    $sql  = "SELECT * FROM ch_bbsinfo WHERE type='BBS' ORDER BY grp ASC, prior ASC";
    $res  = $this->pdo->query($sql);
    $bbs  = $res->fetchAll();
    $row['bbs'] = $bbs;

    $sql  = "SELECT * FROM ch_page ORDER BY prior ASC, idx DESC";
    $res  = $this->pdo->query($sql);
    $page = $res->fetchAll();
    $row['page'] = $page;

    // $sql  = "SELECT * FROM ch_otherinfo WHERE type = 'domain' ORDER BY idx ASC";
    // $res  = $this->pdo->query($sql);
    // $domain = $res->fetchAll();
    // $row['domain']  = $domain;

    $menu_arr = array();
    $menu_tmp = explode("/", $row['menu_use']);
    for($ii=0; $ii<count($menu_tmp); $ii++) {
      $menu_arr[$menu_tmp[$ii]] = true;
    }
    $row['menu_arr']  = $menu_arr;

    return $row;
  }

  public function adminMain() {

    global $util;

    $return  = array();

    // 전체회원수
		$sql  = "SELECT idx FROM ch_member WHERE 1=1";
		$res  = $this->pdo->query($sql);
		$all_total = $res->rowCount();

		// 오늘가입자수
		$sql  = "SELECT idx FROM ch_member WHERE wdate BETWEEN '".date('Y-m-d 00:00:00')."' AND '".date('Y-m-d 23:59:59')."'";
		$res  = $this->pdo->query($sql);
		$today_total = $res->rowCount();

		// 이번달가입회원수
		$sql  = "SELECT idx FROM ch_member WHERE wdate BETWEEN '".date('Y-m-d 00:00:00', strtotime("-1 month"))."' AND '".date('Y-m-d 23:59:59')."'";
		$res  = $this->pdo->query($sql);
		$month_total = $res->rowCount();

		// 이번연도가입회원수
		$sql  = "SELECT idx FROM ch_member WHERE wdate BETWEEN '".date('Y-m-d 00:00:00', strtotime("-1 year"))."' AND '".date('Y-m-d 23:59:59')."'";
		$res  = $this->pdo->query($sql);
		$year_total = $res->rowCount();

    $return['all_total']    = number_format($all_total);
    $return['today_total']  = number_format($today_total);
    $return['month_total']  = number_format($month_total);
    $return['year_total']   = number_format($year_total);

    // 최근 가입회원 8명
    $sql  = "SELECT m.*, l.name AS lv
             FROM ch_member AS m
             LEFT JOIN ch_level AS l ON m.level = l.idx
             ORDER BY m.wdate DESC";
    $res  = $this->pdo->query($sql);
    $mem  = $res->fetchAll();
    $return['member']       = $mem;

    // 최근 게시글 8개
    $sql  = "SELECT b.idx, b.code, b.subject, b.wdate, bi.title, bi.type
             FROM ch_bbs AS b
             LEFT JOIN ch_bbsinfo AS bi ON b.code = bi.code
						 WHERE b.code = bi.code
             ORDER BY b.idx DESC LIMIT 0,8";
    $res  = $this->pdo->query($sql);
    $row  = $res->fetchAll();
    $i    = 0;

    foreach($row AS $_row) {
      $calc_date  = calc_date($_row['wdate']);
      $new		= "";
      if($calc_date <= 2)	$new = "<img src='../image/main/n.gif' border='0' align='absmiddle'>";	// new
      if(strpos($_row['type'], "SCH") !== false)  $url = "../schedule/list.php";
      else 														            $url = "../bbs/list.php";
      $row[$i]['new'] = $new;
      $row[$i]['url'] = $url;
      $i++;
    }

    $return['bbs']  = $row;

    // 총게시판수
    $sql      = "SELECT code FROM ch_bbsinfo WHERE type != 'SCH'";
    $res      = $this->pdo->query($sql);
    $bbs_num  = $res->rowCount();

    // 총게시물수
    $sql      = "SELECT idx FROM ch_bbs";
    $res      = $this->pdo->query($sql);
    $bbs_total= $res->rowCount();

    // 오늘게시물수
    $today  = date("Y-m-d");
    $sql      = "SELECT idx FROM ch_bbs WHERE wdate >= '{$today} 00:00:00' AND wdate <= '{$today} 23:59:59'";
    $res      = $this->pdo->query($sql);
    $bbs_today= $res->rowCount();

    // 오늘댓글
    $sql      = "SELECT idx FROM ch_comment WHERE wdate >= '{$today} 00:00:00' AND wdate <= '{$today} 23:59:59'";
    $res      = $this->pdo->query($sql);
    $cmt_today= $res->rowCount();

    $return['bbs_num']    = number_format($bbs_num);
    $return['bbs_total']  = number_format($bbs_total);
    $return['bbs_today']  = number_format($bbs_today);
    $return['cmt_today']  = number_format($cmt_today);


    $sql    = "SELECT * FROM ch_order WHERE status != '' AND orderid !='' ORDER BY order_date DESC LIMIT 0,5";
    $res    = $this->pdo->query($sql);
    $order  = $res->fetchAll();

    $return['order']  = $order;

    // 오늘매출액
    $sdate  = date('Y-m-d')." 00:00:00";
    $edate  = date('Y-m-d')." 23:59:59";
    $sql    = "SELECT SUM(total_price) AS total_price FROM ch_order
               WHERE order_date >= '{$sdate}' AND order_date <= '{$edate}'
               AND (status='OY' OR status='DR' OR status='DI' OR status='DC')";
    $res    = $this->pdo->query($sql);
    $row    = $res->fetch();
    $today_price  = $row['total_price'];

    // 이달매출액
    $sdate  = date('Y-m')."-01 00:00:00";
    $edate  = date('Y-m')."-".date('t')." 23:59:59";
    $sql    = "SELECT SUM(total_price) AS total_price FROM ch_order
               WHERE order_date >= '{$sdate}' AND order_date <= '{$edate}'
               AND (status='OY' OR status='DR' OR status='DI' OR status='DC')";
    $res    = $this->pdo->query($sql);
    $row    = $res->fetch();
    $month_price  = $row['total_price'];

    // 올해매출액
    $sdate  = date('Y')."-01-01 00:00:00";
    $edate  = date('Y')."-12-31 23:59:59";
    $sql    = "SELECT SUM(total_price) AS total_price FROM ch_order
               WHERE order_date >= '{$sdate}' AND order_date <= '{$edate}'
               AND (status='OY' OR status='DR' OR status='DI' OR status='DC')";
    $res    = $this->pdo->query($sql);
    $row    = $res->fetch();
    $year_price  = $row['total_price'];

    // 총매출액
    $sql    = "SELECT SUM(total_price) AS total_price FROM ch_order WHERE (status='OY' OR status='DR' OR status='DI' OR status='DC')";
    $res    = $this->pdo->query($sql);
    $row    = $res->fetch();
    $total_price  = $row['total_price'];

    $return['today_price']  = number_format($today_price);
    $return['month_price']  = number_format($month_price);
    $return['year_price']   = number_format($year_price);
    $return['total_price']  = number_format($total_price);

    // 메인게시판 차트 데이터
    $prev_period  = date('Y-m-')."01 00:00:00";
    $next_period  = date('Y-m-').date('t')." 23:59:59";

    // 일별
    $label		= "일";
    $cnt_list = array();
    $ccnt_list= array();
    $sql      = "SELECT COUNT(*) AS cnt, SUBSTRING(wdate, 7, 2) AS wdate
                FROM ch_bbs, ch_bbsinfo
                WHERE ch_bbs.code = ch_bbs.code
                AND wdate >= '{$prev_period}' AND wdate <= '{$next_period}'
                AND type='BBS'
                GROUP BY SUBSTRING(wdate, 7, 2) ORDER BY wdate";
    $res      = $this->pdo->query($sql);
    while($row = $res->fetch()) { $cnt_list[$row['wdate']]  = $row['cnt']; }

    $sql      = "SELECT COUNT(*) AS cnt, SUBSTRING(wdate, 7, 2) AS wdate
                FROM ch_comment
                WHERE wdate >= '{$prev_period}' AND wdate <= '{$next_period}'
                GROUP BY SUBSTRING(wdate, 7, 2) ORDER BY wdate";
    $res      = $this->pdo->query($sql);
    while($row = $res->fetch()) { $ccnt_list[$row['wdate']]  = $row['cnt']; }

    $pr_end     = (int)date('t');
    $bbs_count  = array();
    $cmt_count  = array();

    for($ii=1; $ii<=$pr_end; $ii++) {
      if($cnt_list[$ii]=='')  $cnt_list[$ii]=0;
      if($ccnt_list[$ii]=='') $ccnt_list[$ii]=0;
      $bbs_count[$ii] = $cnt_list[$ii];
      $cmt_count[$ii] = $ccnt_list[$ii];
    }
    $max_bbs      = max($bbs_count);
    $max_comment  = max($cmt_count);
    if($max_bbs >= $max_comment)  $border_cnt=$max_bbs;
    else                          $border_cnt=$max_comment;
    $jj     = 0;
    $result = 0;
    do {
      $border_cnt_str = substr($result, -1);
      $result         = $border_cnt+$jj;
      $jj++;
    } while($border_cnt_str == '0' && $jj != 0);

    if($result==$border_cnt)  $result += 10;
    $bbs_labels = implode("','", array_keys($bbs_count));
    $bbs_datas  = implode("','", $bbs_count);
    $cmt_labels = implode("','", array_keys($cmt_count));
    $cmt_datas  = implode("','", $cmt_count);

    $return['bbs_max']    = $result;
    $return['bbs_labels'] = "'{$bbs_labels}'";
    $return['bbs_datas']  = "'{$bbs_datas}'";
    $return['cmt_labels'] = "'{$cmt_labels}'";
    $return['cmt_datas']  = "'{$cmt_datas}'";

    $prev_period  = date('Ym')."0100";
    $next_period  = date('Ymd')."24";
    $period_sql = " WHERE time >= '".str_replace('-', '', $prev_period)."'
                    AND   time <= '".str_replace('-', '', $next_period)."' ";
    $sql	= "SELECT SUM(cnt) AS cnt,
             SUBSTRING(`time`, 7, 2) AS `time`
             FROM ch_contime {$period_sql} GROUP BY SUBSTRING(`time`, 7, 2) ORDER BY SUBSTRING(`time`, 7, 2)";
    $res  = $this->pdo->query($sql);
    $con_list = array();
    while($row = $res->fetch()) { $con_list[$row['time']]	= $row['cnt']; }

    for($ii=1;$ii<=$pr_end;$ii++){
      if($cnt_list[$ii]=='')  $con_list[$ii]=0;
      $con_count[$ii] = $con_list[$ii];
    }
    $common_cnt = max($con_count);
    $jj     =0;
    $result =0;
    do {
      $common_cnt_str = substr($result, -1);
      $result         = $common_cnt+$jj;
      $jj++;
    } while($common_cnt_str == '0' && $jj != 0);
    if($result==$common_cnt) $result  += 10;
    $con_labels = implode("','", array_keys($con_count));
    $con_datas  = implode("','", $con_count);

    $return['con_max']    = $result;
    $return['con_labels'] = "'{$con_labels}'";
    $return['con_datas']  = "'{$con_datas}'";

    return $return;
  }
}

?>
