<?php
namespace application\_core;

class Application {

  public $controller;
  public $action;

  public function __construct() {
    $getUrl = '';
    if (isset($_GET['url'])) {
      $getUrl = rtrim($_GET['url'], '/');
      $getUrl = filter_var($getUrl, FILTER_SANITIZE_URL);
    }

    $getParams  = explode('/', $getUrl);
    $getParams  = array_values(array_filter($getParams));

    $_dir     = isset($getParams[0]) && $getParams[0] != '' ? $getParams[0] : 'Home';
    $_action  = isset($getParams[1]) && $getParams[1] != '' ? $getParams[1] : 'index';
    $_params  = array_slice($getParams,2,count($getParams)-2);
    // echo "<pre>"; print_r($_params); echo "</pre>";
    if (!file_exists(__DIR__."/../controllers/{$_dir}Controller.php")) {
      $err_key  = $_dir;
      $err_msg  = "Controller Class Not Found";
      include __DIR__."/../views/inc/error.inc";
      exit();
    }
    $controllerName = "\application\controllers\\".$_dir."controller";
    new $controllerName($_dir, $_action, $_params);

  }
}
?>
