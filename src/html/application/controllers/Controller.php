<?php
namespace application\controllers;

class Controller {

  public function __construct($menu, $action, $params) {
    if (!file_exists(__DIR__.'/../models/'.$menu.'Model.php')) {
      // var_dump("Model Class not found. ({$menu})");
      $err_key  = $menu;
      $err_msg = "Model Class Not Found";
      include __DIR__."/../views/inc/error.inc";
      exit();
    }
    if(!method_exists($this, $action)) {
      $err_key  = $action;
      $err_msg = "Method is not defined in Class {$menu}Model";
      include __DIR__."/../views/inc/error.inc";
      exit();
    }
    $this->$action($params);
  }
}
?>
