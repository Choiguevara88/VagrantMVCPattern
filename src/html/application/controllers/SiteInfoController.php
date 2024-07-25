<?php
namespace application\controllers;

class SiteInfoController extends Controller {

  public function index($params) {
    if($_SESSION['ch_session']['id'] == "") {
      require_once __DIR__.'/../views/home/login.php';
    } else {

      $home = new \application\models\HomeModel();
      $siteinfo   = new \application\models\HomeModel();

      $site_info  = $home->siteInfo();
      $admin_main = $home->adminMain();

      require_once __DIR__.'/../views/inc/admin_header.inc';
      require_once __DIR__.'/../views/admin/config/site_info.php';
      require_once __DIR__.'/../views/inc/admin_footer.inc';
    }
  }
}
?>
