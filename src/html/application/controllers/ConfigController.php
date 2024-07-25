<?php
namespace application\controllers;

class ConfigController extends Controller {
  function index() {
    $home = new \application\models\HomeModel();
    $site_info  = $home->siteInfo();

    require_once __DIR__.'/../views/inc/admin_header.inc';
    require_once __DIR__.'/../views/admin/config/config.php';
    require_once __DIR__.'/../views/inc/admin_footer.inc';
  }

  function save() {
    global $util;

    if(empty($_POST)) {
      $err_key  = "Ooooopsss!";
      $err_msg = "Someting went wrong.";
      include __DIR__."/../views/inc/error.inc";
      exit();
    }

    $conf     = new \application\models\ConfigModel();
    $is_save  = $conf->siteSave();
    if(gettype($is_save) != "boolean" || $is_save !== true) {
    } else {
      $util->complete("기본 설정이 저장되었습니다.","/config/");
    }
  }
}
?>
