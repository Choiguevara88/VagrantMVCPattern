<?php
namespace application\controllers;

class AdminController extends Controller {

  public function index($params) {
    if($_SESSION['ch_admin']['id'] == "") {
      require_once __DIR__.'/../views/admin/login/login.php';
    } else {
      $this->list($params);
    }
  }

  public function list($params) {

  }
}
?>
