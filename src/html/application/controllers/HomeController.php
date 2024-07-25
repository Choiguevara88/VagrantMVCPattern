<?php
namespace application\controllers;

class HomeController extends Controller {

  public function index($params) {
    if($_SESSION['ch_session']['id'] == "") {

      // $form['id'] 			= "test1234";
      // $form['passwd']		= "1234";
      // $form['name']			= "테스트";
      // $form['icon']			= "";
      // $form['photo']		= "";
      // $form['nick']			= "테스트";
      // $form['email']		= "test@test.com";
      // $form['tphone']		= "02-1234-5678";
      // $form['hphone']		= "010-1234-5678";
      // $form['homepage']	= "";
      // $form['post']			= "08574";
      // $form['address1']	= "서울 금천구 탑골로 1";
      // $form['address2']	= "틀니읍 딱딱리";
      // $form['reemail']	= "Y";
      // $form['resms']		= "Y";
      // $form['birthday']	= "1988-05-04";
      // $form['intro']		= "HiHelloKonnichiwaNihao";
      // $form['memo']			= "메모입니다.";
      // $id = "test20220108104130";
      // $member	= new \application\models\MemberModel($form['id']);
      // $member->info();
      // print_r($member);
      // $is_join = $member->join($form);
      // echo (gettype($is_join));
      // echo "<br />";
      // echo ($is_join);

      require_once __DIR__.'/../views/home/login.php';
    } else {

      $home = new \application\models\HomeModel();
      $site_info  = $home->siteInfo();
      $admin_main = $home->adminMain();

      require_once __DIR__.'/../views/inc/admin_header.inc';
      require_once __DIR__.'/../views/admin/main/main.php';
      require_once __DIR__.'/../views/inc/admin_footer.inc';
    }
  }
}
?>
