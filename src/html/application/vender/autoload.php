<?php
spl_autoload_register(function($path) {

  $path = str_replace('\\','/',$path);
  $paths = explode('/', $path);

  if (preg_match('/model/', strtolower($paths[1])))           $className  = 'models';
  else if (preg_match('/controller/',strtolower($paths[1])))  $className  = 'controllers';
  else if (preg_match('/api/',strtolower($paths[1])))         $className  = 'api';
  else                                                        $className  = '_core';

  if($paths[2] == "") $contName = 'application';
  else                $contName = $paths[2];

  $loadpath =  $paths[0].'/'.$className.'/'.$contName.'.php';
  // print_r($paths); exit;
  // echo $loadpath; exit;
  // echo 'autoload $path : ' . $loadpath . '<br>';
  if (!file_exists(__DIR__."/../../{$loadpath}")) {
    // echo " --- autoload : . (".__DIR__."/../../{$loadpath}".") ";
    $err_key  = $loadpath;
    $err_msg = "File Not Found";
    include __DIR__."/../views/inc/error.inc";
    exit();    

  }
  require_once $loadpath;
});

?>
