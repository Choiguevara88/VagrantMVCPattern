<?php
namespace application\controllers;

class MemberController extends Controller {

  public function LoginApi($params) {

    global $util;

    if(empty($_POST['id']) || empty($_POST['pw'])) die($util->result_data(false, "잘못된 접근방식 입니다.", []));

    $member   = new \application\models\MemberModel($_POST['id']);
    $is_login = $member->login($_POST['id'], $_POST['pw']);

    if(gettype($is_login) != "boolean" || $is_login !== true) {
      echo $util->result_data(false, $is_login, []);
    } else {
      if($_POST["save_id"] == "Y") setcookie("save_id", $id, time()+3600*24*365, "/");

      $_SESSION['ch_session']['id']      = $member->id;
    	$_SESSION['ch_session']['name']    = $member->name;
    	$_SESSION['ch_session']['email']   = $member->email;

      echo $util->result_data(true, "{$member->name} 님 반갑습니다.", []);
    }
  }

}
?>
