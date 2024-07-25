<?php

namespace application\models;

class AdminModel extends Model {

  public function LoginApi($params) {

    global $util;

    if(empty($_POST['id']) || empty($_POST['pw'])) die($util->result_data(false, "잘못된 접근방식 입니다.", []));

    $adm      = new \application\models\AdminModel($_POST['id']);
    $is_login = $adm->login($_POST['id'], $_POST['pw']);

    if(gettype($is_login) != "boolean" || $is_login !== true) {
      echo $util->result_data(false, $is_login, []);
    } else {
      if($_POST["save_id"] == "Y") setcookie("save_id", $id, time()+3600*24*365, "/");

      $_SESSION['ch_admin']['id']      = $adm->id;
    	$_SESSION['ch_admin']['name']    = $adm->name;
    	$_SESSION['ch_admin']['email']   = $adm->email;
      $_SESSION['ch_admin']['photo']   = $adm->photo;

      echo $util->result_data(true, "{$adm->name} 님 반갑습니다.", []);
    }
  }

}
?>
