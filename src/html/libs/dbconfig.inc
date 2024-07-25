<?
define('DB_HOST', "localhost");
define('DB_PORT', "3306");
define('DB_NAME', "prj20220110");
define('DB_USER', "prj20220110");
define('DB_PASS', "prj20220110");

// class Database  {
//
// }

try {
  $pdo  = new PDO("mysql:host=".DB_HOST.";dbname=".DB_NAME, DB_USER,DB_PASS);
  $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
} catch(PDOException $e) {
  echo "{$e->getMessage()}<br/>{$e->getFile()} - Line({$e->getLine()})<br/>";
}

?>
