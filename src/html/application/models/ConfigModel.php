<?php

namespace application\models;

class ConfigModel extends Model {
  public function siteSave() {
    extract($_POST);
    // 로고등록
    if($_FILES['admin_logo']['size'] > 0 && $util->file_check($_FILES['admin_logo']['name'])){
      $photo_name = $this->util->file_upload("admin_logo", CH_DATA_PATH."/config", "adm_logo");
    }
    if(isset($menu_use)) $tmp_menu = implode("/", $menu_use);
    else                 $tmp_menu = "";

    $site_key = trim($site_key);

    if($designer_pw != "")	{
      $pass       = hash('sha256', $designer_pw);
      $design_sql = "designer_pw = '{$pass}', ";
    }

    $sql	= " UPDATE ch_site_info SET
          site_key		     = '{$site_key}',
          admin_title		   = '{$admin_title}',
          admin_copyright	 = '{$admin_copyright}',
          addbbs_use		   = '{$addbbs_use}',
          ssl_use			     = '{$ssl_use}',
          ssl_port		     = '{$ssl_port}',
          msg_use			     = '{$msg_use}',
          sms_use			     = '{$sms_use}',
          sms_id			     = '{$sms_id}',
          sms_pw			     = '{$sms_pw}',
          namecheck_use	   = '{$namecheck_use}',
          namecheck_id	   = '{$namecheck_id}',
          namecheck_pw	   = '{$namecheck_pw}',
          point_use		     = '{$point_use}',
          designer_id		   = '{$designer_id}',
          {$design_sql}
          menu_use		     = '{$tmp_menu}',
          mini_use		     = '{$mini_use}',
          estimate_use	   = '{$estimate_use}'";

    try {
      $this->pdo->exec($sql);
      return true;
    } catch(PDOException $e) {
      return "{$e->getMessage()}\n{$e->getFile()} - Line({$e->getLine()})\n{$sql}";
    }
  }
}
?>
